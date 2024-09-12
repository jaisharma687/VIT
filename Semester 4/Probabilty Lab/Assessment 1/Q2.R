sno <- c(1,2,3,4,5,6,7,8,9,10,11,12)
temp <- c(53,62,57,71,78,66,84,87,96,91,94,96)
chirps <- c(20,32,40,60,80,100,120,140,160,180,200,220)
table <- data.frame(sno, temp, chirps)
plot(temp, chirps, col = "blue", main = "Regression Lines", cex = 1.3, 
     pch = 16, xlab = "Temperature(F)", ylab = "Chirps per minute")
abline(lm(chirps ~ temp), col = "red") # Regression 
abline(lm(temp ~ chirps), col = "green")
legend("topleft", legend = c("Regression line of y on x", "Regression line of x on y"), col = c("red", "green"), lty = 1, lwd = 2)