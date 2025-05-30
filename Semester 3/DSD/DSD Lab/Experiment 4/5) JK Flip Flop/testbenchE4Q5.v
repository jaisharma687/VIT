module testbenchE4Q5;
reg J, K;
wire Q, Qb;
reg Clk;
JKFlipFlop test(Q, Qb, J, K, Clk);
initial begin
Clk = 0;
end
always #5 Clk = ~Clk;
initial begin
$monitor($time, ": Clk = %b , J = %b, K = %b , Q = %b , Qbar = %b", Clk, J, K, Q, Qb);
#20 J = 0; K = 0;
#20 J = 0; K = 1;
#20 J = 1; K = 0;
#20 J = 1; K = 1;
#20;
$stop;
end
endmodule