mean <- 2040
sd <- 60  
n <- 2000 
first <- round((1-pnorm(2150,mean,sd))*2000)
second <- round(pnorm(1950,mean,sd)*2000)
third <- round((pnorm(2160,mean,sd) - pnorm(1920,mean,sd))*2000)
cat("i. More than 2150 hours:", first, "\n")
cat("ii. Less than 1950 hours:", second, "\n")
cat("iii. More than 1920 hours but less than 2160 hours:", third, "\n")
cat("iv. More than 2150 hours:", first, "\n")
x <- seq(mean - 3*sd, mean + 3*sd, length.out = 1000)
y <- dnorm(x, mean, sd)
plot(x, y, type = "l", main = "Normal Distribution of Bulb Life (i)", xlab = "Bulb Life (hours)", ylab = "Density")
polygon(c(2150,x[x >= 2150],mean + 3*sd),c(0,y[x >= 2150],0),col="green")
legend("topright", legend = c("More than 2150"), fill = "green", bty = "n")

plot(x, y, type = "l", main = "Normal Distribution of Bulb Life (ii)", xlab = "Bulb Life (hours)", ylab = "Density")
polygon(c(mean - 3*sd,x[x <= 1950],1950),c(0,y[x <= 1950],0),col="purple")
legend("topright", legend = c("Less than 1950"), fill = "purple", bty = "n")

plot(x, y, type = "l", main = "Normal Distribution of Bulb Life (iii)", xlab = "Bulb Life (hours)", ylab = "Density")
polygon(c(1920,x[1920 <= x & x <= 2160],2160),c(0,y[1920 <= x & x <= 2160],0),col="red")
legend("topright", legend = c("More than 1920 but less than 2160"), fill = "red", bty = "n")

plot(x, y, type = "l", main = "Normal Distribution of Bulb Life (iv)", xlab = "Bulb Life (hours)", ylab = "Density")
polygon(c(2150,x[x >= 2150],mean + 3*sd),c(0,y[x >= 2150],0),col="orange")
legend("topright", legend = c("More than 2150"), fill = "orange", bty = "n")