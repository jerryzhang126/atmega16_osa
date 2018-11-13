#ifndef SDVIG_C
#define SDVIG_C
#include <driver_h/sdvig.h>
//***********************************************************************
//		������ ��� ������ �� ������� � ���������� �����					*
//----------------------------------------------------------------------*
// ����� �� ����������� ����� ��� 1 �����
// ���� ��� ������ � ����������� �����, ���-�� �������

int8_t sdvig8(int8_t ch, uint8_t kol)
{
uint8_t ret;
asm volatile(
		"WHILE_%=:"			"\n\t" // ����� ��������� ��������
		"cpi %[KOL],0" 		"\n\t" // ��������� � 0
		"breq EXIT_%=" 		"\n\t" // ���� ������� ��� ����������� ������ �� ������� �� �����
		"asr %[CH]" 		"\n\t" // �������� ������� ����
		"dec %[KOL] "		"\n\t" // ����������� ���-�� �������
		"rjmp WHILE_%="		"\n\t" // ������� �����
		"EXIT_%=:" 			 "\n\t"
		"mov %[RET],%[CH]" "\n\t"
		:[RET]"=&r"(ret)
		:[CH]"r"(ch), [KOL] "r"(kol)
		);
return ret;
}

//-------------------------------------------------------------------------
// ����� �� ����������� ����� ��� 2 ����
// ���� ��� ������ � ����������� �����, ���-�� �������
int16_t sdvig16(int16_t ch, uint8_t kol)
{
int16_t ret;
asm volatile (
	"WHILE_%=:"			"\n\t" // ����� ��������� ��������
	"cpi %[KOL],0" 		"\n\t" // ��������� � 0
	"breq EXIT_%=" 		"\n\t" // ���� ������� ��� ����������� ������ �� ������� �� �����
	"asr %B[CH]" 		"\n\t" // �������� ������� ����
	"ror %A[CH]" 		"\n\t" // �������� ������� ����
	"dec %[KOL] "		"\n\t" // ����������� ���-�� �������
	"rjmp WHILE_%="		"\n\t" // ������� �����
	"EXIT_%=:" 			 "\n\t"
	"mov %A[RET],%A[CH]" "\n\t"
	"mov %B[RET],%B[CH]" "\n\t"
	:[RET]"=&r"(ret)
	:[CH]"r"(ch), [KOL] "r"(kol)
	);
return ret;
}
//***********************************************************************************
#endif
