/*
 * SPI Master.c
 *
 * Created: 07-08-2024 15:44:32
 * Author : Raj More
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define MOSI PB3
#define MISO PB4
#define SCK PB5
#define SS PB2

void master_tx(char data)
{
	SPDR = data;
	while(!(SPSR & (1 << SPIF)));
}

int main(void)
{
    DDRB = (1 << MOSI)|(1 << SCK)|(1 << SS);
	SPCR = (1 << SPE)|(1 << MSTR)|(1 << SPR0);
	while(1)
	{
		PORTB &= ~(1 << SS);
		master_tx('A');
		PORTB |= (1 << SS);
		_delay_ms(1000);
		PORTB &= ~(1 << SS);
		master_tx('B');
		PORTB |= (1 << SS);
		_delay_ms(1000); 
	}
}

