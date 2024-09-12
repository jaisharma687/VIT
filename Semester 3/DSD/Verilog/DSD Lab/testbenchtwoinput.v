module testbenchtwoinput();
	reg x1,y1;
	wire A1,B1,C1,D1,E1,F1,G1;
	test(x1,y1,A1,B1,C1,D1,E1,F1,G1);
	initial 
	begin
		$monitor($time,"x1=%b,y1=%b,A1=%b,B1=%b,C1=%b,D1=%b,E1=%b,F1=%b,G1=%b",x1,y1,A1,B1,C1,D1,E1,F1,G1);
		x1='b0;y1='b0; //1
		#100
		x1='b0;y1='b1; //2
		#100
		x1='b1;y1='b0; //3
		#100
		x1='b1;y1='b1; //4
	end
endmodule