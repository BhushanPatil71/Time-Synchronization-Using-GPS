#define F_CPU 8000000UL

#include"lcd.h"


   
void LCD_init(void)
{
	
	LCD_cmd(0x20);  
	_delay_ms(1);
	LCD_cmd(0x28);  // 4-bit data
	_delay_ms(1);
	LCD_cmd(0x08);  // display off
	_delay_ms(1);
	LCD_cmd(0x01);  // clear LCD display 
	_delay_ms(1);
	LCD_cmd(0x02);  // home 
	_delay_ms(1);
	LCD_cmd(0x06);  // entry mode 
	_delay_ms(1);
	LCD_cmd(0x0c);  // display on 
	_delay_ms(1);

}

void LCD_data(unsigned char data)
{
	while(LCD_busy());

	LCD_PORT=(data & 0xF0)|RS;
	LCD_PORT=(data & 0xF0)|RS|ENBLE;
	LCD_PORT=(data & 0xF0)|RS;
	LCD_PORT=(data & 0xF0);

	LCD_PORT=((data<<4) & 0xF0)|RS;
	LCD_PORT=((data<<4) & 0xF0)|RS|ENBLE;
	LCD_PORT=((data<<4) & 0xF0)|RS;
	LCD_PORT=((data<<4) & 0xF0);

	LCD_PORT=0x00;
	_delay_ms(10);

}

void LCD_cmd(unsigned char cmd)
{
	while(LCD_busy());

	LCD_PORT=(cmd & 0xF0);
	LCD_PORT=(cmd & 0xF0)|ENBLE;
	LCD_PORT=(cmd & 0xF0);

	LCD_PORT=((cmd<<4) & 0xF0);
	LCD_PORT=((cmd<<4) & 0xF0)|ENBLE;
	LCD_PORT=((cmd<<4) & 0xF0);

	LCD_PORT=0x00;
	_delay_ms(10);

}

int LCD_busy(void)
{
	unsigned char input;
	LCD_DDR=0x00;    // i/p port
	input=LCD_PIN;
	LCD_DDR=0xFF;    // o/p port
	LCD_PORT=0x00;

	return(0x80==(input&0x80));

}


void LCD_setpos(unsigned char row,unsigned char column)
{
	
	switch(row)
	{
	  
	   case 1:
	   		LCD_cmd(0x80+column-1);
			break;

	   case 2:
	   		LCD_cmd(0xc0+column-1);
			break;

       default :
			break;

     }
}

void LCD_string(char *data)
{

    while(*data!='\0')
 
    LCD_data(*data++);
}

