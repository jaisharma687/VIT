# double tail test
P <- 0.90
n <- 200
p <- 0.85
los <- 0.05
z <- abs((p - P) / sqrt((P * (1 - P)) / n))
critical_value <- qnorm(1-los/2)
print(paste("Test statistic:", z))
print(paste("Critical value:", critical_value))
if (z > critical_value) {
  print("We reject the null hypothesis. There is compelling evidence to suggest that the company's claim of 90% customer satisfaction may not be true.")
} else {
  print("We do not reject the null hypothesis. There is not compelling evidence to suggest that the company's claim of 90% customer satisfaction is inaccurate.")
}