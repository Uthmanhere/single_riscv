module dataMem 
	(
		input			clk,
		input			write_ctrl,
		input	[31:0]	write_data,
		input	[31:0]	data_addr,
		output	[31:0]	dataOut
									);

	reg [31:0] dataMem_regs[2**32];

	assign #2 dataOut = dataMem_regs[data_addr];

	always @(posedge clk) begin
		if (write_ctrl)
			dataMem_regs[data_addr] <= write_data;
	end

endmodule
