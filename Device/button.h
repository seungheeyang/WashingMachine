/*
 * button.h
 *
 * Created: 2020-09-25 오전 9:58:13
 *  Author: kccistc
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


#define PUSHED		0
#define RELEASED	1

#define BUTTON_DDR		DDRF
#define BUTTON_PIN		PINF
#define BUTTON1			0
#define BUTTON2			1
#define BUTTON3			2
#define BUTTON4			3
#define BUTTON5			4
#define BUTTON_RESET	5
#define BUTTON_PAUSE	6

void buttonInit();
uint8_t readButton(uint8_t button);
uint8_t getButton1State();
uint8_t getButton2State();
uint8_t getButton3State();
uint8_t getButton4State();
uint8_t getButton5State();
uint8_t getButtonReset();
uint8_t getButtonPause();


#endif /* BUTTON_H_ */