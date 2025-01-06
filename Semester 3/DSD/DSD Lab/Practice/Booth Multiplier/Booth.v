module BoothMulti(M, Q, A);
input signed [4:0] M, Q;
output reg signed [9:0] A;
reg [1:0] comp;
integer n;
reg Qlast;
always @ (M, Q)
begin
A = 10'd0;
Qlast=1'd0;
A[3:0]=Q;
for (n = 0; n < 5; n = n + 1)
begin
comp = {Q[n], Qlast};
case (comp)
2'd2 : A [9 : 5] = A [9 : 5] -M;
2'd1 : A [9 : 5] = A [9 : 5] + M;
endcase
A = A >> 1;
A[9] = A[8];
Qlast = Q[n];
end
if (M == 5'd16)
begin
A = - A;
end
end
endmodule