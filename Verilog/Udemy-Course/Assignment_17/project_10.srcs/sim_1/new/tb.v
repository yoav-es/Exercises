`timescale 1ns / 1ps

module ripple_carry_adder_tb;

  // Inputs
  reg [3:0] A;
  reg [3:0] B;
  reg Cin;

  // Outputs
  wire [3:0] Sum;
  wire Cout;

  // Instantiate the DUT (top module)
  top #( .SIZE(4) ) dut (A, B, Cin, Cout, Sum);

  // Generate test stimulus
  initial begin
    $display("Testing 4-bit Ripple Carry Adder");
    $monitor("A = %d, B = %d, Cin = %d, Sum = %d, Cout = %d", A, B, Cin, Sum, Cout);

    // Test cases with various inputs
    A <= 4'b0000;
    B <= 4'b0000;
    Cin <= 1'b0;
    #10;  // Wait for simulation time

    A <= 4'b0101;
    B <= 4'b1010;
    Cin <= 1'b0;
    #10;

    A <= 4'b1111;
    B <= 4'b0101;
    #10;
    
    A <= 4'b1011;
    B <= 4'b0011;
    #10;


    A <= 4'b1100;
    B <= 4'b0011;
    #10;


    A <= 4'b1110;
    B <= 4'b1000;
    #10;


    A <= 4'b0111;
    B <= 4'b0100;
    #10;

    A <= 4'b1111;
    B <= 4'b1000;
    #10;

    A <= 4'b0001;
    B <= 4'b0111;
    #10;

    A <= 4'b1000;
    B <= 4'b0100;
    Cin <= 1'b1;
    #10;

    $finish;
  end

endmodule 
    

    