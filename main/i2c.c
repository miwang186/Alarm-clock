#include "STC89C5XRC.h"
#include <intrins.h>
#include "i2c.h"

sbit  SCL=P0^0;
sbit  SDA=P0^1;
///************************************
//** ����ԭ��: void IC_start(void); **
//** �� ��: IC ������ʼλ. **
//************************************/
static void IC_start(void)
{
	SCL=1; /** Send Start **/
	SDA=1;
	_nop_();
	_nop_();
	SDA=0;
	_nop_();
	_nop_();
	SCL=0;
}
////**********************************
////** ����ԭ��: void IC_stop(void); **
////** �� ��: IC ����ֹͣλ. **
////**********************************/
static void IC_stop(void)
{
	SCL=0; /** Send Stop **/
	SDA=0;
	_nop_();
	_nop_();
	SCL=1;
	_nop_();
	_nop_();
	SDA=1;
}
/////***************************************************
////** ����ԭ��: bit IC_writebyte(uchar wdata); **
////** �� ��: �� IC ���߷��� 8 λ����,������һ��Ӧ���� **
////** �� ACK.����յ� ACK Ӧ���򷵻� 1(TRUE), **
////** ���򷵻� 0(FALSE). **
////***************************************************/
static unsigned char IC_WriteByte( unsigned char wdata)
{
	unsigned char i;
	for(i=0; i<8; i++)
	{
		SCL=0;
		SCL=0;
		_nop_();
		_nop_();
		if(wdata&0x80) SDA=1;
		else SDA=0;
		_nop_();
		_nop_();
		SCL=1;
		wdata<<=1;
	}
	SCL=0;
	SCL=0;
	_nop_();
	_nop_();
	SCL=1;
	i=0;
	while(SDA)
	{
		if(++i>12)
		{
			SCL=0;
			return(0);
		}
	}
	SCL=0;
	return(1);
}
/////***********************************************
////** ����ԭ��: uchar IC_readbyte(void); **
////** �� ��: �� IC �����Ͻ��� 8 λ����,�������ܵ� **
////** 8 λ������Ϊһ���ֽڷ���,������Ӧ **
////** ���ź� ACK. **
////***********************************************/
static unsigned char IC_ReadByte(void)
{
	unsigned char i;
	unsigned char IC_data=0;
	SCL=0;
	SDA=1;
	for(i=0; i<8; i++)
	{
		SCL=1;
		SCL=1;
		_nop_();
		_nop_();
		IC_data<<=1;
		IC_data|=SDA;
		_nop_();
		SCL=1;
		_nop_();
		SCL=0;
		_nop_();
	}
	_nop_();
	_nop_();
	_nop_();
	SCL=0;
	SDA=0;
	return(IC_data);
}
/////***************************************************************
////** ����ԭ��: bit readEEone(uchar instr,uchar addr,uchar num); **
////** �� ��: �� S42WD42 �ж�ȡ num ���ֽڵ�����,�������ж������� **
////** ʽ��Ƭ�� Address ��ַ��ʼ������ȡ����.S42WD42 ���� **
////** ��ָ���ĵ�ַ�򷵻� 0(FALSE). **
////***************************************************************/
unsigned char RX8025ReadBytes(unsigned char addr,unsigned char *time, unsigned char num)
{
	unsigned char i;
	IC_start();
	if(IC_WriteByte(0x64)==0)
	{
		IC_stop();
		return(0);
	}
	if(IC_WriteByte(addr)==0)
	{
		IC_stop();
		return(0);
	}
	IC_start();
	if(IC_WriteByte(0x65)==0)
	{
		IC_stop();
		return(0);
	}
	for(i=0; i<num-1; i++)
	{
		time[i]=IC_ReadByte();
		SDA=0; /** Send ACK **/
		SDA=0;
		SCL=1;
	}
	time[num-1] = IC_ReadByte();
	SDA=1; /** Send Read End **/
	SDA=1;
	_nop_();
	SCL=1;
	IC_stop();
	return(1);
}
///****************************************************************
//** ����ԭ��: bit writeEEone(uchar instr,uchar addr,uchar num); **
//** �� ��: �� EEbuf[]��Ԫ�е�����д�� S42WD42 �� num ���ֽ�. **
//** ����ҳд������ʽ,ÿ��д��ʱ����Ҫָ��Ƭ�ڵ�ַ. **
//** ��� S42WD42 ������ָ���ĵ�ַ��ĳ�����͵��ֽ�δ�յ� **
//** Ӧ���ź� ACK,�򷵻� 0(FALSE). **
//****************************************************************/
unsigned char RX8025WriteBytes(unsigned char addr,unsigned char *time, unsigned char num)
{
	unsigned char i;
	IC_start();
	if(IC_WriteByte(0x64)==0)
	{
		IC_stop();
		return(0);
	}
	if(IC_WriteByte(addr)==0)
	{
		IC_stop();
		return(0);
	}
	for(i=0; i<num; i++)
	{
		if(IC_WriteByte(time[i])==0)
		{
			IC_stop();
			return(0);
		}
	}
	IC_stop();
	_nop_();
	_nop_();
	SDA=0;
	SCL=0;
	return(1);
}
static void dec_to_hex(unsigned char *dec,unsigned char *hex,unsigned char len)
{
	unsigned char i;	
	for(i = 0; i < len; i++)
	{
		hex[i] = ((dec[i] / 10) << 4) + dec[i] % 10;
	}
}
static void hex_to_dec(unsigned char *dec,unsigned char *hex,unsigned char len)
{
	unsigned char i;	
	for(i = 0; i < len; i++)
	{
		dec[i] = (hex[i] & 0x0f) + ((hex[i] >> 4) * 10);
	}
}
unsigned char bit_to_dec_week(unsigned char dat)
{
	unsigned char i;
	for(i = 0; i < 7; i++)
	{
		if(dat & (0x01<<i))
		{
			return i;
		}
	}
	return 0;
}

