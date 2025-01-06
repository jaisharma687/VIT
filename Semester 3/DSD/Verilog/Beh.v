module threeipgatelevel(x,y,z,F,Fn);
input x,y,z;
output F,Fn;
wire nx,ny,xyz1,xyz2,xy1,xy2,nf1,nf2,f1;
not n1(nx,x);
not n2(ny,y);
and a1(xy1,nx,ny);
and a2(xyz1,xy1,z);
and a3(xy2,nx,y);
and a4(xyz2,xy2,z);
and a5(xy3,ny,x);
or o1(f1,xyz1,xyz2);
or o2(F,f1,xy3);
or o3(nf1,xyz1,xyz2);
or o4(nf2,f1,xy3);
not n3(Fn,nf2);
endmodule

module testbnch();
reg x,y,z;
wire F,Fn;
threeipgatelevel tst(x,y,z,F,Fn);
initial
begin
$monitor($time,"x=%b,y=%b,z=%b,F=%b,Fn=%b",x,y,z,F,Fn);
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