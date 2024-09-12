module hatestbench();
reg A, B;
wire Sum, Carry;
haBL ha1(Sum, Carry, A, B);
initial begin
$dumpfile("dump.vcd");
$dumpvars(1, A);
$dumpvars(1, B);
$dumpvars(1, Sum);
$dumpvars(1, Carry);
$monitor( $time, "ns:\t A=%b, B=%b, Sum=%b, Carry=%b", A, B, Sum, Carry);
A=1'b0;B=1'b0;
#50
A=1'b0;B=1'b1;
#50
A=1'b1;B=1'b0;
#50
A=1'b1;B=1'b1;
end
endmodule