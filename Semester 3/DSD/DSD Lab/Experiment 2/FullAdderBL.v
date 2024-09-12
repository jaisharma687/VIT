module faBL(s, ca, a, b, c);
output reg s, ca;
input a,b, c;
always @(a or b or c)
begin
{ca, s}=a+b+c;
end
endmodule
