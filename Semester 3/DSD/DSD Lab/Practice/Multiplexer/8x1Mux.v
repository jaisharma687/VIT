module mux8x1(I7, I6, I5, I4, I3, I2, I1, I0, S2, S1, S0, y);
  input I7, I6, I5, I4, I3, I2, I1, I0;
  input S2, S1, S0;
  output reg y;
  
  always @ (S2 or S1 or S0)
  begin
    case ({S2, S1, S0})
      3'b000: y <= I0;
      3'b001: y <= I1;
      3'b010: y <= I2;
      3'b011: y <= I3;
      3'b100: y <= I4;
      3'b101: y <= I5;
      3'b110: y <= I6;
      3'b111: y <= I7;
      default: y <= 1'bx;
    endcase
  end
endmodule

module boolean(A,B,C,D,F);
input A,B,C,D;
output F;
mux8x1 m1(A,A,1,1,0,0,0,~A,B,C,D,F);
endmodule

module booleantb;
wire F;
reg A,B,C,D;
boolean b1(A,B,C,D,F);
initial begin
$monitor($time,": ABCD = %b%b%b%b , F = %b",A,B,C,D,F);
{A,B,C,D}=4'b0000;
#10 {A,B,C,D}=4'b0001;
#10 {A,B,C,D}=4'b0010;
#10 {A,B,C,D}=4'b0011;
#10 {A,B,C,D}=4'b0100;
#10 {A,B,C,D}=4'b0101;
#10 {A,B,C,D}=4'b0110;
#10 {A,B,C,D}=4'b0111;
#10 {A,B,C,D}=4'b1000;
#10 {A,B,C,D}=4'b1001;
#10 {A,B,C,D}=4'b1010;
#10 {A,B,C,D}=4'b1011;
#10 {A,B,C,D}=4'b1100;
#10 {A,B,C,D}=4'b1101;
#10 {A,B,C,D}=4'b1110;
#10 {A,B,C,D}=4'b1111;
#10 $stop;
end
endmodule
