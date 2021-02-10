#include <avr/io.h>
#include <avr/eeprom.h>
#include <avr/interrupt.h>

#define LEDON  PORTB |= (1 << PORTB5)
#define LEDOFF PORTB &= ~(1 << PORTB5)


int main(void)
{
    	DDRB |= ( 1<< DDB5);
    	//TIMER 2
    	sei();
    	TCCR2A |= 1 << WGM21;
    	TCCR2B |= (1 << CS20) |(1 << CS21) | (1 << CS22);	//change to 1024 preset
    	OCR2A = 77;  //78.125 -1  5ms
    	OCR2B = 0;
    	//compare match A and B interrupt
    	TIMSK2 |=(1<<OCIE2A)|(1<<OCIE2B);
	
	///////////////////////////////////////////////
	
	
	
	uint8_t Num_of_times_run =	eeprom_read_byte ((uint8_t*)20);
	
		if (Num_of_times_run == 0)
		{
			OCR2B= 0;
			Num_of_times_run++;
			eeprom_update_byte ((uint8_t*)20 , Num_of_times_run );			
		}
		
	
else if (Num_of_times_run == 1)
	{
		OCR2B= OCR2A*.1;
		Num_of_times_run++;
		eeprom_update_byte ((uint8_t*)20 , Num_of_times_run );
		
		
	}
	
	else if (Num_of_times_run == 2)
	{
		
		OCR2B= OCR2A*.20;
		Num_of_times_run++;
		eeprom_update_byte ((uint8_t*)20 , Num_of_times_run );
		
	}
	
		
	else if (Num_of_times_run == 3)
	{
		OCR2B= OCR2A*.30;
		Num_of_times_run++;
		eeprom_update_byte ((uint8_t*)20 , Num_of_times_run );
		
	}
	
	
	else if (Num_of_times_run == 4)
		{
			OCR2B= OCR2A*.40;
			Num_of_times_run++;
			eeprom_update_byte ((uint8_t*)20 , Num_of_times_run );
			
		}
		
	
	else if (Num_of_times_run == 5)
	{
		OCR2B= OCR2A*.50;
		Num_of_times_run++;
		eeprom_update_byte ((uint8_t*)20 , Num_of_times_run );
		
	}
		
	else if (Num_of_times_run == 6)
	{
		OCR2B= OCR2A*.60;
		Num_of_times_run++;
		eeprom_update_byte ((uint8_t*)20 , Num_of_times_run );
		
	}

	
	else if (Num_of_times_run == 7)
	{
		OCR2B= OCR2A*.70;
		Num_of_times_run++;
		eeprom_update_byte ((uint8_t*)20 , Num_of_times_run );
		
	}
	
	
	else if (Num_of_times_run == 8)
	{
		OCR2B= OCR2A*.80;
		Num_of_times_run++;
		eeprom_update_byte ((uint8_t*)20 , Num_of_times_run );
		
	}
	
	
	
	else if (Num_of_times_run == 9)
	{
		OCR2B= OCR2A*.90;
		Num_of_times_run++;
		eeprom_update_byte ((uint8_t*)20 , Num_of_times_run );
		
	}
	

	
	else if (Num_of_times_run >= 10)
	{
		OCR2B= OCR2A-1;
		//Num_of_times_run=0;
		eeprom_update_byte ((uint8_t*)20 , 0 );
		
	}
	
		
	
	
	
	
    while (1) 
    {
    }
}






ISR (TIMER2_COMPA_vect)
{
	LEDON;
}


ISR (TIMER2_COMPB_vect)
{
	LEDOFF;
}