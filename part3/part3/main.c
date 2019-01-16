

#include <avr/io.h>


int main(void)
{
	/* Replace with your application code */
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0x00; PORTC = 0xFF; // Configure port C's 8 pins as outputs, initialize to 0s
	unsigned char tmpA0 = 0x00;
	unsigned char tmpA1 = 0x00;
	unsigned char tmpA2 = 0x00;
	unsigned char tmpA3 = 0x00;
	unsigned char tmpA4 = 0x00;
	unsigned char tmpA5 = 0x00;
	unsigned char tmpA6 = 0x00;
	unsigned char tmpA7 = 0x00;
	while(1)
	{
		unsigned char cntavail = 0x00;
		tmpA0 = PINA & 0x01;
		tmpA1 = PINA & 0x02;
		tmpA2 = PINA & 0x04;
		tmpA3 = PINA & 0x08;
		tmpA4 = PINA & 0x10;
		tmpA5 = PINA & 0x20;
		tmpA6 = PINA & 0x40;
		tmpA7 = PINA & 0x80;
		if (tmpA0 == 0x01) {
			cntavail ++;
		}
		if (tmpA1 == 0x02) {
			cntavail ++;
		}
		if (tmpA2 == 0x04) {
			cntavail ++;
		}
		if (tmpA3 == 0x08) {
			cntavail ++;
		}
		if (tmpA4 == 0x10) {
			cntavail ++;
		}
		if (tmpA5 == 0x20) {
			cntavail ++;
		}
		if (tmpA6 == 0x40) {
			cntavail ++;
		}
		if (tmpA7 == 0x80) {
			cntavail ++;
		}
		// 3) Write output
		if (cntavail <= 7){
			PORTC = 8 - cntavail;
		}
		else {
			PORTC = 128;
		}
	}
}

