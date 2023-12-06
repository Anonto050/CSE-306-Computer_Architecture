/*
 * ALU.c
 *
 * Created: 2/12/2023 3:39:59 PM
 * Author : Anonto
 */ 

#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>

int main(void)
{
	
	//first 4 bits data1, second 4 bits are data2
	DDRD = 0x00;	
	//ALU control bits - first 3 bits 			
	DDRB = 0xF8;
	
	//first 4 bits are result, D[7] is zero flag
	DDRA = 0x8f;			

	unsigned int ALU_control;
	unsigned int data1,data2;
	unsigned int ALU_result = 0;

	while (1)
	{
		ALU_control = (0b111 & PINB);

		data1 = PIND & 0x0F;
		data2 = (PIND & 0xF0) >> 4;
		ALU_result = 0;

		if(ALU_control == 0) {
			ALU_result = data1 + data2;
			} 
		else if(ALU_control == 1){
			ALU_result = data1 - data2;
			} 
		else if(ALU_control == 2) {
			ALU_result = data1 & data2;
			} 
		else if(ALU_control == 3) {
			ALU_result = data1 | data2;
			} 
		else if(ALU_control == 4) {
			ALU_result = ~(data1 | data2);
			} 
		else if(ALU_control == 5) {
			ALU_result = data1 << data2;
			} 
		else if(ALU_control == 6) {
			ALU_result = data1 >> data2;
		}

		ALU_result = ALU_result & 0b1111;
		
		//If result is zero, set the zero flag
		if(ALU_result == 0) {
			ALU_result = ALU_result | 0b10000000;
		}

		PORTA = ALU_result;
	}
}

