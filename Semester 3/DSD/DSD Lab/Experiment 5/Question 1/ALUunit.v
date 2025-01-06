module ALUunit(A,B,clk,ALU_Sel,ALU_Out);
input [7:0] A, B;
output reg [7:0] ALU_Out;
output reg [3:0] ALU_Sel;
input clk;
initial begin
ALU_Sel = 4'b1111;
end
always @(posedge clk)
begin
if(ALU_Sel != 4'b1111)
begin
case(ALU_Sel)
4'b0000 : ALU_Out = A + 1;
4'b0001 : ALU_Out = A + B;
4'b0010 : ALU_Out = A - 1;
4'b0011 : ALU_Out = A - B;
4'b0100 : ALU_Out = A * B;
4'b0101 : ALU_Out = A == B;
4'b0110 : ALU_Out = A > B;
4'b0111 : ALU_Out = A < B;
4'b1000 : ALU_Out = ~A;
4'b1001 : ALU_Out = A & B;
4'b1010 : ALU_Out = A | B;
4'b1011 : ALU_Out = ~(A & B);
4'b1100 : ALU_Out = ~(A | B);
4'b1101 : ALU_Out = A ^ B;
4'b1110 : ALU_Out = A >> 1;
endcase
ALU_Sel = ALU_Sel + 4'b0001;
end
else
begin
ALU_Out = A << 1;
ALU_Sel = 4'b0000;
end
end
endmodule
