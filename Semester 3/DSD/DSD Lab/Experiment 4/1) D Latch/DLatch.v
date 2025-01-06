module DLatch(Q,D,En);
output Q;
input D, En;
reg Q;
always@(En or D)
begin
if(En) Q<=D;
else Q<=0;
end
endmodule