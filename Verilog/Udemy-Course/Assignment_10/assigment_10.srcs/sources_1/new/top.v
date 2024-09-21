`timescale 1ns / 1ps



module top(
    input D0,D1,D2,D3,sel0, sel1,
    output out, out_n
    );
    
wire y1, y2;

    assign y1    = ~(~sel0 & D0) | (sel0 & D1);
    assign y2    = ~(~sel0 & D2) | (sel0 & D3);
    assign out   = sel1 ? y2 : y1; 
    assign out_n = ~out;
      
endmodule
