/*
 * UART.c
 *
 * Created: 01-08-2024 09:11:54
 * Author : Raj More
 */ 
#ifdef F_CPU
#define F_CPU 16000000UL;
#endif
#include <avr/io.h>
#include <stdio.h>

void delay(int n)
{
	for(int i=0;i<n;i++){
	TCNT0=0xCE;
	TCCR0B|=(1<<CS00);
	TIMSK0|=(1<<TOIE0);
	while((TIFR0&(1<<TOV0))==0);
	TCCR0B&=(~(1<<CS00));
	TIFR0|=(1<<TOV0);
	}
}

int main(void)
{
	int ubrr=103;
	UBRR0L=ubrr;
	UBRR0H=0;
	UCSR0B|=(1<<RXEN0);
	UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00);
	DDRD=0xFF;
	while(1)
	{
		while(!(UCSR0A & (1<<RXC0)));
		{
			switch(UDR0)
			{
				case '1':
				PORTD|=(1<<5);
				OCR0A=255;
				TCCR0A=0x83;
				TCCR0B=0x01;
				delay(10000);
				PORTD&=(~(1<<5));
				break;
				
				case '2':
				PORTD|=(1<<4);
				OCR0A=255;
				TCCR0A=0x83;
				TCCR0B=0x01;
				delay(10000);
				PORTD&=(~(1<<4));
				break;
				
				default:
				break;
			}
		}
		
	}
}
