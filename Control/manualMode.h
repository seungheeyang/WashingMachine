/*
 * manual.h
 *
 * Created: 2020-10-11 오후 8:01:11
 *  Author: rjsdn
 */ 


#ifndef MANUAL_H_
#define MANUAL_H_

#include <avr/io.h>

#include "../Device/button.h"
#include "stateController.h"
#include "checkBtnCnt.h"
#include "selectMode.h"
#include "../Device/I2C_LCD.h"

void manualMode();
uint8_t getBtn3cnt();
void setBtn3cnt(uint8_t data);
uint8_t getBtn4cnt();
void setBtn4cnt(uint8_t data);
uint8_t getBtn5cnt();
void setBtn5cnt(uint8_t data);

#endif /* MANUAL_H_ */