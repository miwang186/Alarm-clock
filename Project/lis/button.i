
#line 1 "..\main\button.c" /0
  
#line 1 "..\MAIN\BUTTON.H" /0
 
 
  
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
 
 









 
 
 
 
 
 
#line 3 "..\MAIN\BUTTON.H" /0
 
 
 
 
 
 
 sbit Button_SET	 	= P2^2;
 sbit Button_PLUSE	= P2^3;
 sbit Button_MINUS	= P2^4;
 
 void button_scanning(void);
 extern unsigned char button_status_bit;
 
#line 1 "..\main\button.c" /0
 
  
#line 1 "D:\PROGRAM FILES\KEIL_V5\C51\INC\STC\STC89C5XRC.H" /0
 
#line 2 "D:\PROGRAM FILES\KEIL_V5\C51\INC\STC\STC89C5XRC.H" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 









 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 




















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 







 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 









 
 
 
 
 
#line 233 "D:\PROGRAM FILES\KEIL_V5\C51\INC\STC\STC89C5XRC.H" /0
 
#line 2 "..\main\button.c" /0
 
  
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
 
 
 
 
#line 3 "..\main\button.c" /0
 
 
 typedef unsigned char uint8_t;
 typedef unsigned int  uint16_t;
 
 
 






 
 uint8_t button_status_bit = 0;
 


 
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
 button_out |= (0x01 << (i*2)); 
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
 
 
 
 
 
 
 
 
 
 
 
 
 }
 button_out_backup = button_out;
 }
 else if(button_out_backup != 0)
 {
 if(keep_time >= 25)
 {
 for(i = 0; i < 3; i++)
 {
 if(button_out_backup & (0x01 << (i*2)))
 {
 button_status_bit &= ~(0x03 << (i*2));
 button_status_bit |= (0x03 << (i*2));
 }					
 }
 keep_time = 23;
 }
 keep_time++;
 }
 else 
 {
 
 
 
 
 
 
 
 
 keep_time = 0;
 }
 }
