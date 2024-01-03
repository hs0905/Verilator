module cnt(
   input    logic clk,
   input    logic rstn,
   output   logic [7:0] out 
);

always_ff@(posedge clk, negedge rstn)begin
   if(!rstn)begin
      out <= 0;
   end else begin
      if(out<250) out <= out + 1;
      else out <= 0;
   end
end
endmodule