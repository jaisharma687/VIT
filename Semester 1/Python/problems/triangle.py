l1=int(input("a "))
l2=int(input("b "))
l3=int(input("c "))
if l1==l2:
    if l2==l3:
        print("equi")
    else:
        print("iso")
elif l2==l3:
    if l2==l1:
        print("equi")
    else:
        print("iso")
elif l3==l1:
    if l3==l2:
        print("equi")
    else:
        print("iso")
else:
    print("sca")
