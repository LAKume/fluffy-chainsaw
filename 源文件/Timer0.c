#include <REGX52.H>

/**
  * @brief 定时器0初始化，1毫秒@12.000MHz
  * @param 无
  * @retval 无
  */
void Timer0Init(void)		
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0=1;			//定时器/计数器0中断允许位，打开T0中断
	EA=1;			//打开中断开关
	PT0=0;   //配置中断优先级

}

/*定时器中断模板
void Timer0Routine() interrupt 1
{
	static unsigned int T0Count;		//static可将其设置为静态变量
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;
		P2_2=~P2_2;
	}

}*/
