#include "display.h"
#include <intrins.h>
#include "i2c.h"
#include "button.h"
//#include <stdlib.h>

#define PWM_MAX  200
uint8_t code code_7seg_pwm[] = {0xff,0x7f,0x77,0x5d,0x55,0x52,0x11,0x01};

uint8_t polling_display_timing = 2;

uint8_t TimeoutColse = 60;			/*超时关闭时长倒计时*/
/*
bit 7 常亮开启 1 
bit 0 - 5 超时时长; 
*/
uint8_t TimeoutColseMAX = 5;		/*超时关闭预设值*/
/*
bit 0 - 1 单个显示,显示模式的索引
年 温度  -> 月日 星期  ->时分 秒 ->时分 温度
bit 3 - 6 每bit表示要轮询的显示模式 
bit 7 开启轮询显示
*/
uint8_t display_mode_index = 0; 	/*数码管显示的模式*/
uint8_t display_7seg_pwm = 0xff;
uint8_t display_7seg_pwm_index = 0;
uint8_t disp_time[7];
/*
bit 7 开启 ：1 关闭 ：0
bit 6 暂停 ：1 启动 ：0
bit 5 单色 ：1 随机 ：0

bit 0 - 3 递增递减的RGB灯的索引
*/
uint8_t led_cloor_index = 0x40;    	/*led显示灯颜色*/
uint8_t breathing_rate = 4;			/*呼吸速率*/
/* RGB 颜色灯 PWM阈值*/
uint8_t RGB_ratio[3] = {0}; 

/*
bit 7 双击
*/
uint8_t main_key_timing = 0;
/*
bit 0 - 6   1 - 7 数码管
bit 7 是否 开启闪烁
闪烁的位置
*/
uint8_t twink_index = 0;

bit TimeFlag1s 		= 1;
bit StartRunFlag 	= 1;
bit DotDispFlag 	= 1;
bit AlarmEnableFlag = 0;
bit SetModeFlag 	= 0;	/*设置模式标志*/
bit SetTwinkleFlag  = 0;	/*显示闪烁标志*/

void close_all_low_power()
{
	/*关闭定时器中断*/
	ET0 = 0;
	ET1 = 0;			
	TR0 = 0;
	TR1 = 0;
	
	/*退出设置*/
	SetModeFlag = 0;
	/*清楚主按键标记*/
	main_key_timing = 0;
	/*关闭全彩LED*/
	P0 |= 0xe0; 
	/*关闭数码管输出*/
	DisplayBitSelect(0x00);
	DisplayOneLED(0x00);
	/*关闭时间小点显示*/
	COLON_PIN = 1;
	INT0 = 1;                   //ready read INT0 port
	INT1 = 1; 
	while (!INT0 && !INT1);              //check INT0
	_nop_();
	_nop_();
	PCON = 0x02;                //MCU power down
	_nop_();
	_nop_();	
}

void init_system_io()
{
	Timer0Init();
	Timer1Init();
	
    IT0 = 1;                        //set INT0 int type (1:Falling 0:Low level)
    EX0 = 1;                        //enable INT0 interrupt
	
	IT1 = 1;
    EX1 = 1;
	
    EA = 1;                         //open global interrupt switch
	P0 |= 0xe0;	
}

