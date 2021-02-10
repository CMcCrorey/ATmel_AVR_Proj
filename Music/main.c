

#include <avr/io.h>
#include <stdlib.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <math.h>

#define MAXTIME .004096

void play_Music( double index);
char Music_KeypadC ();

int main(void)
{
    /* setting FAST PWM mode */
	TCCR0A |= (1 << WGM00) |(1<< WGM01) ;
	TCCR0B |= (1 << WGM02) ;	
		
	/*enable OC0A pin (pin D5)*/
	TCCR0A |=(1 << COM0B1);
	
	
			
	/* preset 256 4.096ms  */
	TCCR0B |= (1 << CS02);
		
    while (1) 
    {
	
	


		Music_KeypadC ();
	 	DDRD &= ~(1<< DDD5);
	  
	   
		
		
	}
}


char Music_KeypadC ()

{
	char x = 'F';
	
	DDRC |= ((1 << DDC0)|(1 << DDC1)|(1 << DDC2)|(1 << DDC3));
	PORTB |= ((1 << PORTB0)|(1 << PORTB1)|(1 << PORTB2)|(1 << PORTB3));
	
	
	for (int i =0; i< 4; i++)
	{
		
		
		PORTC |= ((1 << PORTC0)|(1 << PORTC1)|(1 << PORTC2)|(1 << PORTC3));
		PORTC &= ~(1 << i );
		
		
		switch (i)
		{
			case 0:
			if (!(PINB &= (1 << PINB0)))
			{
				x='1';
				
				play_Music(0);
				
				
			}
			else if (!(PINB &= (1 << PINB1)))
			{
				x ='2';
				
				play_Music(1);
			}
			
			else if (!(PINB &= (1 << PINB2)))
			{
				x ='3';
				play_Music(2);
			}
			else if (!(PINB &= (1 << PINB3)))
			{
				x='A';
				play_Music(3);
			}
			break;
			
			
			case 1:
			if (!(PINB &= (1 << PINB0)))
			{
				x='4';
				play_Music(4);
			}
			else if (!(PINB &= (1 << PINB1)))
			{
				x='5';
				play_Music(5);
			}
			
			else if (!(PINB &= (1 << PINB2)))
			{
				x='6';
				play_Music(6);
			}
			else if (!(PINB &= (1 << PINB3)))
			{
				x='B';
				play_Music(7);
			}
			break;
			
			case 2:
			if (!(PINB &= (1 << PINB0)))
			{
				x='7';
				play_Music(8);
			}
			else if (!(PINB &= (1 << PINB1)))
			{
				x='8';
				play_Music(9);
			}
			
			else if (!(PINB &= (1 << PINB2)))
			{
				x='9';
				play_Music(10);
			}
			else if (!(PINB &= (1 << PINB3)))
			{
				x='C';
				play_Music(11);
			}
			break;
			
			case 3:
			if (!(PINB &= (1 << PINB0)))
			{
				x='*';
				play_Music(12);
			}
			else if (!(PINB &= (1 << PINB1)))
			{
				x='0';
				play_Music(13);
			}
			
			else if (!(PINB &= (1 << PINB2)))
			{
				x='#';
				play_Music(14);
			}
			else if (!(PINB &= (1 << PINB3)))
			{
				x='D';
				play_Music(15);
			}
			break;		
			
		}
					
	}

	return x;
}



void play_Music(double index)
{
		DDRD |= (1<< DDD5);
		 double T_on;
		 T_on = 1/(440* (pow(2, index/12)));
		 
		 OCR0A = (256*(T_on/MAXTIME)-1);	
		 OCR0B = OCR0A/2;
		 	 		
}

