/*
 * GccApplication1.c
 *
 * Created: 7.2.2017 14:42:07
 * Author : Samu Haapoja
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

/*Function prototypes*/
void SPI_MasterTransmit(char);
char SPI_SlaveReceive(void);

int main(void) {
	DDRD = 0xFF; // Port D as output
	PORTD = 0xFF; // ALL LEDs off
	DDRB = 0xB0; // 1011 0000 SS out, MOSI out, MISO in, SCK out, 
	PORTB |= (0<<PB4); // SS should be now 0
	//DDRB = 0x40; //  0100 0000, SS in, MOSI in, MISO out,
	SPCR = 0x51; // 0101 0001 - SPI Master
	//SPCR = 0x40; // 0100 0000 - SPI Slave
	char value = 255;
	
	while (1) {
		//value = SPI_SlaveReceive(); // waits for a value from SPI buffer
		//_delay_ms(2000);
		//PORTD = ~value;
		SPI_MasterTransmit(value); // Transmits value to SPI
		_delay_ms(2000);
		//value = SPI_SlaveReceive();
		PORTD = ~value;
		//value = value/2;
		//SPI_MasterTransmit(value);	
	}
	return 0;
}

void SPI_MasterTransmit(char cData) {
	SPDR = cData;
	while(!(SPSR &(1<<SPIF)));
}

char SPI_SlaveReceive(void) {
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}
