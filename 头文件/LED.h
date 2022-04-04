#ifndef __LED_H__
#define __LED_H__

#include"rtx51tny.h"
#include <REGX51.H>
#include "Delay.h"

sbit led1=P2^0;
sbit led2=P2^1;

void LED_Run(void);
void LED_Init(void);

#endif