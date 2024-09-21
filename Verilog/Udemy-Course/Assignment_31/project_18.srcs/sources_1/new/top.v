`timescale 1ns / 1ps
 
module pwm(
input clk, rst, 
output reg dout
);
 
parameter period = 100;
integer count = 0;
integer ton   = 0;
reg ncyc      = 1'b0;
reg dir       = 1'b0; // 0: increasing, 1: decreasing

always@(posedge clk)
begin
     if(rst == 1'b1)
        begin
         count <= 0;
         ton   <= 0;
         ncyc  <= 1'b0;
         dir   <= 1'b0; // Initialize dir
        end   
     else 
       begin
            if(count <= ton) 
              begin
              count <= count + 1;
              dout  <= 1'b1;
              ncyc  <= 1'b0;
              end
            else if (count < period)
              begin
              count <= count + 1;
              dout <= 1'b0;
              ncyc <= 1'b0;
              end
            else
               begin
               ncyc  <= 1'b1;
               count <= 0;
               end
       end
end
 
 
always @(posedge clk) begin
    if (rst == 1'b0) begin
        if (ncyc == 1'b1) begin
            // Update direction based on ton value
            if (ton >= period) begin
                dir <= 1'b1;  // Start decrementing
                ton <= period - 5; // Ensure ton is set to period
            end else if (ton <= 0) begin
                dir <= 1'b0;  // Start incrementing
                ton <= 5;     // Ensure ton is set to 0
            end
            // Update ton based on direction
            if (dir == 1'b0) begin
                // Increment ton, but ensure it does not exceed period
                if (ton < period) begin
                    ton <= ton + 5;
                end
            end else if (dir == 1'b1) begin
                // Decrement ton, but ensure it does not go below 0
                if (ton > 0) begin
                    ton <= ton - 5;
                end
            end
        end
    end
end
endmodule