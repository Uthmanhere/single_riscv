module regfile
	(
		input 		clk,
		input		write_ctrl,
		input	[31:0]	write_data,
		input	[4:0]	write_addr,
		input	[4:0]	rs1_addr,
		input	[4:0]	rs2_addr,
		output	[31:0]	rs1,
		output	[31:0]	rs2
					);

	reg [31:0] regfile_regs[31:0];

	assign #2 rs1 = regfile_regs[rs1_addr];
	assign #2 rs2 = regfile_regs[rs2_addr];

	always @(posedge clk) begin
		if (write_ctrl)
			regfile_regs[write_addr] <= write_data;
	end

endmodule
