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

uint8_t i, j, k = 0; // intialize a counters

ISR(TIMER0_OVF_vect) {
	TCNT0 = 246; // increase the counter so it goes only 10 ticks ~ 10ms
	i++;
	j++;
	k++;
	 // increase counter every ~10 ms
		if (i == 3) { 
			PORTB = PORTB^0x01;
			i = 0;
		}
		if (j == 6) {
			PORTB = PORTB^0x02;
			j = 0;
		}
		if (k == 10) {
			PORTB = PORTB^0x04;
			k = 0;
		}
}
// Requires a CLK of 1MHz
int main(void) {
	DDRB = 0xFF;  // PORTB as input
	PORTB = 0xFF; // PORTB default values off
	TCCR0 = TCCR0 | 0x05; // 0000 0101, Prescaler value of 1024
	TCNT0 = 246;
	TIMSK = TIMSK | 0x01 ; // 0000 0001
	sei(); // Enables global interrupts
	while (1) {
		// endless loop	
	}
	
	return 0;
}
