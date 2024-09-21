`timescale 1ns / 1ps


module top(
    input a,b ,bin,
    output diff, bout
    );

wire t1, t2, t3, t4, t5;

assign t1   = a ^ b;
assign t2   = t1 ^ bin;
assign diff = t2;
assign t3   = ~a & b;
assign t4   = bin & ~t1;
assign bout = t3 | t4 ;

endmodule
