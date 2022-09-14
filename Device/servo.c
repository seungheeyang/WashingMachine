/*
 * servo.c
 *
 * Created: 2020-09-21 오후 12:46:56
 *  Author: kccistc
 */ 

/*
* TCNT3, TCCR3A,TCCR3B
* 분주비:8, -> CS32:0, CS31:1, CS30:0
* FAST PWM MODE 14번 사용 : WGM33 :1, WGM32 :1 , WGM31 :1, WGM30 :0, ICR1 : TOP
* OC3B PE4 출력으로 설정 -> COM3B1 :1, COM3B0 :0 (비반전모드)

*/

#include "servo.h"

void setDutyRate (uint16_t duty)
{
	DUTY_OCR = duty;
}

void servoRun(uint8_t degree)
{
	uint16_t degValue = 0;
	degValue= (uint16_t)(((degree/180.0) * 500 + 150)*8);
	//OCR3B = degValue;
	setDutyRate(degValue);
}

void servoInit()
{
	//분주비:8, -> CS32:0, CS31:1, CS30:0
	TCCR3B |= (0<<CS32) | (1<<CS31) | (0<<CS30);
	//FAST PWM MODE 14번 사용 : WGM33 :1, WGM32 :1 , WGM31 :1, WGM30 :0, ICR1 : TOP
	TCCR3B |= (1<<WGM33) | (1<<WGM32);
	TCCR3A |= (1<<WGM31) | (0<<WGM30);
	//OC3B PE4 출력으로 설정 -> COM3B1 :1, COM3B0 :0 (비반전모드)
	TCCR3A |= (1<<COM3B1);
	//PE4 출력설정
	DDRE = (1<<DDRE4);
	// TOP값 : ICR3
	ICR3 = 39999;
}
