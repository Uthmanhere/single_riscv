module cu #(
	parameter branch_op			=	7'b1100011,
	parameter load_op			=	7'b0000011,
	parameter store_op			=	7'b0100011,
	parameter immArithmetic_op	=	7'b0010011,
	parameter arithmetic_op		=	7'b0110011
)
(
	input	[6:0]	opcode,
	output			branch_ctrl,
	output			memRead_ctrl,
	output	[2:0]	aluOp,
	output			write_ctrl_dataMem,
	output			aluOp_ctrl,	//0 for r2
	output			write_ctrl_regfile
);

	always_comb begin
		case (opcode)
			branch_op :
				branch_ctrl			= 1'b1;
				memRead_ctrl		= 1'b0;
				write_ctrl_dataMem	= 1'b0;
				aluOp				= 1'b0;
				aluOp_ctrl			= 2'b11;	//branches
				write_ctrl_regfile	= 1'b0;
			load_op :
				branch_ctrl			= 1'b0;
				memRead_ctrl		= 1'b1;
				write_ctrl_dataMem	= 1'b0;
				aluOp_ctrl			= 1'b1;
				aluOp				= 2'b00;	//loads
				write_ctrl_regfile	= 1'b1;
			store_op :
				branch_ctrl			= 1'b0;
				memRead_ctrl		= 1'b0;
				write_ctrl_dataMem	= 1'b1;
				aluOp_ctrl			= 1'b1;
				aluOp				= 2'b00;	//stores are like loads?
				write_ctrl_regfile	= 1'b0;
			immArithmetic_op :
				branch_ctrl			= 1'b0;
				memRead_ctrl		= 1'b0;
				write_ctrl_dataMem	= 1'b0;
				aluOp_ctrl			= 1'b1;
				aluOp				= 2'b01;	//arithmetic
				write_ctrl_regfile	= 1'b1;
			arithmetic_op :
				branch_ctrl			= 1'b0;
				memRead_ctrl		= 1'b0;
				write_ctrl_dataMem	= 1'b0;
				aluOp_ctrl			= 1'b0;
				aluOp				= 2'b01;	//arithmetic
				write_ctrl_regfile	= 1'b1;
		endcase
	end
endmodule
