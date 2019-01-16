/*	Glenn Bersabe Email: Gbers002@ucr.edu
	Bohan Zhang Email: Bzhan014@ucr.edu
 *	Lab Section: 023
 *	Assignment: Lab 2  Exercise 1 
 *	Exercise Description: Checks to see if pin A0 and A1 are of certain values. Sets B0 to respective value.
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char tmpA0 = 0x01; // Temporary variable to hold the value of A0
	unsigned char tmpA1 = 0x00; // Temporary variable to hold the value of A1
	unsigned char tmpB = 0x00;
	while(1)
	{
		tmpA0 = PINA & 0x01;
		tmpA1 = PINA & 0x02;
		if (tmpA0 == 0x01 && tmpA1 ==0x00) {
			tmpB = 0x01; //Case that sets Port B0 to 1
		}
		else {
			tmpB = 0x00; //All other cases set B0 to 0
		}
		PORTB = tmpB; 
	}
	return 0;
}
