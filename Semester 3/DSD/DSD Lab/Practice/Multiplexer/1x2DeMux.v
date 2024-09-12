module demux1to2(S,y,O);
input y,S;
output reg [1:0] O;
always @ (S)
case(S)
1'b0:begin O[0]=y; O[1]=0;end
1'b1:begin O[0]=0; O[1]=y;end
endcase
endmodule

module demux1to2tb;
reg y,S;
wire [1:0] O;
demux1to2 test(S,y,O);
initial begin
$monitor($time,": S= %b , O = %b",S,O);
y=0;
S=1'b0;
#10 S=1'b1;
#10 S=1'b0; y=1;
#10 S=1'b1;
#10 $stop;
end
endmodule