/*
 * GccApplication1.c
 *
 * Created: 31.1.2017 14:18:49
 * Author : Samu Haapoja
 */ 
#define F_CPU 8000000UL 

#include <avr/io.h>
#include <avr/interrupt.h>

/*Function prototypes*/
void uart_putc(unsigned char c);

/*Variable declarations*/
volatile uint8_t count = 0;
volatile uint8_t table[10];


ISR(USART_RXC_vect) {
	table[count] = UDR; // inserts the character in UDR Buffer to Table_count position
	count++; 
}


int main(void) {
    UBRRL = 25; // Calculated value of 25 to UBRR
    UCSRA = 0x02; // U2X to 1
    UCSRB = 0xD8; // 11011000 Enable Receive/Transmit
	sei(); // enable global interrupts
	/* This program prints out to RS-232 communication if the amount of material is 10*/
	while (1) {
		
		if (count == 10) {
			
			for (int i = 0; i < 10; i++) {
				uart_putc(table[i]);
			}
			count = 0;
		}	
    }
	return 0;
}

/*RS-232 printout function*/
void uart_putc(unsigned char c) {
	while(!(UCSRA & (1 << UDRE)));
	UDR = c;
}

