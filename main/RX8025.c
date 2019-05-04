//////////////////////////////////////////////////////
////////////时间日期芯片RX8025///////////////////////
////////////////////////////////////////////////////
#include "RX8025.h"
#include "intrins.h"

static unsigned char RX8025_State;
unsigned char gTime[RX8025_TIME_LENGTH];

void DelayUs(char i)
{
	do{
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	}while(i--);
}


void RX8025_IIC_Init(void)
{	
	RX8025_SCK_HIGH();
	RX8025_SDA_HIGH();
}

void RX8025_IIC_Start(void)
{
	RX8025_SCK_HIGH();
	RX8025_SDA_HIGH();

	RX8025_SDA_LOW();
	DelayUs(RX8025_SPEED);
	RX8025_SCK_LOW();
	DelayUs(RX8025_SPEED);
}


void RX8025_IIC_Stop(void)
{
	RX8025_SDA_LOW();
	DelayUs(RX8025_SPEED);
	RX8025_SCK_HIGH();	
	DelayUs(RX8025_SPEED);
	RX8025_SDA_HIGH();
	DelayUs(RX8025_SPEED);
}


void RX8025_IIC_WriteByte(unsigned char Data)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		if( (Data & 0x80) == 0x00 )
		{
			RX8025_SDA_LOW();
		}
		else
		{
			RX8025_SDA_HIGH();
		}
		RX8025_SCK_HIGH();
		DelayUs(RX8025_SPEED);
		RX8025_SCK_LOW();
		DelayUs(RX8025_SPEED);
		Data <<= 1;
	}
	
	RX8025_SCK_HIGH();//读取数据第九位-从机确认位
	DelayUs(RX8025_SPEED);

	i = RX8025_SDA_GET();	//检测是否有应答
	if( i!=0x00 )
	{
		RX8025_State = RX8025_STATE_NOACK;
	}
	else
	{
		RX8025_State = RX8025_STATE_ACK;
	}

	RX8025_SCK_LOW();
	DelayUs(RX8025_SPEED);
}



unsigned char RX8025_IIC_ReadByte(unsigned char ACK)
{
	unsigned char i,Data,temp;

	Data = 0x00;

	for(i=0;i<8;i++)
	{
		Data <<= 1;
		
		RX8025_SCK_HIGH();
		DelayUs(RX8025_SPEED);		
		temp = RX8025_SDA_GET();

		if(temp != 0 )
		{
			Data |= 0x01;
		}
		else
		{
		}
		RX8025_SCK_LOW();
		DelayUs(RX8025_SPEED);

	}
	//主机读数据时，需要根据工作状况发送ACK	
	if(ACK)	//发应答
	{
		RX8025_SDA_LOW();
	}
	else
	{
		RX8025_SDA_HIGH();		//不发应答
	}
	RX8025_SCK_HIGH();
	DelayUs(RX8025_SPEED);
	RX8025_SCK_LOW();
	DelayUs(RX8025_SPEED);

	return Data;
}



/*--------------------------------------------------------------------
函数名称：RX8025读日期时间
函数功能：
注意事项：无
提示说明：无
输 入：
返 回：无
--------------------------------------------------------------------*/
void RX8025_GetDateTime(unsigned char *timebuf)
{
	unsigned char i;
	uint8_t buf[RX8025_TIME_LENGTH];
	RX8025_IIC_Start();
	RX8025_IIC_WriteByte(RX8025_WR);
	RX8025_IIC_WriteByte(0x00);
	
	RX8025_IIC_Start();
	RX8025_IIC_WriteByte(RX8025_RD);
	for (i = 0;i < RX8025_TIME_LENGTH;i++)
	{
		buf[i] = RX8025_IIC_ReadByte(1);//接收后，单片机回复应答
	}
	RX8025_IIC_ReadByte(0);//接收后，单片机不回复应答
	RX8025_IIC_Stop();
	
	//buf[RX8025_ADDR_SEC] &= ~RX8025_CH;
	//buf[RX8025_ADDR_HOUR] &= ~RX8025_24H;
	
	for (i=0;i<RX8025_TIME_LENGTH;i++)
	{
		timebuf[i] = buf[i];
	}
}


/*--------------------------------------------------------------------
函数名称：DS1302设置日期时间
函数功能：
注意事项：无
提示说明：无
输 入：
返 回：无
--------------------------------------------------------------------*/
void RX8025_SetDateTime(unsigned char *timebuf)
{
	unsigned char i;

	RX8025_IIC_Start();
	RX8025_IIC_WriteByte(RX8025_WR);
	RX8025_IIC_WriteByte(0x00);
	for (i=0x00;i<RX8025_TIME_LENGTH;i++)
	{
		RX8025_IIC_WriteByte(timebuf[i]);//接收后，单片机回复应答
	}
	RX8025_IIC_Stop();
}





/*--------------------------------------------------------------------
函数名称：RX8025初始化
函数功能：
注意事项：无
提示说明：无
输 入：无
返 回：无
--------------------------------------------------------------------*/
void RX8025_Init(void)
{
		
	RX8025_IIC_Init();
	
	RX8025_IIC_Start();
	RX8025_IIC_WriteByte(RX8025_WR);
	RX8025_IIC_WriteByte(RX8025_ADDR_CTOL1);	
	RX8025_IIC_WriteByte(0x60);	
	RX8025_IIC_Stop();
}



