#include <verilated.h>
#include <Vpc.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


Vpc * pc;

vluint64_t main_time = 0;

double sc_time_stamp()
{
	return main_time;
}

int main(int argc, char ** argv)
{
	Verilated::commandArgs(argc, argv);

	pc = new Vpc;
	pc->clk = 0;
	pc->rst = 1;
	pc->clk = 1;
	pc->rst = 0;
	pc->clk = 0;
	pc->clk = 1;
	for (int i = 49; i; --i)
	{
		pc->clk = !pc->clk;
//		pc->rst = rand() % 2;
		pc->eval();

		printf("rst %1X inst_addr [%5X]\n", pc->rst, pc->inst_addr);
		
	}
	pc->final();
	delete pc;
	return 0;
}
