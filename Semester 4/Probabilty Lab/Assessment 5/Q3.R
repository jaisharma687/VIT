data <- c(14, 12, 22, 23,
          16, 18, 20, 25,
          15, 14, 23, 28,
          17, 11, 19, 21,
          13, 18, 20, 24,
          10, 17, 21, 18)
blocks <- gl(6, 4, labels = paste0("Block", 1:6))
treatments <- gl(4, 1, 24, labels = paste0("Treatment", 1:4))
rbdfit <- aov(data ~ blocks + treatments)
rbdfit
summary.aov(rbdfit)
