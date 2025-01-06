module Question2(F,x,y,z);
input x,y,z;
output F;
wire a1,a2,a3,n1,n2;

not xn(n1,x);
not yn(n2,y);
and an1(a1,n1,n2,z);
and an2(a2,n1,y,z);
and an3(a3,x,n2);
or o(F,a1,a2,a3);
endmodule