module MagnitudeComparator(A , B , A_grt_B , A_less_B , A_eq_B);
  input [3:0] A, B;
  output A_grt_B, A_less_B, A_eq_B;

  assign A_grt_B = (A > B) ? 1'b1 : 1'b0;
  assign A_less_B = (A < B) ? 1'b1 : 1'b0;
  assign A_eq_B = (A == B) ? 1'b1 : 1'b0;

endmodule