void rgbled_gradient_breathing()
{
	/*哪几种颜色呼吸变换 bit 7 - 5 R G B*/
	uint8_t code on_num[16] ={0x80,0x40,0x20,0xa0,0x60,0xc0,0xe0,0x60,0xa0,0x80,0x20,0xc0,0xa0,0x40,0x80,0xe0};
	/*bit 0 - 3 哪几个灯呼吸灯索引  
	  bit 7 - 5 RGB灯PWM的方向增大还是减小
	*/
	static uint8_t RGB_dir = 0xe0;
	uint8_t i;
	
	for(i = 0; i < 3; i++)
	{
		if(on_num[led_cloor_index & 0x0f] & (0x80>>i))
		{
			if(RGB_ratio[i] == PWM_MAX && (RGB_dir & (0x80>>i)) != 0)	
			{
				RGB_dir &= (~(0x80>>i));
			}
			else if(RGB_ratio[i] == 0  && (RGB_dir & (0x80>>i)) == 0)
			{
//				RGB_dir &= 0xf0;
				led_cloor_index ++;
				led_cloor_index &= 0xef;
				
//				RGB_dir |= (led_cloor_index & 0x0f);
				RGB_dir |= (0x80>>i);
			}

			if(RGB_dir & (0x80>>i))
			{
				RGB_ratio[i]++;
			}
			else 
			{
				RGB_ratio[i]--;
			}
		}
	}
}

void display_mode(uint8_t *time,uint8_t index)
{
	switch(index)
	{
		case 0:
			display_hour_min_sec(time,0);  // 时 分 温度
			display_temperature();
			DotDispFlag = 1;
			break;
		
		case 1:
			display_hour_min_sec(time,1);   //时 分 秒
			DotDispFlag = 1;
			break;
		
		case 2:
			display_month_day_week(time);	//月 日 星期
			DotDispFlag = 0;
			break;
		
		case 3:
			dispaly_year(time);				//年 温度
			if(!SetModeFlag)
			{
				display_temperature();	
			}
			else
			{
				display_set_mode(0);
			}
			DotDispFlag = 0;
			break;
		
		default:
			DotDispFlag = 1;				
			display_hour_min_sec(time,0);
			display_temperature();				
			break;	
	}
}

bit polling_display_mode()
{
	/*bit 0 - 1 低位计时
	  bit 3 - 
	*/
	static uint8_t index = 0;
	uint8_t temp;
	bit status = 0;
	
	if(index != 0)
	{
		index++;
		
		if((index & 0x03) < polling_display_timing)
		{
			return 1;
		}
	}
	
	temp = index>>3;
	do{

		temp++;
		if(temp >= 5)
		{
			temp = 0;
			index = 0;
			return 0;
		}
		
		if(display_mode_index & (0x80>>temp))
		{
			display_mode_index &= ~0x03;				
			display_mode_index |= (4 - temp);
			status = 1;
		}
		
	}while(!status);
	index = temp << 3;
		
	return status;
}

bit timeout_no_operation_quit()
{
	if(TimeFlag1s == 1 && StartRunFlag == 1)
	{	
		TimeFlag1s = 0;
		if(TimeoutColse > 0)
		{
			TimeoutColse--;
			return  0;
		}
		else 
		{
			if(TimeoutColseMAX & 0x80 == 0)
			{
				StartRunFlag = 0;
			}
			return 1;
		}
	}			
	return  0;
}

void text_data_out_range(uint8_t time_index,uint8_t *time)
{
	uint8_t max_value,min_value;
	switch(time_index)
	{
		case 0:
			twink_index = 0x60 | 0x80;
			max_value = 60;
			min_value = 0;			
			break;
		case 1:
			twink_index = 0x0c | 0x80;
			max_value = 60;
			min_value = 0;
			break;
		
		case 2:
			twink_index = 0x03 | 0x80;			
			max_value = 24;
			min_value = 0;
			break;
		
		case 3:
			twink_index = 0x40 | 0x80;			
			max_value = 7;
			min_value = 0;
			break;
		
		case 4:
			twink_index = 0x0c | 0x80;			
			max_value = 32;
			min_value = 1;
			break;
		
		case 5:
			twink_index = 0x03 | 0x80;						
			max_value = 13;
			min_value = 1;
			break;
		
		case 6:
			twink_index = 0x0c | 0x80;				
			max_value = 100;
			min_value = 00;
			break;	
		case 7:
			max_value = 61;
			min_value = 00;
			break;	
		case 8:
			max_value = 5;
			min_value = 1;
			break;	
		case 9:
			max_value = 4;
			min_value = 1;
			break;
		default:
			return;
	}	
	if(*time == max_value)
	{
		*time = min_value;
	}
	else if(*time > max_value) 
	{
		*time = max_value - 1;
	}
	else if(*time < min_value)
	{
		*time = max_value - 1;
	}
}	

