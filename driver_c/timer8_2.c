#ifndef TIMER8_2_C
#define TIMER8_2_C
#include "avr_cmsis.h"


//***********************************************************************
// ����������� ��� �������� �������� ���������� TCCR2 ����� �������		*
//----------------------------------------------------------------------* 
//	�������� �������� � ������� ��������� OCR2 � ����������� ������		*
#define ASYN_TCR2_BYSE()		while(assr->tcr2ub)					//	*
//***********************************************************************

//***********************************************************************
//																		*
//	� � � � � � �		� � �	� � � � � � 	�	T I M E R 8_0		*
//																		*
//***********************************************************************

//***********************************************************************
//																		*
//		��������� ������  � ������ �������								*
//																		*
//----------------------------------------------------------------------*
// ������������� ������ NORMAL											*
void TIMER8_2_NORMAL(FunctionalState_t state_ISR)//��������� ���������� *
{																	//	*
// ��������� ������														*
#ifdef ASYNCHRONOUS_MODE	//���� �������� �������� ������			//	*
ASYN_TCR2_BYSE();			// �������� ���������� � ������			//	*
#endif																//	*
tccr2->wgm20=0;														//	*
#ifdef ASYNCHRONOUS_MODE	//���� �������� �������� ������			//	*
ASYN_TCR2_BYSE();			// �������� ���������� � ������			//	*
#endif																//	*
tccr2->wgm21=0;														//	*
// ��������� ����������												//	*
timsk->toie2=state_ISR;												//	*
}																	//	*
//----------------------------------------------------------------------*
// 	������������� ������ CTC (����� ��� ���������� ��� �������� OCR2)	*
void TIMER8_2_CTC_OCR2(uint8_t OCR, // �������� �������� ������������	*
		 FunctionalState_t state_ISR) // ��������� ���������			*
{																	//	*
// ��������� ������														*
#ifdef ASYNCHRONOUS_MODE	//���� �������� �������� ������			//	*
ASYN_TCR2_BYSE();			// �������� ���������� � ������			//	*
#endif																//	*
tccr2->wgm20=0;														//	*
#ifdef ASYNCHRONOUS_MODE	//���� �������� �������� ������			//	*
ASYN_TCR2_BYSE();			// �������� ���������� � ������			//	*
#endif																//	*
tccr2->wgm21=1;														//	*
// ��������� �������� ���������											*
#ifdef ASYNCHRONOUS_MODE											//	*
ASYN_OCR2_LOAD(OCR);	// ������ � ������� ��������� � ���������	//	*
#else																//	*
OCR2=OCR;															//	*
#endif																//	*
// ��������� ����������													*
timsk->ocie2=state_ISR;												//	*
}																	//	*
//----------------------------------------------------------------------*
//======================================================================*
//																		*
//	��������� ������ ���������� � ������� OC2	� ������ �������		*
//																		*
//----------------------------------------------------------------------*
// ��������� ������ ���������� �  ������ OC2							*
void TIMER8_2_COUNT_OCR2(uint8_t OCR, // �������� �������� ���������	*
		  FunctionalState_t state_ISR, // ��������� ����������			*
					 count_OC_t count) // ��������� ������ ������ ��2 	*
{																	//	*
// ��������� ���� �� �����
DDR_OC2->PIN_OC2=1;
// ��������� �������� ���������											*
#ifdef ASYNCHRONOUS_MODE											//	*
ASYN_OCR2_LOAD(OCR);	// ������ � ������� ��������� � ���������	//	*
#else																//	*
OCR2=OCR;															//	*
#endif																//	*
// ��������� ����������													*
timsk->ocie2=state_ISR;												//	*
// ��������� ������ ������												*
#ifdef ASYNCHRONOUS_MODE	//���� �������� �������� ������			//	*
ASYN_TCR2_BYSE();			// �������� ���������� � ������			//	*
#endif																//	*
tccr2->com2=count;													//	*
}																	//	*
//***********************************************************************

//***********************************************************************
//																		*
//				������ ������� � ������ � � �							*
//																		*
//----------------------------------------------------------------------*
//		����� 	F A S T		P W M										*
//----------------------------------------------------------------------*
// ����� Fast PWM														*
void TIMER8_2_FAST_PWM(FunctionalState_t state_ISR)//��������� ���������
{
// ��������� ������														*
#ifdef ASYNCHRONOUS_MODE	//���� �������� �������� ������			//	*
ASYN_TCR2_BYSE();			// �������� ���������� � ������			//	*
#endif																//	*
tccr2->wgm20=1;
#ifdef ASYNCHRONOUS_MODE	//���� �������� �������� ������			//	*
ASYN_TCR2_BYSE();			// �������� ���������� � ������			//	*
#endif																//	*
tccr2->wgm21=1;
// ��������� ����������												//	*
timsk->toie2=state_ISR;
}
//----------------------------------------------------------------------*
//		����� 	P H A S E	C O R R E C T		P W M					*
//----------------------------------------------------------------------*
// ����� Phase Correct PWM 												*
void TIMER8_2_PhasCorr_PWM(FunctionalState_t state_ISR)//�-��� ���������
{
// ��������� ������														*
#ifdef ASYNCHRONOUS_MODE	//���� �������� �������� ������			//	*
ASYN_TCR2_BYSE();			// �������� ���������� � ������			//	*
#endif																//	*
tccr2->wgm20=1;
#ifdef ASYNCHRONOUS_MODE	//���� �������� �������� ������			//	*
ASYN_TCR2_BYSE();			// �������� ���������� � ������			//	*
#endif																//	*
tccr2->wgm21=0;
// ��������� ����������												//	*
timsk->toie2=state_ISR;
}
//----------------------------------------------------------------------*
//======================================================================*
//																		*
//	��������� ������ ���������� � ������ OC2	� ������ ���			*
//																		*
//----------------------------------------------------------------------*
// ��������� ������ ���������� �  ������ OC0							*
void TIMER8_2_PWM_OCR2(uint8_t OCR, // �������� �������� ���������		*
		  FunctionalState_t state_ISR, // ��������� ����������			*
					 pwm_OC_t pwm) // ��������� ������ ������� ��0		*
{
// ��������� ���� �� �����
DDR_OC2->PIN_OC2=1;
// ��������� �������� ���������											*
#ifdef ASYNCHRONOUS_MODE											//	*
ASYN_OCR2_LOAD(OCR);	// ������ � ������� ��������� � ���������	//	*
#else																//	*
OCR2=OCR;															//	*
#endif																//	*
// ��������� ����������													*
timsk->ocie2=state_ISR;												//	*
// ��������� ������ ������												*
#ifdef ASYNCHRONOUS_MODE	//���� �������� �������� ������			//	*
ASYN_TCR2_BYSE();			// �������� ���������� � ������			//	*
#endif																//	*
tccr2->com2=pwm;													//	*
}																	//	*
//***********************************************************************




#endif
