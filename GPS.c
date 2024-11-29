#define F_CPU 8000000UL

#include<avr/io.h>
#include<util/delay.h>

#include"lcd.h"
#include"usart.h"

//unsigned char temp[]="$GPGGA,101229.487,3723.2475,N,12158.3416,W,1,07,1.0,9.0,M, , , ,0000*3E";
unsigned char temp,lat[15],lon[15],lat_dir,lon_dir,i;


int main(void)
{
	LCD_init();
	USART_init();
	while(1)
	{

	   	  
		temp=USART_recieve();
		if(temp=='$')
		{
			temp=USART_recieve();
			if(temp=='G')
			{
				temp=USART_recieve();
				if(temp=='P')
				{
					temp=USART_recieve();
					if(temp=='G')
					{
						temp=USART_recieve();
						if(temp=='G')
						{
							temp=USART_recieve();
							if(temp=='A')
							{
                                temp=USART_recieve();
								if(temp==',')
								{
									for(i=0;temp!=',';i++)                                  
									{
										lat[i]=USART_recieve();
										temp=lat[i];
									}
									lat_dir=USART_recieve();
									if(temp==',')
									{

										for(i=0;temp!=',';i++)                                  
										{
											lon[i]=USART_recieve();
											temp=lat[i];
										}
										lon_dir=USART_recieve();
										
										LCD_cmd(0x01);										
										_delay_ms(10);
										LCD_cmd(0x80);
										_delay_ms(10);	
										
										for(i=0;i!='\0';i++)
										{
											LCD_data(lat[i]);
										}
											  												
										LCD_data(lat_dir);
										_delay_ms(10);
										LCD_cmd(0xc0);
										_delay_ms(10);
										for(i=0;i!='\0';i++)
										{
											LCD_data(lon[i]);
										}
										LCD_data(lon_dir);
										_delay_ms(10);
									}
								
								}
							}
						}
					}
				}
			}
		}
	}
}

