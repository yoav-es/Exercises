`timescale 1ns / 1ps


module test;
  // Declare variables
  reg [7:0] a;
  reg [7:0] b;
  reg [7:0] c;

  // Initial block to assign values and display them
  initial begin
    // Initialize variables
    a = 12;       // Decimal value 12
    b = 8'o345;   // Octal value 345
    c = 8'b100;   // Binary value 100

    // Display values in decimal
    $display("Value of a (decimal): %d", a);
    $display("Value of b (octal): %o", b);
    $display("Value of c (binary): %b", c);
    
  end
endmodule