/*	Glenn Bersabe Email: Gbers002@ucr.edu
 *  Bohan Zhang Email: Bzhan014@ucr.edu
 *	Lab Section: 023
 *	Assignment: Lab 2  Exercise 2
 *	Exercise Description: Checks to see if pin A0 and A1 are of certain values. Sets B0 to respective value.
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>


int main(void)
{
    DDRA = 0x00; PORTA = 0xFF; //Configure Port A to accept inputs
	DDRC = 0xFF; PORTC = 0x00; //Configure Port C to read outputs
	unsigned char tmpA0;
	unsigned char tmpA1;
	unsigned char tmpA2;
	unsigned char tmpA3;
	unsigned char cntavail;
    while (1) 
    {
		cntavail = 0x00;
		tmpA0 = PINA & 0x01;
		tmpA1 = PINA & 0x02;
		tmpA2 = PINA & 0x04;
		tmpA3 = PINA & 0x08;
		
		if (tmpA0 == 0x01) {
			cntavail++;
		}
		if (tmpA1 == 0x02) {
			cntavail++;
		}
		if (tmpA2 == 0x04) {
			cntavail++;
		}
		if (tmpA3 == 0x08) {
			cntavail++;
		}
		PORTC = 4 - cntavail;
    }
}

