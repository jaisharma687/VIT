marks <- c(23, 12, 45, 67, 34, 56, 78, 23, 56, 34, 23, 87, 56, 32, 12, 76, 
           45, 23, 90, 67, 45, 78, 23, 56, 34, 23, 56, 78, 90, 12)
mean <- mean(marks)
median <- median(marks)
mode <- names(sort(-table(marks)))[1]
range <- range(marks)
quartiles <- quantile(marks, probs = c(0.25, 0.5, 0.75))
variance <- var(marks)
std_deviation <- sd(marks)
mean_deviation <- mean(abs(marks - mean))
mean
median
mode
range
quartiles
variance
std_deviation
mean_deviation