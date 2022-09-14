/*
* DCmotor.c
*
* Created: 2020-10-09 오후 5:18:18
*  Author: kccistc
*/

#include "DCmotor.h"


// 타이머카운터3(16비트) , PE3


void DCmotorInit()
{
	MOTOR_DDR |= (1<<MOTOR_PIN);
	DDRA |= (1<<0) | (1<<1);
	
	TCCR3A |= (1<<COM3A1);			//분주비8, CTC모드, FAST PWM (비반전모드)
	TCCR3B |= (0<<CS32) | (1<<CS31) | (0<<CS30);
	TCCR3B |= (1<<WGM33) | (1<<WGM32);
	TCCR3A |= (1<<WGM31) | (0<<WGM30);
	
	ICR3=39999;
}

void DCmotorStop()
{
	MOTOR_DDR &= ~(1<<MOTOR_PIN);
	//PORTA = (0<<0) | (0<<1);
}

void DCmotorRun()
{
	MOTOR_DDR |= (1<<MOTOR_PIN);
}

void revolveRight()
{
	PORTA = (0<<0) | (1<<1);
}

void revolveLeft()
{
	PORTA = (1<<0) | (0<<1);
}