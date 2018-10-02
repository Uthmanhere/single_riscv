#include <verilated.h>
#include <iostream>
#include <VintMem.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

VinstMem * instMem;

vluint64_t main_time = 0;

double sc_time_stamp()
{
	return main_time;
}

int main(int argc, char ** argv)
{
	Verilated::commandArgs(argc, argv);

	instMem = new VinstMem;

	instMem->clk = 0;


	for (int i = 0x00; i < 0x040; ++i)
	{
		instMem->pc = i;
		
		instMem->clk = !instMem->clk;

		printf("pc [%X] inst [%X] ", instMem->pc, intMem->inst);
		
		instMem->eval();

		main_time += 3;
	}




	instMem->final();
	delete instMem;
	return 0;
}
