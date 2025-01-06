module MooreByDFF(y,clk,rst,x);
output y;
input clk, rst, x;
wire [2:0] D,Q,Qn;
assign D[0] = (Q[0] & ~Q[2] & x) | (Q[1] & Q[2] & ~x);
assign D[1] = (~x & ~Q[0] & ~Q[1] & Q[2]) | (x & ~Q[2] & Q[1]);
assign D[2] = x;
assign y = Q[0] & Q[2];
DFF D0 (Q[0],Qn[0],clk,rst,D[0]);
DFF D1 (Q[1],Qn[1],clk,rst,D[1]);
DFF D2 (Q[2],Qn[2],clk,rst,D[2]);
endmodule
