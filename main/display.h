#ifndef __DISPLAY_H__
#define __DISPLAY_H__
#include "STC89C5XRC.h"

typedef unsigned char uint8_t;
typedef unsigned int  uint16_t;

sbit LED_RED_O   = P0^5;
sbit LED_GREEN_O = P0^6;
sbit LED_BLUE_O  = P0^7;

sbit COLON_PIN	= P3^4;
void display_set_mode(uint8_t index);
void display_temperature(void);
void display_dynamic_buff(void);
void DisplayOneLED(uint8_t dat);
void DisplayBitSelect(uint8_t dat);
void Timer1Init(void);
void Timer0Init(void);
void display_hour_min_sec(uint8_t *time,bit is_sec);
void display_month_day_week(uint8_t *time);
void dispaly_year(uint8_t *time);
void display_alarm_clock(uint8_t *alarm);
void display_colse_tab(uint8_t index);
void display_function_param(uint8_t dat);
#endif
