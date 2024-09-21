module seconds_timer(clk, resetb, hex1, hex2);
	input wire clk;
	input wire resetb;
	//the seconds keeper lets us know what digit we need to set
	//at every moment the hex0 and hex1
	reg [6:0] seconds_indicator;
	//digit0 refers to the ones digits and digit1 refers to the tens digits
	reg [3:0] digit0;
	reg [3:0] digit1;
	output reg [6:0] hex1;
	output reg [6:0] hex2;
	//the indicator we defined in the counter module
	wire indicator;
	
	counter counter_inst(.clk(clk), .resetb(resetb), .indicator(indicator));
	//we get the value of the seconds indicator each second.
	always @(posedge clk or negedge resetb)
		begin
			if(~resetb)
				seconds_indicator <= 7'b0000000;
			else if (indicator)
				begin
				seconds_indicator <= seconds_indicator + 7'b0000001;
				end
			//if the seconds indicator passes the value 99, we reset it to 0
			else if (seconds_indicator > 7'b1100011)
			begin
				seconds_indicator <= 7'b0000000;
			end
		end
	
	always @(posedge clk or negedge resetb)
		begin
			
			//each second we define the digits that we will see on screen
			if (~resetb)
				begin	
				digit0 <= 4'b0000;
				digit1 <= 4'b0000;
				end
			else
				begin
				digit0 <= seconds_indicator%10;
				digit1 <= (seconds_indicator-digit0)/10;
				end
			//we define hex1 and hex2 compared with the values of the
		    //parameters digit0 and digit1
			case (digit0)
				4'b0000: hex1 <= 7'b1000000;
				4'b0001: hex1 <= 7'b1111001;
				4'b0010: hex1 <= 7'b0100100;
				4'b0011: hex1 <= 7'b0110000;
				4'b0100: hex1 <= 7'b0011001;
				4'b0101: hex1 <= 7'b0010010;
				4'b0110: hex1 <= 7'b0000010;
				4'b0111: hex1 <= 7'b1111000;
				4'b1000: hex1 <= 7'b0000000;
				4'b1001: hex1 <= 7'b0010000;
			endcase	
			case (digit1)
				4'b0000: hex2 <= 7'b1000000;
				4'b0001: hex2 <= 7'b1111001;
				4'b0010: hex2 <= 7'b0100100;
				4'b0011: hex2 <= 7'b0110000;
				4'b0100: hex2 <= 7'b0011001;
				4'b0101: hex2 <= 7'b0010010;
				4'b0110: hex2 <= 7'b0000010;
				4'b0111: hex2 <= 7'b1111000;
				4'b1000: hex2 <= 7'b0000000;
				4'b1001: hex2 <= 7'b0010000;
			endcase	
		end
endmodule
				
				