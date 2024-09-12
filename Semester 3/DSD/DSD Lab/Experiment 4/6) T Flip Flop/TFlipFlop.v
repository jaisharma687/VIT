module TFlipFlop(Q,Qb,T,Clk);
input T,Clk;
output Q,Qb;
reg Q=0;
reg Qb;
always@(posedge Clk)
begin
case(T)
1'b0 : Q = Q;
1'b1 : Q = ~Q;
endcase
assign Qb = ~Q;
end
endmodule