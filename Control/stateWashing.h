/*
 * stateWashing.h
 *
 * Created: 2020-10-09 오후 5:13:26
 *  Author: kccistc
 */ 


#ifndef STATEWASHING_H_
#define STATEWASHING_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "../Device/DCmotor.h"
#include "../Device/servo.h"
#include "../timeTick.h"
#include "checkBtnCnt.h"
#include "manualMode.h"
#include "stateController.h"

void washing();
void washingPross();
void washingEvent();

#endif /* STATEWASHING_H_ */