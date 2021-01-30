#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "beep.h"
#include "pwm.h"
 
void hardware_Init()
{
	LED_Init();		  		//��ʼ����LED���ӵ�Ӳ���ӿ�
	BEEP_Init();         	//��ʼ���������˿�
	KEY_Init();         	//��ʼ���밴�����ӵ�Ӳ���ӿ�
	TIM3_PWM_Init(199, 7199); //(7200*200)/72000000=0.02=20ms  ��ӳ�䵽PB5
}

void software_Init()
{
	delay_init();	    	 //��ʱ������ʼ��	  
}
 
int main(void)
{
 	vu8 key=0;

	hardware_Init();
	software_Init();
	
	LED0=0;					//�ȵ������
	while(1)
	{
 		key=KEY_Scan(0);	//�õ���ֵ
	  if(key)
		{						   
			switch(key)
			{				 
				case WKUP_PRES:	
					TIM_SetCompare2(TIM3, 190); //45��,1ms
					delay_ms(2000);
					break; 
				case KEY1_PRES:	
					TIM_SetCompare2(TIM3, 185); //90��,1.5ms
					delay_ms(2000);
					break;
				case KEY0_PRES:	
					TIM_SetCompare2(TIM3, 180); //135��,2ms
					delay_ms(2000);
					break;
			}
		}else delay_ms(10); 
	}	 
}
