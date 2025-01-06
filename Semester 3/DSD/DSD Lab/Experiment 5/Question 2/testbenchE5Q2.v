module testbenchE5Q2;
  reg clk,rst; reg [3:0] inp;
  wire out;
  VendingMachine test(clk,rst,inp,out);
  initial begin
    clk = 0;
    forever #5 clk = ~clk;
  end
  initial begin
    $monitor($time,": Input = %d , Output = %b",inp,out);
    inp = 0;
    rst = 1;
    #30 rst = 0;
    #40 inp = 0;
    #10 inp = 5;
    #10 inp = 10;
    #10 inp = 10;
    #10 inp = 0;
    #10 inp = 10;
    #10 inp = 10;
    #10 inp = 5;
    #10 inp = 10;
    #10 inp = 10;
    #10 inp = 0;
    #10 inp = 5;
    #10 inp = 5;
    #10 inp = 10;
    #10 inp = 10;
    #10 inp = 0;
    #10 inp = 10;
    #10 inp = 10;
    #10 inp = 5;
    #10 inp = 10;
    #10 inp = 10;
    #10 inp = 0;
    #10 inp = 5;
    $stop;
  end
 initial begin
   $dumpfile("dump.vcd"); 
   $dumpvars; 
 end
endmodule
