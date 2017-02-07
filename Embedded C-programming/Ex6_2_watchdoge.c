/*
 * GccApplication1.c
 *
 * Created: 7.2.2017 14:42:07
 * Author : Samu Haapoja
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/wdt.h>
#include <util/delay.h>

/*Function prototypes*/
static inline uint8_t debounce(volatile uint8_t *, const uint8_t);

int main(void) {
	DDRD = 0x00; // Port D as output
	DDRB = 0xFF; 
	PORTB = 0xFF;
	while (debounce(&PIND, PD0)==0); // Waits until button is pressed
	PORTB = 0x00; // Turns all LEDS on as opposed to just LED0
	wdt_enable(WDTO_2S);
	while (debounce(&PIND, PD0)==0); // waits until button is pressed again
	wdt_reset();
	while (1) {
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
