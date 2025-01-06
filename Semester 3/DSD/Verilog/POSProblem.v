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

module testSOP();
reg x,y,z;
wire F,Fn;
SOPgate sop(x,y,z,F,Fn);
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
