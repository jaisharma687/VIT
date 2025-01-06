module testbenchE5Q3();
  reg clk,rst,inp;
  wire out;
  Mooretype uut(clk,rst,inp,out);
  initial begin
    clk = 0;
    forever #5 clk = ~clk;
  end
  initial begin
    $monitor($time,": Input = %b , Output = %b",inp,out);
    inp = 0;
    rst = 1;
    #30 rst = 0;
    #40 inp = 0;
    #10 inp = 1;
    #10 inp = 0;
    #10 inp = 1;
    #10 inp = 1;
    #10 inp = 1;
    #10 inp = 0;
    #10 inp = 1;
    #10 inp = 0;
    #10 inp = 1;
    #10 inp = 0;
    #10 inp = 1;
    #100 $finish;
  end
 initial begin
   $dumpfile("dump.vcd"); 
   $dumpvars; 
 end
endmodule