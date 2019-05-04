
#line 1 "..\main\i2c.c" /0
  
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
 
 









 
 
 
 
 
 
#line 1 "..\main\i2c.c" /0
 
  
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
 
 
 
 
#line 2 "..\main\i2c.c" /0
 
  
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
 
#line 3 "..\main\i2c.c" /0
 
 
 sbit  SCL=P0^0;
 sbit  SDA=P0^1;
 
 
 
 
 static void IC_start(void)
 {
 SCL=1;  
 SDA=1;
 _nop_();
 _nop_();
 SDA=0;
 _nop_();
 _nop_();
 SCL=0;
 }
 
 
 
 
 static void IC_stop(void)
 {
 SCL=0;  
 SDA=0;
 _nop_();
 _nop_();
 SCL=1;
 _nop_();
 _nop_();
 SDA=1;
 }
 
 
 
 
 
 
 static unsigned char IC_WriteByte( unsigned char wdata)
 {
 unsigned char i;
 for(i=0; i<8; i++)
 {
 SCL=0;
 SCL=0;
 _nop_();
 _nop_();
 if(wdata&0x80) SDA=1;
 else SDA=0;
 _nop_();
 _nop_();
 SCL=1;
 wdata<<=1;
 }
 SCL=0;
 SCL=0;
 _nop_();
 _nop_();
 SCL=1;
 i=0;
 while(SDA)
 {
 if(++i>12)
 {
 SCL=0;
 return(0);
 }
 }
 SCL=0;
 return(1);
 }
 
 
 
 
 
 
 static unsigned char IC_ReadByte(void)
 {
 unsigned char i;
 unsigned char IC_data=0;
 SCL=0;
 SDA=1;
 for(i=0; i<8; i++)
 {
 SCL=1;
 SCL=1;
 _nop_();
 _nop_();
 IC_data<<=1;
 IC_data|=SDA;
 _nop_();
 SCL=1;
 _nop_();
 SCL=0;
 _nop_();
 }
 _nop_();
 _nop_();
 _nop_();
 SCL=0;
 SDA=0;
 return(IC_data);
 }
 
 
 
 
 
 
 unsigned char RX8025ReadBytes(unsigned char addr,unsigned char *time, unsigned char num)
 {
 unsigned char i;
 IC_start();
 if(IC_WriteByte(0x64)==0)
 {
 IC_stop();
 return(0);
 }
 if(IC_WriteByte(addr)==0)
 {
 IC_stop();
 return(0);
 }
 IC_start();
 if(IC_WriteByte(0x65)==0)
 {
 IC_stop();
 return(0);
 }
 for(i=0; i<num-1; i++)
 {
 time[i]=IC_ReadByte();
 SDA=0;  
 SDA=0;
 SCL=1;
 }
 time[num-1] = IC_ReadByte();
 SDA=1;  
 SDA=1;
 _nop_();
 SCL=1;
 IC_stop();
 return(1);
 }
 
 
 
 
 
 
 
 unsigned char RX8025WriteBytes(unsigned char addr,unsigned char *time, unsigned char num)
 {
 unsigned char i;
 IC_start();
 if(IC_WriteByte(0x64)==0)
 {
 IC_stop();
 return(0);
 }
 if(IC_WriteByte(addr)==0)
 {
 IC_stop();
 return(0);
 }
 for(i=0; i<num; i++)
 {
 if(IC_WriteByte(time[i])==0)
 {
 IC_stop();
 return(0);
 }
 }
 IC_stop();
 _nop_();
 _nop_();
 SDA=0;
 SCL=0;
 return(1);
 }
 static void dec_to_hex(unsigned char *dec,unsigned char *hex,unsigned char len)
 {
 unsigned char i;	
 for(i = 0; i < len; i++)
 {
 hex[i] = ((dec[i] / 10) << 4) + dec[i] % 10;
 }
 }
 static void hex_to_dec(unsigned char *dec,unsigned char *hex,unsigned char len)
 {
 unsigned char i;	
 for(i = 0; i < len; i++)
 {
 dec[i] = (hex[i] & 0x0f) + ((hex[i] >> 4) * 10);
 }
 }
 unsigned char bit_to_dec_week(unsigned char dat)
 {
 unsigned char i;
 for(i = 0; i < 7; i++)
 {
 if(dat & (0x01<<i))
 {
 return i;
 }
 }
 return 0;
 }
 
 void Get_Time_Dec(unsigned char *time)
 {
 unsigned char time_hex[7] = {0};
 RX8025ReadBytes(0,time_hex,7);
 hex_to_dec(time,time_hex,7);
 time[3] = bit_to_dec_week(time_hex[3]);
 }
 
 void Set_Time_Dec(unsigned char *time_dec)
 {
 unsigned char time_hex[7] = {0};
 dec_to_hex(time_dec,time_hex,7);
 time_hex[3] = 0x01 << time_dec[3];
 RX8025WriteBytes(0,time_hex,7);
 }
 
 void Get_Alarm_EveryDay(unsigned char *alarm_time)
 {
 unsigned char time_hex[2] = {0};
 RX8025ReadBytes(0x08,time_hex,2);
 hex_to_dec(alarm_time,time_hex,2);
 }
 
 void Set_Alarm_EveryDay(unsigned char *alarm_time)
 {
 unsigned char time_hex[2] = {0};
 dec_to_hex(alarm_time,time_hex,2);	
 RX8025WriteBytes(0x08,time_hex,2);
 RX8025WriteBytes(0x0a,0x80,1);
 }
 
 void Enable_Alarm(bit p)
 {
 unsigned char dat = 0,clean = 0;
 if(p)
 {
 dat = 0x08;
 RX8025WriteBytes(0x0e,&clean,1);
 }	
 RX8025WriteBytes(0x0f,&dat,1);
 }
 
 
 bit Recovery_Default_Setting()
 {
 unsigned char dat[16] = {0};
 
 memset(dat, 0, 16);
 if(!RX8025WriteBytes(0,dat,16))
 {
 return 0;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 return 1;
 }
 bit Get_Init_RX8025_Flag()
 {
 unsigned char dat;	
 RX8025ReadBytes(0x0e,&dat,1);	
 if(dat & 0x02)
 {
 return 0;
 }
 else 
 {
 return 1;
 }	
 }
 bit Get_Alarm_Status()
 {
 unsigned char dat;	
 RX8025ReadBytes(0x0f,&dat,1);	
 if(dat & 0x08)
 {
 return 1;
 }
 else 
 {
 return 0;
 }
 }
