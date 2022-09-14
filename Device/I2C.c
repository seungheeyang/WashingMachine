/*
* I2C.c
*
* Created: 2020-09-22 오후 2:41:06
*  Author: kccistc
*/

#include "I2C.h"



void I2C_Init()
{
	DDRD |= (1<<DDRD0) | (1<<DDRD1);
	TWBR = 72; //100kHz, 32:200kHz, 12:400kHz,
}

void I2C_Start()
{
	//TWINT를 1로 쓰면 해당 레지스터의 비트는 0이 된다 ( (1<<TWINT)  => 1이 아니라 0이라는 소리 ,, )
	// TWINT: ACK를 받을 수 있음(동작완료), TWSTA:START(마스터 모드에서 전송을 시작하기위해 세트), TWEN:ENABLE (TWI 활성화)
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT))); //0이 아닌값이 되면 빠져나옴
}

void I2C_Stop()
{
	TWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);
}

void I2C_TxData(uint8_t data)
{
	TWDR = data;		// TWDR: 데이터 레지스터
	TWCR = (1<<TWINT) | (1<<TWEN);
	//uint16_t count=0;
	while (! (TWCR & (1<<TWINT)));	//ACK를 받으면 1이 되면서 빠져나옴
	/*{
	count ++;
	if (count>60000)
	{
	return;
	}
	}*/
}

void I2C_TxByte(uint8_t addr_W,uint8_t data)
{
	//start bit 전송
	I2C_Start();
	//SLA 주소(7비트) 전송 + write(1비트) Mode
	I2C_TxData(addr_W); 	/*ACk 수신		SLA+WRITE => PCF8574 : SLA0X27 + R/W	SLA_W : SLA<<1 + W
	SLA_R : SLA<<1 + W	*/
	//1 byte 전송시도 (못 도착함)
	I2C_TxData(data);	////ack 수신
	//stop bit 송신
	I2C_Stop();
}

void I2C_TxBuffer(uint8_t devceAddr, uint8_t memoryAddr, uint8_t *data, uint8_t length)
{
	//1. start bit 송신
	I2C_Start();
	//2. SLA+Write 송신, Ack 수신
	I2C_TxData((devceAddr<<1) | WRITE);
	//3. write 하는 memory주소 송신, ack수신
	I2C_TxData(memoryAddr);
	//4. data 송신, ack 수신
	//5. data 송신, ack 수신
	for (uint8_t i=0; i<length; i++)
	{
		I2C_TxData(data[i]);
	}
	//6. stop bit 송신
	I2C_Stop();
}

void I2C_RxBuffer(uint8_t deviceAddr, uint8_t memoryAddr, uint8_t *data, uint8_t length)
{
	//1.start bit 송신
	I2C_Start();
	
	//2. SLA+Write 송신, ack수신
	I2C_TxData((deviceAddr<<1) | WRITE);
	
	//3. read 하는 memory 주소 송신, ack수신
	I2C_TxData(memoryAddr);
	
	//4. repeat start bit 송신
	I2C_Start();
	
	//5.SLA+READ 송신, ACK수신
	I2C_TxData((deviceAddr<<1) | READ);
	
	//6. DATA수신, ACK송신
	//7. DATA수신, ACK송신
	//8. DATA수신, NACK
	for (uint8_t i=0; i<length; i++)
	{
		if (i<length-1)
		{
			I2C_RxAck(&data[i]);	//6.7. DATA수신, ACK송신
		}
		else
		{
			I2C_RxNack(&data[i]);	//8. DATA수신, Nack
		}
	}
	//9. stop bit 송신
	I2C_Stop();
}

void I2C_RxAck(uint8_t *data)
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while (!(TWCR & (1<<TWINT)));
	*data = TWDR;
}

void I2C_RxNack(uint8_t *data)
{
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	*data = TWDR;
}
