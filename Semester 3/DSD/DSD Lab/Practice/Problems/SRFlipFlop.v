module srff(s,r,clk,rst,q,qbar);
  input s, r, clk, rst;
  output reg q, qbar;

always @(posedge clk or posedge rst)
begin
  if (rst)
  begin
    q <= 1'b0;
    qbar <= 1'b1;
  end
  else
  begin
    case ({s, r})
      2'b00: begin q <= q; qbar <= qbar; end
      2'b01: begin q <= 1'b0; qbar <= 1'b1; end
      2'b10: begin q <= 1'b1; qbar <= 1'b0; end
      2'b11: begin q <= 1'bx; qbar <= 1'bx; end
    endcase
  end
end
endmodule


module srtb;
  reg s, r, clk, rst;
  wire q, qbar;
  srff s1(s, r, clk, rst, q, qbar);
  always #5 clk = ~clk;
  initial 
  begin
    r = 0; s = 0; clk = 0; rst = 1;
    #10 rst = 0;
    #10 s = 0; r = 1;
    #10 s = 1; r = 0;
    #10 s = 1; r = 1;
    #50 $stop;
  end
endmodule
