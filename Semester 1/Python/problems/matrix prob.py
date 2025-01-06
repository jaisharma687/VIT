x = input("Enter the numbers").split()

for i in range(len(x)):
    x[i] = int(x[i])

print(x)
for w in range(len(x)):
    sum1 = 0
    sum2 = 0
    t = 0
    for e in range(0,w):
        sum1 += x[e]
    for r in range(w+1,len(x)):
        sum2 += x[r]
    if sum1 == sum2:
        t = 1
        print(x[w])
        break
if t == 0:
    print("sfsrr")