void Get_Time_Dec(unsigned char *time)
{
	unsigned char time_hex[7] = {0};
	RX8025ReadBytes(0,time_hex,7);
	hex_to_dec(time,time_hex,7);
	time[3] = bit_to_dec_week(time_hex[3]);
}

void Set_Time_Dec(unsigned char *time_dec)
{
	unsigned char time_hex[7] = {0};
	dec_to_hex(time_dec,time_hex,7);
	time_hex[3] = 0x01 << time_dec[3];
	RX8025WriteBytes(0,time_hex,7);
}

void Get_Alarm_EveryDay(unsigned char *alarm_time)
{
	unsigned char time_hex[2] = {0};
	RX8025ReadBytes(0x08,time_hex,2);
	hex_to_dec(alarm_time,time_hex,2);
}

void Set_Alarm_EveryDay(unsigned char *alarm_time)
{
	unsigned char time_hex[2] = {0};
	dec_to_hex(alarm_time,time_hex,2);	
	RX8025WriteBytes(0x08,time_hex,2);
	RX8025WriteBytes(0x0a,0x80,1);
}

void Enable_Alarm(bit p)
{
	unsigned char dat = 0,clean = 0;
	if(p)
	{
		dat = 0x08;
		RX8025WriteBytes(0x0e,&clean,1);
	}	
	RX8025WriteBytes(0x0f,&dat,1);
}


bit Recovery_Default_Setting()
{
	unsigned char dat[16] = {0};
	
	memset(dat, 0, 16);
	if(!RX8025WriteBytes(0,dat,16))
	{
		return 0;
	}
	
//	para_dat.timeout_colse = 5;
//	para_dat.disp_mode = 0;
//	para_dat.led_cloor = 0x40;
//	para_dat.led_rate = 2;
//	para_dat.led_pwm[0] = 0;
//	para_dat.led_pwm[0] = 0;
//	para_dat.led_pwm[0] = 0;
//	para_dat.reserve = 0xaa;
//	
//	IapEraseSector(IAP_ADDRESS);
//	Delay50ms();
//	memcpy(dat, &para_dat, sizeof(Parameter_data));
//	
//	for (i=0; i<sizeof(Parameter_data); i++)           //Check whether all sector data is FF
//    {
//        IapProgramByte(IAP_ADDRESS + i,dat[i]);
//    }
//	Delay50ms();
//	memset(dat, 0, 16);	
//	for (i=0; i<sizeof(Parameter_data); i++)           //Check whether all sector data is FF
//    {
//        dat[i] = IapReadByte(IAP_ADDRESS + i);
//    }
//	Delay50ms();
//	if(memcmp(dat, &para_dat, 8) != 0);
//	{
//		return 0;
//	}

	return 1;
}
bit Get_Init_RX8025_Flag()
{
	unsigned char dat;	
	RX8025ReadBytes(0x0e,&dat,1);	
	if(dat & 0x02)
	{
		return 0;
	}
	else 
	{
		return 1;
	}	
}
bit Get_Alarm_Status()
{
	unsigned char dat;	
	RX8025ReadBytes(0x0f,&dat,1);	
	if(dat & 0x08)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}