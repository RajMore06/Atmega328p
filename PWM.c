/*
 * PWM.c
 *
 * Created: 30-07-2024 12:29:53
 * Author : Raj more
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
int main(void)
{
	DDRB=DDRB|(1<<3);
	OCR0A=191;
	TCCR0A=0x83;
	TCCR0B=0x01;
	while(1);
	return 0;
}

