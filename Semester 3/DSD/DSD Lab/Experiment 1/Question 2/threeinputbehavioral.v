module threeinputbehavioural(x,y,z,F,Fn);
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
