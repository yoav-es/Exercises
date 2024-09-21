`timescale 1ns / 1ps

module tb;

  reg clk, reset;
  wire [3:0] q;

  ring_counter_4bit dut (
    .clk(clk),
    .reset(reset),
    .q(q)
  );

  always #5 clk = ~clk;

  initial begin
    reset = 1'b1;
    clk   = 1'b0;
    #10;
    reset = 1'b0;
    #40;
    $finish;
  end

endmodule