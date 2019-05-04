#include "display.h"
#include <intrins.h>
#include "i2c.h"
#include "button.h"
//#include <stdlib.h>

#define PWM_MAX  200
uint8_t code code_7seg_pwm[] = {0xff,0x7f,0x77,0x5d,0x55,0x52,0x11,0x01};

uint8_t polling_display_timing = 2;

uint8_t TimeoutColse = 60;			/*��ʱ�ر�ʱ������ʱ*/
/*
bit 7 �������� 1 
bit 0 - 5 ��ʱʱ��; 
*/
uint8_t TimeoutColseMAX = 5;		/*��ʱ�ر�Ԥ��ֵ*/
/*
bit 0 - 1 ������ʾ,��ʾģʽ������
�� �¶�  -> ���� ����  ->ʱ�� �� ->ʱ�� �¶�
bit 3 - 6 ÿbit��ʾҪ��ѯ����ʾģʽ 
bit 7 ������ѯ��ʾ
*/
uint8_t display_mode_index = 0; 	/*�������ʾ��ģʽ*/
uint8_t display_7seg_pwm = 0xff;
uint8_t display_7seg_pwm_index = 0;
uint8_t disp_time[7];
/*
bit 7 ���� ��1 �ر� ��0
bit 6 ��ͣ ��1 ���� ��0
bit 5 ��ɫ ��1 ��� ��0

bit 0 - 3 �����ݼ���RGB�Ƶ�����
*/
uint8_t led_cloor_index = 0x40;    	/*led��ʾ����ɫ*/
uint8_t breathing_rate = 4;			/*��������*/
/* RGB ��ɫ�� PWM��ֵ*/
uint8_t RGB_ratio[3] = {0}; 

/*
bit 7 ˫��
*/
uint8_t main_key_timing = 0;
/*
bit 0 - 6   1 - 7 �����
bit 7 �Ƿ� ������˸
��˸��λ��
*/
uint8_t twink_index = 0;

bit TimeFlag1s 		= 1;
bit StartRunFlag 	= 1;
bit DotDispFlag 	= 1;
bit AlarmEnableFlag = 0;
bit SetModeFlag 	= 0;	/*����ģʽ��־*/
bit SetTwinkleFlag  = 0;	/*��ʾ��˸��־*/

void close_all_low_power()
{
	/*�رն�ʱ���ж�*/
	ET0 = 0;
	ET1 = 0;			
	TR0 = 0;
	TR1 = 0;
	
	/*�˳�����*/
	SetModeFlag = 0;
	/*������������*/
	main_key_timing = 0;
	/*�ر�ȫ��LED*/
	P0 |= 0xe0; 
	/*�ر���������*/
	DisplayBitSelect(0x00);
	DisplayOneLED(0x00);
	/*�ر�ʱ��С����ʾ*/
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
	/*�ļ�����ɫ�����任 bit 7 - 5 R G B*/
	uint8_t code on_num[16] ={0x80,0x40,0x20,0xa0,0x60,0xc0,0xe0,0x60,0xa0,0x80,0x20,0xc0,0xa0,0x40,0x80,0xe0};
	/*bit 0 - 3 �ļ����ƺ���������  
	  bit 7 - 5 RGB��PWM�ķ��������Ǽ�С
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
			display_hour_min_sec(time,0);  // ʱ �� �¶�
			display_temperature();
			DotDispFlag = 1;
			break;
		
		case 1:
			display_hour_min_sec(time,1);   //ʱ �� ��
			DotDispFlag = 1;
			break;
		
		case 2:
			display_month_day_week(time);	//�� �� ����
			DotDispFlag = 0;
			break;
		
		case 3:
			dispaly_year(time);				//�� �¶�
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
	/*bit 0 - 1 ��λ��ʱ
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
		
		if(button_status_bit == N_key)   //�ް���
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
		
		if(button_status == S_key)   //�̰� �л����õĵ�λ
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
		else if(button_status == L_key)  //����
		{
			Set_Time_Dec(disp_time);
			break;
		}
		
		if(button_status_bit & (S_key<<2))  //���� ��  �̰�
		{
			disp_time[time_index]++; 
		}

		if(button_status_bit & (S_key<<4)) //���� ��  �̰�
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
		if(button_status_bit == N_key)   //�ް���
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
		
		if(button_status == S_key)   //�̰� �л����õĵ�λ
		{
			time_index++;
			if(time_index >= 3)
			{
				time_index = 0;
			}
		}
		else if(button_status == L_key)  //����
		{
			Set_Alarm_EveryDay(alarm + 1);
			Enable_Alarm(AlarmEnableFlag);
			break;
		}
		
		if(button_status_bit & (S_key<<2))  //���� ��  �̰�
		{
			alarm[time_index]++; 
		}

		if(button_status_bit & (S_key<<4)) //���� ��  �̰�
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
		if(button_status_bit == N_key)   //�ް���
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
		
		if(button_status == S_key)   //�̰� �л����õĵ�λ
		{
			func_index++;
			if(func_index >= 3)
			{
				func_index = 0;
			}
			display_set_mode(func_index + 3);
		}
		else if(button_status == L_key)  //����
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
		
		if(button_status_bit & (S_key<<2))  //���� ��  �̰�
		{
			temp_param[func_index]++; 
		}

		if(button_status_bit & (S_key<<4)) //���� ��  �̰�
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
	if(button_status_bit == N_key)   //�ް���
	{
		return ;
	}
	
	TimeoutColse = 60;
	button_status = button_status_bit & 0x03;
	
	if(button_status == S_key)   //���ܼ�  �̰�
	{
		if(SetModeFlag)	/*��������ģʽ*/
		{
			set_mode_index++;
			if(set_mode_index >= 3)
			{
				set_mode_index = 0;
			}
			display_set_mode(set_mode_index);		
		}
		else
		{	/*�л���ʾģʽ*/
			display_mode_index++;
			display_mode_index &= 0xfb;	
			display_mode(disp_time,display_mode_index & 0x03);
		}

	}
	else if(button_status == L_key)  //����
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
	if(button_status == S_key)  //�̰� ��������
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
	if(button_status == S_key) //���� ��  �̰�
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


/*2ms ����һ��*/
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
	
	TL0 = 0x30;		//���ö�ʱ��ֵ
	TH0 = 0xF8;		//���ö�ʱ��ֵ
	if(display_7seg_pwm & (0x01 << (i % 8)))
	{
		display_dynamic_buff();
	}
	else 
	{
		DisplayBitSelect(0xf0);
		DisplayOneLED(0x00);
		/*�ر���������*/
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
