module dec2to4(I,D);
input [1:0] I;
output reg [3:0] D;
always@(I)
case(I)
2'b00:D=4'b1000;
2'b01:D=4'b0100;
2'b10:D=4'b0010;
2'b11:D=4'b0001;
endcase
endmodule

module dec2to4tb;
reg [1:0] I;
wire [3:0] D;
dec2to4 test(I,D);
initial begin
$monitor($time,": I=%b , D=%b",I,D);
I=2'b00;
#10 I=2'b01;
#10 I=2'b10;
#10 I=2'b11;
#10 $stop;
end
endmodule