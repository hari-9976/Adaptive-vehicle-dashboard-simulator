#include"header.h"
void adc_init(void){
PINSEL1|=0x15400000;
ADCR=0x00200400;
}

u32 adc_read(u32 channel){
ADCR|=1<<channel;
ADCR|=1<<24;
while(((ADDR>>31)&1)==0);
ADCR^=1<<24;
ADCR^=1<<channel;
return ((ADDR>>6)&0X3ff);
}