void button_set_time()
{
	uint8_t time_index = 7,button_status,mode_index;
	button_status_bit = 0x01;
	twink_index = 0x80;
	DotDispFlag = 0;
	while(SetModeFlag) 
	{
		
		if(button_status_bit == N_key)   //无按键
		{
			if(SetTwinkleFlag)
			{
				display_mode(disp_time,mode_index);				
			}
			else 
			{
				display_colse_tab(twink_index);
			}
			
			if(timeout_no_operation_quit())
			{
				return ;
			}
			continue;
		}
		
		TimeoutColse = 60;
		button_status = button_status_bit & 0x03;
		
		if(button_status == S_key)   //短按 切换设置的单位
		{
			time_index--;			
			if(time_index == 6)
			{
				mode_index = 0x03;
			}
			else if(time_index >=3 && time_index < 6)
			{
				mode_index = 0x02;
			}
			else if(time_index >= 0 && time_index < 3)
			{
				mode_index = 0x01;
			}
			else 
			{
				time_index = 6;
				mode_index = 0x03;
			}
			display_mode(disp_time,mode_index);
		}
		else if(button_status == L_key)  //长按
		{
			Set_Time_Dec(disp_time);
			break;
		}
		
		if(button_status_bit & (S_key<<2))  //按键 加  短按
		{
			disp_time[time_index]++; 
		}

		if(button_status_bit & (S_key<<4)) //按键 减  短按
		{
			disp_time[time_index]--;
		}
		
		text_data_out_range(time_index,&disp_time[time_index]);
		
		display_mode(disp_time,mode_index);
		button_status_bit = 0;	
	}
}

void button_set_alarm()
{
	uint8_t alarm[3] = {0};
	uint8_t time_index = 0,button_status;
	twink_index = 0x80;	
	button_status_bit = 0x01;
	Enable_Alarm(0);	
	Get_Alarm_EveryDay(alarm + 1);
	while(SetModeFlag) 
	{	
		if(button_status_bit == N_key)   //无按键
		{
			if(SetTwinkleFlag)
			{
				display_alarm_clock(alarm + 1);			
			}
			else 
			{
				display_colse_tab(twink_index);
			}
			if(timeout_no_operation_quit())
			{
				return ;
			}
			continue;
		}
		
		TimeoutColse = 60;
		button_status = button_status_bit & 0x03;
		
		if(button_status == S_key)   //短按 切换设置的单位
		{
			time_index++;
			if(time_index >= 3)
			{
				time_index = 0;
			}
		}
		else if(button_status == L_key)  //长按
		{
			Set_Alarm_EveryDay(alarm + 1);
			Enable_Alarm(AlarmEnableFlag);
			break;
		}
		
		if(button_status_bit & (S_key<<2))  //按键 加  短按
		{
			alarm[time_index]++; 
		}

		if(button_status_bit & (S_key<<4)) //按键 减  短按
		{
			alarm[time_index]--;
		}
		button_status_bit = 0;
		text_data_out_range(time_index, &alarm[time_index]);
		AlarmEnableFlag = alarm[0] & 0x01;
		display_alarm_clock(alarm + 1);			
	}
}

