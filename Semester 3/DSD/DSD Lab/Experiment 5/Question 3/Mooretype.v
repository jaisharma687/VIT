module Mooretype(clk,rst,inp,out);
  input clk,rst,inp;
  output reg out;
  parameter A = 3'b000;
  parameter B = 3'b001;
  parameter C = 3'b010;
  parameter D = 3'b011;
  parameter E = 3'b100;
  parameter F = 3'b101;
  reg [2:0] state, nxt_state;
  always@(posedge clk , posedge rst) begin
    if(rst == 1)
      state <= A;
    else
      state <= nxt_state;
  end
  always@(state , inp) begin
    case(state)
      A : begin 
        if(inp == 1'b0)
          nxt_state <= A;
        else
          nxt_state <= B;
      end
      B : begin
        if(inp == 1'b0)
          nxt_state <= C;
        else
          nxt_state <= B;
      end
      C : begin
        if(inp == 1'b0)
          nxt_state <= A;
        else
          nxt_state <= D;
      end
      D : begin
        if(inp == 1'b0)
          nxt_state <= E;
        else 
          nxt_state <= B;
      end
      E : begin
        if(inp == 1'b0)
          nxt_state <= A;
        else
          nxt_state <= F;
      end
      F : begin
        if(inp == 1'b0)
          nxt_state <= A;
        else
          nxt_state <= B;
      end
      default : nxt_state <= A;
    endcase
  end
  always@(state) begin
    case(state)
      F : out <= 1;
      default : out <= 0;
    endcase
  end
endmodule