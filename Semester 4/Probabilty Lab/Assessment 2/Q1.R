total_families <- 200
families_purchasing_newspaper <- 40
sample_size <- 10
prob_purchasing <- families_purchasing_newspaper / total_families
prob_only_one <- dbinom(1, size = sample_size, prob = prob_purchasing)
prob_none_purchases <- dbinom(0, size = sample_size, prob = prob_purchasing)
prob_not_more_than_one <- pbinom(1, size = sample_size, prob = prob_purchasing)
cat("i. Probability that only one family purchases the newspaper:", prob_only_one, "\n")
cat("ii. Probability that no family purchases the newspaper:", prob_none_purchases, "\n")
cat("iii. Probability that not more than one family purchases the newspaper:", prob_not_more_than_one, "\n")