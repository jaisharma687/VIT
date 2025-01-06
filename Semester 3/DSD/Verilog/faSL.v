module faSL(s, ca, a, b, c);
output s, ca;
input a,b, c;
wire w1, w2, w3;
xor (s, a, b, c);
and (w1, a, b);
and (w2, b, c);
and (w3, c, a);
or (ca, w1, w2, w3);
endmodule
