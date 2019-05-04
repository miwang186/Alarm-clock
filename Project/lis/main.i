
#line 1 "..\main\main.c" /0
  
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
 
#line 1 "..\main\main.c" /0
 
  
#line 1 "D:\PROGRAM FILES\KEIL_V5\C51\INC\INTRINS.H" /0






 
 
 
 
 
 extern void          _nop_     (void);
 extern bit           _testbit_ (bit);
 extern unsigned char _cror_    (unsigned char, unsigned char);
 extern unsigned int  _iror_    (unsigned int,  unsigned char);
 extern unsigned long _lror_    (unsigned long, unsigned char);
 extern unsigned char _crol_    (unsigned char, unsigned char);
 extern unsigned int  _irol_    (unsigned int,  unsigned char);
 extern unsigned long _lrol_    (unsigned long, unsigned char);
 extern unsigned char _chkfloat_(float);
 
 extern void          _push_    (unsigned char _sfr);
 extern void          _pop_     (unsigned char _sfr);
 
 
 
 
#line 2 "..\main\main.c" /0
 
  
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
 
#line 3 "..\main\main.c" /0
 
  
#line 1 "..\MAIN\BUTTON.H" /0
 
 
  
#line 1 "D:\PROGRAM FILES\KEIL_V5\C51\INC\STC\STC89C5XRC.H" /0
 
#line 2 "D:\PROGRAM FILES\KEIL_V5\C51\INC\STC\STC89C5XRC.H" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 









 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 




















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 







 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 









 
 
 
 
 
#line 233 "D:\PROGRAM FILES\KEIL_V5\C51\INC\STC\STC89C5XRC.H" /0
 
#line 3 "..\MAIN\BUTTON.H" /0
 
 
 
 
 
 
 sbit Button_SET	 	= P2^2;
 sbit Button_PLUSE	= P2^3;
 sbit Button_MINUS	= P2^4;
 
 void button_scanning(void);
 extern unsigned char button_status_bit;
 
