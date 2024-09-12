module twoinputData(x,y,A,B,C,D,E,F,G);
input x,y;
output A,B,C,D,E,F,G;
assign A = x|y; //or gate
assign B = x&y; //and gate
assign C = ~(x|y); //nor gate
assign D = ~(x&y); //nand gate
assign E = x^y; //xor gate
assign F = ~(x^y); //xnor gate
assign G = ~x; //not gate
endmodule
