`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Engineer: Yoav Eshed
// 
// Create Date: 01.09.2024 22:48:41
// Design Name: half_adder
// Module Name: top
//////////////////////////////////////////////////////////////////////////////////


//basic half adder module
module top(

input a,b,

output s, c
);

assign s = a ^ b;

assign c = a & b;

endmodule
