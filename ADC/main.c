#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdint.h>
#define F_CPU 16000000UL
//#define BAUD 9600
//#define MYUBRR  F_CPU/16/BAUD -1
#define LEDON  PORTB |= (1 << PORTB5)
#define LEDOFF PORTB &= ~(1 << PORTB5)








void adc_init(void);
//void UART_Initialize(void);
//void USART_Transmit( unsigned char Data );

volatile  uint8_t  Converted_value;

	

int main(void)
{
   DDRB |= (1<< DDB5);
	sei();
	/* CTC mode*/
	TCCR0A |= 1 << WGM01;
	/* 64 preset*/
	TCCR0B |= (1 << CS00) |(1 << CS01);
	/* setting to 1ms occurs at 250-1 count */
	OCR0A = 249;
	
	/* compA interrupt enable */
	TIMSK0 |=  (1<< OCIE0A);
	
	
	////////////////
	
	TCCR2A |= 1 << WGM21;
	TCCR2B |= (1 << CS21) | (1 << CS22);
	
	OCR2A = 104;  //104.167 for 300hz pre scale 256 
			

			
	//compare match A and B interrupt
	TIMSK2 |=(1<<OCIE2A)|(1<<OCIE2B);
	
	
	
	adc_init();
	//UART_Initialize();


	while (1)
	{
		if ( Converted_value <= 10 &&  Converted_value >= 0)  //0-10%
		{
			 OCR2B= OCR2A*.05;
			
		}
		if (Converted_value <= 20 && Converted_value > 10)  //0-10%
		{
			OCR2B= OCR2A*.20;
			
		}
		if (Converted_value <= 30 && Converted_value > 20)  //0-10%
		{
			OCR2B= OCR2A*.30;
			
		}
		if (Converted_value <= 40 && Converted_value > 30)  //0-10%
		{
			OCR2B= OCR2A*.40;
			
		}
		if (Converted_value <= 50 && Converted_value > 40)  //0-10%
		{
			OCR2B= OCR2A*.50;
			
		}
		
		if (Converted_value <= 60 && Converted_value > 50)  //0-10%
		{
			OCR2B= OCR2A*.60;
			
		}
		if (Converted_value <= 70 && Converted_value > 60)  //0-10%
		{
			OCR2B= OCR2A*.70;
			
		}
		
		if (Converted_value <= 80 && Converted_value > 70)  //0-10%
		{
			OCR2B= OCR2A*.80;
			
		}
		if (Converted_value <= 90 && Converted_value > 80)  //0-10%
		{
			OCR2B= OCR2A*.90;
			
		}
		if (Converted_value > 90)  //0-10%
		{
			OCR2B= OCR2A*.99;
			
		}
		
		
		
		
		
	}
	
	
}



ISR(TIMER0_COMPA_vect)
{
	
	
}


ISR(ADC_vect)
{
	//uint16_t variable = ADC; //Automatically reads both ADCH and ADCL
	
	uint16_t adc = ADC*.097656;  // ADC*1/1024 *100
	
	 Converted_value = adc;
	
	
	//convert ADC value to OCRnB value
}





ISR (TIMER2_COMPA_vect)
{
	LEDON;
}


ISR (TIMER2_COMPB_vect)
{
	LEDOFF;
}





void adc_init(void)

{
	ADMUX |= (1 << REFS0); //VCC reference voltage
	ADMUX |= (1 << MUX1) | (1 << MUX0); //Select ADC channel
	ADCSRA |= (1 << ADEN); //ADC Enable
	ADCSRA |= (1 << ADIE); //ADC Conversion Complete Interrupt Enable
	ADCSRA |= (1 << ADPS1) | (1 << ADPS0); //ADC Prescaler
	ADCSRA |= (1 << ADATE); //Enable Auto Trigger
	ADCSRB |= (1 << ADTS1) | (1 << ADTS0); // Configure Auto Trigger
}




//void UART_Initialize(void)
//{
	//UBRR0H = ((MYUBRR) >> 8);
	//UBRR0L = MYUBRR;
	//
	//UCSR0B |= (1 <<  TXEN0) | (1 << RXEN0);
	//UCSR0C |= (1 <<  UCSZ00) | (1 << UCSZ01);                           // 8 bit data enable
	//UCSR0C &= ~(1 << USBS0);                                      // one bit stop
	////UCSR0C &= ~( (1 << UMSEL00)| (1<< UMSEL01) )               //set asych mode
	//
//}

//void USART_Transmit( unsigned char Data )
//{
	//
	//while ( !( UCSR0A & (1<<UDRE0)) );     // wait for empty buffer
	//UDR0 = Data;                          // send data to buffer does character at a time
//}


