module counter(clk, resetb, cur_speed, on_switch, step_size_sw, quarter_button, indicator);

	input wire clk, resetb, on_switch, step_size_sw, quarter_button;
	reg [26:0] count;
	wire [26:0] clock_cycles;
	
	reg [26:0] current_cycles; //our current clock cycles number
	
	input [2:0] cur_speed;
	
	reg [6:0] step_counter; //counts the number of steps we did
	reg finished_quarter; //indicator which tells us if we finished a quarter
	output reg indicator; //our pulse when we make 1 full/half step
								 //of a circle
	reg [26:0] cycles_counter; //sums the cycles we passed so far
	
	reg long_press_reg;
	wire long_press_wire;
	
	parameter laps_10 = 3'b001,
				 laps_20 = 3'b010,
				 laps_30 = 3'b011,
				 laps_40 = 3'b100,
				 laps_50 = 3'b101,
				 laps_60 = 3'b110,
				 full_step = 1'b0,
				 half_step = 1'b1;
	
	//define the number of cycles needed according to the current speed/step size mode
	assign clock_cycles = (cur_speed == laps_10 && step_size_sw == full_step) ? 27'b001_0110_1110_0011_0110_0000:
								 (cur_speed == laps_20 && step_size_sw == full_step) ? 27'b000_1011_0111_0001_1011_0000:	
								 (cur_speed == laps_30 && step_size_sw == full_step) ? 27'b000_0111_1010_0001_0010_0000:		
								 (cur_speed == laps_40 && step_size_sw == full_step) ? 27'b000_0101_1011_1000_1101_1000:	
								 (cur_speed == laps_50 && step_size_sw == full_step) ? 27'b000_0100_1001_0011_1110_0000:
								 (cur_speed == laps_60 && step_size_sw == full_step) ? 27'b000_0011_1101_0000_1001_0000:
								 
								 (cur_speed == laps_10 && step_size_sw == half_step) ? 27'b000_1011_0111_0001_1011_0000: 
								 (cur_speed == laps_20 && step_size_sw == half_step) ? 27'b000_0101_1011_1000_1101_1000:	
								 (cur_speed == laps_30 && step_size_sw == half_step) ? 27'b000_0011_1101_0000_1001_0000:		
								 (cur_speed == laps_40 && step_size_sw == half_step) ? 27'b000_0010_1101_1100_0110_1100:	
								 (cur_speed == laps_50 && step_size_sw == half_step) ? 27'b000_0010_0100_1001_1111_0000:
								 (cur_speed == laps_60 && step_size_sw == half_step) ? 27'b000_0001_1110_1000_0100_1000:
								 27'b000_0000_0000_0000_0000_0000;
								
	
	
	always @ (posedge clk or negedge resetb) begin
		if(~resetb)
			long_press_reg <= 1'b0;
		
		else
			long_press_reg <= ~quarter_button;	
	end

	assign long_press_wire = (~quarter_button & ((~quarter_button)^long_press_reg));
	
		
	
	
	//continious mode
	always @(posedge clk or negedge resetb)
	begin
		if(~resetb)
		begin
			current_cycles <= 27'b000_0000_0000_0000_0000_0000;
			indicator <= 1'b0;
			finished_quarter <= 1'b0;

		end
			
		else if (on_switch)
		begin
			if (current_cycles ==clock_cycles) //if we got to the clock cycles for the current mode, our indicator turns to logic 1
			begin
				indicator <= 1'b1; //pulse for making a step
				current_cycles <= 27'b000_0000_0000_0000_0000_0000;
			end
			else
			begin
				current_cycles <= current_cycles + 27'b000_0000_0000_0000_0000_0001;
				indicator<=1'b0;
			end
		end
		
	
		//QUARTER MODE

		else if (~on_switch && long_press_wire)
		begin
			finished_quarter <= 1'b1;
		end	
		
		else if (finished_quarter && clk)
		begin
			if (step_size_sw == full_step) //FULL STEP
			begin

				if (cycles_counter == clock_cycles)//our indication for knowing when we got to the correct cycles number
				begin
					indicator <= 1'b1; //pulse for making a step
					cycles_counter <= 27'b0;
					step_counter <= step_counter + 7'b1;
					if (step_counter == 7'b011_0010) //if we passed 50 steps it means we finished a quarter
					begin
						finished_quarter <= 1'b0;
						step_counter <= 7'b0;
						indicator <= 1'b0;
					end
				end	
				else
				begin
					cycles_counter <= cycles_counter + 27'b1;
					indicator <= 1'b0;
				end
			end	
					
				
		
			else if (step_size_sw == half_step) //HALF STEP
			begin

				if (cycles_counter == clock_cycles)//our indication for knowing when we got to the correct cycles number
				begin
					indicator <= 1'b1; //pulse for making a step
					cycles_counter <= 27'b0;
					step_counter <= step_counter + 7'b1;
					if (step_counter == 7'b110_0100) //if we passed 50 steps it means we finished a quarter
					begin
						finished_quarter <= 1'b0;
						step_counter <= 7'b0;
						indicator <= 1'b0;
					end
				end	
				else
				begin
					cycles_counter <= cycles_counter + 27'b000_0000_0000_0000_0000_0000_0001;
					indicator <= 1'b0;
				end
			end
		end
		

		
		else
		begin
			indicator <= 1'b0;
		end	
	end
endmodule	
		
			