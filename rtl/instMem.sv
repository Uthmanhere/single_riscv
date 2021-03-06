module instMem 
	(
		input 		clk,
		input	[31:0]	pc,
		output	[31:0]	inst
					);

	reg [31:0] instMem_regs[2**32:0];

	always_ff @(posedge clk)
		inst <= instMem_regs[pc];


endmodule
