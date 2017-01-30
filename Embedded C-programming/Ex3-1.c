/*
 * GccApplication1.c
 *
 * Created: 23.1.2017 16:27:24
 * Author : Samu Haapoja
 */ 

#define F_CPU 1000000UL // CPU speed @ 1 MHz
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile uint8_t i = 0; // intialize a counter

ISR(TIMER0_OVF_vect) {
	TCNT0 = 6;
	i++; // increase counter every ~250 ms
		if (i == 4) { 
			PORTB = PORTB^0x01;
			i = 0;
		}
}
// Requires a CLK of 1MHz
int main(void) {
	DDRB = 0xFF;  // PORTB as input
	PORTB = 0xFF; // PORTB default values off
	TCCR0 = TCCR0 | 0x05; // 0000 0101
	TCNT0 = 6;
	TIMSK = TIMSK | 0x01 ; // 0000 0001
	sei(); // Enables global interrupts
	while (1) {
		// endless loop	
	}
	
	return 0;
}
