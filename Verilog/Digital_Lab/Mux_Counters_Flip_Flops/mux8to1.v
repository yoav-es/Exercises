module mux8to1r(x, sel, m8);
	input [7:0] x;
	input [2:0] sel;
	output m8;
	wire m0, m1, m2, m3, m4, m5, m6;
	mux2to1 mux_2_1_0(.x(x[0]), .y(x[1]), .s(sel[0]), .m(m0));
	mux2to1 mux_2_1_1(.x(x[2]), .y(x[3]), .s(sel[0]), .m(m1));
	mux2to1 mux_2_1_2(.x(x[4]), .y(x[5]), .s(sel[0]), .m(m2));
	mux2to1 mux_2_1_3(.x(x[6]), .y(x[7]), .s(sel[0]), .m(m3));
	mux2to1 mux_2_1_4(.x(m0), .y(m1), .s(sel[1]), .m(m4));
	mux2to1 mux_2_1_5(.x(m2), .y(m3), .s(sel[1]), .m(m5));
	mux2to1 mux_2_1_6(.x(m4), .y(m5), .s(sel[2]), .m(m8));
	/*
	mux2to1 mux_2_1_4(.x(x[0]), .y(x[1]), .s(sel[0]), .m(m0));
	mux2to1 mux_2_1_5(.x(x[2]), .y(x[3]), .s(sel[0]), .m(m5));
	mux2to1 mux_2_1_6(.x(m0), .y(m5), .s(sel[1]), .m(m8));
	*/
endmodule
