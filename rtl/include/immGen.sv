
parameter I_ctrl = 0;
parameter S_ctrl = 1;

module immGen (

	input	[31:0]	inst,
	input			imm_ctrl,
	output	[31:0]	imm

	);
	
	reg [19:0] imm_ext = inst[31] ? 20'h0FFFFF : 20'h000;

	always_comb

		
		case (imm_ctrl)
			I_ctrl	:	imm = { imm_ext, inst[31:20] };
			S_ctrl	:	imm = {	imm_ext, inst[31:25], inst[11:7] };
		endcase	

endmodule
