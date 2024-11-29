#define F_CPU 8000000UL

#include"usart.h"

void USART_init( void )
{
	UCSRA = 0x00;
	UCSRB|= (1<<RXEN);                   // transmit_enable
	UCSRC|=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);

	UBRRH = 0x01;
	UBRRL = 0x03;                       //UBRRL=51 because we set baudrate=9600 bps
}


unsigned char USART_recieve(void)
{

   unsigned char data;
   while((UCSRA&(1<<RXC))==0x00);

   data=UDR;
   return(data);

}

void USART_transmit(unsigned char d)
{
	
	while((UCSRA&(1<<UDRE))==0x00);     //check UDRE is empty or not
	
	UDR=d;

}
