# Write a python code to find the sum of the following series. Get N from the user.
# 1+2+3+4+5+………………………………+N
# 2+4+6+8+10+……………………………+ N
num = int(input("Enter a num: "))
sum = 0
for i in range(2,num+1,2):
    sum += i
print(sum)