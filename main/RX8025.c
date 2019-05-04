//////////////////////////////////////////////////////
////////////ʱ������оƬRX8025///////////////////////
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
	
	RX8025_SCK_HIGH();//��ȡ���ݵھ�λ-�ӻ�ȷ��λ
	DelayUs(RX8025_SPEED);

	i = RX8025_SDA_GET();	//����Ƿ���Ӧ��
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
	//����������ʱ����Ҫ���ݹ���״������ACK	
	if(ACK)	//��Ӧ��
	{
		RX8025_SDA_LOW();
	}
	else
	{
		RX8025_SDA_HIGH();		//����Ӧ��
	}
	RX8025_SCK_HIGH();
	DelayUs(RX8025_SPEED);
	RX8025_SCK_LOW();
	DelayUs(RX8025_SPEED);

	return Data;
}



/*--------------------------------------------------------------------
�������ƣ�RX8025������ʱ��
�������ܣ�
ע�������
��ʾ˵������
�� �룺
�� �أ���
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
		buf[i] = RX8025_IIC_ReadByte(1);//���պ󣬵�Ƭ���ظ�Ӧ��
	}
	RX8025_IIC_ReadByte(0);//���պ󣬵�Ƭ�����ظ�Ӧ��
	RX8025_IIC_Stop();
	
	//buf[RX8025_ADDR_SEC] &= ~RX8025_CH;
	//buf[RX8025_ADDR_HOUR] &= ~RX8025_24H;
	
	for (i=0;i<RX8025_TIME_LENGTH;i++)
	{
		timebuf[i] = buf[i];
	}
}


/*--------------------------------------------------------------------
�������ƣ�DS1302��������ʱ��
�������ܣ�
ע�������
��ʾ˵������
�� �룺
�� �أ���
--------------------------------------------------------------------*/
void RX8025_SetDateTime(unsigned char *timebuf)
{
	unsigned char i;

	RX8025_IIC_Start();
	RX8025_IIC_WriteByte(RX8025_WR);
	RX8025_IIC_WriteByte(0x00);
	for (i=0x00;i<RX8025_TIME_LENGTH;i++)
	{
		RX8025_IIC_WriteByte(timebuf[i]);//���պ󣬵�Ƭ���ظ�Ӧ��
	}
	RX8025_IIC_Stop();
}





/*--------------------------------------------------------------------
�������ƣ�RX8025��ʼ��
�������ܣ�
ע�������
��ʾ˵������
�� �룺��
�� �أ���
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



