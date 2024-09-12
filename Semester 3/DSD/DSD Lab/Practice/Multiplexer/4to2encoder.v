module en4to2(O,E);
output reg [1:0] O;
input [3:0] E;
always@(E)
case(E)
4'b1000:O=2'b00;
4'b0100:O=2'b01;
4'b0010:O=2'b10;
4'b0001:O=2'b11;
endcase
endmodule

module en4to2tb;
wire [1:0] O;
reg [3:0] E;
en4to2 test(O,E);
initial begin
$monitor($time,": E=%b , O=%b",E,O);
E=4'b1000;
#10 E=4'b0100;
#10 E=4'b0010;
#10 E=4'b0001;
#10 $stop;
end
endmodule