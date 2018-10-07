module pc (

	input	clk,
	input	rst,
	output	[31:0]	inst_addr

	);


	always_ff @(posedge clk) begin
		case (rst)
			1	:	inst_addr <= 0;
			0	:	inst_addr <= inst_addr + 4;
		endcase
	end
	
	
endmodule
