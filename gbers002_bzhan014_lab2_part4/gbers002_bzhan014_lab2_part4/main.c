/*	Glenn Bersabe Email: Gbers002@ucr.edu
 *  Bohan Zhang Email: Bzhan014@ucr.edu
 *	Lab Section: 023
 *	Assignment: Lab 2  Exercise 3
 *	Exercise Description: Checks to see if pin A0 and A1 are of certain values. Sets B0 to respective value.
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
#include <stdlib.h>

int main(void)
{
    DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
	unsigned short totalWeight;
	unsigned short weightDiff;
    while (1) 
    {
		totalWeight = (PINA + PINB + PINC);
		weightDiff = abs((PINA - PINC));
		
		if (totalWeight > 0x8C && weightDiff > 0x50) {
			PORTD = 0x03;
		}
		else if (totalWeight > 0x8C) {
			PORTD = 0x01;
		}
		else if (weightDiff > 0x50) {
			PORTD = 0x02;
		}

    }
}

