/*
* buzzer.c
*
* Created: 2020-09-15 오후 5:34:52
*  Author: kccistc
*/

#include "buzzer.h"

void buzzerInit()
{
	DDRB |= (1<<DDRB5);	// OC1A 출력 핀 설정   -> 출력을 5번으로 할거임
	
	TCCR1A |= (0<<WGM11) | (0<<WGM10);	//CTC MODE
	TCCR1B |= (0<<WGM13) | (1<<WGM12);	//CTC MODE
	TCCR1B |= (0<<CS12) | (1<<CS11) | (0<<CS10);		//8분주비
}

void setBuzzer(int note)
{
	int ocr_value = 1000000 / note; //F_CPU/2/PRESCALER/note
	OCR1A = ocr_value;
}

void playBuzzer(void)
{
	TCCR1A |= ( (0<<COM1A1) | (1<<COM1A0) );	//ocr 같아지면 반전
}

void noBuzzer(void)
{
	TCCR1A &= ~( (1<<COM1A1) | (1<<COM1A0) );	//출력안됨
}

void powerONbuzzer(void)
{
	playBuzzer();
	setBuzzer(1000);	//1KHz
	_delay_ms(70);
	setBuzzer(2000);	//2KHz
	_delay_ms(70);
	setBuzzer(3000);	//3KHz
	_delay_ms(70);
	setBuzzer(4000);	//4KHz
	_delay_ms(70);
	noBuzzer();
	
}