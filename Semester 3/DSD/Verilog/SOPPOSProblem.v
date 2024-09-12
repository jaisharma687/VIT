module threeinput(x,y,z,F,Fn);
input x,y,z;
output F,Fn;
assign F= (~x&~y&z)|(~x&y&z)|(x&~y);
assign Fn = ~((~x&~y&z)|(~x&y&z)|(x&~y));
endmodule;

module testbnch();
reg x,y,z;
wire F,Fn;
threeinput tst(x,y,z,F,Fn);
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