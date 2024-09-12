module gatelevelmodelling(x,y,A,B,C,D,E,F,G);
input x,y;
output A,B,C,D,E,F,G;
or ol(A,x,y);
and al(B,x,y);
nor nol(C,x,y);
nand nal(D,x,y);
xor xl(E,x,y);
xnor nxl(F,x,y);
not nl(G,x);
endmodule
