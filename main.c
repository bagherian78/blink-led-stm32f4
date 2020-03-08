#include "stm32f4xx.h"                  // Device header
int main(){															// start int main
	uint32_t * p;
	p=(uint32_t *)0x40023830;							// Memory address rcc + AHB1ENR
	*p=0x08;															// enable rcc
	p=(uint32_t *)0x40020c00;							// memory address GPIOD
	*p=1<<24|1<<26|1<<28|1<<30;						// GPIOD set MODER REGISTER
	while(1){
		p=(uint32_t *)0x40020c14;						//GPIOD->ODR
		*p=1<<12|1<<13|1<<14|1<<15;					//WRITE 1 on 12,13,14,15 GPIOD
		for(int i=0;i<=3000000;i++){				//create delay
		}
		*p=0<<12|0<<13|0<<14|0<<15;					//WRITE 0 on 12,13,14,15 GPIOD
		for(int i=0;i<=3000000;i++){				//create delay
		}
	}
}																				//end of main