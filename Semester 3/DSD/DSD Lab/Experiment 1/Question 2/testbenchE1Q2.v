module testbenchE1Q2();
reg x,y,z;
wire F,Fn;
threeinputdata test(x,y,z,F,Fn);
initial
begin
$monitor($time," x=%b,y=%b,z=%b,F=%b,Fn=%b",x,y,z,F,Fn);
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
