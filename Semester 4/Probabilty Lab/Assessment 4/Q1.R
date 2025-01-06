# double tail test
mean <- 2.06
sd <- 0.141
null_mean <- 2.00
los <- 0.10
n <- 51
z <- abs((mean - null_mean) / (sd/sqrt(n)))
critical_value <- qnorm(1-los/2)
print(paste("Test statistic:", z))
print(paste("Critical value:", critical_value))
if (z > critical_value) {
  print(paste("Null Hypothesis rejected, therefore is evidence that the population mean zinc mass exceeds 2.0 g."))
} else {
  print(paste("Null Hypothesis accepted, therefore is not enough evidence to conclude that the population mean zinc mass exceeds 2.0 g."))
}