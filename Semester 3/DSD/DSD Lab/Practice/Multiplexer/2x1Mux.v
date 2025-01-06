module mux2x1(I,S,y);
input S;
input [1:0] I;
output reg y;
always@(S)
begin
case(S)
1'b0:y<=I[0];
1'b1:y<=I[1];
endcase
end
endmodule

module mux2x1tb;
reg S;
reg [1:0] I;
wire y;
mux2x1 test(I,S,y);
initial begin
$monitor($time,": S= %b , y = %b",S,y);
I=2'b00;
S=1'b0;
#10 S=1'b1;
#10 S=1'b0; I=2'b01;
#10 S=1'b1;
#10 $stop;
end
endmodule

