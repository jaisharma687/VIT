political_affiliation <- c("Democrat", "Democrat", "Democrat", 
                           "Republic", "Republic", "Republic")
opinion <- c("Favor", "Indifferent", "Oppose", 
             "Favor", "Indifferent", "Oppose")
counts <- c(138, 83, 64, 
            64, 67, 84)
data <- data.frame(political_affiliation, opinion, counts)
cont_table <- matrix(data$counts, nrow = 2, byrow = TRUE)
rownames(cont_table) <- c("Democrat", "Republic")
colnames(cont_table) <- c("Favor", "Indifferent", "Oppose")
chi_sq_result <- chisq.test(cont_table)
df <- chi_sq_result$parameter
p_value <- chi_sq_result$p.value
los <- 0.05
critical_value <- qchisq(1 - los, df)
print(paste("Degrees of Freedom:", df))
print(paste("P-value:", p_value))
print(paste("Critical Value:", critical_value))
if (p_value < los) {
  print("We reject the null hypothesis. Political affiliation and opinion on tax reform bill are not independent at 5% level of significance.")
} else {
  print("We do not reject the null hypothesis. Political affiliation and opinion on tax reform bill are independent at 5% level of significance.")
}