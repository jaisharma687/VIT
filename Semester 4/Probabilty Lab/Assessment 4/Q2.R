# right tail test
n1 <- 125
mean1 <- 48.9
sd1 <- 14.6
n2 <- 90
mean2 <- 43.2
sd2 <- 14.4
los <- 0.05
z <- abs((mean1 - mean2) / sqrt((sd1^2/n1) + (sd2^2/n2)))
critical_value <- qnorm(1-los)
print(paste("Test statistic: ", z))
print(paste("Critical value: ", critical_value))
if (z > critical_value) {
  print("We reject the null hypothesis. There is compelling evidence that the mean lifetime after graduation for doctors in full-time practice exceeds the mean lifetime for those who have an academic affiliation.")
} else {
  print("We do not reject the null hypothesis. There is not compelling evidence that the mean lifetime after graduation for doctors in full-time practice exceeds the mean lifetime for those who have an academic affiliation.")
}