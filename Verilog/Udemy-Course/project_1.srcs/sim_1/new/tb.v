`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01.09.2024 22:48:59
// Design Name: 
// Module Name: tb
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module tb();

reg a, b;

wire s, c;


top dut (a,b,s,c);

initial begin

a = 0;
b = 0;
#10;
a = 0;
b = 1;
#10;
a = 1;
b = 0;
#10
a = 1;
b = 1;
#10
a = 0;
b = 0;
end



endmodule