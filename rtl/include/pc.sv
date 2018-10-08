module pc (

	input	clk,
	input	inst_addr_in
	output	[31:0]	inst_addr_out

	);


	always_ff @(posedge clk) begin
		inst_addr_in <= inst_addr_out;
	end
	
	
endmodule
