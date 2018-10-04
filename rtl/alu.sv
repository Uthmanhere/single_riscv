
parameter add_funct3	=	3'b000;
parameter slt_funct3	=	3'b010;
parameter sltu_funct3	=	3'b011;
parameter xor_funct3	=	3'b100;
parameter or_funct3		=	3'b110;
parameter and_funct3	=	3'b111;
parameter sll_funct3	=	3'b001;
parameter sr_funct3		=	3'b101;


module alu (

		input	[31:0]	r1,
		input	[31:0]	r2,
		input	[2:0]	funct3,
		output			zero,
		output	[31:0]	aluOut

	);


	assign zero = aluOut == 32'h00 ? 1'b1 : 1'b0;

	always_comb
	case(funct3)
		add_funct3	:	assign aluOut = r1 + r2;
//		slt_funct3	:	assign aluOut = r1 < r2;
//		sltu_funct3	:	assign aluOut = r1 < r2;
//		xor_funct3	:	assign aluOut = r1 ^ r2;
		or_funct3	:	assign aluOut = r1 | r2;
		and_funct3	:	assign aluOut = r1 & r2;
		sll_funct3	:	assign aluOut = r1 << r2;
		sr_funct3	:	assign aluOut = r1 >> r2;
	endcase
/*
	if (aluOutReg == 32'b0) begin
		zeroReg = 1'b1;
	end else begin
		zeroReg = 1'b0;
	end
*/
endmodule
