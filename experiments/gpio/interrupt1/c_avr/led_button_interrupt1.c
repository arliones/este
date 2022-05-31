/*
 * led_button_interrupt1.c
 *
 *  Created on: 18/09/2015
 *      Author: katharine
 */

#define F_CPU 16000000UL  //16MHZ
#include <avr/io.h>
#include <inttypes.h>
#include <avr/interrupt.h>
#include <util/atomic.h>

//variables to keep track of the timing of recent interrupts
volatile unsigned char state = 0x00;
typedef unsigned long long milli_counter_t;
volatile milli_counter_t milli_counter_ms, last_button_time = 0, button_time = 0;

void milli_counter_start()
{
    milli_counter_ms = 0;

    TCCR0B = 0x05; //Init Timer0, normal, prescalar = 1024
    TCNT0 = 0xF0; //16 clock cycles
    TIMSK0 = 0x01; //Set TOIE bit
}

milli_counter_t milli_counter()
{
    return milli_counter_ms;
}

ISR(TIMER0_OVF_vect) {
    TCNT0 = 0xF0;
    milli_counter_ms++;
}

void Move_interrupts(void){
	/* Enable change of Interrupt Vectors */
	MCUCR = (1<<IVCE);
	/* Move interrupts to Boot Flash section */
	MCUCR = (1<<IVSEL);
}

void Configure_interrupts(void){
	EICRA= 0x1; //We set the ISC00, the first bit of EICRA, so that any logical change on INT0 generates the interrupt request.
	//ISC00 = 0x1;
	EIMSK = 0x1;	//We set the INT0, the first bit of EIMSK, to enable the external interrupt INT0.
	//INT0 = 0x1;
}

ISR(INT0_vect){

	button_time = milli_counter();
	//check to see if ISR() was called in the last 1000 milliseconds
	if(button_time-last_button_time >= 250){
		state = ~state;
		last_button_time = button_time;

	}
}

int main(void) {

    /* Set the whole portB (all bits) to "output" */
    DDRB = 0xff;	//portB are the digital pins (PB1 = pin9)
    /* Turn off all leds connected to port B at the beginning of the execution*/
    PORTB = state;
    /* Set the whole portD (all bits) to "input" */
    DDRD = 0xff;	//portD are other digital pins (PD2 = pin2, PD3 = pin3)

    sei(); //The macro sei() enables the interrupts. The Global Interrupt Enable Bit is set on SRE.
    Move_interrupts();
    Configure_interrupts();

    milli_counter_start();
	while(1) {
		PORTB = state;
	}
	return 0;
}
