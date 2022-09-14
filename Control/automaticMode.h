/*
 * automatic.h
 *
 * Created: 2020-10-11 오후 8:00:41
 *  Author: rjsdn
 */ 


#ifndef AUTOMATIC_H_
#define AUTOMATIC_H_

#include <avr/io.h>

#include "../Device/button.h"
#include "stateController.h"
#include "checkBtnCnt.h"
#include "selectMode.h"
#include "../Device/I2C_LCD.h"

void atuomaticMode();

#endif /* AUTOMATIC_H_ */