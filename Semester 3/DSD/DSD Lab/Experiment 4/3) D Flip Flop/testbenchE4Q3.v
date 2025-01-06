module testbenchE4Q3;
wire Q;
reg D,Clk;
DFlipFlop test(D,Q,Clk);
always #2 Clk=~Clk;
initial begin
$monitor($time,": Clk = %b , D = %b , Q = %b",Clk,D,Q);
Clk<=0;
D<=0;
#3 D<=1;
#4 D<=0;
#3 D<=1;
#1 D<=1'bx;
#2 D<=1;
#2;
$stop;
end
endmodule