`timescale 1ns / 1ps
module tb;

  // Input and output signals
  reg  [7:0] D;
  wire [2:0] Q;

  // Instantiate the priority encoder module
  top DUT (D, Q);

  initial begin
    // Test all possible input combinations
    D = 8'b00000000;  // No active bits (expected Q=000)
    #10;
    if (Q !== 3'b000) begin
      $display("Error: Incorrect output for D=00000000, Q=%b", Q);
    end

    D = 8'b01000000;  // Active bit D0 (expected Q=001)
    #10;
    if (Q !== 3'b001) begin
      $display("Error: Incorrect output for D=00000001, Q=%b", Q);
    end

    D = 8'b00100000;  // Active bit D1 (expected Q=010)
    #10;
    if (Q !== 3'b010) begin
      $display("Error: Incorrect output for D=00000010, Q=%b", Q);
    end

    D = 8'b00010000;  // Active bit D1 (expected Q=010)
    #10;
    if (Q !== 3'b101) begin
      $display("Error: Incorrect output for D=00000010, Q=%b", Q);
    end
    D = 8'b00001000;  // Active bit D1 (expected Q=010)
    #10;
    if (Q !== 3'b100) begin
      $display("Error: Incorrect output for D=00000010, Q=%b", Q);
    end
    D = 8'b00000100;  // Active bit D1 (expected Q=010)
    #10;
    if (Q !== 3'b011) begin
      $display("Error: Incorrect output for D=00000010, Q=%b", Q);
    end
    D = 8'b00000010;  // Active bit D1 (expected Q=010)
    #10;
    if (Q !== 3'b010) begin
      $display("Error: Incorrect output for D=00000010, Q=%b", Q);
    end
    D = 8'b00000001;  // Active bit D1 (expected Q=010)
    #10;
    if (Q !== 3'b001) begin
      $display("Error: Incorrect output for D=00000010, Q=%b", Q);
    end
    D = 8'b00000000;  // Active bit D1 (expected Q=010)
    #10;
    if (Q !== 3'b000) begin
      $display("Error: Incorrect output for D=00000010, Q=%b", Q);
    end

    $finish;
  end

  // Monitor the input and output signals
  always @(posedge D) begin
    $monitor("D = %b, Q = %b", D, Q);
  end

endmodule