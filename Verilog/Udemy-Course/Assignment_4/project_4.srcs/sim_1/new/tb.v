`timescale 1ns / 1ps

module tb;

  // Inputs
  reg clk, rst, d;

  // Outputs
  wire q, qbar;

  // DUT (Device Under Test) instantiation
  top DUT (
    .clk(clk), .rst(rst), .d(d), .q(q), .qbar(q_bar)
  );

  initial begin 
      rst <= 1'b0;
      d   <= 1'b0;
      q   <= 1'b0;
      qbar <=1'b0;
      #10
      rst <=1'b1;
      #10 
      rst <=1'b0;
      d   <=1'b1;
  end

endmodule