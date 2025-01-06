module NorGate(x,y,z,F);
input x,y,z;
output F;
wire xn,nz,nxz,nxy,nf;
nor n1(xn,x,x);
nor n2(nz,z,z);
nor n3(nxz,x,nz);
nor n4(nxy,xn,y);
nor n5(nf,nxy,nxz);
nor n6(F,nf,nf);
endmodule;

module tst();
reg x,y,z;
wire F;
NorGate tst(x,y,z,F);
initial
begin
$monitor($time,"x=%b, y=%b, z=%b, F=%b",x,y,z,F);
    x=1'b0;y=1'b0;z=1'b0; //1
#50 x=1'b0;y=1'b0;z=1'b1; //2
#50 x=1'b0;y=1'b1;z=1'b0; //3
#50 x=1'b0;y=1'b1;z=1'b1; //4
#50 x=1'b1;y=1'b0;z=1'b0; //5
#50 x=1'b1;y=1'b0;z=1'b1; //6
#50 x=1'b1;y=1'b1;z=1'b0; //7
#50 x=1'b1;y=1'b1;z=1'b1; //8
end
endmodule