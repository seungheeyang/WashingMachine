/*
 * stateController.h
 *
 * Created: 2020-10-09 오후 4:48:33
 *  Author: kccistc
 */ 


#ifndef STATECONTROLLER_H_
#define STATECONTROLLER_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include "stateWashing.h"
#include "stateRinse.h"
#include "stateSpinDry.h"
#include "stateCommon.h"
#include "../Device/I2C_LCD.h"
#include "../timeTick.h"
#include "checkBtnCnt.h"
#include "selectMode.h"
#include "manualMode.h"
#include "../device/button.h"

#define COMMON		1
#define WASH		2
#define RINSE		3
#define SPINDRY		4
#define FINISH		5
//#define RESET		6

uint8_t getStateExcute();
void setStateExcute(uint8_t data);
void stateExcute();
void finish();
void pause();

#endif /* STATECONTROLLER_H_ */