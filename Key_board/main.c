/*
 * Keyboard2.c
 *
 * Created: 9/26/2019 9:03:27 PM
 * Author : Cameron
 */ 

#include <avr/io.h>
#include <stdlib.h>


#define F_CPU 16000000UL  // 16MHz clock from the debug processor
#include <util/delay.h>
#define BAUD 9600           //defining baud
#define MYUBRR  F_CPU/16/BAUD -1

void USART_Transmit( unsigned char Data );

void UART_Initialize();
char Scan_KeypadC ();
char ToggleUserButton ();

int main(void)
{
	UART_Initialize();
	char y;
	//char x;
	
    /* Replace with your application code */
    while (1) 
    {
	
		y=  Scan_KeypadC ();
	//	x= ToggleUserButton ();
	//	_delay_ms(1000);
	//    USART_Transmit( x);
		
		if ( y == 'F')
		{			
			
			
		}
		else 
		{
			_delay_ms(50);
			USART_Transmit(y);
		}
		
		
		
    }
}


char Scan_Keypad ()

{
	char x = 'F';
	
		DDRD |= ((1 << DDD4)|(1 << DDD5)|(1 << DDD6)|(1 << DDD7));  //set b 4-7 as output

		PORTB |= ((1 << PORTB0)|(1 << PORTB1)|(1 << PORTB2)|(1 << PORTB3));
	
	
	for (int i =4; i< 8; i++)
	{
		PORTD |= ((1 << PORTD4)|(1 << PORTD5)|(1 << PORTD6)|(1 << PORTD7));
		PORTD &= ~(1 << i );
		
		
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





void UART_Initialize()
{
	UBRR0H = ((MYUBRR) >> 8);                                //initialize Baude rate and store in registers
	UBRR0L = MYUBRR;
	
	UCSR0B |= (1 <<  TXEN0) | (1 << RXEN0);                               // turn on trans and receiver
	UCSR0C |= (1 <<  UCSZ00) | (1 << UCSZ01);                           // 8 bit data enable
	UCSR0C &= ~(1 << USBS0);                                      // one bit stop
	//UCSR0C &= ~( (1 << UMSEL00)| (1<< UMSEL01) )               //set asych mode
	
	
}




void USART_Transmit( unsigned char Data )
{
	
	while ( !( UCSR0A & (1<<UDRE0)) );     // wait for empty buffer
	UDR0 = Data;                          // send data to buffer does character at a time
}



char ToggleUserButton ()
{
	char x;
	DDRB |= (1 << DDB5); //  output for LED
	PORTB |= (1 << PORTB7); // enable pull resistor
	
	if (PINB &= (1 << PINB7))
	{
		
		PORTB &= ~(1 << PORTB5);
		x= '0';
		// turn pin off when pinB7 or button released
	}
	else
	{
		PORTB |= (1 << PORTB5);
		x= '1';
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