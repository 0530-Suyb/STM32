#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "beep.h"
#include "pwm.h"
 
void hardware_Init()
{
	LED_Init();		  		//初始化与LED连接的硬件接口
	BEEP_Init();         	//初始化蜂鸣器端口
	KEY_Init();         	//初始化与按键连接的硬件接口
	TIM3_PWM_Init(199, 7199); //(7200*200)/72000000=0.02=20ms  重映射到PB5
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
				case WKUP_PRES:	
					TIM_SetCompare2(TIM3, 190); //45度,1ms
					delay_ms(2000);
					break; 
				case KEY1_PRES:	
					TIM_SetCompare2(TIM3, 185); //90度,1.5ms
					delay_ms(2000);
					break;
				case KEY0_PRES:	
					TIM_SetCompare2(TIM3, 180); //135度,2ms
					delay_ms(2000);
					break;
			}
		}else delay_ms(10); 
	}	 
}
