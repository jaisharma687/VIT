module mux4x1(I,S,y);
input [1:0] S;
input [3:0] I;
output reg y;
always@(S)
begin
case(S)
2'b00:y<=I[0];
2'b01:y<=I[1];
2'b10:y<=I[2];
2'b11:y<=I[3];
endcase
end
endmodule

module mux4x1tb;
reg [1:0] S;
reg [3:0] I;
wire y;
mux4x1 test(I,S,y);
initial begin
$monitor($time,": S= %b , y = %b",S,y);
I=4'b1011;
S=2'b00;
#10 S=2'b01;
#10 S=2'b10;
#10 S=2'b11;
#10 I=4'b0101; 
S=2'b00;
#10 S=2'b01;
#10 S=2'b10;
#10 S=2'b11;
#10 $stop;
end
endmodule

