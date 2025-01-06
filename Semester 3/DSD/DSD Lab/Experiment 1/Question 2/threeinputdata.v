module threeinputdata(x,y,z,F,Fn);
input x,y,z;
output F,Fn;
assign F= (~x&~y&z)|(~x&y&z)|(x&~y);
assign Fn = ~((~x&~y&z)|(~x&y&z)|(x&~y));
endmodule
