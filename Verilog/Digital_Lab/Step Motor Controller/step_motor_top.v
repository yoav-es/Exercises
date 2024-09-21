module step_motor_top(clk, resetb, speed_button, quarter_button, step_size_sw, 
						rotation_direction, on_switch, current_state, HEX0, HEX1);
			
			
		input wire clk, resetb, step_size_sw, rotation_direction, on_switch, 
						speed_button, quarter_button;
		wire indicator;
		wire [2:0] cur_speed;
		output wire [6:0] HEX0;
		output wire [6:0] HEX1;
		output wire[3:0] current_state;
		
		speed_controller speed_controller_inst(.resetb(resetb), .speed_button(speed_button), .out_speed(cur_speed));
		
		seven_segment_speed seven_segment_speed_inst(.resetb(resetb), .cur_speed(cur_speed), .HEX0(HEX0), .HEX1(HEX1));
		
		motion_state_machine motion_state_machine_inst(.clk(clk), .resetb(resetb), .rotation_direction(rotation_direction), .step_size_sw(step_size_sw), .current_state(current_state), .indicator(indicator));

		counter counter_inst(.clk(clk), .resetb(resetb), .cur_speed(cur_speed), .on_switch(on_switch), .step_size_sw(step_size_sw), .quarter_button(quarter_button), .indicator(indicator));

		

endmodule
