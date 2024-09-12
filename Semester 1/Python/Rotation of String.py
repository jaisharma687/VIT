string=input('Enter a string: ')
l=list(string)
for i in range(0,len(l)):
    x=l.pop()
    a=l.insert(0, x)
    for j in l:
        empty_str=''
        empty_str=empty_str+j
        print(empty_str,end=' ')
    print()