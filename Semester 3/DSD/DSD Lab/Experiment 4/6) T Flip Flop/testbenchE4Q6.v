module testbenchE4Q6;
reg T,Clk;
wire Q,Qb;
TFlipFlop test(Q,Qb,T,Clk);
always #10 Clk = ~Clk;
initial begin
$monitor($time,": Clk = %d , T = %d , Q = %d , Qb = %d",Clk,T,Q,Qb);
Clk = 1;
#20 T=0;
#20 T=1;
#20 T=0;
#20 T=1;
#20 $stop;
end
endmodule