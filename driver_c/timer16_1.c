#ifndef TIMER16_1_c
#define TIMER16_1_c
#include <atmega16_32.h>
//***********************************************************************
//																		*
//				������ ������� � ������ ��������						*
//																		*
//----------------------------------------------------------------------*
// ������������� ������ NORMAL											*

void TIMER16_1_NORMAL(FuncState_t state_ISR)//��������� ����������* 
// ������ �� ����������: 												*
{																	//	*
// ��������� ������													//	*
tccr1b->wgm1=0;														//	*
tccr1a->wgm1=0;														//	*
// ��������� ����������													*
timsk->toie1=state_ISR;												//	*
}																	//	*
//----------------------------------------------------------------------*
// 	������������� ������ CTC (����� ��� ���������� ��� �������� ICR1)	*
void TIMER16_1_CTC_ICR1(uint16_t ICR, // �������� �������� ������������	*
		 FuncState_t state_ISR) // ��������� ���������			*
{																	//	*
// ��������� ������														*
tccr1b->wgm1=0b11;													//	*
tccr1a->wgm1=0b00;													//	*
// ��������� �������� ������											*
uint16hl_t temp;													//	*
temp.HL=ICR;														//	*
ICR1H=temp.H;														//	*
ICR1L=temp.L;														//	*
// ��������� ����������													*
timsk->ticie1=state_ISR;											//	*
}																	//	*
//----------------------------------------------------------------------*
// 	������������� ������ CTC (����� ��� ���������� ��� �������� OCR1A)	*
void TIMER16_1_CTC_OCR1A(uint16_t OCR, // �������� �������� ������������*
		 FuncState_t state_ISR) // ��������� ���������			*
{																	//	*
// ��������� ������														*
tccr1b->wgm1=0b01;													//	*
tccr1a->wgm1=0b00;													//	*
// ��������� �������� ������											*
uint16hl_t temp;													//	*
temp.HL=OCR;														//	*
OCR1AH=temp.H;														//	*
OCR1AL=temp.L;														//	*
// ��������� ����������													*
timsk->ocie1a=state_ISR;											//	*
}																	//	*
//======================================================================*
//																		*
//	��������� ������ ������� OC1A/OC1B � ������ ��������				*
//																		*
//----------------------------------------------------------------------*
// ��������� ������ ������ OC1A											*
void TIMER16_1_COUNT_OCR1A(count_OC_t count)//��������� ������ ������� ��1A*
{																	//	*
// ��������� ���� �� �����											//	*
DDR_OC1->PIN_OC1A=1;												//	*
// ��������� ������ ������												*
tccr1a->com1a=count;												//	*
}																	//	*
//----------------------------------------------------------------------*
// ��������� ������  ������ OC1B										*
void TIMER16_1_COUNT_OCR1B(count_OC_t count)//��������� ������ ������ ��1�*
{																	//	*
// ��������� ���� �� �����												*
DDR_OC1->PIN_OC1B=1;												//	*
// ��������� ������ ������												*
tccr1a->com1b=count;												//	*
}																	//	*
//***********************************************************************

//***********************************************************************
//																		*
//				������ ������� � ������ � � �							*
//																		*
//----------------------------------------------------------------------*
// ����� Fast PWM � ������� ������ ����� (8,9,10 ���)					*
void TIMER16_1_FAST_PWM_reslt(bit16_t bit, // ������ �����				*
	     	  FuncState_t state_ISR) // ��������� ���������		*
