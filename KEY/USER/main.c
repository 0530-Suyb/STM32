#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "beep.h"
 
void hardware_Init()
{
	LED_Init();		  		//初始化与LED连接的硬件接口
	BEEP_Init();         	//初始化蜂鸣器端口
	KEY_Init();         	//初始化与按键连接的硬件接口
}

void software_Init()
{
	delay_init();	    	 //延时函数初始化	  
}
 
int main(void)
{
 	vu8 key=0;

	hardware_Init();
	software_Init();
	
	LED0=0;					//先点亮红灯
	while(1)
	{
 		key=KEY_Scan(0);	//得到键值
	  if(key)
		{						   
			switch(key)
			{				 
				case WKUP_PRES:	//控制蜂鸣器
					BEEP=!BEEP;
					break; 
				case KEY1_PRES:	//控制LED1翻转	 
					LED1=!LED1;
					break;
				case KEY0_PRES:	//同时控制LED0,LED1翻转 
					LED0=!LED0;
					LED1=!LED1;
					break;
			}
		}else delay_ms(10); 
	}	 
}
