#include "stm32f10x.h"
#include "stm32f10x_flash.h"

int main()
{
	NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x0);
	FLASH_Unlock();
	FLASH_ReadOutProtection(DISABLE);
	return 0;
}
