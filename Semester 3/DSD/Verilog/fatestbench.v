module fatestbench();
reg A, B, C;
wire S,CA;
faha fa1(S, CA, A, B, C);
initial begin
$dumpfile("dump.vcd");
$monitor($time, "ns", "\t A=%b, B=%b, C=%b, Sum=%b, Carry=%b", A, B, C, S, CA);
$dumpvars(1, A);
$dumpvars(1, B);
$dumpvars(1, C);
$dumpvars(1, S);
$dumpvars(1, CA);
{A, B, C}={1'b0, 1'b0, 1'b0};
#50 {A, B, C}={1'b0, 1'b0, 1'b1};
#50 {A, B, C}={1'b0, 1'b1, 1'b0};
#50 {A, B, C}={1'b0, 1'b1, 1'b1};
#50 {A, B, C}={1'b1, 1'b0, 1'b0};
#50 {A, B, C}={1'b1, 1'b0, 1'b1};
#50 {A, B, C}={1'b1, 1'b1, 1'b0};
#50 {A, B, C}={1'b1, 1'b1, 1'b1};
end
endmodule