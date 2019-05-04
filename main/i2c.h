#ifndef _I2C_H_
#define _I2C_H_
#include <string.h>

#define RX8025_ADDR_SEC		0
#define RX8025_ADDR_MIN		1
#define RX8025_ADDR_HOUR	2
#define RX8025_ADDR_WEEK	3
#define RX8025_ADDR_DATE	4
#define RX8025_ADDR_MON		5
#define RX8025_ADDR_YEAR	6
#define RX8025_ADDR_CTRL	7
#define RX8025_ADDR_RAM		8
#define RX8025_ADDR_CTOL1	0x0e

bit Get_Alarm_Status();
void Enable_Alarm(bit p);
void Set_Alarm_EveryDay(unsigned char *alarm_time);
void Get_Alarm_EveryDay(unsigned char *alarm_time);
void Get_Time_Dec(unsigned char *time);
void Set_Time_Dec(unsigned char *time_dec);	
unsigned char RX8025ReadBytes(unsigned char addr,unsigned char *time, unsigned char num);
unsigned char RX8025WriteBytes(unsigned char addr,unsigned char *time, unsigned char num);

bit Recovery_Default_Setting();
bit Get_Init_RX8025_Flag();
#endif