#include <verilated.h>
#include <Vregfile.h>
#include <stdlib.h>
#include <stdio.h>


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


	for (int i = 0x00; i < 0x020; ++i)
	{
		regfile->write_addr = i;
		int random_data = rand() % 32;
		regfile->write_data = random_data; 

		regfile->rs1_addr = i;
		regfile->rs2_addr = i + 1;

		
		regfile->write_ctrl = rand() % 2;
		regfile->clk = !regfile->clk;

		printf("W %d [%X] %X\tr1 [%X] %X\tr2 [%X] %X\n", regfile->write_ctrl, regfile->write_addr, regfile->write_data, regfile->rs1_addr, regfile->rs1, regfile->rs2_addr, regfile->rs2);
		
		regfile->eval();

		main_time += 3;
	}

	for (int i = 0x00; i < 0x020; ++i)
	{
		regfile->write_addr = i;
		int random_data = rand() % 32;
		regfile->write_data = random_data; 

		regfile->rs1_addr = i;
		regfile->rs2_addr = i + 1;

		
		regfile->write_ctrl = rand() % 2;
		regfile->clk = !regfile->clk;

		printf("W %d [%X] %X\tr1 [%X] %X\tr2 [%X] %X\n", regfile->write_ctrl, regfile->write_addr, regfile->write_data, regfile->rs1_addr, regfile->rs1, regfile->rs2_addr, regfile->rs2);
		
		regfile->eval();

		main_time += 3;
	}



	regfile->final();
	delete regfile;
	return 0;
}
