/*
 * GccApplication1.c
 * NOTE: Didn't work with 1 board, under revising
 * Created: 6.2.2017 14:21:23
 * Author : Samu Haapoja
 */ 



#include <avr/io.h>
#include <avr/interrupt.h>



ISR(ADC_vect) {
	uint16_t value = ADCL;
	value += ADCH<<8;
	if (value >= 0 && value < 204) PORTB = 0xFE; //1111 1110	
	else if (value >= 204 && value < 409) PORTB = 0xFC; //1111 1100 	
	else if (value >= 409 && value < 614) PORTB = 0xF8; //1111 1000 
	else if (value >= 614 && value < 819) PORTB = 0xF0; //1111 0000 
	else if (value >= 819 ) PORTB = 0xE0; //1110 0000 
	else PORTB = 0xFF; //1111 1111		
	ADCSRA |= (1<<ADSC);
}
    
int main(void) {	
  DDRB = 0xFF; // PORTB as output
	PORTB = 0xFF; // LEDs off
	ADMUX = 0x03; // 0000 0011
	/*Enable ADC, Set ADSC 1, enable interrupt and set pre-scaler*/
	ADCSRA = 0xCC; // 1100 1100 
	sei();
	
    while (1) {
		/*Loopdy loop loop*/
    }
}
