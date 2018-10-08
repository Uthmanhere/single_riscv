
module rv32i (

	input	clk

);

	`include "alu.sv"
	`include "pc.sv"
	`include "dataMem.sv"
	`include "instMem.sv"
	`include "regfile.sv"

	logic	clk;
	logic	[31:0]	pc_in_reg;
	logic	[31:0]	pc_out_reg;

	pc	pc(
		.clk(clk),
		.inst_addr_in(pc_in_reg),
		.inst_addr_out(pc_out_reg)
	)

endmodule
