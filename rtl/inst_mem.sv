module regfile
	(
		input 		clk,
		input	[31:0]	pc,
		output	[31:0]	inst
					);

	reg [2**32:0] instMem_regs;

	assign inst = intMem_regs[pc];


endmodule
