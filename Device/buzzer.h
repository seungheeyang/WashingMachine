/*
 * buzzer.h
 *
 * Created: 2020-09-15 오후 5:35:02
 *  Author: kccistc
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

#define F_CPU  16000000UL	//정확한 주파수
#include <avr/io.h>
#include <util/delay.h>		//딜레이함수사용

void buzzerInit();
void setBuzzer(int note);
void playBuzzer(void);
void noBuzzer(void);
void powerONbuzzer(void);


#endif /* BUZZER_H_ */