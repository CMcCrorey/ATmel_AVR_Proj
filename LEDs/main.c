
#include <avr/io.h>
#include <stdlib.h>
#define F_CPU 16000000UL
#include <util/delay.h>

#define LEDON  PORTB |= (1 << PORTB5)
#define LEDOFF PORTB &= ~(1 << PORTB5)

void Delay_delay(int x);

void delaydim(char OCRB);

int main(void)
{
   	DDRB |= (1 << DDB5);
   	PORTB |= (1 << PORTB7);
	   
	/* setting FAST PWM mode */
	TCCR0A |= (1 << WGM00) |(1<< WGM01) ;
	TCCR0B |= (1 << WGM02) ;
	/* preset 1024  */
	TCCR0B |= (1 << CS00) |(1 << CS02);

	
	/* setting to 10ms occurs at 157-1 count */
	OCR0A = 156;
	 OCR0B =1;
	  //int x=0; 
	   
    while (1) 
    {
		if(!(PINB &= (1 << PINB7)))
		{
			//
			//Delay_delay(x);
			//
			//x++;
			 //if (x >= 1000)
			 //{
				 //x =1000;
				 //
			 //}
			
			
			 
		 delaydim(OCR0B);
		 OCR0B++;
		 		
		}
		
			
			else 
			{
				
				
			
				//Delay_delay(x);
					//x--;
					 //if (x < 1)
					 //{
						 //x =0;
						 //
					 //}
			//
					
				delaydim(OCR0B);
				OCR0B--;
			
				
				
			
			}
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
					//for (OCR0B; OCR0B <= 156; OCR0B++)
					//{
						//
						//LEDON;
						//while ( (TIFR0 & (1 << OCF0B) ) == 0){} // wait for OCR0B overflow event
						//TIFR0 |= (1 << OCF0B);
						//
						//
						//LEDOFF;
						//while ( (TIFR0 & (1 << OCF0A) ) == 0){} // wait for OCR0A overflow event
						//TIFR0 |= (1 << OCF0A);
						//
					//}
					//
				//
					//
				//
			//
			//
		//}
		//
		//else 
		//{
			//
			//
				//for (OCR0B; OCR0B >= 156; OCR0B--)
				//{
					//
					//LEDON;
					//while ( (TIFR0 & (1 << OCF0B) ) == 0){} // wait for OCR0B overflow event
					//TIFR0 |= (1 << OCF0B);
					//
					//
					//LEDOFF;
					//while ( (TIFR0 & (1 << OCF0A) ) == 0){} // wait for OCR0A overflow event
					//TIFR0 |= (1 << OCF0A);
					//
				//}
				//
		//
			//
			//
		//}
		
		
		
			
			
			
		
			
		
		
		
		

		
		
    }
}







void delaydim(char OCRB)
{
	
	
	LEDON;
	while ( (TIFR0 & (1 << OCF0B) ) == 0){} // wait for OCR0B overflow event
	TIFR0 |= (1 << OCF0B);
	
	 if (OCR0B == 156)
	 {
		 OCR0B =155;
		 
	 }
	 
	 if (OCR0B < 1)
	 {
		 OCR0B =1;
		 
	 }
	
	LEDOFF;
	while ( (TIFR0 & (1 << OCF0A) ) == 0){} // wait for OCR0A overflow event
	TIFR0 |= (1 << OCF0A);
	
	
}




void Delay_delay(int x)
{
	LEDON;
	for (int y=0; y <x ; y++   )
	{
		_delay_us(1);
		
	}
	
	
			
	 
LEDOFF;
	for (int k=0; k < (1000-x) ; k++  )
	{
		_delay_us(1);
		
	}

	
	
	
}



void dim_on ()
{
	
		for (OCR0B; OCR0B < 156; OCR0B++)
		{
			
			LEDON;
			while ( (TIFR0 & (1 << OCF0B) ) == 0){} // wait for OCR0B overflow event
			TIFR0 |= (1 << OCF0B);
			
			for (int i=0; i < 100; i++)
			{
				while ( (TIFR0 & (1 << OCF0A) ) == 0){} // wait for OCR0A overflow event
				TIFR0 |= (1 << OCF0A);
			}
			
			
		
			if ( OCR0B==155)
			{
				LEDON;
				
			}
			else 
			{
						LEDOFF;
						while ( (TIFR0 & (1 << OCF0A) ) == 0){} // wait for OCR0A overflow event
						TIFR0 |= (1 << OCF0A);
					
					
			}
		
			
		}
		
	
}

void dim_off ()
{
	
	
	for (OCR0B; OCR0B >= 155; OCR0B--)
	{
		
		LEDON;
		while ( (TIFR0 & (1 << OCF0B) ) == 0){} // wait for OCR0B overflow event
		TIFR0 |= (1 << OCF0B);
		
		if ( OCR0B==0)
		{
			LEDOFF;
			
		}
		else
		{
			LEDOFF;
			while ( (TIFR0 & (1 << OCF0A) ) == 0){} // wait for OCR0A overflow event
			TIFR0 |= (1 << OCF0A);
			
		}
		
		
	}
	
	
	
	
	
	
}
