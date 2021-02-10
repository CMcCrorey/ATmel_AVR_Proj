/*
 * Lab6Music.c
 *
 * Created: 10/15/2019 11:28:19 AM
 * Author : Cameron
 */ 

#include <avr/io.h>
#include <stdlib.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <math.h>
#define ON  PORTC |= (1 << PORTC5)
#define OFF PORTC &= ~(1 << PORTC5)

#define MAXTIME .016        //0.016 ms or 16us no prescale

//void key1();
char Scan_KeypadC ();


int main(void)
{
		/* setting FAST PWM mode */
		TCCR0A |= (1 << WGM00) |(1<< WGM01) ;
		TCCR0B |= (1 << WGM02) ;
		
		/*enable OC0A pin (pin D6)*/
		TCCR0A |=(1 << COM0A1);
		
		
		/* preset 256 4.096ms  */
		//TCCR0B |= (1 << CS02);
		
	
	long double T_on;
	DDRC |= (1 << DDC5);
	DDRD |= (1<< DDD6);
	

    /* Replace with your application code */
    while (1) 
    {
		char y=  Scan_KeypadC ();
		
	
		
		switch (y)
		{
			case '1': 
				
			
		 T_on = 1/(440* (pow(2,0/12)));  // .0027 ms or 2.27us
		 
		 OCR0A = 256*(T_on/MAXTIME)-1;
		 OCR0B = OCR0A/2;
		 
	//
	//ON;
	//while ( (TIFR0 & (1 << OCF0B) ) == 0){} // wait for OCR0B overflow event
	//TIFR0 |= (1 << OCF0B);
	//
//
	//OFF;
	//while ( (TIFR0 & (1 << OCF0A) ) == 0){} // wait for OCR0A overflow event
	//TIFR0 |= (1 << OCF0A);
	
	
	
		 
		 //
		//ON;
		//_delay_ms(T_on);
		//OFF;
		//_delay_ms(T_on);
			
			break;
			
			case '2': 
			
			
		 T_on = 1/(440* (pow(2,1/12)));
		 
		 
		 	 
		 	 OCR0A = 256*(T_on/MAXTIME)-1;
		 	 OCR0B = OCR0A/2;
		 	 
		 	 
		 	 ON;
		 	 while ( (TIFR0 & (1 << OCF0B) ) == 0){} // wait for OCR0B overflow event
		 	 TIFR0 |= (1 << OCF0B);
		 	 

		 	 OFF;
		 	 while ( (TIFR0 & (1 << OCF0A) ) == 0){} // wait for OCR0A overflow event
		 	 TIFR0 |= (1 << OCF0A);
		//ON;
		//_delay_ms(T_on);
		 //OFF;
		//_delay_ms(T_on);
		
		
		
		
			 break;
			 
		case '3':
		T_on = 1/(440* (pow(2,2/12)));
		ON;
		_delay_ms(T_on);
		OFF;
		_delay_ms(T_on);
		break;	
		
				case 'A':
				T_on = 1/(440* (pow(2,3/12)));
				ON;
				_delay_ms(T_on);
				OFF;
				_delay_ms(T_on);
				break;
				
				
				case '4':
				T_on = 1/(440* (pow(2,4/12)));
				ON;
				_delay_ms(T_on);
				OFF;
				_delay_ms(T_on);
				break;
				
				
			case '5':
			T_on = 1/(440* (pow(2,5/12)));
			ON;
			_delay_ms(T_on);
			OFF;
			_delay_ms(T_on);
			break;
			
			case '6':
			T_on = 1/(440* (pow(2,6/12)));
			ON;
			_delay_ms(T_on);
			OFF;
			_delay_ms(T_on);
			break;
			
			
			case 'B':
			T_on = 1/(440* (pow(2,7/12)));
			ON;
			_delay_ms(T_on);
			OFF;
			_delay_ms(T_on);
			break;
			
			case '7':
			T_on = 1/(440* (pow(2,8/12)));
			ON;
			_delay_ms(T_on);
			OFF;
			_delay_ms(T_on);
			break;
		
		
		case '8':
		T_on = 1/(440* (pow(2,9/12)));
		ON;
		_delay_ms(T_on);
		OFF;
		_delay_ms(T_on);
		break;
		
		
			case '9':
			T_on = 1/(440* (pow(2,10/12)));
			ON;
			_delay_ms(T_on);
			OFF;
			_delay_ms(T_on);
			break;
			
			
			case 'C':
			T_on = 1/(440* (pow(2,11/12)));
			ON;
			_delay_ms(T_on);
			OFF;
			_delay_ms(T_on);
			break;
			
			
			case '*':
			T_on = 1/(440* (pow(2,12/12)));
			ON;
			_delay_ms(T_on);
			OFF;
			_delay_ms(T_on);
			break;
			
			
			case '0':
			T_on = 1/(440* (pow(2,13/12)));
			ON;
			_delay_ms(T_on);
			OFF;
			_delay_ms(T_on);
			break;
			
			
			
			case '#':
			T_on = 1/(440* (pow(2,14/12)));
			ON;
			_delay_ms(T_on);
			OFF;
			_delay_ms(T_on);
			break;
			
			
			case 'D':
			T_on = 1/(440* (pow(2,15/12)));
			ON;
			_delay_ms(T_on);
			OFF;
			_delay_ms(T_on);
			break;
				
				
			
			
				
				
				
				
				
				 
			
			
		}
		
    }
}





