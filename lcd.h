#define F_CPU 8000000UL

#include<avr/io.h>
#include<util/delay.h>


//       FUNCTION PROTOTYPE       


void LCD_init(void);
void LCD_data(unsigned char data);
void LCD_cmd(unsigned char cmd);
int LCD_busy(void);
void LCD_setpos(unsigned char row,unsigned char column);
void LCD_string(char *data);


//       MACROS


#define RS 0x04
#define ENBLE 0x08
#define LCD_DDR DDRB
#define LCD_PORT PORTB
#define LCD_PIN PINB

