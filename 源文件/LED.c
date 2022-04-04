#include "LED.h"

void LED_Init(void)
{
	P2=0;
}

void LED_Run(void)
{
	int i=0;
	while(1)
	{
		P2=0xFE;
		Delay(500);
		P2=0xFC;
		Delay(500);
		P2=0xF8;
		Delay(500);
		P2=0xF0;
		Delay(500);
		P2=0xE0;
		Delay(500);
		P2=0xC0;
		Delay(500);
		P2=0x80;
		Delay(500);
		P2=0x00;
		Delay(500);
	}
}