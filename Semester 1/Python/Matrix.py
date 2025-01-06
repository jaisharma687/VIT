#we make 2 matrices using for loop

l=input('Please enter the value of matrix: ').split(',')
l=[int(i) for i in l]
mat1=[]
for i in range(0,l[0]):
    temp=[]
    print('Enter row',i+1)
    temp=input().split(',')
    temp=[int(j) for j in temp]
    if len(temp)==l[1]:
        mat1.append(temp)
    else:
        print('gae')
        break
else:
    mat_sum=[]
    for i, j in zip(mat1,mat2):
        # print(j,i)
        temp=[]
        for k in range(0,3):
            temp.append(i[k]+j[k])
        mat_sum.append(temp)
    for i in mat_sum:
        print(i)