
#line 1 "..\main\display.c" /0
  
#line 1 "..\MAIN\DISPLAY.H" /0
 
 
  
#line 1 "D:\PROGRAM FILES\KEIL_V5\C51\INC\STC\STC89C5XRC.H" /0
 
 
 
 
 
 
 
 
 
 
 
 sfr  P4  = 0xe8;
 sbit P46 = P4^6;
 sbit P45 = P4^5;        
 sbit P44 = P4^4;
 sbit P43 = P4^3;
 sbit P42 = P4^2;
 sbit P41 = P4^1;
 sbit P40 = P4^0;
 
 sfr  XICON = 0xc0;
 
 sfr  WDT_CONTR = 0xe1;
 
 sfr ISP_DATA  = 0xe2;
 sfr ISP_ADDRH = 0xe3;
 sfr ISP_ADDRL = 0xe4;
 sfr ISP_CMD   = 0xe5;
 sfr ISP_TRIG  = 0xe6;
 sfr ISP_CONTR = 0xe7;
 
 
 









 
 
 
 sfr P0   = 0x80;
 sbit P00 = P0^0;
 sbit P01 = P0^1;
 sbit P02 = P0^2;
 sbit P03 = P0^3;
 sbit P04 = P0^4;
 sbit P05 = P0^5;
 sbit P06 = P0^6;
 sbit P07 = P0^7;
 sfr P1   = 0x90;
 sbit P10 = P1^0;
 sbit P11 = P1^1;
 sbit P12 = P1^2;
 sbit P13 = P1^3;
 sbit P14 = P1^4;
 sbit P15 = P1^5;
 sbit P16 = P1^6;
 sbit P17 = P1^7;
 sfr P2   = 0xA0;
 sbit P20 = P2^0;
 sbit P21 = P2^1;
 sbit P22 = P2^2;
 sbit P23 = P2^3;
 sbit P24 = P2^4;
 sbit P25 = P2^5;
 sbit P26 = P2^6;
 sbit P27 = P2^7;
 sfr P3   = 0xB0;
 sbit P30 = P3^0;
 sbit P31 = P3^1;
 sbit P32 = P3^2;
 sbit P33 = P3^3;
 sbit P34 = P3^4;
 sbit P35 = P3^5;
 sbit P36 = P3^6;
 sbit P37 = P3^7;
 sfr PSW  = 0xD0;
 sfr ACC  = 0xE0;
 sfr B    = 0xF0;
 sfr SP   = 0x81;
 sfr DPL  = 0x82;
 sfr DPH  = 0x83;
 sfr PCON = 0x87;
 sfr TCON = 0x88;
 sfr TMOD = 0x89;
 sfr TL0  = 0x8A;
 sfr TL1  = 0x8B;
 sfr TH0  = 0x8C;
 sfr TH1  = 0x8D;
 sfr IE   = 0xA8;
 sfr IP   = 0xB8;
 sfr SCON = 0x98;
 sfr SBUF = 0x99;
 
 
 sfr AUXR   = 0x8E;
 sfr AUXR1  = 0xA2;
 sfr SADDR  = 0xA9;
 sfr IPH    = 0xB7;
 sfr SADEN  = 0xB9;
 sfr T2CON  = 0xC8;
 sfr T2MOD  = 0xC9;
 sfr RCAP2L = 0xCA;
 sfr RCAP2H = 0xCB;
 sfr TL2    = 0xCC;
 sfr TH2    = 0xCD;
 




















 
 
 
 
 sbit CY   = PSW^7;
 sbit AC   = PSW^6;
 sbit F0   = PSW^5;
 sbit RS1  = PSW^4;
 sbit RS0  = PSW^3;
 sbit OV   = PSW^2;
 sbit P    = PSW^0;
 
 
 sbit TF1  = TCON^7;
 sbit TR1  = TCON^6;
 sbit TF0  = TCON^5;
 sbit TR0  = TCON^4;
 sbit IE1  = TCON^3;
 sbit IT1  = TCON^2;
 sbit IE0  = TCON^1;
 sbit IT0  = TCON^0;
 
 
 sbit EA   = IE^7;
 sbit EC   = IE^6;
 sbit ET2  = IE^5;
 sbit ES   = IE^4;
 sbit ET1  = IE^3;
 sbit EX1  = IE^2;
 sbit ET0  = IE^1;
 sbit EX0  = IE^0;
 
 
 
 sbit PT2  = IP^5;
 sbit PS   = IP^4;
 sbit PT1  = IP^3;
 sbit PX1  = IP^2;
 sbit PT0  = IP^1;
 sbit PX0  = IP^0;
 
 
 sbit RD   = P3^7;
 sbit WR   = P3^6;
 sbit T1   = P3^5;
 sbit T0   = P3^4;
 sbit INT1 = P3^3;
 sbit INT0 = P3^2;
 sbit TXD  = P3^1;
 sbit RXD  = P3^0;
 
 
 sbit SM0  = SCON^7;  
 sbit FE   = SCON^7;
 sbit SM1  = SCON^6;
 sbit SM2  = SCON^5;
 sbit REN  = SCON^4;
 sbit TB8  = SCON^3;
 sbit RB8  = SCON^2;
 sbit TI   = SCON^1;
 sbit RI   = SCON^0;
 
 







 
 
 sbit T2EX = P1^1;
 sbit T2   = P1^0;
 
 
 sbit TF2   = T2CON^7;
 sbit EXF2  = T2CON^6;
 sbit RCLK  = T2CON^5;
 sbit TCLK  = T2CON^4;
 sbit EXEN2 = T2CON^3;
 sbit TR2   = T2CON^2;
 sbit C_T2  = T2CON^1;
 sbit CP_RL2= T2CON^0;
 
 









 
 
 
 
 
 
