/* I/O PORT B, DATA DIRECTION REGISTER (0 -> in, 1 -> out) */
#define DDRB    (*(volatile unsigned char *)(0x17 + 0x20))
/*#define DDRB    (*(volatile unsigned char *)(0x04 + 0x20))*//*for ATMEGA328p*/

/* I/O PORT B, DATA REGISTER */
#define PORTB   (*(volatile unsigned char *)(0x18 + 0x20))
/*#define PORTB	(*(volatile unsigned char *)(0x05 + 0x20))*//*for ATMEGA328p*/

#define F_CPU 1600000UL  //16MHZ
#include <avr/io.h>
#include <inttypes.h>

int main(void) {

	/* Set the whole portB (all bits) to "output" */
	DDRB = 0xff;	//portB are the digital pins (PB2 = pin10, PB3 = pin11)

	/* Turn off all leds connected to port B at the beginning of the execution*/
	PORTB = 0xff;
	/* Set the whole portD (all bits) to "input" */
	DDRD = 0x00;	//portD are other digital pins (PD2 = pin2, PD3 = pin3)


	while (1) {

		if (!(PIND & 1 << 2)) { //check if PD2 is 0 (low)
			// Turn on only the led on pin10-PB2
			PORTB = ~(PORTB | 0x0b);	/*aqui deve ser  a partir de 0x08 até 0x0b pois isto é de 00001000 até 00001011
			binário e como para acender o led em PB2 (um led de alto brilho) precisamos do 3º bit baixo */
		}else {
			// Turn off only the led on pin10-PB2
			PORTB = ~(PORTB | 0x0c);	/*aqui deve ser  a partir de 0x0c até 0x0f pois isto é de 11110100 até 11111111
			binário e como para apagar o led em PB2 precisamos do 3º bit sempre alto */
		}if ((PIND & 1 << 3)) { //check if PD3 is 1 (high)
			// Turn on only the led on pin11-PB3
			PORTB = ~(PORTB | 0x04);	/*aqui deve ser  a partir de 0x04 até 0x07 pois isto é de 00000100 até 00000111
			binário e como para acender o led em PB3 (um led normal) precisamos do 4º bit sempre baixo */
		} else {
			// Turn off only the led on pin11-PB3
			PORTB = ~(PORTB | 0x0c);	/*aqui deve ser  a partir de 0x0d até 0xff pois isto é de 00001100 até 00001111
			binário e como para apagar o led em PB3 (um led normal) precisamos do 4º bit sempre alto */
		}
	}

	return 0;
}