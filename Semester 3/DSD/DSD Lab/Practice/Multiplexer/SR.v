module srff(clk,S,R,Q,Qbar);
input clk,S,R;
output reg Q,Qbar;
initial Q<=0;
always@(posedge clk)
begin
case({S,R})
2'b00: Q<=Q;
2'b01: Q<=0;
2'b10: Q<=1;
2'b11: Q<=1'bx;
endcase
Qbar<=~Q;
end
endmodule

module srfftb;
reg clk,rst,S,R;
wire Q,Qbar;
srff test(clk,S,R,Q,Qbar);
initial 
begin 
clk=0;
end
always #5 clk=~clk;
initial begin
$monitor($time,": SR = %b%b , Q= %b",S,R,Q);
{S,R}=0;
#10 {S,R}=1;
#10 {S,R}=2;
#10 {S,R}=3;
#10 $stop;
end
endmodule
