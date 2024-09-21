module seven_segment_speed(resetb, cur_speed, HEX0, HEX1);

	input wire resetb;
	//the current speed we need to translate to 7-segment
	input [2:0] cur_speed;
	//the speed we will see on the display
	output [6:0] HEX0;
	output [6:0] HEX1;
	
	parameter laps_10 = 3'b001,
				 laps_20 = 3'b010,
				 laps_30 = 3'b011,
				 laps_40 = 3'b100,
				 laps_50 = 3'b101,
				 laps_60 = 3'b110;
	
	assign HEX1 = (cur_speed == laps_10) ? 7'h79 : 
									(cur_speed == laps_20) ? 7'h24 :
									(cur_speed == laps_30) ? 7'h30 :
									(cur_speed == laps_40) ? 7'h19 :
									(cur_speed == laps_50) ? 7'h12 :
									(cur_speed == laps_60) ? 7'h02 :7'h40;
	assign HEX0 = 7'h40;		
endmodule
	