#include <verilated.h>
#include <iostream>
#include <Vregfile.h>

using namespace std;

Vregfile * regfile;

vluint64_t main_time = 0;

double sc_time_stamp()
{
	return main_time;
}

int main(int argc, char ** argv)
{
	Verilated::commandArgs(argc, argv);

	regfile = new Vregfile;
	regfile->write_ctrl = 0;
	regfile->clk = 0;
	regfile->write_addr = 0x01;
	regfile->rs1_addr = 0x01;

	while ( !Verilated::gotFinish() )
	{
		if ( (main_time % 10) == 2 ) regfile->clk = !regfile->clk;
		if (main_time > 2) regfile->write_data = 0x05;
		if (main_time > 3) regfile->write_ctrl = 1;
		if (main_time > 50) break;
		regfile->eval();
		cout << regfile->rs1 << endl;
		++main_time;
	}

	regfile->final();
	delete regfile;
	return 0;
}
