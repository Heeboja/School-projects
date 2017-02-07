/*
 * GccApplication1.c
 *
 * Created: 7.2.2017 14:42:07
 * Author : u97479
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER1_COMPA_vect) {
	PORTB = PORTB^0x01;
	OCR1A += 1000; // decimal 1000
}

ISR(TIMER1_COMPB_vect) {
	OCR1B += 5000; // decimal 5000 every 5 seconds
	PORTB = PORTB^0x02;
}

int main(void) {
	DDRB = 0xFF;
	PORTB = 0xFF;
	DDRD |= (1<<PD5);
	DDRD |= (1<<PD4); // PD5 and PD4 needs to be output
	TCCR1B = 0x05; // 0000 0101 Prescaler of 1024
	TCCR1A = 0x50; // 0101 0000 Output compare mode to toggle OC1A pin on match (COM1A0) (pin 6)
	OCR1A = 0x03E7; // Decimal 999 compare
	OCR1B = 4999;
	TIMSK = 0x18; // 0001 1000
	
	sei();
	
	while (1) {
	}
	return 0;
}
