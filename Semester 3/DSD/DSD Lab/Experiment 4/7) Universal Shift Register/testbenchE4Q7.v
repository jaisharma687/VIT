module testbenchE4Q7;
reg [3:0] parin;
reg clr;
reg clk;
reg [0:1] sel;
wire [3:0] out;
UniversalShiftReg test (.parin(parin),.clr(clr),.clk(clk),.sel(sel),.out(out));
initial begin
clk = 0;
repeat (100) #20 clk = ~clk;
end
initial begin
parin = 4'b1011;
sel = 2'b01;
clr = 1'b0;
#40;
$display("parin = %b, sel = %b, out = %b", parin, sel, out);
parin = 4'b1011;
sel = 2'b10;
clr = 1'b0;
#40;
$display("parin = %b, sel = %b, out = %b", parin, sel, out);
parin = 4'b1011;
sel = 2'b11;
clr = 1'b0;
#40;
$display("parin = %b, sel = %b, out = %b", parin, sel, out);
end
endmodule
