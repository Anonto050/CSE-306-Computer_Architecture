/*
 * ControlUnit.c
 *
 * Created: 2/6/2023 6:52:13 PM
 * Author : Anonto
 */ 

#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>

unsigned int control_rom[] = {0x780, 0x008, 0x506, 0x900, 0x901, 0x903, 0x500, 0x904, 0x505, 0x640, 0x502, 0x501, 0x503, 0x902, 0x011, 0x021};

int main(void)
{
	//turn off JTAG to use PORTC
	//One way is to uncheck the JTAG box while writing the fuse bits, the second is to write a 1 to the JTD bit twice consecutively
	
	MCUCSR = (1<<JTD);
	MCUCSR = (1<<JTD);
	
	DDRB = 0xF0; //Opcode
	DDRA = 0xFF;  //All 8 bits
	DDRC = 0xFF; //first 4 bits
	
	unsigned int instruction = -1;
	unsigned int control = -1;
	
	
    /* Replace with your application code */
    while (1) 
    {
		if((0b1111 & PINB) != instruction){
			instruction = 0b1111 & PINB;
			control = control_rom[instruction];
			PORTA = control;
			PORTC = (control>>8);
		}
    }
}

