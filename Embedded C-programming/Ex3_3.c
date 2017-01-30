/*
 * GccApplication1.c
 *
 * Created: 30.1.2017 16:36:18
 * Author : u97479
 *
 * GccApplication1.c
 *
 * Created: 23.1.2017 16:27:24
 * Author : Samu Haapoja
 */ 

#define F_CPU 8000000UL // CPU speed @ 1 MHz
#include <avr/io.h>
#include <util/delay.h>

/* function protypes */
void uart_putc(unsigned char c);

unsigned char uart_getc(void);


int main(void) {
	DDRB = 0xFF;  // PORTB as output
	PORTB = 0xFF; // PORTB default values off
	UBRRL = 0x19; // Calculated value of 25 to UBRR
	UCSRA = 0x02; // U2X to 1
	UCSRB = 0x18; // Enable Receive/Transmit
	uint8_t tmp = 0; // temporary value to store the rs-232 value

	while (1) {
		
		tmp = (uint8_t) uart_getc(); // typecasting the UDR value 
		PORTB = ~tmp;
		_delay_ms(1000);
		PORTB = 0xFF;
		uart_putc(tmp);
	}
	
	return 0;
}

unsigned char uart_getc(void) {
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}

void uart_putc(unsigned char c) {
	while(!(UCSRA & (1 << UDRE)));
	UDR = c;
}
