module motion_state_machine(clk,resetb,rotation_direction, step_size_sw, current_state, indicator);

	input wire resetb;              // key
	input wire clk;                 // clk
	
	input wire rotation_direction;  // key
	
	input wire step_size_sw;        // key
	
	input wire indicator; 

	output reg[3:0] current_state;
	
	reg [3:0]next_state;
	
				//rotation states
	parameter idle    = 4'b0000,
	 
			  fstep_1 = 4'b1000,
			  fstep_2 = 4'b0010,
			  fstep_3 = 4'b0100,
			  fstep_4 = 4'b0001,
			  
			  hstep_1 = 4'b1010,
			  hstep_2 = 4'b0110,
			  hstep_3 = 4'b0101,
			  hstep_4 = 4'b1001,
					
			  // Roatation directions			
			  clockwise = 1'b0,
			  counterclockwise = 1'b1,
			  
			  //step size
			  full_step = 1'b0,
			  half_step = 1'b1;
			
	
		// Rotation conditions, 
	always @(posedge clk or negedge resetb)
		  begin
				 if (~resetb)
					//if reset is pressed
						next_state = idle;
						
						
				 else if(indicator)
					begin
					
					current_state = next_state;
					//Full step clockwise direction 
					if(rotation_direction == clockwise && step_size_sw == full_step)
						
							case (current_state)
							idle:  
							        next_state <= fstep_1;
							fstep_1:   
									next_state <= fstep_2;
							fstep_2:   
									next_state <= fstep_3;
							fstep_3:
									next_state <= fstep_4;	
							fstep_4:
									next_state <= fstep_1;
							default :
									next_state <= idle;
							endcase
						
					//Full step counterclockwise direction 
					else if(rotation_direction == counterclockwise && step_size_sw == full_step)
						
							case (current_state)
							idle:  
							        next_state <= fstep_1;
							fstep_1:   
									next_state <= fstep_4;
							fstep_4:   
									next_state <= fstep_3;
							fstep_3:
									next_state <= fstep_2;	
							fstep_2:
									next_state <= fstep_1;
							default :
									next_state <= idle;
							endcase
						
					//halt step clockwise direction 
					else if(rotation_direction == clockwise && step_size_sw == half_step)
						
							case (current_state)
							idle:  
							        next_state <= fstep_1;
							fstep_1:   
									next_state <= hstep_1;
							hstep_1:   
									next_state <= fstep_2;
							fstep_2:
									next_state <= hstep_2;	
							hstep_2:
									next_state <= fstep_3;
							fstep_3:
									next_state <= hstep_3;	
							hstep_3:
									next_state <= fstep_4;
						   fstep_4:
									next_state <= hstep_4;	
							hstep_4:
									next_state <= fstep_1;
							default :
									next_state <= idle;
							endcase
							
					//halt step counterclockwise direction 
					else if(rotation_direction == counterclockwise && step_size_sw == half_step)
						
							case (current_state)
							idle:  
							        next_state <= fstep_1;
							fstep_1:   
									next_state <= hstep_4;
							hstep_4:   
									next_state <= fstep_4;
							fstep_4:
									next_state <= hstep_3;	
							hstep_3:
									next_state <= fstep_3;
							fstep_3:
									next_state <= hstep_2;	
							hstep_2:
									next_state <= fstep_2;
						   fstep_2:
									next_state <= hstep_1;	
							hstep_1:
									next_state <= fstep_1;
							default :
									next_state <= idle;
							endcase
			
					end
				else
					current_state = current_state; // enable to the motor to finnish step
				end
		  //end cases

endmodule

		 
	
	
