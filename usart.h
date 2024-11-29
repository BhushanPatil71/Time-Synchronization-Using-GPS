


#define F_CPU 8000000UL


#include<avr/io.h>
#include<util/delay.h>


//   function prototype 

void USART_init(void);
unsigned char USART_recieve(void);
void USART_transmit(unsigned char d);
