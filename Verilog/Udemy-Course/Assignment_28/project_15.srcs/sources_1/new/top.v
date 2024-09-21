`timescale 1ns / 1ps

module counter(
    input rst, clk, ld, [3:0] ldvalue,
    output [3:0] res);

reg [3:0] temp;

always@(posedge clk or posedge rst) begin
    if(rst == 1'b1)
        begin
            temp <= 4'b0000;
        end
    else
        begin
        if (ld == 1'b1)
            temp <= ldvalue;
        else
            begin
                temp <= temp - 1'b1;
            end
        end
    end     
    
assign res = temp;
    
endmodule
