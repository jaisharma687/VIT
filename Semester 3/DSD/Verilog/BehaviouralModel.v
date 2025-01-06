module Behavioural(x,y,z,F,Fn);
input x,y,z;
output reg F,Fn;
always @(x or y or z)
begin
    if(x==1'b1 && y==1'b1 && z==1'b0)
	begin
        F=1'b1 ; Fn = 1'b0;
	end
    else if(x==1'b1 && y==1'b0 && z==1'b0)
	begin
        F=1'b1 ; Fn = 1'b0;
	end
    else if(x==1'b0 && y==1'b1)
	begin
        F=1'b1 ; Fn = 1'b0;
	end
    else
	begin
        F=1'b0 ; Fn = 1'b1;
	end
    
end
endmodule

module testb();
reg x,y,z;
wire F,Fn;
Behavioural tstmisc(x,y,z,F,Fn);
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