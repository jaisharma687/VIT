module NandGate(x,y,z,F);
input x,y,z;
output F;
wire xn,nxz,yn,nxy;
nand n1(xn,x,x);
nand n2(nxz,xn,z);
nand n3(yn,y,y);
nand n4(nxy,x,yn);
nand n5(F,nxy,nxz);
endmodule;

module test();
reg x,y,z;
wire F;
NandGate tst(x,y,z,F);
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
