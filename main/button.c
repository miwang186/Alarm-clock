#include "button.h"
#include "STC89C5XRC.h"
#include <intrins.h>

typedef unsigned char uint8_t;
typedef unsigned int  uint16_t;



/*
bit 0-1 00 无按键 01 短按 10双击 11长按 
bit 2-3	加
bit 4-5 减
bit 6  保留
bit 7  
*/
uint8_t button_status_bit = 0;

/*
20ms 扫描一次
*/
void button_scanning()
{
	static uint8_t key_buf[3] = {0xff,0xff,0xff};
	static uint8_t button_out_backup = 0,keep_time = 0;
	uint8_t i,button_out = 0;

	key_buf[0] = (key_buf[0]<<1)|Button_SET;
	key_buf[1] = (key_buf[1]<<1)|Button_PLUSE;
	key_buf[2] = (key_buf[2]<<1)|Button_MINUS;
	
	for(i = 0; i < 3; i++)
	{
		if((key_buf[i] & 0x0f) == 0x00)
		{
			button_out &= ~(0x03 << (i*2));
			button_out |= (S_key << (i*2)); 
		}
		else 
		{
			button_out &= ~(0x03 << (i*2));			
		}
	}

	if(button_out_backup != button_out)
	{
		if(button_out_backup != 0)
		{
			button_status_bit = button_out_backup;			
//			if((free_time & 0x80) && ((free_time & 0x7f) < 25))
//			{
//				for(i = 0; i < 3; i++)
//				{
//					if(button_out_backup & (S_key << (i*2)))
//					{
//						button_status_bit &= ~(0x03 << (i*2));
//						button_status_bit |= (D_key << (i*2));
//					}					
//				}
//			}
//			free_time = 0x80;
		}
		button_out_backup = button_out;
	}
	else if(button_out_backup != 0)
	{
		if(keep_time >= 25)
		{
			for(i = 0; i < 3; i++)
			{
				if(button_out_backup & (S_key << (i*2)))
				{
					button_status_bit &= ~(0x03 << (i*2));
					button_status_bit |= (L_key << (i*2));
				}					
			}
			keep_time = 23;
		}
		keep_time++;
	}
	else 
	{
//		if(free_time & 0x80)
//		{
//			free_time ++;
//			if(free_time > (25+0x80))
//			{
//				free_time = 0;
//			}
//		}
		keep_time = 0;
	}
}