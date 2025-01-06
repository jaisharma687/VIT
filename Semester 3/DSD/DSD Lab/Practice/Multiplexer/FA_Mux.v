module FAmux(a,b,c,sum,carry);
input a,b,c;
output sum,carry;
mux m1(c,~c,~c,c,a,b,sum);
mux m2(0,c,c,1,a,b,carry);
endmodule

module FAmuxtb;
reg a,b,c;
wire sum,carry;
FAmux test(a,b,c,sum,carry);
initial begin 
$monitor($time,": a=%b, b=%b, c=%b, sum=%b, carry=%b",a,b,c,sum,carry);
{a,b,c}=3'b000;
#10 {a,b,c}=3'b001;
#10 {a,b,c}=3'b010;
#10 {a,b,c}=3'b011;
#10 {a,b,c}=3'b100;
#10 {a,b,c}=3'b101;
#10 {a,b,c}=3'b110;
#10 {a,b,c}=3'b111;
#10 $stop;
end
endmodule

module mux(I0,I1,I2,I3,S1,S0,y);
input I0,I1,I2,I3,S1,S0;
output reg y;
always@(S0 or S1)
begin
case({S1,S0})
2'b00:y<=I0;
2'b01:y<=I1;
2'b10:y<=I2;
2'b11:y<=I3;
endcase
end
endmodule
