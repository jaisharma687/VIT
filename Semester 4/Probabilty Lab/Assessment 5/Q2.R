# two tail test
Unit_A = c(14.1, 10.1, 14.7, 13.7 ,14.0)
Unit_B = c(14.0, 14.5, 13.7, 12.7, 14.1)
los <- 0.1 / 2
f_test <- var.test(Unit_A,Unit_B)
f <- f_test$statistic
f
p_value <- f_test$p.value
p_value
df1 <- f_test$parameter[1]
df2 <- f_test$parameter[2]
critical_value <- qf(1-los,df1,df2)
print(paste("Test statistic: ", f))
print(paste("P-value: ", p_value))
print(paste("Critical value: ", critical_value))
if (p_value < los) {
  print("Null hypothesis rejected. There is sufficient evidence to conclude that the two populations have different variances.")
} else {
  print("Fail to reject the null hypothesis. There is not enough evidence to conclude that the two populations have different variances.")
}