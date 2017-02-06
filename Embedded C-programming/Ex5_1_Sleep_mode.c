/*
 * GccApplication1.c
 *
 * Created: 6.2.2017 14:21:23
 * Author : Samu Haapoja
 */ 

#define F_CPU 8000000UL 
//#define SLEEP_MODE_PWR_DOWN _BV(SM1):
 
#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(INT2_vect) {
	sleep_disable();
	PORTD = PORTD^0x01; // Turn on LED_0
	_delay_ms(2000);
	PORTD = PORTD^0x01; // Turn off LED_0
	sleep_enable();
}

int main(void)
{
    DDRB = 0x00; // PORTB input
	  DDRD = 0xFF; // PORTD as output
	  PORTD = 0xFF; //Turn off all LEDs
	  GICR = 0x00; // INT2 is disabled for config to prevent interupt
    MCUCSR |= (1<<ISC2); // ISC2 to 1
	  GIFR = 0xFF;  // Logical 1 to GIFR
	  GICR |= (1<<INT2); //Enable INT2 again
	  set_sleep_mode(SLEEP_MODE_PWR_DOWN); //Sleep mode is power down mode
	  sei(); // enable interrupts
	  sleep_enable(); // enable sleepmode
	
    while (1) {
		sleep_cpu(); // CPU sleeps
    }
}
