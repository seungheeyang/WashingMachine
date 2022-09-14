﻿/*
 * uart0.h
 *
 * Created: 2020-01-09 오전 11:02:25
 *  Author: kccistc
 */ 

#ifndef UART0_H_
#define UART0_H_
void UART0_Init();
void UART0_transmit(char data);
unsigned char UART0_receive(void);
void UART0_printf_string(char *str);
void UART0_print_1_byte_number(uint8_t n);
uint8_t isRxD();
uint8_t isRxString();     // Add DHT11
uint8_t* getRxString();   // Add DHT11
void UART0_ISR_Receive(); // Add DHT11
#endif /* UART0_H_ */