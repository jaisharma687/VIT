module VendingMachine(clk,rst,inp,out);
  input clk,rst;
  input [3:0] inp;
  output reg out;
  parameter A = 2'b00;
  parameter B = 2'b01;
  parameter C = 2'b10;
  reg [1:0] state, nxt_state;
  always@(posedge clk , posedge rst) begin
    if(rst == 1)
      state <= A;
    else
      state <= nxt_state;
  end
  always@(state , inp) begin
    case(state)
      A : begin 
        if(inp == 0)
	begin
          nxt_state <= A;
	  out = 0;
	end
        else if (inp == 5)
	begin
          nxt_state <= B;
	  out = 0;
	end
	else if (inp == 10)
	begin
	  nxt_state <= C;
	  out = 0;
	end
      end
      B : begin 
        if(inp == 0)
	begin
          nxt_state <= A;
	  out = 0;
	end
        else if (inp == 5)
	begin
          nxt_state <= C;
	  out = 0;
	end
	else if (inp == 10)
	begin
	  nxt_state <= A;
	  out = 1;
	end
      end
       C : begin 
        if(inp == 0)
	begin
          nxt_state <= A;
	  out = 0;
	end
        else if (inp == 5)
	begin
          nxt_state <= A;
	  out = 1;
	end
	else if (inp == 10)
	begin
	  nxt_state <= A;
	  out = 0;
	end
      end
      default : 
	begin
	  nxt_state <= A;
	  out = 0;
	end
    endcase
  end
endmodule