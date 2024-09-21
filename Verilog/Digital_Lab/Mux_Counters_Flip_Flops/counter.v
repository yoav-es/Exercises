module counter(clk, resetb, indicator);
	input wire clk;
	input wire resetb;
	output reg indicator;
	reg [24:0] count;
	//we decided to use the 27Mhz system clock which requiers 25 bits
	always @(posedge clk or negedge resetb)
		begin
			if(~resetb)
				count <= 25'b0000000000000000000000000;
			else if (count == 25'b1100110111111110011000000)
			//if the theres 27M cycles, the indicator turns to
			//logic 1 and the count sums 1 each time. when it happens we know
			//that 1 second passed.
				begin
					indicator <= 1;
					count <= 25'b0000000000000000000000000;
				end
			else
				begin
					count <= count + 25'b0000000000000000000000001;
					indicator <= 0;
				end
		end
endmodule	
