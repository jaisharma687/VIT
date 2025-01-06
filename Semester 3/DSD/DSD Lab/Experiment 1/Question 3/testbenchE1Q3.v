module testbenchE1Q3();
reg x,y,z;
wire F;
NORGate test(x,y,z,F);
initial
begin
$monitor($time," x=%b,y=%b,z=%b,F=%b",x,y,z,F);
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
