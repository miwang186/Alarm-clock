#include "ds18b20.h"

sbit DS18B20_DQ=P0^2;
void Delay10us(unsigned char us)
{
	unsigned char i=0;
	do{
		i = 4;
		while(--i);
	}while(--us);
}
void DS18B20Init()
{
	DS18B20_DQ=1;
	DS18B20_DQ=0;
	Delay10us(50);
	DS18B20_DQ=1;
	Delay10us(7);
	while(!DS18B20_DQ);		
}
void DS18B20WriteByte(unsigned char dat)
{
	unsigned char i;
	EA=0;
	for(i=0;i<8;i++)
	{
		DS18B20_DQ=0;
		DS18B20_DQ=dat&0x01;
		Delay10us(6);
		DS18B20_DQ=1;
		dat>>=1;
	}
	EA=1;
}
unsigned char DS18B20ReadByte()
{
	unsigned char i,dat=0x00;
	EA=0;
	for(i=0;i<8;i++)
	{
		DS18B20_DQ=0;
		dat>>=1;
		DS18B20_DQ=1;
		Delay10us(2);
		if(DS18B20_DQ)
			dat|=0x80;		
		Delay10us(4);
	}
	EA=1;
	return dat;
}

int DS18B20Read_Dat()
{
	static int temp;
	unsigned char High,Low;
	static bit read_flag = 0;
	
	DS18B20Init();
	DS18B20WriteByte(0xcc);
	
	if(!read_flag)
	{
		DS18B20WriteByte(0x44);		
	}
	else
	{
		DS18B20WriteByte(0xbe);
		Low=DS18B20ReadByte();
		High=DS18B20ReadByte();	
		
		temp = High <<8;
		temp |= Low;
	}
	read_flag = ~read_flag;
	return temp;
}