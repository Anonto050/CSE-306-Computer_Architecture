/*
 * InstructionMemory.c
 *
 * Created: 2/6/2023 6:51:06 PM
 * Author : Anonto
 */ 

#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>

unsigned int instructions[] = {0xF246, 0x3302, 0x4450, 0x5514, 0x8343, 0x2521, 0x1FF0, 0xA012, 0xC25B, 0x9347, 0x1080};

int main(void)
{
	//turn off JTAG to use PORTC
	//One way is to uncheck the JTAG box while writing the fuse bits, the second is to write a 1 to the JTD bit twice consecutively
	
	MCUCSR = (1<<JTD);
	MCUCSR = (1<<JTD);
	
	//PC Input
	DDRD = 0x00 ;
	
	//Output
	//Lower bits
	DDRC = 0xFF;
	
	//Upper 8 bits
	DDRA = 0xFF;
	
	unsigned int inst_mem;
	
	
    /* Replace with your application code */
    while (1) 
    {
		inst_mem = instructions[PIND];
		
		PORTC = inst_mem;
		PORTA = (inst_mem>>8);
    }
}

