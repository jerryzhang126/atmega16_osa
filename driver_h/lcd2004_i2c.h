#ifndef LCD2004_I2C_H
#define LCD2004_I2C_H
//----------------------------------------------------------
#include <avr_cmsis.h>
#include <driver_h\i2c.h>		// TWI �������
#include <util/delay.h>
#include <avr/pgmspace.h>

//---------------------------------------------------------------

//***************************************************************
//																*
//			��������� ������ ��-���������						*
//																*
//***************************************************************
// ����� ������ (PCF8574 - 0b0100xxx;PCF8574A - 0b0111xxx)		*
#define Addres_lcd		0b0111111							//	*
//--------------------------------------------------------------*
// ����� ������													*
#define Shift_Disp 0 // ��������								*
//--------------------------------------------------------------*
// �������� ������� ��� ������ �������							*
#define Shift_Curr 1 // �������									*
//--------------------------------------------------------------*
// ������ ��������												*
#define Blink 0		// 0-��������/1-�������						*
//--------------------------------------------------------------*
// ������ _														*
#define Cursor 0	// 0-��������/1-�������						*
//--------------------------------------------------------------*
// �������														*
#define Display 1	// 0-��������/1-�������						*
//--------------------------------------------------------------*
// �����:														*
#define Font 0 		// 5*7px									*
//--------------------------------------------------------------*
// ���-�� �����:												*
#define Lines 1		// 1-2_������								*
//--------------------------------------------------------------*
// ����������� �������� ��� Lcd_clear()							*
#define delay_lcd_clear()		_delay_ms(1600)				//	*				
//***************************************************************

//***************************************************************
//																*
//		��������� ��� ��������� �������							*
//																*
//--------------------------------------------------------------*
typedef union												//	*
{															//	*
struct														//	*
{															//	*
uint8_t	shift_disp:1;// ������������� ����� ������ ��� ������ 	*
			   		//	������� ��������=0/��������=1			*
uint8_t	shift_curr:1;// �������� ������� ��� ������ ������� 	*
			   		//	�����=0/������=1						*
//--------------------------------------------------------------*
uint8_t blink:	1; 	// ������ �������� ���������=0/��������=1	*
uint8_t cursor:	1; 	// ������ _ ���������=0/��������=1			*
uint8_t display:1; 	// ������� ���������=0/��������=1			*
//--------------------------------------------------------------*
uint8_t font:	1;	// �����: 5*7px=0/5*10px=1					*
uint8_t lines:	1;	// ���-�� �����: 1������=0/2������=1		*
uint8_t bits:	1;	// ������ ����: 4���=0/8���=1				*
};															//	*
uint8_t set;		// ������ � ������ ��������					*
}SetLCD_t;													//	*
//***************************************************************


//***************************************************************
//																*
//		�������� ������� ��� ������ � ������� ��-���������		*
//																*
//--------------------------------------------------------------*
// ������������� ������ ��-���������							*
#define Init_lcd_def()		 Init_LCD(Addres_lcd)			//	*
//--------------------------------------------------------------*
// ��������� ��������� � ������									*									
#define Setting_LCD_def(set) setting_lcd(Addres_lcd, set)	//	*
//--------------------------------------------------------------*
// ����������� ������ � ������� �-�								*
#define GoTo(x,y)			 CursorGoTo(Addres_lcd,x,y)		//	*
//--------------------------------------------------------------*
// �������� �����												*
#define Lcd_clear()		 LCD_clear(Addres_lcd) 				//	*
//--------------------------------------------------------------*
// ������� ��������/���������									*
void Lcd_Display(void); 									//  *
//--------------------------------------------------------------*
// ������ ������������� ��������/��������� 						*
void Cursor_underline(void); 								//	*
//--------------------------------------------------------------*
// ������ ������������ ������� �������							*
void Cursor_blink(void); // ��������/��������� 					*
//--------------------------------------------------------------*
// ���������� ��������/���������								*
void BackLight(void);										//	*
//--------------------------------------------------------------*
// ����� ������ �� RAM											*
#define Lcd_SendString(string) LCD_SendString(Addres_lcd, string)//*
//--------------------------------------------------------------*
// ����� ������ �� ROM											*
//	prog_char string[]="ALEKSEY"								*
#define Lcd_SendStringFlash(string) LCD_SendStringFlash(Addres_lcd, string)
//***************************************************************


//***************************************************************
//																*
//		�������� ������� ��� ������ � �������					*
//																*
//--------------------------------------------------------------*
// ������������� ������ �� ������
SetLCD_t Init_LCD(uint8_t add_lcd);
//--------------------------------------------------------------*
// ������ ������� ������
void LCD_clear(uint8_t add_lcd);
//--------------------------------------------------------------*
void setting_lcd(uint8_t add_lcd, SetLCD_t SetLCD);
//--------------------------------------------------------------*
//	������� ������� �� ������: �-������; �-�������				*
void CursorGoTo(uint8_t add_lcd, uint8_t x, uint8_t y);		//	*
//--------------------------------------------------------------*
// �������� ������ �� RAM ������								*
// ��������� ������� ����� �������� ������ �����-1/������-0		*
 void LCD_SendString(uint8_t addres_lcd, char *str);		//	*
//--------------------------------------------------------------*
// �������� ������ �� Flash ������								*
void LCD_SendStringFlash(uint8_t addres_lcd, prog_char *str);//*
//***************************************************************
#endif
