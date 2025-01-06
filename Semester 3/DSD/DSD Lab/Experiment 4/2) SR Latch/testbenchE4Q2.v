module testbenchE4Q2;
reg S,R;
wire Q,Qbar;
SRLatch test(.S(S),.R(R),.Q(Q),.Qbar(Qbar));
initial begin
$monitor($time,": SR = %d%d , Q = %d , Qbar = %d",S,R,Q,Qbar);
S=0;R=0;
#100 S=0;R=1;
#100 S=1;R=0;
#100 S=1;R=1;
#100 S=0;R=0;
#100;
end
endmodule