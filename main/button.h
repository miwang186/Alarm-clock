#ifndef __BUTTON_H__
#define __BUTTON_H__
#include "STC89C5XRC.h"
#define N_key  0x00
#define S_key  0x01
#define D_key  0x02
#define L_key  0x03

sbit Button_SET	 	= P2^2;
sbit Button_PLUSE	= P2^3;
sbit Button_MINUS	= P2^4;

void button_scanning(void);
extern unsigned char button_status_bit;
#endif 