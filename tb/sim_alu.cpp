#include <verilated.h>
#include <iostream>
#include <Valu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

Valu * alu;

vluint64_t main_time = 0;

double sc_time_stamp()
{
	return main_time;
}

int main(int argc, char ** argv)
{
	Verilated::commandArgs(argc, argv);

	alu = new Valu;



	for (int i = 0x00; i < 0x050; ++i)
	{

		alu->funct3 = rand() % 8;
		alu->funct7 = rand() % 2;
		alu->op1 = rand() % 100;
		alu->op2 = rand() % 100;

		

		
		alu->eval();

	printf("funct3 [%3X] funct7 [%1X] op1 %5X op2 %5X aluOut %5X zero %1d overflow %1d\n", 
			alu->funct3, alu->funct7, alu->op1, alu->op2, alu->aluOut, alu->zero, alu->overflow);
		
		main_time += 3;
	}



	alu->final();
	delete alu;
	return 0;
}
