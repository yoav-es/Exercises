`timescale 1ns / 1ps

module top (
  input  [7:0] d,  // Data inputs (D7 is MSB, D0 is LSB)
  output reg  [2:0] q   // Encoded output (highest priority encoded)
);

  // Case statement for priority encoding
  always @(d) begin
    case (d)
      8'b00000000: q <= 3'b000;  // No active bits (default)
      8'b00000000_10000000: q <= 3'b000;  // D0 active 
      8'b00000000_01000000: q <= 3'b001;  // D1 active 
      8'b00000000_00100000: q <= 3'b010;  // D2 active 
      8'b00000000_00010000: q <= 3'b011;  // D3 active
      8'b00000000_00001000: q <= 3'b100;  // D4 active
      8'b00000000_00000100: q <= 3'b101;  // D5 active
      8'b00000000_00000010: q <= 3'b110;  // D6 active
      8'b00000000_00000001: q <= 3'b111;  // D7 active 
      default: q <= 3'bX;  
    endcase
  end

endmodule