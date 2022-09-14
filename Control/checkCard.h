/*
 * checkCard.h
 *
 * Created: 2020-09-30 오후 5:13:33
 *  Author: rjsdn
 */ 


#ifndef CHECKCARD_H_
#define CHECKCARD_H_

#define NORMAL		2
#define CORRECT		1
#define INCORRECT	0


#include <avr/io.h>
#include <util/delay.h>
#include "../Device/utils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../Device/uart0.h"
#include "../Device/mfrc522.h"
#include "../Device/spi.h"
#include "../Device/I2C_LCD.h"

#include "stateController.h"


void checkCard();
void setCardState(uint8_t data);
uint8_t getCardState();
void checkCardInit();

#endif /* CHECKCARD_H_ */