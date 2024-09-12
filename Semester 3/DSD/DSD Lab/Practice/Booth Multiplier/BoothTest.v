module BoothTB;
reg [4:0] M;
reg [4:0] Q;
wire [9:0] A;
BoothMulti uut (.M(M),.Q(Q),.A(A));
initial begin
M = 0;
Q = 0;
#100;
M=-10;
Q=8;
end
endmodule
