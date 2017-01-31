/*
 * GccApplication1.c
 *
 * Created: 31.1.2017 14:18:49
 * Author : Samu Haapoja
 */ 
#define F_CPU 4000000UL 

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER1_COMPA_vect) {
	OCR1A += 0x0145; // decimal 325
}

int main(void) {
    
	DDRD |= (1<<PD5); // PD5 needs to be output, so initializing all as outputs 
	TCCR1B = 0x02; // 0000 0010
    TCCR1A = 0x40; // 0100 0000 Output compare mode to toggle OC1A pin on match (COM1A0) (pin 6)
	OCR1A = 0x0144; // Decimal 324
	TIMSK = 0x10; // 0001 0000
	
	sei();
	
	while (1) {
    }
	return 0;
}
