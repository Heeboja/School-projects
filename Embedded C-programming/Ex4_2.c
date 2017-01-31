/*
 * GccApplication1.c
 *
 * Created: 31.1.2017 14:18:49
 * Author : Samu Haapoja
 */ 
#define F_CPU 4000000UL 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/*Function prototypes*/
static inline uint8_t debounce(volatile uint8_t *, const uint8_t);

int main(void) {
    
	DDRB = 0x00; // Port b as input
	DDRD |= (1<<PD5); // PD5 needs to be output, so initializing all as outputs 
	TCCR1B = 0x1A; // 0001 1010 Output compare mode to toggle OC1A pin on match (COM1A0) (pin 6) 
	               // set PRE-scaler as well
	TCCR1A = 0xA2; // 1010 0010
	ICR1 = 500; // this means a scalar for 1000 ms (500 times 2 us)
	OCR1A = 0; //
	
	while (1) {
		if (debounce(&PINB, PB0)) {
			OCR1A = 0;
		}
		if (debounce(&PINB, PB1)) {
			OCR1A = 125;
		}
		if (debounce(&PINB, PB2)) {
			OCR1A = 250;
		}
		if (debounce(&PINB, PB3)) {
			OCR1A = 375;
		}
		if (debounce(&PINB, PB4)) {
			OCR1A = ICR1;
		}	
    }
	return 0;
}

static inline uint8_t debounce(volatile uint8_t *pinReg, const uint8_t pin) {
	if(!(*pinReg & (1 << pin))) {
		//pin grounded wait 100ms
		_delay_ms(100);
		
		if(*pinReg & (1 << pin)) {
			// give the user time to release the button
			_delay_ms(100);
			return 1;
		}
	}
	
	return 0;
}
