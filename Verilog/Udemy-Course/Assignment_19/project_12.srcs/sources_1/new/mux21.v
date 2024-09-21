`timescale 1ns / 1ps

module mux21(
    input a,b,s,
    output y
    );
    
    assign y = (s == 1'b1) ? a : b; 

endmodule
