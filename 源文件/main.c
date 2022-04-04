#include"rtx51tny.h"
#include <REGX51.H>
#include "Delay.h"
#include "LED.h"
#include "Timer0.h"

#define Beep=P3^4;
int Sec,Min,Hour;				//定义秒，分，时
unsigned char Table[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void Nixie(unsigned char Location,number)		//数码管
{
	switch(Location)
	{
		case 1:P1_4=1;P1_3=1;P1_2=1;break;
		case 2:P1_4=1;P1_3=1;P1_2=0;break;
		case 3:P1_4=1;P1_3=0;P1_2=1;break;
		case 4:P1_4=1;P1_3=0;P1_2=0;break;
		case 5:P1_4=0;P1_3=1;P1_2=1;break;
		case 6:P1_4=0;P1_3=1;P1_2=0;break;
		case 7:P1_4=0;P1_3=0;P1_2=1;break;
		case 8:P1_4=0;P1_3=0;P1_2=0;break;
	}
	P0=Table[number];
	Delay(1);
	P0=0x00;
}
//数码管没调好


void main(void)
{
	while(1)
	{
		Timer0Init();
		LED_Init();
		LED_Run();
		if(P3^7==0)	
		{
			Delay(20);
			while(P3^7==0);
			Delay(20);
			Beep=~Beep;
		}		
		Nixie(1,Sec);
		Nixie(3,Min);
		Nixie(5,Hour);
	}
}


void Timer0Routine() interrupt 1		//定时器中断
{
	
	static unsigned int T0Count;		//static可将其设置为静态变量
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;
		Sec++;
		if(Sec>=60)
		{
			Sec=0;
			Min++;
			if(Min>=60)
			{
				Min=0;
				Hour++;
				if(Hour>=24)
				{
					Hour=0;
				}

			}
		}
	}
}
