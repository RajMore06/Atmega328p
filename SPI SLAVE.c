/*
 * SPI.c
 *
 * Created: 06-08-2024 12:34:54
 * Author : Raj More
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include <util/delay.h>
#define MISO PB4
#define LED PD5

char slave_rx()
{
	while(!(SPSR & (1 << SPIF)));
	return SPDR;
}
int main(void)
{
	DDRD |= (1 << LED);
    DDRB |= (1 << MISO);
	SPCR |= (1 << SPE);
	while(1)
	{
		char ans = slave_rx();
		if(ans == 'A')
		PORTD |= (1 << LED);
		else		
		PORTD &= (~(1 << LED));
	}
}

