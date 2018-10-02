#include <verilated.h>
#include <iostream>
#include <VdataMem.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

VdataMem * dataMem;

vluint64_t main_time = 0;

double sc_time_stamp()
{
	return main_time;
}

int main(int argc, char ** argv)
{
	Verilated::commandArgs(argc, argv);

	dataMem = new VdataMem;

	dataMem->write_ctrl = 0;
	dataMem->clk = 0;


	for (int i = 0x00; i < 0x050; ++i)
	{
		dataMem->data_addr = rand() % 10;
		dataMem->write_data = rand() % 32; 

		
		dataMem->write_ctrl = rand() % 2;
		dataMem->clk = !dataMem->clk;

		printf("W %d [%X] %X data %X\n", dataMem->write_ctrl, dataMem->data_addr, dataMem->write_data, dataMem->dataOut);
		
		dataMem->eval();

		main_time += 3;
	}



	dataMem->final();
	delete dataMem;
	return 0;
}
