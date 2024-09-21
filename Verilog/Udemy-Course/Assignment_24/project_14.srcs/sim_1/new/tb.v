`timescale 1ns / 1ps

module no_fsm_tb;

  reg clk, rst, din;//////////////////////////////////////////////////////////////////////25
  wire dout;//module tb;

  fsm uut (//  reg clk, rst, din;
    .clk(clk), //  wire dout;
    .rst(rst), 
    .din(din), //  mil uut (
    .dout(dout)//    .clk(clk),
  );//    .rst(rst),
//    .din(din),
  initial begin//    .dout(dout)
    clk = 1'b0;//  );
    rst = 1'b1;
    din = 1'b0;//  initial begin
//    clk = 1'b0;
    #10 rst = 1'b0;//    rst = 1'b1;
//    din = 1'b0;
    // Apply input sequence 10011001
    #10 din = 1'b1;//    #5 rst = 1'b0;
    #10 din = 1'b0;
    #10 din = 1'b0;//    // Apply input sequence 101100
    #10 din = 1'b1;//    #10 din = 1'b1;
    #10 din = 1'b0;
    #10 din = 1'b0;
    #10 din = 1'b1;//    #10 din = 1'b0;
    #10 din = 1'b0;//    #10 din = 1'b1;
    #10 din = 1'b0;//    #10 din = 1'b1;
    #10 din = 1'b1;//    #10 din = 1'b0;
//    #10 din = 1'b0;
    #100 $finish;//    #10 din = 1'b0;
  end//    #10 din = 1'b0;
//    #10 din = 1'b0;
  always #5 clk = ~clk;//    #10 din = 1'b1;

  // Optional: Add a monitor for debugging//    #100 $finish;
  // initial begin//  end
  //   $monitor("time=%t clk=%b rst=%b din=%b dout=%b", $time, clk, rst, din, dout);//////////////////////////////////////////////////////////////////////////24
  // end//  always #5 clk = ~clk;

endmodule  // Optional: Add a monitor for debugging
  // initial begin
  //   $monitor("time=%t clk=%b rst=%b din=%b dout=%b", $time, clk, rst, din, dout);
  // end

//endmodule

//`timescale 1ns / 1ps

//module tb;

//  // Inputs
//  reg clk, rst, din;

//  // Outputs
//  wire dout;

//  // Instantiate the Unit Under Test (UUT)
//  moo uut (
//    .clk(clk), 
//    .rst(rst), 
//    .din(din), 
//    .dout(dout)
//  );

//  // Clock generation
//  always #10 clk = ~clk;

//  // Testbench stimulus
//  initial begin
//    clk = 0;
//    rst = 1;
//    din = 1'b0;

//    #10 rst = 0; // Release reset after 10 ns

//    // Apply input sequence 10010 with clk*2
//    #20 din = 1'b1;
//    #20 din = 1'b0;
//    #20 din = 1'b0;
//    #20 din = 1'b1;
//    #20 din = 1'b0;
//    #100
//    // Apply input sequence 10010 with clk*2
//    #20 din = 1'b1;
//    #20 din = 1'b0;
//    #20 din = 1'b0;
//    #20 din = 1'b1;
//    #20 din = 1'b0;
//    // Monitor the output
//    #100 $monitor("time = %t, clk = %b, rst = %b, din = %b, dout = %b", $time, clk, rst, din, dout);

//    #100 $finish;
//  end

//endmodule