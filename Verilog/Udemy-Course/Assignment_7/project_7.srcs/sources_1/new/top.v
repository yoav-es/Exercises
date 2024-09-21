`timescale 1ns / 1ps


module top;
reg [15:0] a = 16'hABCD;
reg [15:0] b = 16'h1234;
reg [15:0] c = 16'hABCD;
reg [15:0] d = 16'h1234;

reg [15:0] temp;
//blocking example
initial begin
    $display("blocking start swap - a : %0h and b :%0h", a, b);
    temp = a;
    a    = b;
    b    = temp; 
    #5
    $display("blocking end swap - a : %0h and b :%0h", a, b);
end
    
//non-blocking example 
initial begin 
    $display("non blocking start swap - a : %0h and b :%0h", c, d);
    c <= d;
    d <= c;
    #5;
    $display("non blocking end swap : %0h and b :%0h", c, d);
end
endmodule
