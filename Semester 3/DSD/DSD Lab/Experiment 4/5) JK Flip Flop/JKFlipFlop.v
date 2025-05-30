module JKFlipFlop(Q,Qb,J,K,Clk);
input J,K,Clk;
output reg Q,Qb;
always@(posedge Clk)
begin
case({J,K})
2'b00 : Q<=Q;
2'b01 : Q<=0;
2'b10 : Q<=1;
2'b11 : Q<=~Q;
endcase
assign Qb = ~Q;
end
endmodule