module ha
(
    input a,b,
    output s,c
);
     
assign s =  a ^ b;
assign c =  a & b;

endmodule
//////////////////////////////////////////
module fa 
(
    input a,b,cin,
    output s,cout
    );
     
     
wire t1, t2,t3;
 
ha h1 (.a(a), .b(b), .s(t2), .c(t1));
ha h2 (.a(t2), .b(cin), .s(s), .c(t3));
     
     
assign cout = t1 | t3;
     
endmodule
///////////////////////////////////////////
module top
(
    input [3:0] a,b,
    input cin,
    output cout,
    output [3:0] s
);
    
    wire t0,t1,t2;
    
    fa f0 (.a(a[0]), .b(b[0]), .cin(cin), .s(s[0]), .cout(t0));
    fa f1 (.a(a[1]), .b(b[1]), .cin(t0),  .s(s[1]), .cout(t1));
    fa f2 (.a(a[2]), .b(b[2]), .cin(t1),  .s(s[2]), .cout(t2));
    fa f3 (.a(a[3]), .b(b[3]), .cin(t2),  .s(s[3]), .cout(cout));

endmodule