`timescale 1ns / 1ps

module ring_counter_4bit (
    input clk,
    input reset,
    output reg [3:0] q
);

  always @(posedge clk) begin
    if (reset) begin
      q <= 4'b1000; // Initial state on reset
    end else begin
      q <= {q[0], q[3], q[2], q[1]}; // Shift left
    end
  end

endmodule