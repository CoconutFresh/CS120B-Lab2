/*	Glenn Bersabe Email: Gbers002@ucr.edu
 *  Bohan Zhang Email: Bzhan014@ucr.edu
 *	Lab Section: 023
 *	Assignment: Lab 2  Exercise 4
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
	unsigned char totalWeight;
	unsigned char weightDiff;
	unsigned char signal;
	unsigned char weightA;
	unsigned char weightB;
	unsigned char weightC;
	
    while (1) 
    {
		signal = 0x00;
		weightA = PINA;
		weightB = PINB;
		weightC = PINC;
		
		totalWeight = weightA + weightB + weightC;
		weightDiff = abs(weightA - weightC);
		
		if (totalWeight > 140) {
			signal = signal | 0x01;
		}
		if (weightDiff > 80) {
			signal = signal | 0x02;
		}

		totalWeight = totalWeight & 0xFC;
		//weightDiff += totalWeight;
		PORTD = totalWeight | signal;
    }
}

