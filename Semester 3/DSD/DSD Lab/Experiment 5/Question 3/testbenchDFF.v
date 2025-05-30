module testbenchDFF;
reg clk,x,rst;
wire y;
MooreByDFF test(y,clk,rst,x);
initial begin
clk = 0;
forever #5 clk = ~clk;
end
initial begin
    $monitor($time,": clk = %b , rst = %b , x = %b , y = %b",clk,rst,x,y);
    x = 0;
    rst = 1;
    #30 rst = 0;
    #40 x = 0;
    #10 x = 1;
    #10 x = 0;
    #10 x = 1;
    #10 x = 1;
    #10 x = 1;
    #10 x = 0;
    #10 x = 1;
    #10 x = 0;
    #10 x = 1;
    #10 x = 0;
    #10 x = 1;
    #100 $finish;
  end
 initial begin
   $dumpfile("dump.vcd"); 
   $dumpvars; 
 end
endmodule
