l=[4,6,1,9,3,5,3]
for i in l:
    ind=l.index(i)
    if sum(l[:ind])==sum(l[ind+1:]):
        print(i,end=' ')