module top_tb;

  // Inputs
  reg D0, D1, D2, D3;
  reg sel0, sel1;

  // Outputs
  wire out;
  wire out_n;

  // DUT (Device Under Test) instantiation
  top DUT (
    .D0(D0), .D1(D1), .D2(D2), .D3(D3),
    .sel0(sel0), .sel1(sel1),
    .out(out), .out_n(out_n)
  );

  initial begin
    // Apply different stimuli to test all functionalities

    // Test selecting each data input (D0-D3) with different S1 values
    D0 <= 1'b0; D1 <= 1'b0; D2 <= 1'b0; D3 <= 1'b0;
    sel0 <= 1'b0; sel1 <= 1'b0;  // Select D1 (S0=0, S1=0)
    #10;
    sel0 <= 1'b0; sel1 <= 1'b1;  // Select D1 (S0=0, S1=1 - should not change)
    #10;

    D0 <= 1'b1; D1 <= 1'b0; D2 <= 1'b0; D3 <= 1'b0;
    sel0 <= 1'b1; sel1 <= 1'b0;  // Select D0 (S0=1, S1=0)
    #10;
    sel0 <= 1'b1; sel1 <= 1'b1;  // Don't care about S1 when S0=1
    #10;

    D0 <= 1'b1; D1 <= 1'b1; D2 <= 1'b1; D3 <= 1'b0;
    sel0 <= 1'b1; sel1 <= 1'b0;  // Select D3 (S0=1, S1=0)
    #10;

    // Test with invalid selection lines (ignored)
    D0 <= 1'b1; D1 <= 1'b1; D2 <= 1'b1; D3 <= 1'b1;
    sel0 <= 1'b0; sel1 <= 1'b0;  // Both S0 & S1 are invalid (ignored)
    #10;

    $finish;  // End simulation after all tests
  end

  always @(posedge sel0 or posedge sel1 or posedge D0 or posedge D1 or posedge D2 or posedge D3) begin
    // Monitor the inputs and outputs for verification
    $display("Time: %0t, D0=%b, D1=%b, D2=%b, D3=%b, sel0=%b, sel1=%b, Out=%b, Out_n=%b",
             $time, D0, D1, D2, D3, sel0, sel1, out, out_n);
  end

endmodule