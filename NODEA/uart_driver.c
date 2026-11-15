#include<lpc21xx.h>
#include"header.h"
void uart0_init(unsigned int baud)
{
int pclk, result=0;
int a[]={15,60,30,15,0};
pclk=a[VPBDIV]*1000000;
result=pclk/(16*baud);
PINSEL0|=0x5;
U0LCR=0x83;
U0DLL=(result&0xff);
U0DLM=(result>>8)&0xff;
U0LCR=0x03;
}
// Transmit 1 byte of Data
#define THRE ((U0LSR>>5)&1)
void uart0_tx(unsigned char data)
{
U0THR=data;
while(THRE==0);
}
// Receive 1 byte of Data
#define RDR (U0LSR&1)
unsigned char uart0_rx()
{
while(RDR==0);
return U0RBR;
}
// Uart0_tx_string() function
void uart0_tx_string(char *ptr)
{
while(*ptr!=0)
{
uart0_tx(*ptr);
ptr++;
}
}
// uart0_binary function
void uart0_binary(int num)
{
int pos, temp;
for(pos=7;pos>=0; pos--)
{
temp=(num>>pos&1);
uart0_tx(temp+48);
}
}
// Uart0_integer function
void uart0_integer(int num)
{
int a[10],i;
if(num==0)
{
uart0_tx('0');
}
if(num<0)
{
num=-num;
uart0_tx('-');
}
while(num>0)
{
a[i]=num%10+48;
num=num/10;
i++;
}
for(i=i-1;i>=0;i--)
{
uart0_tx(a[i]);
}
}
//Uart0_Rx_string Function
void uart0_rx_string(char *ptr, int len)
{
int i;
for(i=0;i<len;i++)// rotating loop
{
while(RDR==0);
ptr[i]=U0RBR;
if(ptr[i]=='\r')
break;
}
ptr[i]='\0';

}
