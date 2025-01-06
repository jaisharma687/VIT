module Counter013570(clk,rst,pre,nxt);
input clk,rst;
output reg [2:0] nxt, pre;
wire clk, rst;
initial begin
pre<=3'b000;
end
always @ (posedge clk or negedge rst)
begin
if(rst!=0)
begin
case(pre)
3'b000 : nxt = 3'b001;
3'b001 : nxt = 3'b011;
3'b010 : nxt = 3'bxxx;
3'b011 : nxt = 3'b101;
3'b100 : nxt = 3'bxxx;
3'b101 : nxt = 3'b111;
3'b110 : nxt = 3'bxxx;
3'b111 : nxt = 3'b000;
endcase
pre<=nxt;
end
else
nxt<=3'b000;
end
endmodule