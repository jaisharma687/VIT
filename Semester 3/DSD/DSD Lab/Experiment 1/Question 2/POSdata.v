module POSdata(x,y,z,F,Fn);
input x,y,z;
output F,Fn;
assign F= (~x&z)|(x&~y);
assign Fn = (~x&~z)|(x&y);
endmodule