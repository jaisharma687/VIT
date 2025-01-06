module faha(s, ca, a, b, c);
output s, ca;
input a,b, c;
wire hs, c1, c2;
haSL ha1(hs, c1, a, b);
haSL ha2(s, c2, hs, c);
or (ca, c1, c2);
endmodule
