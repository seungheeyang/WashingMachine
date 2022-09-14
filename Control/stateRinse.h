/*
 * stateRinse.h
 *
 * Created: 2020-10-09 오후 6:47:19
 *  Author: kccistc
 */ 


#ifndef STATERINSE_H_
#define STATERINSE_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "../Device/DCmotor.h"
#include "../Device/servo.h"
#include "../timeTick.h"
#include "checkBtnCnt.h"
#include "manualMode.h"
#include "stateController.h"

#define LED_DDR			DDRA
#define LED_PORT		PORTA
#define IN_LED_PIN		3
#define OUT_LED_PIN		2	

void rinsing();
void rinsingPross();


#endif /* STATERINSE_H_ */