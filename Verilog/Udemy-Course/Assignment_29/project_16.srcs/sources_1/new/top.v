`timescale 1ns / 1ps


module dmux14(
    input din ,[1:0] sel,
    output out0, out1, out2, out3
    );
    
    assign out0 = din & ~sel[0] & ~sel[1];
    assign out1 = din &  sel[0] & ~sel[1];
    assign out2 = din & ~sel[0] &  sel[1];
    assign out3 = din &  sel[0] &  sel[1];
    
endmodule
