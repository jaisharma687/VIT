module SOPgate(x,y,z,F,Fn);
input x,y,z;
output F,Fn;
wire xn,yn,xz,xy;
not n1(xn,x);
not n2(yn,y);
or o1(xz,x,z);
or o2(xy,xn,yn);
and a1(F,xy,xz);
not n3(Fn,F);
endmodule