#line 3 "..\MAIN\DISPLAY.H" /0
 
 
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
 
#line 1 "..\main\display.c" /0
 
  
#line 1 "..\MAIN\DS18B20.H" /0
 
 
  
#line 1 "D:\PROGRAM FILES\KEIL_V5\C51\INC\STC\STC89C5XRC.H" /0
 
#line 2 "D:\PROGRAM FILES\KEIL_V5\C51\INC\STC\STC89C5XRC.H" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 









 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 




















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 







 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 









 
 
 
 
 
#line 233 "D:\PROGRAM FILES\KEIL_V5\C51\INC\STC\STC89C5XRC.H" /0
 
#line 3 "..\MAIN\DS18B20.H" /0
 
 int DS18B20Read_Dat(void);
 
#line 2 "..\main\display.c" /0
 
  
#line 1 "D:\PROGRAM FILES\KEIL_V5\C51\INC\STC\STC89C5XRC.H" /0
 
#line 2 "D:\PROGRAM FILES\KEIL_V5\C51\INC\STC\STC89C5XRC.H" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 









 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 




















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 







 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 









 
 
 
 
 
#line 233 "D:\PROGRAM FILES\KEIL_V5\C51\INC\STC\STC89C5XRC.H" /0
 
#line 3 "..\main\display.c" /0
 
  
#line 1 "..\MAIN\I2C.H" /0
 
 
  
#line 1 "D:\PROGRAM FILES\KEIL_V5\C51\INC\STRING.H" /0






 
 
 
 
 
 
 
 typedef unsigned int size_t;
 
 
 
 
 
 
 #pragma SAVE
 #pragma REGPARMS
 extern char *strcat (char *s1, char *s2);
 extern char *strncat (char *s1, char *s2, int n);
 
 extern char strcmp (char *s1, char *s2);
 extern char strncmp (char *s1, char *s2, int n);
 
 extern char *strcpy (char *s1, char *s2);
 extern char *strncpy (char *s1, char *s2, int n);
 
 extern int strlen (char *);
 
 extern char *strchr (const char *s, char c);
 extern int strpos (const char *s, char c);
 extern char *strrchr (const char *s, char c);
 extern int strrpos (const char *s, char c);
 
 extern int strspn (char *s, char *set);
 extern int strcspn (char *s, char *set);
 extern char *strpbrk (char *s, char *set);
 extern char *strrpbrk (char *s, char *set);
 extern char *strstr  (char *s, char *sub);
 extern char *strtok  (char *str, const char *set);
 
 extern char memcmp (void *s1, void *s2, int n);
 extern void *memcpy (void *s1, void *s2, int n);
 extern void *memchr (void *s, char val, int n);
 extern void *memccpy (void *s1, void *s2, char val, int n);
 extern void *memmove (void *s1, void *s2, int n);
 extern void *memset  (void *s, char val, int n);
 #pragma RESTORE
 
 
#line 3 "..\MAIN\I2C.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
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
 
#line 4 "..\main\display.c" /0
 
 
 sbit HC595DIO_P = P3^7;
 sbit HC595CS_P  = P3^6;
 sbit HC595CLK_P = P3^5;
 
 sbit HC595DIO_T = P1^7;
 sbit HC595CS_T  = P1^6;
 sbit HC595CLK_T = P1^5;
 
 
 uint8_t code DispTabAnode[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07, 0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00};
 
 uint8_t code DispTabCathode[]={0xc0,0xcf,0xa4,0x86,0x8b,0x92,0x90,0xc7,0x80,0x82,0x81,0x98,0xf0,0x8c,0xb0,0xb1,0xff};
 



 
 uint8_t code display_palce[]={0x70,0xb0,0xd0,0xe0,0xf8,0xf4,0xf2,0xf0};
 
 
 uint8_t display_buff[8]={0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xff};
 
 extern bit AlarmEnableFlag;
 void Timer0Init(void)	 
 {
 EA = 1;
 AUXR &= 0x7F;		 
 TMOD &= 0xF0;		 
 TMOD |= 0x01;		 
 TL0 = 0x30;		 
 TH0 = 0xF8;		 
 TF0 = 0;		 
 ET0 = 1;
 TR0 = 1;		 
 }
 
 void Timer1Init(void)		 
 {
 AUXR &= 0xBF;		 
 TMOD &= 0x0F;		 
 TMOD |= 0x20;		 
 TL1 = 0xEC;		 
 TH1 = 0xEC;		 
 TF1 = 0;		 
 ET1 = 1;
 TR1 = 1;		 
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
 display_buff[6] = 0x33; 
 if(temperature >= 0) 
 {
 temperature = temperature*0.0625;
 
 display_buff[4] = DispTabCathode[temperature/10%10];
 display_buff[5] = DispTabCathode[temperature%10];				
 }
 else
 {
 temperature =(~temperature+1)*0.0625;
 
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
 
