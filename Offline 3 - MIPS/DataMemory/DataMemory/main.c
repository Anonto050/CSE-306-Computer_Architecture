/*
 * DataMemory.c
 *
 * Created: 2/6/2023 6:56:51 PM
 * Author : Anonto
 */ 

#define CLOCK	 0b0100
#define RESET	 0b1000
#define MEM_READ 0b0010
#define MEM_WRITE 0b0001

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000

unsigned int DATA_MEM[16];

//reset values to zero
void Reset() {
	for (int i=0; i<16; i++)
	     DATA_MEM[i] = 0;
}

int main(void)
{
	DDRB = 0xF0;	// B[0] - Memory Write | B[1] - Memory Read | B[2] - Clock | B[3] - Reset
	DDRD = 0x00;	// Address D[3:0] | Write Data D[7:4]
	DDRA = 0xFF;	// A[3:0] - Data Read
	
	Reset();
	
	unsigned int control_last = 0b0000; 
	unsigned int control_current = 0b0000;
	
	unsigned int prev_write_address = 0b0000;
	unsigned int current_write_address = 0b0000;
	
	while (1)
	{
		control_current = 0b1111 & PINB;
		current_write_address = PIND;
		
		if (control_current & RESET) {
			Reset();
			_delay_ms(100);
			} 
		else if ((control_last ^ control_current) & CLOCK) {		
			if (control_last & CLOCK) {						
				if (control_last & MEM_WRITE) {
					DATA_MEM[prev_write_address & 0b1111] = (prev_write_address >> 4);
				}
			}
			_delay_ms(100);
		}
		if (control_current & MEM_READ) {
			PORTA = DATA_MEM[current_write_address & 0b1111];
		}
		
		control_last = control_current;
		prev_write_address = current_write_address;
	}
}

