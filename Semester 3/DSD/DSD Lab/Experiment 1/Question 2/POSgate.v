module POSgate(x,y,z,F,Fn);
input x,y,z;
output F,Fn;
wire xn,xz,yn,xy;
not n1(xn,x);
not n2(yn,y);
and a1(xz,xn,z);
and a2(xy,yn,x);
or o(F,xz,zy);
not n3(Fn,F);
endmodule
