#include <verilated.h>
#include <Vrv32i.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


Vrv32i * rv32i;

vluint64_t main_time = 0;

double sc_time_stamp()
{
	return main_time;
}

int main(int argc, char ** argv)
{
	Verilated::commandArgs(argc, argv);

	rv32i = new Vrv32i;

	rv32i->final();
	delete rv32i;
	return 0;
}
