module DFlipFlop(D,Q,Clk);
input D,Clk;
output reg Q;
always@(posedge Clk)
begin
Q<=D;
end
endmodule