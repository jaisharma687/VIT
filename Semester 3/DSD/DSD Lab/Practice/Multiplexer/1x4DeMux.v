module demux1to4(S,O,y);
input y;
input [1:0] S;
output reg [3:0] O;
always @(S or y)
case(S)
2'b00:begin O={3'b000,y};end
2'b01:begin O={2'b00,y,1'b0};end
2'b10:begin O={1'b0,y,2'b00};end
2'b11:begin O={y,3'b000};end
endcase
endmodule

module demux1to4tb;
reg y;
reg [1:0] S;
wire [3:0] O;
demux1to4 test(S,O,y);
initial begin
$monitor($time,": S=%b , O=%b",S,O);
y=0;
S=0;
#10 S=1;
#10 S=2;
#10 S=3;
#10 y=1;
#10 S=0;
#10 S=1;
#10 S=2;
#10 S=3;
#10 $stop;
end
endmodule