#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char tmpA0 = 0x01; // Temporary variable to hold the value of B
	unsigned char tmpA1 = 0x00; // Temporary variable to hold the value of A
	unsigned char tmpB = 0x00;
	while(1)
	{
		tmpA0 = PINA & 0x01;
		tmpA1 = PINA & 0x00;
		//tmpA0 = PINA & 0x01;
		//tmpA1 = PINA & 0x00;
		//tmpB = PORTB & 0x00;
		
		if (tmpA0 == 0x01 && tmpA1 ==0x00) {
			//tmpB = tmpB & 0x01;
			tmpB = 0x01;
		}
		else {
			tmpB = 0x00;
		}
		PORTB = tmpB;
	}
	return 0;
}
