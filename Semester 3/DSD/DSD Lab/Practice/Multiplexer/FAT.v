module program(a,b,c,d,Y);
input [3:0]a,b,c,d;
output [4:0]Y;
assign Y[0]=~(a&b);
assign Y[1]=(a[3]<b[3]);
assign Y[2]=(a===b);
assign Y[3]=(a!=b)?1'b1:1'b0;
assign Y[4]=(a<<2)+(b>>1);
endmodule

module programtb();
reg [3:0]a,b,c,d;
wire [4:0]Y;
program test(a,b,c,d,Y);
initial begin
$monitor($time,": a = %b , b = %b , Y = %b",a,b,Y);
a = 4'b0000;
b = 4'b0000;
c = 4'b0000;
d = 4'b0000;
#10 a = 4'b1010; b = 4'b1101; d = 4'bx1xz; c = 4'bx1xz;
#10 $stop;
end
endmodule