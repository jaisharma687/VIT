n = int(input())
l = []
for i in range(n):
    numb = int(input())
    l.append(str(numb))
print(l)
len_req = len(l[0])
l2 = []
for k in l:
    if len(k) == len_req:
        l2.append(k)
print(l2)
if len(l2) == 1:
    print("No isomorph")
else:
    for k in l2:
        for j in l2:
            if k == j:
                pass
            else:
                k1 = list(k)
                j1 = list(j)
                for p in range(k1):
                    for q in range(j1):
                        if p == q:
                            