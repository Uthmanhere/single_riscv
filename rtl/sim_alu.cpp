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

//	alu->clk = 0;


	for (int i = 0x00; i < 0x050; ++i)
	{

		alu->funct3 = 7;
		alu->r1 = rand() % 100;
		alu->r2 = rand() % 100;

		
//		alu->clk = !alu->clk;

		
		alu->eval();
printf("funct3 [%3X] r1 %5X r2 %5X aluOut %5X zero %1d\n", alu->r1, alu->r2, alu->aluOut, alu->zero);
		
		main_time += 3;
	}



	alu->final();
	delete alu;
	return 0;
}
