/*
* checkCard.c
*
* Created: 2020-09-30 오후 5:13:21
*  Author: rjsdn
*/

#include "checkCard.h"

uint8_t byte;
uint8_t str[16];
uint8_t recCard[2][5] =
{
	{0x49, 0xb0, 0xb8, 0xb8, 0xf9 },
	{0x04, 0xc7, 0xb5, 0x2b, 0x5d }
};

uint8_t cardState = INITIAL;

void setCardState(uint8_t data)
{
	cardState = data;
}

uint8_t getCardState()
{
	return cardState;
}

void checkCardInit()
{
	spi_init();
	mfrc522_init();
}

void checkCard()
{
	
	byte = mfrc522_request(PICC_REQALL, str);
	uint8_t cardFlag=0;
	
	if (byte == CARD_FOUND)
	{
		byte = mfrc522_get_card_serial(str);	// 카드 번호 read
		
		for (int i=0; i<2; i++)
		{
			if ( strncmp(str, recCard[i], 5) == 0)	//str 배열, recCard 이중배열, 주소랑 5비트 비교
			{
				setCardState(VALID);
				cardFlag = CARD_FOUND;
				break;
			}
			cardFlag = CARD_NOT_FOUND;
		}
		
		if (cardFlag == CARD_NOT_FOUND)
		{
			setCardState(INVALID);
		}

		_delay_ms(200);
	}
}