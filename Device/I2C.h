/*
 * I2C.h
 *
 * Created: 2020-09-22 오후 2:41:14
 *  Author: kccistc
 */ 


#ifndef I2C_H_
#define I2C_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SLA		0X27
#define  WRITE	0
#define READ	1
#define SLA_W	(SLA<<1 | WRITE)
#define  SLA_R	(SLA<<1 | READ)

void I2C_Init();
void I2C_Start();
void I2C_Stop();
void I2C_TxByte(uint8_t addr_W,uint8_t data);
void I2C_TxData(uint8_t data);
void I2C_TxBuffer(uint8_t devceAddr, uint8_t memoryAddr, uint8_t *data, uint8_t length);
void I2C_RxBuffer(uint8_t deviceAddr, uint8_t memoryAddr, uint8_t *data, uint8_t length);
void I2C_RxAck(uint8_t *data);
void I2C_RxNack(uint8_t *data);

#endif /* I2C_H_ */