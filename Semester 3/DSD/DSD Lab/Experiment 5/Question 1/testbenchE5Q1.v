module testbenchE5Q1;
integer i;
reg [7:0] A, B;
wire [3:0] ALU_Sel;
reg clk;
wire [7:0] ALU_Out;
ALUunit test(A,B,clk,ALU_Sel,ALU_Out);
always #5 clk = ~clk;
initial begin
$monitor($time," : A = %b , B = %b , ALU_Sel = %b , ALU_Out = %b",A,B,ALU_Sel,ALU_Out);
A = 8'b10101111;
B = 8'b01001011;
clk = 0;
#200 $stop;
end
endmodule
