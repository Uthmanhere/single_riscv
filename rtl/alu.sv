
parameter add_funct3	=	3'b000;
parameter slt_funct3	=	3'b010;
parameter sltu_funct3	=	3'b011;
parameter xor_funct3	=	3'b100;
parameter or_funct3		=	3'b110;
parameter and_funct3	=	3'b111;
parameter sl_funct3		=	3'b001;
parameter sr_funct3		=	3'b101;


module alu (

		input	[31:0]	r1,
		input	[31:0]	r2,
		input	[2:0]	funct3,
		input			funct7,
		output			zero,
		output			overflow,
		output	[31:0]	aluOut

	);


	assign zero = aluOut == 32'h00; //? 1'b1 : 1'b0;

	always_comb
	case(funct3)
		add_funct3	:
			case(funct7)
				1'b0	:	{overflow, aluOut} = r1 + r2;
				1'b1	:	{overflow, aluOut} = r1 - r2;
			endcase
		slt_funct3	:	aluOut = r1 < r2 ? 32'h0ff : 32'h000;
		sltu_funct3	:	aluOut = r1 < r2 ? 32'h0ff : 32'h000;
		xor_funct3	:	aluOut = r1 ^ r2;
		or_funct3	:	aluOut = r1 | r2;
		and_funct3	:	aluOut = r1 & r2;
		sl_funct3	:	aluOut = r1 << r2;
		sr_funct3	:	case(funct7)
							1'b0	:	aluOut = r1 >> r2;
							1'b1	:	aluOut = r1 >>> r2;
						endcase
	endcase

endmodule
