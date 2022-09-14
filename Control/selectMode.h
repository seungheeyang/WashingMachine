/*
 * modeSelect.h
 *
 * Created: 2020-10-11 오후 6:27:25
 *  Author: rjsdn
 */ 


#ifndef MODESELECT_H_
#define MODESELECT_H_


#define USUAL		0
#define AUTOMATIC	1
#define MANUAL		2
#define MOVE		3
#define PAUSE		4

#include <avr/io.h>
#include <stdio.h>
#include "../Device/button.h"
#include "../Device/I2C_LCD.h"

void selectModeState();
uint8_t getSelectMode();
void setSelectMode(uint8_t data);
void usualMode();
//void pause();

#endif /* MODESELECT_H_ */