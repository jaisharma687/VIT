module DFF(Q,Qn,clk,rst,D);
input clk, rst, D;
output reg Q,Qn;
always@(posedge clk,posedge rst)
if(rst!=0)
begin
Q <= 1'b0;
Qn <= 1'b1;
end
else
begin
Q <= D;
Qn <= ~D;
end
endmodule
