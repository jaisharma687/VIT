mid <- seq(147.5,182.5,5)
f <- c(4,6,28,58,64,30,5,5)
fr.distr <- data.frame(mid,f)
fr.distr
mean <- (sum(mid*f))/sum(f)
mean
cl <- cumsum(f)
n <- sum(f)
ml <- min(which(cl>=n/2))
h <- 5
freq <- f[ml]
c <- cl[ml-1]
l <- mid[ml]-h/2
median <- l+(((n/2)-c)/freq)*h
median
m <- which(f==max(f))
fm <- f[m]
f1 <- f[m-1]
f2 <- f[m+1]
l2 <- mid[m]-h/2
mode <- l2+((fm-f1)/(2*fm-f1-f2))*h
mode