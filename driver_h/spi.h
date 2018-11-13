#ifndef SPI_H
#define SPI_H
#include "avr_cmsis.h"
//*******************************************************************
//		��������� ������ SPI										*
//------------------------------------------------------------------*
// ��������� �������� � ������� ���������� ����������				* 
#define PORT_SPI	PORTB	// ����									*
#define DDR_SPI		DDRB	// 										*
#define SS			0		// ����� ������ ��������				*
#define MOSI		2		// ����� �������� ������ �� �������		*
#define MISO		3		// ����� ����� ������ ��������			*
#define SCK			1		// ����� ������������					*
#define def_SS				// ����� ���� �� ���������				*
//*******************************************************************
//------------------------------------------------------------------*
// ����������� �������� ����										*
typedef enum												//		*
{															//		*
MSB=0,	// ������� ����� ������										*
LSB=1	// ������� ����� ������										*
} dord_t;													//		*
//------------------------------------------------------------------*
// ���������� ����������� ���������									*
typedef enum												//		*
{															//		*
idle_low=0,	// � ������ �������� ����������� ����� � ���. ������	*
idle_high=1	// � ������ �������� ����������� ����� � �����. ������	*
} cpol_t;													//		*
//------------------------------------------------------------------*
// ���� ���������� ������											*
typedef enum													//	*
{																//	*
read_first=0,	// ���������� ������ �� ������� ������				*
read_second=1	// ���������� ������ �� ������� ������				*
} cpha_t;														//	*
//------------------------------------------------------------------*
// ��������� �������� ��������										*
typedef enum													//	*
{																//	*
div_2=	4,														//	*
div_4=	0,														//	*
div_8=	5,														//	*
div_16=	1,														//	*
div_32=	6,														//	*
div_64=	2,														//	*
div_128=3														//	*
} spr_t;														//	*
//------------------------------------------------------------------*
//	��������� ��� ��������� SPI										*
typedef struct													//	*
{																//	*
dord_t dord:1; // ����������� �������� �����						*
cpol_t cpol:1; // ���������� ��� ��������� 							*
cpha_t cpha:1; // ���� ���������� ������							*
spr_t  div: 3; // ������������ ������������							*
} SpiSet_t;														//	*
//------------------------------------------------------------------*

//*******************************************************************
//	������������� ������, ���������									*
void init_spi(SpiSet_t set);									//	*
//------------------------------------------------------------------*
//	����� � �������� �����											*
uint8_t SPI_Byte(uint8_t data);									//	*
//------------------------------------------------------------------*
//	����� � �������� ������� ������ ������ NUM						*
void SPI_Array(uint8_t *input, uint8_t *output, uint8_t num);	//	*
//*******************************************************************
#endif