//																		*
{																	//	*
// ��������� ������														*
tccr1b->wgm1=0b01;													//	*
tccr1a->wgm1=bit;													//	*
// ��������� ����������													*
timsk->toie1=state_ISR;												//	*
}																	//	*
//----------------------------------------------------------------------*
// ����� Fast PWM � ���������� ������ ����� � �������� ICR1				*
void TIMER16_1_FAST_PWM_ICR1(uint16_t ICR, // �������� ���-�� �����-��	*
		 FuncState_t state_ISR) // ��������� ���������			*
{
// ��������� ������	
tccr1a->wgm1=0b10;
tccr1b->wgm1=0b11;
// ��������� �������� ���������											*
uint16hl_t temp;
temp.HL=ICR;
ICR1H=temp.H;
ICR1L=temp.L;
// ��������� ����������		
timsk->ticie1=state_ISR;
}
//----------------------------------------------------------------------*
// ����� Fast PWM � ���������� ������ ����� � �������� OCR1A			*
void TIMER16_1_FAST_PWM_OCR1A(uint16_t OCR, // �������� ���-�� �����-��	*
		 FuncState_t state_ISR) // ��������� ���������			*
{
// ��������� ������	
tccr1a->wgm1=0b11;
tccr1b->wgm1=0b11;
// ��������� �������� ���������											*
uint16hl_t temp;
temp.HL=OCR;
OCR1AH=temp.H;
OCR1AL=temp.L;
// ��������� ����������		
timsk->ocie1a=state_ISR;
}
//----------------------------------------------------------------------*
// ����� Phase Correct PWM � ������� ������ ����� (8,9,10 ���)			*
void TIMER16_1_PhasCorr_PWM_reslt(bit16_t bit, // ������ �����			*
	     		FuncState_t state_ISR) // ��������� ���������		*
{
// ��������� ������														*
tccr1b->wgm1=0b00;
tccr1a->wgm1=bit;
// ��������� ����������													*
timsk->toie1=state_ISR;												//	*
}
//----------------------------------------------------------------------*
// ����� Phase Correct PWM � ���������� ������ ����� � �������� ICR1	*
void TIMER16_1_PhaseCorr_PWM_ICR1(ph_cor_t mode,//����� ����� ���.���-���
					uint16_t ICR, // �������� �������� ������������		*
				    FuncState_t state_ISR) // ��������� ���������	*
{
// ��������� ������
tccr1b->wgm1=0b10;
tccr1a->wgm1=mode;
// ��������� �������� ���������											*
uint16hl_t temp;
temp.HL=ICR;
ICR1H=temp.H;
ICR1L=temp.L;
// ��������� ����������													*
timsk->ticie1=state_ISR;
}
//----------------------------------------------------------------------*
// ����� Phase Correct PWM � ���������� ������ ����� � �������� OCR1A	*
void TIMER16_1_PhaseCorr_PWM_OCR1A(ph_cor_t mode,//����� ����� ���.���-���
					uint16_t OCR, // �������� �������� ������������		*
				    FuncState_t state_ISR) // ��������� ���������	*
{

// ��������� ������
tccr1b->wgm1=0b10;
tccr1a->wgm1=mode|0b01;
// ��������� �������� ���������											*
uint16hl_t temp;
temp.HL=OCR;
OCR1AH=temp.H;
OCR1AL=temp.L;
// ��������� ����������													*
timsk->ocie1a=state_ISR;
}
//======================================================================*
//																		*
//	��������� � ������ Phase Correct PWM ���������� � ������� OC1A/OC1B *
//																		*
//----------------------------------------------------------------------*
// ��������� ������ ���������� �  ������ OC1A							*
void TIMER16_1_PWM_OCR1A(uint16_t OCR, // �������� �������� ���������	*
		  FuncState_t state_ISR, // ��������� ����������			*
					 pwm_OC_t count) // ��������� ������ ������� ��1A	*
{																		
// ��������� ���� �� �����
DDR_OC1->PIN_OC1A=1;
// ��������� �������� ���������											*
uint16hl_t temp;
temp.HL=OCR;
OCR1AH=temp.H;
OCR1AL=temp.L;
// ��������� ����������													*
timsk->ocie1a=state_ISR;
// ��������� ������ ������												*
tccr1a->com1a=(uint8_t)count;
}
//----------------------------------------------------------------------*
// ��������� ������ ����������, ���������� �  ������ OC1B				*
void TIMER16_1_PWM_OCR1B(uint16_t OCR, //��������� �������� ���������	*
		  FuncState_t state_ISR, // ���/����. ���������			*
					 pwm_OC_t count) // ��������� ������ ������ ��1�	*
{
// ��������� ���� �� �����
DDR_OC1->PIN_OC1B=1;
// ��������� �������� ���������											*
uint16hl_t temp;
temp.HL=OCR;
OCR1BH=temp.H;
OCR1BL=temp.L;
// ��������� ����������													*
timsk->ocie1b=state_ISR;
// ��������� ������ ������												*
tccr1a->com1b=count;
}
//***********************************************************************



#endif
