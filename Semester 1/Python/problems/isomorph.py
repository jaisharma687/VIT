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