void button_function_param()
{
	uint8_t polling_index[] = {0x00,0xaa,0xb2,0xf3};
	uint8_t func_index = 0,button_status;
	uint8_t temp_param[3] = {1,1,1};
	DotDispFlag = 0;
	temp_param[0] = (TimeoutColseMAX & 0x7f);
	temp_param[1] = polling_display_timing;
	display_set_mode(func_index + 3);
	while(SetModeFlag) 
	{	
		if(button_status_bit == N_key)   //无按键
		{
			display_function_param(temp_param[func_index]);
			if(timeout_no_operation_quit())
			{
				return ;
			}
			continue;
		}
		
		TimeoutColse = 60;
		button_status = button_status_bit & 0x03;
		
		if(button_status == S_key)   //短按 切换设置的单位
		{
			func_index++;
			if(func_index >= 3)
			{
				func_index = 0;
			}
			display_set_mode(func_index + 3);
		}
		else if(button_status == L_key)  //长按
		{
			if(temp_param[0] == 0)
			{
				TimeoutColseMAX |= 0x80;
			}
			else
			{
				TimeoutColseMAX = temp_param[0];
			}
			display_mode_index  = polling_index[temp_param[1] - 1];
			polling_display_timing 	= temp_param[2];
			break;
		}
		
		if(button_status_bit & (S_key<<2))  //按键 加  短按
		{
			temp_param[func_index]++; 
		}

		if(button_status_bit & (S_key<<4)) //按键 减  短按
		{
			temp_param[func_index]--;
		}	
		button_status_bit = 0;	
		text_data_out_range(func_index + 7 ,&temp_param[func_index]);
		
	}
}

void button_process()
{
	static uint8_t set_mode_index = 0;
	uint8_t button_status;
	if(button_status_bit == N_key)   //无按键
	{
		return ;
	}
	
	TimeoutColse = 60;
	button_status = button_status_bit & 0x03;
	
	if(button_status == S_key)   //功能键  短按
	{
		if(SetModeFlag)	/*若在设置模式*/
		{
			set_mode_index++;
			if(set_mode_index >= 3)
			{
				set_mode_index = 0;
			}
			display_set_mode(set_mode_index);		
		}
		else
		{	/*切换显示模式*/
			display_mode_index++;
			display_mode_index &= 0xfb;	
			display_mode(disp_time,display_mode_index & 0x03);
		}

	}
	else if(button_status == L_key)  //长按
	{
		if(!SetModeFlag)
		{
			SetModeFlag = 1;
			set_mode_index = 0;	
			display_set_mode(set_mode_index);
		}
		else 
		{
			display_mode_index &= 0xf8;
			SetModeFlag = 0;
			display_mode(disp_time,0);
		}
		while(Button_SET == 0);
	}
	
	button_status = (button_status_bit >> 2) & 0x03;		
	if(button_status == S_key)  //短按 进入设置
	{
		if(SetModeFlag)
		{	
			button_status_bit = 0;			
			switch(set_mode_index)
			{
				case 0:
					button_set_time();
					break;
				case 1:
					button_set_alarm();
					break;

				case 2:
					button_function_param();
					break;
				default:
					break;
			}
			display_mode_index &= 0xf8;
			twink_index = 0;
			display_set_mode(0xe0);
			while(Button_SET == 0);
			SetModeFlag = 0;
		}
		else if(led_cloor_index & 0x80 && TR1 == 1)
		{
			led_cloor_index ++;
			led_cloor_index &= 0xef;
		}
		else 
		{
			display_7seg_pwm = code_7seg_pwm[display_7seg_pwm_index++];
			if(display_7seg_pwm_index >= 8)
			{
				display_7seg_pwm_index = 0;
			}
		}
	}
	else if(button_status == L_key)
	{
		if(led_cloor_index & 0x80 && TR1 == 1)
		{
			if(led_cloor_index & 0x40)
			{
				led_cloor_index &= ~0x40;
			}
			else 
			{
				led_cloor_index |= 0x40;				
			}
			while(Button_PLUSE == 0);
		}			
	}

	button_status = (button_status_bit >> 4) & 0x03;			
	if(button_status == S_key) //按键 减  短按
	{
		if(led_cloor_index & 0x80 && TR1 == 1)
		{
			breathing_rate++;
			if(breathing_rate >= 10)
			{
				breathing_rate = 0;
			}
		}
		else if(SetModeFlag == 0)
		{
			TimeoutColse = 0;
			close_all_low_power();
		}			
	}
	else if(button_status == L_key)
	{
		TimeoutColse = 0;
		close_all_low_power();		
	}

	button_status_bit = 0;
}

