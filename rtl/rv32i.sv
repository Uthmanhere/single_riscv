module rv32i (

	input	clk

);

	logic	[31:0]	pc;

	logic	[31:0]	inst;

	instMem instMem(
		.clk(clk),
		.pc(pc),
		.inst(inst)
	);

	logic	write_ctrl_regfile;
	logic	[31:0]	write_data_regfile;
	logic	[31:0]	rs1;
	logic	[31:0]	rs2;

	regfile regfile(
		.clk(clk),
		.write_ctrl(write_ctrl_regfile),
		.write_data(write_data_regfile),
		.write_addr(inst[11:7]),
		.rs1_addr(inst[19:15]),
		.rs2_addr(inst[24:20]),
		.rs1(rs1),
		.rs2(rs2)
	);

	logic	[31:0]	imm;
	logic			imm_ctrl;

	immGen immGen(
		.inst(inst),
		.imm_ctrl(imm_ctrl),
		.imm(imm)
	);

	logic	[02:0]	funct3;
	logic			funct7;
	logic			zero;
	logic			overflow;
	logic	[31:0]	aluOut;

	logic	aluOp_ctrl;
	logic	[31:0]	aluOp;

	assign aluOp = aluOp_ctrl ? imm : rs2;

	alu alu(
		.op1(rs1),
		.op2(aluOp),
		.funct3(inst[14:12]),
		.funct7(inst[30]),
		.zero(zero),
		.overflow(overflow),
		.aluOut(aluOut)
	);

	logic	write_ctrl_dataMem;
	logic	[31:0]	dataOut;

	dataMem dataMem(
		.clk(clk),
		.write_ctrl(write_ctrl_dataMem),
		.write_data(rs2),
		.data_addr(aluOut),
		.dataOut(dataOut)
	);

	logic	memRead_ctrl;

	assign write_data_regfile = memRead_ctrl ? dataOut : aluOut;

endmodule
