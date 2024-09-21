module m21(in1, in2, sel, out);
//inputs
input wire in1;
input wire in2; 
input wire sel;
//outputs
output out;
//mux  function
assign out = (sel)?in2:in1;
endmodule

