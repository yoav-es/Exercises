module speed_controller(resetb, speed_button, out_speed);

	//inputs for the speed conroller
	input wire resetb, speed_button;
	
	//this parameter will be an indicator for adding 
	//speed or decreasing if needed. 1- add, 0 - decrease.
	reg speed_up;
	
	//the current speed will be defined by number
	output reg [2:0] out_speed;
	
	parameter ten_laps = 3'b001,
				 laps_50 = 3'b101,
				 laps_20 = 3'b010;
	
	
	always @(negedge speed_button or negedge resetb)
	begin
		if (~resetb)
		begin
			out_speed <= 3'b001;
			speed_up <= 1'b1; 
		end
		else
		begin
			if (~speed_button && speed_up) //pressing the speed button will increase speed
			begin
				out_speed <= out_speed + ten_laps;
				if (out_speed == laps_50 )
					speed_up <= 1'b0; //we got to 60 laps per minute 
			end
		
			else if (~speed_button && ~speed_up) //pressing the speed button will now decrease speed
			begin
				out_speed <= out_speed - ten_laps;
				if (out_speed == laps_20)
					speed_up <= 1'b1; //we got to 10 laps per minute
			end
		end	
	end				
endmodule					
				
				
			