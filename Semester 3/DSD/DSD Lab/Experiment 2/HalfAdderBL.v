module haBL(sum, carry, a, b);
input a, b;
output reg sum, carry;
always @(a or b)
begin
if (a==0 && b==0)
begin
sum=0; carry=0;
end
else if (a==1 && b==1)
begin
sum=0; carry=1;
end
else
sum=1; carry=0;
end
endmodule