char Scan_Keypad ()

{
	char x = 'F';
	//
	//DDRD |= ((1 << DDD4)|(1 << DDD5)|(1 << DDD6)|(1 << DDD7));  //set b 4-7 as output
      DDRC |= ((1 << DDC0)|(1 << DDC1)|(1 << DDC2)|(1 << DDC3));
	PORTB |= ((1 << PORTB0)|(1 << PORTB1)|(1 << PORTB2)|(1 << PORTB3));
	
	
	for (int i =0; i< 4; i++)
	{
		//PORTD |= ((1 << PORTD4)|(1 << PORTD5)|(1 << PORTD6)|(1 << PORTD7));
		//PORTD &= ~(1 << i );
		
		PORTC |= ((1 << PORTC0)|(1 << PORTC1)|(1 << PORTC2)|(1 << PORTC3));
		PORTC &= ~(1 << i );
		
		
		switch (i)
		{
			case 4:
			if (!(PINB &= (1 << PINB0)))
			{
				x='1';
			}
			else if (!(PINB &= (1 << PINB1)))
			{
				x ='2';
			}
			
			else if (!(PINB &= (1 << PINB2)))
			{
				x ='3';
			}
			else if (!(PINB &= (1 << PINB3)))
			{
				x='A';
			}
			break;
			
			
			case 5:
			if (!(PINB &= (1 << PINB0)))
			{
				x='4';
			}
			else if (!(PINB &= (1 << PINB1)))
			{
				x='5';
			}
			
			else if (!(PINB &= (1 << PINB2)))
			{
				x='6';
			}
			else if (!(PINB &= (1 << PINB3)))
			{
				x='B';
			}
			break;
			
			case 6:
			if (!(PINB &= (1 << PINB0)))
			{
				x='7';
			}
			else if (!(PINB &= (1 << PINB1)))
			{
				x='8';
			}
			
			else if (!(PINB &= (1 << PINB2)))
			{
				x='9';
			}
			else if (!(PINB &= (1 << PINB3)))
			{
				x='C';
			}
			break;
			
			case 7:
			if (!(PINB &= (1 << PINB0)))
			{
				x='*';
			}
			else if (!(PINB &= (1 << PINB1)))
			{
				x='0';
			}
			
			else if (!(PINB &= (1 << PINB2)))
			{
				x='#';
			}
			else if (!(PINB &= (1 << PINB3)))
			{
				x='D';
			}
			break;
			
			
			
			
			
		}
		
		
		
	}

	return x;
}



char Scan_KeypadC ()

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
			}
			else if (!(PINB &= (1 << PINB1)))
			{
				x ='2';
			}
			
			else if (!(PINB &= (1 << PINB2)))
			{
				x ='3';
			}
			else if (!(PINB &= (1 << PINB3)))
			{
				x='A';
			}
			break;
			
			
			case 1:
			if (!(PINB &= (1 << PINB0)))
			{
				x='4';
			}
			else if (!(PINB &= (1 << PINB1)))
			{
				x='5';
			}
			
			else if (!(PINB &= (1 << PINB2)))
			{
				x='6';
			}
			else if (!(PINB &= (1 << PINB3)))
			{
				x='B';
			}
			break;
			
			case 2:
			if (!(PINB &= (1 << PINB0)))
			{
				x='7';
			}
			else if (!(PINB &= (1 << PINB1)))
			{
				x='8';
			}
			
			else if (!(PINB &= (1 << PINB2)))
			{
				x='9';
			}
			else if (!(PINB &= (1 << PINB3)))
			{
				x='C';
			}
			break;
			
			case 3:
			if (!(PINB &= (1 << PINB0)))
			{
				x='*';
			}
			else if (!(PINB &= (1 << PINB1)))
			{
				x='0';
			}
			
			else if (!(PINB &= (1 << PINB2)))
			{
				x='#';
			}
			else if (!(PINB &= (1 << PINB3)))
			{
				x='D';
			}
			break;
			
			
			
			
			
		}
		
		
		
	}

	return x;
}












//void Cal_Period(int index)
//{
		//
	//
	//double  T_on = 1/(440* (pow(2,index/12)));
//
//}