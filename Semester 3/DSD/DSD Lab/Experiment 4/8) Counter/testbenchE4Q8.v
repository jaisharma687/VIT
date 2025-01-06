module testbenchE4Q8;
reg clk, rst;
wire [2:0] nxt, pre;
Counter013570 test(clk,rst,pre,nxt);
always #2 clk = ~clk;
initial begin
$monitor($time,": Clk = %d , Count = %d",clk,nxt);
clk=0;
rst = 0;
#2 rst = 1;
#50 $stop;
end
endmodule
