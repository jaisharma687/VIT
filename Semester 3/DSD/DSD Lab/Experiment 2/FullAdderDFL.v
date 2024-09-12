module faDFL(s, ca, a, b, c);
output s, ca;
input a,b, c;
assign s=a^b^c;
assign ca=((a&b)+(b&c)+(c&a));
endmodule
