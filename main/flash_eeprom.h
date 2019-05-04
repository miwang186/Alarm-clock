#ifndef __FLASH_EEPROM_H_
#define __FLASH_EEPROM_H_
#include "STC89C5XRC.h"
//Start address for STC89C52xx EEPROM
#define IAP_ADDRESS 0x02000

typedef struct parameter
{
	unsigned char timeout_colse;
	unsigned char disp_mode;
	unsigned char led_cloor;
	unsigned char led_rate;
	unsigned char led_pwm[3];
	unsigned char reserve;
}Parameter_data;


unsigned char IapReadByte(unsigned int addr);
void IapProgramByte(unsigned int addr, unsigned char dat);
void IapEraseSector(unsigned int addr);

#endif 

