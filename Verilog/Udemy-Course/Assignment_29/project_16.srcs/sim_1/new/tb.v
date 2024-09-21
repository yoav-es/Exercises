module demux_tb;

  reg in;
  reg [1:0] sel;
  wire out0, out1, out2, out3;

  dmux14 dut (
    .din(in),
    .sel(sel),
    .out0(out0),
    .out1(out1),
    .out2(out2),
    .out3(out3)
  );
  integer i = 0;
  initial begin
    // Test all possible combinations
    for (i = 0; i < 4; i = i+1) begin
      in = 1;
      sel = i;
      #10;
      $display("in=%b, sel=%b, out0=%b, out1=%b, out2=%b, out3=%b", in, sel, out0, out1, out2, out3);
      in = 0;
      #10;
      $display("in=%b, sel=%b, out0=%b, out1=%b, out2=%b, out3=%b", in, sel, out0, out1, out2, out3);
    end

    $finish;
  end

endmodule