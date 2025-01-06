module testbenchE4Q1;
reg D, En;
wire Q;
DLatch test(.Q(Q),.D(D),.En(En));
initial begin
D=0;
En = 0;
$monitor("Q = %b , En = %b , D = %b",Q,En,D);
#10 D=1;
#10 D=0;
#10 D=1;
#10 D=1;
#10 En=1;
#10 D=1;
#10 D=0;
#10 D=1;
#10 D=1;
end
endmodule