#line 4 "..\main\main.c" /0
 
 
 
 
 uint8_t code code_7seg_pwm[] = {0xff,0x7f,0x77,0x5d,0x55,0x52,0x11,0x01};
 
 uint8_t polling_display_timing = 2;
 
 uint8_t TimeoutColse = 60;			 



 
 uint8_t TimeoutColseMAX = 5;		 





 
 uint8_t display_mode_index = 0; 	 
 uint8_t display_7seg_pwm = 0xff;
 uint8_t display_7seg_pwm_index = 0;
 uint8_t disp_time[7];






 
 uint8_t led_cloor_index = 0x40;    	 
 uint8_t breathing_rate = 4;			 
 
 uint8_t RGB_ratio[3] = {0}; 
 


 
 uint8_t main_key_timing = 0;




 
 uint8_t twink_index = 0;
 
 bit TimeFlag1s 		= 1;
 bit StartRunFlag 	= 1;
 bit DotDispFlag 	= 1;
 bit AlarmEnableFlag = 0;
 bit SetModeFlag 	= 0;	 
 bit SetTwinkleFlag  = 0;	 
 
 void close_all_low_power()
 {
 
 ET0 = 0;
 ET1 = 0;			
 TR0 = 0;
 TR1 = 0;
 
 
 SetModeFlag = 0;
 
 main_key_timing = 0;
 
 P0 |= 0xe0; 
 
 DisplayBitSelect(0x00);
 DisplayOneLED(0x00);
 
 COLON_PIN = 1;
 INT0 = 1;                    
 INT1 = 1; 
 while (!INT0 && !INT1);               
 _nop_();
 _nop_();
 PCON = 0x02;                 
 _nop_();
 _nop_();	
 }
 
 void init_system_io()
 {
 Timer0Init();
 Timer1Init();
 
 IT0 = 1;                         
 EX0 = 1;                         
 
 IT1 = 1;
 EX1 = 1;
 
 EA = 1;                          
 P0 |= 0xe0;	
 }
 
 void rgbled_gradient_breathing()
 {
 
 uint8_t code on_num[16] ={0x80,0x40,0x20,0xa0,0x60,0xc0,0xe0,0x60,0xa0,0x80,0x20,0xc0,0xa0,0x40,0x80,0xe0};


 
 static uint8_t RGB_dir = 0xe0;
 uint8_t i;
 
 for(i = 0; i < 3; i++)
 {
 if(on_num[led_cloor_index & 0x0f] & (0x80>>i))
 {
 if(RGB_ratio[i] == 200 && (RGB_dir & (0x80>>i)) != 0)	
 {
 RGB_dir &= (~(0x80>>i));
 }
 else if(RGB_ratio[i] == 0  && (RGB_dir & (0x80>>i)) == 0)
 {
 
 led_cloor_index ++;
 led_cloor_index &= 0xef;
 
 
 RGB_dir |= (0x80>>i);
 }
 
 if(RGB_dir & (0x80>>i))
 {
 RGB_ratio[i]++;
 }
 else 
 {
 RGB_ratio[i]--;
 }
 }
 }
 }
 
 void display_mode(uint8_t *time,uint8_t index)
 {
 switch(index)
 {
 case 0:
 display_hour_min_sec(time,0);   
 display_temperature();
 DotDispFlag = 1;
 break;
 
 case 1:
 display_hour_min_sec(time,1);    
 DotDispFlag = 1;
 break;
 
 case 2:
 display_month_day_week(time);	 
 DotDispFlag = 0;
 break;
 
 case 3:
 dispaly_year(time);				 
 if(!SetModeFlag)
 {
 display_temperature();	
 }
 else
 {
 display_set_mode(0);
 }
 DotDispFlag = 0;
 break;
 
 default:
 DotDispFlag = 1;				
 display_hour_min_sec(time,0);
 display_temperature();				
 break;	
 }
 }
 
 bit polling_display_mode()
 {


 
 static uint8_t index = 0;
 uint8_t temp;
 bit status = 0;
 
 if(index != 0)
 {
 index++;
 
 if((index & 0x03) < polling_display_timing)
 {
 return 1;
 }
 }
 
 temp = index>>3;
 do{
 
 temp++;
 if(temp >= 5)
 {
 temp = 0;
 index = 0;
 return 0;
 }
 
 if(display_mode_index & (0x80>>temp))
 {
 display_mode_index &= ~0x03;				
 display_mode_index |= (4 - temp);
 status = 1;
 }
 
 }while(!status);
 index = temp << 3;
 
 return status;
 }
 
 bit timeout_no_operation_quit()
 {
 if(TimeFlag1s == 1 && StartRunFlag == 1)
 {	
 TimeFlag1s = 0;
 if(TimeoutColse > 0)
 {
 TimeoutColse--;
 return  0;
 }
 else 
 {
 if(TimeoutColseMAX & 0x80 == 0)
 {
 StartRunFlag = 0;
 }
 return 1;
 }
 }			
 return  0;
 }
 
 void text_data_out_range(uint8_t time_index,uint8_t *time)
 {
 uint8_t max_value,min_value;
 switch(time_index)
 {
 case 0:
 twink_index = 0x60 | 0x80;
 max_value = 60;
 min_value = 0;			
 break;
 case 1:
 twink_index = 0x0c | 0x80;
 max_value = 60;
 min_value = 0;
 break;
 
 case 2:
 twink_index = 0x03 | 0x80;			
 max_value = 24;
 min_value = 0;
 break;
 
 case 3:
 twink_index = 0x40 | 0x80;			
 max_value = 7;
 min_value = 0;
 break;
 
 case 4:
 twink_index = 0x0c | 0x80;			
 max_value = 32;
 min_value = 1;
 break;
 
 case 5:
 twink_index = 0x03 | 0x80;						
 max_value = 13;
 min_value = 1;
 break;
 
 case 6:
 twink_index = 0x0c | 0x80;				
 max_value = 100;
 min_value = 00;
 break;	
 case 7:
 max_value = 61;
 min_value = 00;
 break;	
 case 8:
 max_value = 5;
 min_value = 1;
 break;	
 case 9:
 max_value = 4;
 min_value = 1;
 break;
 default:
 return;
 }	
 if(*time == max_value)
 {
 *time = min_value;
 }
 else if(*time > max_value) 
 {
 *time = max_value - 1;
 }
 else if(*time < min_value)
 {
 *time = max_value - 1;
 }
 }	
 
 void button_set_time()
 {
 uint8_t time_index = 7,button_status,mode_index;
 button_status_bit = 0x01;
 twink_index = 0x80;
 DotDispFlag = 0;
 while(SetModeFlag) 
 {
 
 if(button_status_bit == 0x00)    
 {
 if(SetTwinkleFlag)
 {
 display_mode(disp_time,mode_index);				
 }
 else 
 {
 display_colse_tab(twink_index);
 }
 
 if(timeout_no_operation_quit())
 {
 return ;
 }
 continue;
 }
 
 TimeoutColse = 60;
 button_status = button_status_bit & 0x03;
 
 if(button_status == 0x01)    
 {
 time_index--;			
 if(time_index == 6)
 {
 mode_index = 0x03;
 }
 else if(time_index >=3 && time_index < 6)
 {
 mode_index = 0x02;
 }
 else if(time_index >= 0 && time_index < 3)
 {
 mode_index = 0x01;
 }
 else 
 {
 time_index = 6;
 mode_index = 0x03;
 }
 display_mode(disp_time,mode_index);
 }
 else if(button_status == 0x03)   
 {
 Set_Time_Dec(disp_time);
 break;
 }
 
 if(button_status_bit & (0x01<<2))   
 {
 disp_time[time_index]++; 
 }
 
 if(button_status_bit & (0x01<<4))  
 {
 disp_time[time_index]--;
 }
 
 text_data_out_range(time_index,&disp_time[time_index]);
 
 display_mode(disp_time,mode_index);
 button_status_bit = 0;	
 }
 }
 
 void button_set_alarm()
 {
 uint8_t alarm[3] = {0};
 uint8_t time_index = 0,button_status;
 twink_index = 0x80;	
 button_status_bit = 0x01;
 Enable_Alarm(0);	
 Get_Alarm_EveryDay(alarm + 1);
 while(SetModeFlag) 
 {	
 if(button_status_bit == 0x00)    
 {
 if(SetTwinkleFlag)
 {
 display_alarm_clock(alarm + 1);			
 }
 else 
 {
 display_colse_tab(twink_index);
 }
 if(timeout_no_operation_quit())
 {
 return ;
 }
 continue;
 }
 
 TimeoutColse = 60;
 button_status = button_status_bit & 0x03;
 
 if(button_status == 0x01)    
 {
 time_index++;
 if(time_index >= 3)
 {
 time_index = 0;
 }
 }
 else if(button_status == 0x03)   
 {
 Set_Alarm_EveryDay(alarm + 1);
 Enable_Alarm(AlarmEnableFlag);
 break;
 }
 
 if(button_status_bit & (0x01<<2))   
 {
 alarm[time_index]++; 
 }
 
 if(button_status_bit & (0x01<<4))  
 {
 alarm[time_index]--;
 }
 button_status_bit = 0;
 text_data_out_range(time_index, &alarm[time_index]);
 AlarmEnableFlag = alarm[0] & 0x01;
 display_alarm_clock(alarm + 1);			
 }
 }
 
 void button_function_param()
 {
 uint8_t polling_index[] = {0x00,0xaa,0xb2,0xf3};
 uint8_t func_index = 0,button_status;
 uint8_t temp_param[3] = {1,1,1};
 DotDispFlag = 0;
 temp_param[0] = (TimeoutColseMAX & 0x7f);
 temp_param[1] = polling_display_timing;
 display_set_mode(func_index + 3);
 while(SetModeFlag) 
 {	
 if(button_status_bit == 0x00)    
 {
 display_function_param(temp_param[func_index]);
 if(timeout_no_operation_quit())
 {
 return ;
 }
 continue;
 }
 
 TimeoutColse = 60;
 button_status = button_status_bit & 0x03;
 
 if(button_status == 0x01)    
 {
 func_index++;
 if(func_index >= 3)
 {
 func_index = 0;
 }
 display_set_mode(func_index + 3);
 }
 else if(button_status == 0x03)   
 {
 if(temp_param[0] == 0)
 {
 TimeoutColseMAX |= 0x80;
 }
 else
 {
 TimeoutColseMAX = temp_param[0];
 }
 display_mode_index  = polling_index[temp_param[1] - 1];
 polling_display_timing 	= temp_param[2];
 break;
 }
 
 if(button_status_bit & (0x01<<2))   
 {
 temp_param[func_index]++; 
 }
 
 if(button_status_bit & (0x01<<4))  
 {
 temp_param[func_index]--;
 }	
 button_status_bit = 0;	
 text_data_out_range(func_index + 7 ,&temp_param[func_index]);
 
 }
 }
 
 void button_process()
 {
 static uint8_t set_mode_index = 0;
 uint8_t button_status;
 if(button_status_bit == 0x00)    
 {
 return ;
 }
 
 TimeoutColse = 60;
 button_status = button_status_bit & 0x03;
 
 if(button_status == 0x01)    
 {
 if(SetModeFlag)	 
 {
 set_mode_index++;
 if(set_mode_index >= 3)
 {
 set_mode_index = 0;
 }
 display_set_mode(set_mode_index);		
 }
 else
 {	 
 display_mode_index++;
 display_mode_index &= 0xfb;	
 display_mode(disp_time,display_mode_index & 0x03);
 }
 
 }
 else if(button_status == 0x03)   
 {
 if(!SetModeFlag)
 {
 SetModeFlag = 1;
 set_mode_index = 0;	
 display_set_mode(set_mode_index);
 }
 else 
 {
 display_mode_index &= 0xf8;
 SetModeFlag = 0;
 display_mode(disp_time,0);
 }
 while(Button_SET == 0);
 }
 
 button_status = (button_status_bit >> 2) & 0x03;		
 if(button_status == 0x01)   
 {
 if(SetModeFlag)
 {	
 button_status_bit = 0;			
 switch(set_mode_index)
 {
 case 0:
 button_set_time();
 break;
 case 1:
 button_set_alarm();
 break;
 
 case 2:
 button_function_param();
 break;
 default:
 break;
 }
 display_mode_index &= 0xf8;
 twink_index = 0;
 display_set_mode(0xe0);
 while(Button_SET == 0);
 SetModeFlag = 0;
 }
 else if(led_cloor_index & 0x80 && TR1 == 1)
 {
 led_cloor_index ++;
 led_cloor_index &= 0xef;
 }
 else 
 {
 display_7seg_pwm = code_7seg_pwm[display_7seg_pwm_index++];
 if(display_7seg_pwm_index >= 8)
 {
 display_7seg_pwm_index = 0;
 }
 }
 }
 else if(button_status == 0x03)
 {
 if(led_cloor_index & 0x80 && TR1 == 1)
 {
 if(led_cloor_index & 0x40)
 {
 led_cloor_index &= ~0x40;
 }
 else 
 {
 led_cloor_index |= 0x40;				
 }
 while(Button_PLUSE == 0);
 }			
 }
 
 button_status = (button_status_bit >> 4) & 0x03;			
 if(button_status == 0x01)  
 {
 if(led_cloor_index & 0x80 && TR1 == 1)
 {
 breathing_rate++;
 if(breathing_rate >= 10)
 {
 breathing_rate = 0;
 }
 }
 else if(SetModeFlag == 0)
 {
 TimeoutColse = 0;
 close_all_low_power();
 }			
 }
 else if(button_status == 0x03)
 {
 TimeoutColse = 0;
 close_all_low_power();		
 }
 
 button_status_bit = 0;
 }
 
 void main()
 {		
 init_system_io();	
 AlarmEnableFlag = Get_Alarm_Status();
 if(!Get_Init_RX8025_Flag())
 {
 Recovery_Default_Setting();
 }
 
 while(1)
 {
 
 if(TimeFlag1s == 1 && StartRunFlag == 1)
 {	
 TimeFlag1s = 0;
 if(TimeoutColse > 0)
 {
 TimeoutColse--;
 }
 else if((TimeoutColseMAX & 0x80) == 0)
 {
 StartRunFlag = 0;
 }
 
 if(!SetModeFlag)
 {
 if(display_mode_index & 0x80)
 {
 polling_display_mode();
 }
 Get_Time_Dec(disp_time);
 display_mode(disp_time,display_mode_index & 0x03);
 }				
 }		
 
 
 if(!StartRunFlag)
 {
 close_all_low_power();
 }
 button_process();
 }		
 }
 
 void Exint0() interrupt 0            
 {
 uint8_t timeout = 50;
 StartRunFlag = 1;
 TimeoutColse = (TimeoutColseMAX & 0x7f);
 ET0 = 1;	
 TR0 = 1;
 TimeFlag1s = 1;	
 if((main_key_timing & 0x80 == 0x80) && (main_key_timing & 0x3f) <= 50)
 {
 ET1 = 1;	
 TR1 = 1;
 led_cloor_index	|= 0x80;	
 }
 main_key_timing |= 0x80;
 }
 
 void Exint1() interrupt 2 
 {
 StartRunFlag = 1;
 TimeoutColse = 60;
 ET0 = 1;	
 TR0 = 1;
 TimeFlag1s = 1;
 ET1 = 1;	
 TR1 = 1;
 led_cloor_index	|= 0x80;		
 }
 
 
 
 void InterruptTime0() interrupt 1
 {
 static uint16_t i = 0;
 
 i++;
 
 if(i == 200)
 {
 SetTwinkleFlag = 1;
 if(SetModeFlag == 0)
 {
 COLON_PIN = 1;
 }
 }
 else if(i == 1000)
 {
 SetTwinkleFlag = 0;
 
 COLON_PIN = ~DotDispFlag;	
 
 }
 
 if(i >= 1000)
 {
 i = 0;
 TimeFlag1s = 1;
 }
 
 if(i % breathing_rate == 0)
 {
 if(led_cloor_index & 0x80)
 {
 if(led_cloor_index & 0x40)
 {
 rgbled_gradient_breathing();
 }
 }
 else
 {
 P0 |= 0xe0;	
 }
 }
 
 if(i % 20 == 0)
 {
 button_scanning();
 if(main_key_timing & 0x80)
 {
 main_key_timing ++;
 if((main_key_timing & 0x3f) == 0x3f)
 {
 main_key_timing = 0;
 }
 }
 }
 
 TL0 = 0x30;		 
 TH0 = 0xF8;		 
 if(display_7seg_pwm & (0x01 << (i % 8)))
 {
 display_dynamic_buff();
 }
 else 
 {
 DisplayBitSelect(0xf0);
 DisplayOneLED(0x00);
 
 DisplayBitSelect(0x00);
 }
 }
 
 void InterruptTime1() interrupt 3
 {
 static uint8_t count = 0;
 uint8_t i;
 TR1 = 0;
 count++;	
 for(i = 0; i < 3; i++)
 {
 if(count < RGB_ratio[i])
 {
 P0 &= (~(0x20 << i));
 }
 else 
 {
 P0 |= (0x20 << i);	
 }
 }		
 TR1 = 1;	
 }
