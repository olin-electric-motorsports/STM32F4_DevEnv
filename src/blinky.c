#include <stdio.h>
#include <stdlib.h>
#define RCCAHB1ENR *(unsigned int*)(0x40023800 + 0x30)
#define GPIOD_MODER *(unsigned int*)(0x40020C00+0x00)
#define GPIOD_ODR   *(unsigned int*)(0x40020C00+0x14)

void delay(uint32_t ns)
{
	/* simple delay loop */
	while (ns--) {
		asm volatile ("nop");
	}
}

int main(void){
  /* Enable GPIOD EN bit on RCCAHB1 peripheral clock register */
  RCCAHB1ENR |= (1<<3);

  /* Set PD12, 13, 14, 15 to output by setting the bits in GPIOD_MODER */
  GPIOD_MODER |= (1 << 2*12);
  GPIOD_MODER |= (1 << 2*13);
  GPIOD_MODER |= (1 << 2*14);
  GPIOD_MODER |= (1 << 2*15);

  while(1){
    GPIOD_ODR |=(1<<12);
    delay(0xFFFFF);
    //for(unsigned long i=0; i<=0x3FFFFF; i++);
    GPIOD_ODR &=~(1<<12);
    delay(0xFFFFF);
    //for(unsigned long i=0; i<=0x3FFFFF; i++);
    GPIOD_ODR |=(1<<13);
    delay(0xFFFFF);
    //for(unsigned long i=0; i<=0x3FFFFF; i++);
    GPIOD_ODR &=~(1<<13);
    delay(0xFFFFF);
    //for(unsigned long i=0; i<=0x3FFFFF; i++);
    GPIOD_ODR |=(1<<14);
    delay(0xFFFFF);
    //for(unsigned long i=0; i<=0x3FFFFF; i++);
    GPIOD_ODR &=~(1<<14);
    delay(0xFFFFF);
    //for(unsigned long i=0; i<=0x3FFFFF; i++);
  }

  return 0;

}

