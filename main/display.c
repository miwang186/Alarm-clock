#include "display.h"
#include "ds18b20.h"
#include <STC89C5xRC.H>
#include "i2c.h"

sbit HC595DIO_P = P3^7;
sbit HC595CS_P  = P3^6;
sbit HC595CLK_P = P3^5;

sbit HC595DIO_T = P1^7;
sbit HC595CS_T  = P1^6;
sbit HC595CLK_T = P1^5;

/*共阴数字段码 0123456789abcdef */
uint8_t code DispTabAnode[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07, 0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00};
/*共阳数字段码 0123456789abcdef */
uint8_t code DispTabCathode[]={0xc0,0xcf,0xa4,0x86,0x8b,0x92,0x90,0xc7,0x80,0x82,0x81,0x98,0xf0,0x8c,0xb0,0xb1,0xff};

/*
0 - 3 时间 共阴
4 - 6 温度 共阳
*/
uint8_t code display_palce[]={0x70,0xb0,0xd0,0xe0,0xf8,0xf4,0xf2,0xf0};

/*显示缓存 2ms 显示一个*/
uint8_t display_buff[8]={0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xff};

extern bit AlarmEnableFlag;
void Timer0Init(void)	//2毫秒@12.000MHz
{
	EA = 1;
	AUXR &= 0x7F;		//定时器时钟6T模式
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x30;		//设置定时初值
	TH0 = 0xF8;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	ET0 = 1;
	TR0 = 1;		//定时器0开始计时
}

void Timer1Init(void)		//10微秒@12.000MHz
{
	AUXR &= 0xBF;		//定时器时钟6T模式
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xEC;		//设置定时初值
	TH1 = 0xEC;		//设置定时重载值
	TF1 = 0;		//清除TF1标志
	ET1 = 1;
	TR1 = 1;		//定时器1开始计时
}

void DisplayBitSelect(uint8_t dat)
{
	uint8_t i;
	
	HC595CLK_P = 0;	
	HC595CS_P = 0;
	for(i = 0; i < 8; i++)
	{
		if(dat & 0x80)
		{
			HC595DIO_P = 1;
		}
		else 
		{
			HC595DIO_P = 0;
		}
		HC595CLK_P = 1;
		dat <<= 1;
		HC595CLK_P = 0;
	}
	HC595CS_P = 1;
	HC595CS_P = 0;
}

void DisplayOneLED(uint8_t dat)
{
	uint8_t i;
	
	HC595CLK_T = 0;	
	HC595CS_T = 0;
	for(i = 0; i < 8; i++)
	{
		if(dat & 0x80)
		{
			HC595DIO_T = 1;
		}
		else 
		{
			HC595DIO_T = 0;
		}
		HC595CLK_T = 1;
		dat <<= 1;
		HC595CLK_T = 0;
	}
	HC595CS_T = 1;
	HC595CS_T = 0;
}

void display_dynamic_buff()
{
	static uint8_t index = 0;
	
	DisplayBitSelect(0xf0);
	DisplayOneLED(display_buff[index]);
	DisplayBitSelect(display_palce[index]);	
	index ++;
	if(index >= 7)
	{
		index = 0;
	}
}

void display_temperature()
{
	int temperature;	
	temperature = DS18B20Read_Dat();	
	display_buff[6] = 0x33;/*摄氏度符号*/
	if(temperature >= 0) 
	{
		temperature = temperature*0.0625;
		//正温度	
		display_buff[4] = DispTabCathode[temperature/10%10];
		display_buff[5] = DispTabCathode[temperature%10];				
	}
	else
	{
		temperature =(~temperature+1)*0.0625;
		//负温度时，取反加1再乘以0.0625得实际温度，乘10+0.5显示小数点一位，且四舍五入
		if(temperature < 10)
		{
			display_buff[4] = 0xbf;
			display_buff[5] = DispTabCathode[temperature%10];	
		}
		else 
		{
			display_buff[4] = 0xbf;
			display_buff[5] = DispTabCathode[temperature/10%10];
			display_buff[6] = DispTabCathode[temperature%10];								
		}
	}	
}

