#include <verilated.h>
#include <VimmGen.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


VimmGen * immGen;

vluint64_t main_time = 0;

double sc_time_stamp()
{
	return main_time;
}

int main(int argc, char ** argv)
{
	Verilated::commandArgs(argc, argv);

	immGen = new VimmGen;


	for (int i = 0; i < 50; ++i)
	{
		immGen->inst = rand() % 0xFFFFFFFFF;
		immGen->imm_ctrl = rand() % 2;

		immGen->eval();

		printf("%1X [%8X] %8X\n", immGen->imm_ctrl, immGen->inst, immGen->imm);
	}

	for (int i = 0; i < 50; ++i)
	{
		immGen->inst = 0x0AFFF00000 + rand() % 0x0FFFFF;
		immGen->imm_ctrl = rand() % 2;

		immGen->eval();

		printf("%1X [%8X] %8X\n", immGen->imm_ctrl, immGen->inst, immGen->imm);
	}

	immGen->final();
	delete immGen;
	return 0;
}
