+/*	Glenn Bersabe Email: Gbers002@ucr.edu
 *  Bohan Zhang Email: Bzhan014@ucr.edu
 *	Lab Section: 023
 *	Assignment: Lab 2  Exercise 3
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
     unsigned char cntavail;
     while (1)
     {
	     cntavail = PINA;
	     if (PINA == 0x0F) {
		     PORTC = 0x8F;
	     }
	     else {
		     PORTC = cntavail;
	     }
     }
}