void dispaly_year(uint8_t *time)
{
	display_buff[0] = DispTabAnode[2];
	display_buff[1] = DispTabAnode[0];
	display_buff[2] = DispTabAnode[time[6] / 10];
	display_buff[3] = DispTabAnode[time[6] % 10];
}

void display_month_day_week(uint8_t *time)
{
//	uint8_t time[3];/*星期 日 月*/
//	
//	RX8025ReadBytes(RX8025_ADDR_WEEK,&time,3);
	
	display_buff[0] = DispTabAnode[time[5] / 10];
	display_buff[1] = DispTabAnode[time[5] % 10] | 0x80;
	display_buff[2] = DispTabAnode[time[4] / 10];
	display_buff[3] = DispTabAnode[time[4] % 10];	
	
	display_buff[4] = DispTabCathode[16];	
	display_buff[5] = DispTabCathode[16];
	display_buff[6] = DispTabCathode[time[3] % 10];	
}

void display_hour_min_sec(uint8_t *time,bit is_sec)
{
//	uint8_t time[3];/*秒 分 时*/
//	
//	RX8025ReadBytes(RX8025_ADDR_SEC,&time,3);
	
	display_buff[0] = DispTabAnode[time[2] / 10];
	display_buff[1] = DispTabAnode[time[2] % 10];
	display_buff[2] = DispTabAnode[time[1] / 10];
	display_buff[3] = DispTabAnode[time[1] % 10]|((uint8_t)AlarmEnableFlag<<7);	
	if(is_sec)
	{
		display_buff[4] = DispTabCathode[16];	
		display_buff[5] = DispTabCathode[time[0] / 10];
		display_buff[6] = DispTabCathode[time[0] % 10];	
	}
}
void display_colse_tab(uint8_t index)
{
	uint8_t i;
	for(i = 0; i < 7; i++)
	{
		if(index & (0x01<<i))
		{
			if(i<4)
				display_buff[i] = DispTabAnode[16];
			else 
				display_buff[i] = DispTabCathode[16];
		}
	}
}
void display_set_mode(uint8_t index)
{
	switch (index)
	{
		case 0:		
			display_buff[4] = DispTabCathode[0x0c];	
			display_buff[5] = DispTabCathode[0x00];
			display_buff[6] = DispTabCathode[0x00];	
			break;
		case 1:
			display_buff[4] = DispTabCathode[0x0A];	
			display_buff[5] = DispTabCathode[0x00];
			display_buff[6] = DispTabCathode[0x00];	
			break;
		case 2:
		case 3:
		case 4:
		case 5:	
			display_buff[4] = DispTabCathode[0x0F];	
			display_buff[5] = DispTabCathode[0x00];
			display_buff[6] = DispTabCathode[index-2];				
			break;
		
		case 0xe0:
			display_buff[0] = DispTabAnode[16];
			display_buff[1] = DispTabAnode[16];
			display_buff[2] = DispTabAnode[16];
			display_buff[3] = DispTabAnode[16];
			display_buff[4] = DispTabCathode[0x0E];	
			display_buff[5] = DispTabCathode[0x00];
			display_buff[6] = DispTabCathode[0x00];				
			break;	
	}
}

void display_function_param(uint8_t dat)
{
	display_buff[0] = 0x40;
	display_buff[1] = DispTabAnode[dat / 10];
	display_buff[2] = DispTabAnode[dat % 10];
	display_buff[3] = 0x40;	
}

void display_alarm_clock(uint8_t *alarm)
{
	display_buff[0] = DispTabAnode[alarm[1] / 10];
	display_buff[1] = DispTabAnode[alarm[1] % 10];
	display_buff[2] = DispTabAnode[alarm[0] / 10];
	display_buff[3] = DispTabAnode[alarm[0] % 10];

	display_buff[4] = DispTabCathode[0x0a];		
	if(AlarmEnableFlag)
	{
		display_buff[5] = 0x9c;
		display_buff[6] = 0x9d;		
	}
	else
	{
		display_buff[5] = 0x9c;
		display_buff[6] = DispTabCathode[0x0f];				
	}
}

