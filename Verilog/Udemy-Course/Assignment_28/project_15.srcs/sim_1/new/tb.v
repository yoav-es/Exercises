`timescale 1ns / 1ps

module tb;

reg rst, clk, ld;
reg [3:0] ldval;
wire [3:0] out;

counter dut(rst,clk,ld, ldval,out);

always #5 clk = ~clk;

task reset_counter;
  begin
    rst = 1'b1;
    #10;
    rst = 1'b0;
  end
endtask

task load_value;
  input [3:0] value;
  begin
    ld = 1'b1;
    ldval = value;
    #10;
    ld = 1'b0;
  end
endtask

initial begin
  reset_counter();
  load_value($urandom);
  #40;
  load_value($urandom);
  reset_counter();
  load_value($urandom);
  #20;
  load_value($urandom);
  $finish();
end

endmodule