void main()
{		
	init_system_io();	
	AlarmEnableFlag = Get_Alarm_Status();
	if(!Get_Init_RX8025_Flag())
	{
		Recovery_Default_Setting();
	}
	
	while(1)
	{
		
		if(TimeFlag1s == 1 && StartRunFlag == 1)
		{	
			TimeFlag1s = 0;
			if(TimeoutColse > 0)
			{
				TimeoutColse--;
			}
			else if((TimeoutColseMAX & 0x80) == 0)
			{
				StartRunFlag = 0;
			}
			
			if(!SetModeFlag)
			{
				if(display_mode_index & 0x80)
				{
					polling_display_mode();
				}
				Get_Time_Dec(disp_time);
				display_mode(disp_time,display_mode_index & 0x03);
			}				
		}		

		
		if(!StartRunFlag)
		{
			close_all_low_power();
		}
		button_process();
	}		
}

void Exint0() interrupt 0           //(location at 0003H)
{
	uint8_t timeout = 50;
	StartRunFlag = 1;
	TimeoutColse = (TimeoutColseMAX & 0x7f);
	ET0 = 1;	
	TR0 = 1;
	TimeFlag1s = 1;	
	if((main_key_timing & 0x80 == 0x80) && (main_key_timing & 0x3f) <= 50)
	{
		ET1 = 1;	
		TR1 = 1;
		led_cloor_index	|= 0x80;	
	}
	main_key_timing |= 0x80;
}

void Exint1() interrupt 2 
{
	StartRunFlag = 1;
	TimeoutColse = 60;
	ET0 = 1;	
	TR0 = 1;
	TimeFlag1s = 1;
	ET1 = 1;	
	TR1 = 1;
	led_cloor_index	|= 0x80;		
}


/*2ms 进入一次*/
void InterruptTime0() interrupt 1
{
	static uint16_t i = 0;

	i++;
	
	if(i == 200)
	{
		SetTwinkleFlag = 1;
		if(SetModeFlag == 0)
		{
			COLON_PIN = 1;
		}
	}
	else if(i == 1000)
	{
		SetTwinkleFlag = 0;

		COLON_PIN = ~DotDispFlag;	
		
	}
	
	if(i >= 1000)
	{
		i = 0;
		TimeFlag1s = 1;
	}
	
	if(i % breathing_rate == 0)
	{
		if(led_cloor_index & 0x80)
		{
			if(led_cloor_index & 0x40)
			{
				rgbled_gradient_breathing();
			}
		}
		else
		{
			P0 |= 0xe0;	
		}
	}
	
	if(i % 20 == 0)
	{
		button_scanning();
		if(main_key_timing & 0x80)
		{
			main_key_timing ++;
			if((main_key_timing & 0x3f) == 0x3f)
			{
				main_key_timing = 0;
			}
		}
	}
	
	TL0 = 0x30;		//设置定时初值
	TH0 = 0xF8;		//设置定时初值
	if(display_7seg_pwm & (0x01 << (i % 8)))
	{
		display_dynamic_buff();
	}
	else 
	{
		DisplayBitSelect(0xf0);
		DisplayOneLED(0x00);
		/*关闭数码管输出*/
		DisplayBitSelect(0x00);
	}
}

void InterruptTime1() interrupt 3
{
	static uint8_t count = 0;
	uint8_t i;
	TR1 = 0;
	count++;	
	for(i = 0; i < 3; i++)
	{
		if(count < RGB_ratio[i])
		{
			P0 &= (~(0x20 << i));
		}
		else 
		{
			P0 |= (0x20 << i);	
		}
	}		
	TR1 = 1;	
}
