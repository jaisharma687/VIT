# x = 10
# while x:
#     x -= 1
#     if x%2 != 0:
#         continue
#     print(x,end=" ")


# n = int(input())
# for i in range(1,n+1):
#     print("* "*i,end='\n')
# for j in range(n-1,0,-1):
#     print("* "*j,end='\n')

# s = "C:\new\text.dat"
# print(s)

# s1 = r"C:\new\text.dat"
# print(s1)

# s2 = "C:\\new\\text.dat"
# print(s2)

# X = 'gdhasjh dajhdsu'
# print(X[3:17:2])

# import re
# numb = input()
# count = 0
# if len(numb)==10:
#     if numb.isdigit()==True:
#         if not numb[0] == "0":
#             print("valid")
#         else:
#             print("invalid")
#     else:
#         print("invalid")
# else:
#     print("invalid")

# L =[1, 2, 3, 4, 5] 
# print(L.insert(2,5))
# print(L.pop(4))
# print(L)

# S = "12345" 
# L = list(S)
# S1 = ''.join(L)
# S2 = int(S1)
# print(S2)

# print(list(range(-4,4)))

# line = 'aaa bbb ccc'
# cols = line.split("-") 
# print(cols)

# L =[1, 2, 3, 4, 5]
# L.insert(4,[4,6])
# print(L)

# L =[1, 2, 3, 4, 5]
# print(L.pop(2))
# print(L)

# D = {'spam': 2, 'ham': 1, 'eggs': 3} 
# print(list(D))
# print(list(D.keys()))
# print(list(D.values()))
# print(D.items())
# print(D.get('spam'))
# print(D.get('toast'))

# D2 = {'toast':4, 'muffin':5}
# D.update(D2)
# print(D)
# D2.update(D)
# print(D2)

# print(D.pop('muffin'))
# print(D)

# print(D.pop('toast'))
# print(D)

# dict = {}
# no_inputs = int(input())
# for i in range(no_inputs):
#     x = input("Enter the name: ")
#     y = int(input("Enter the age: "))
#     dict[x] = y

# l1 = list(dict.keys())
# l2 = list(dict.values())
# r = []
# for k in l2:
#     e = l2.count(k)
#     if e > 1:
#         for m in range(len(l2)):
#             if l2[m] == k:
#                 r.append(m)
#         break
# print(r)

# for n in r:
#     print(l1[n])

# st = "frgsdhgh wehadvfg jhwjeaheryreuda ehgawdbfvherhafvgjkh"
# l1 = st.split(" ")
# print(l1)
# l = []
# for i in l1:
#     lent = len(i)
#     l.append(lent)
# print(l)

# max = 0

# for m in l:
#     if m > max:
#         max = m

# ind = l.index(max)

# print(f'the longest string is {l1[ind]}')

# sorting
# dict = {'spam': 2, 'ham': 1, 'eggs': 3, 'muffin': 5, 'toast': 4}
# print(sorted(dict))
# key_dict = list(dict.keys())
# val1_dict = list(dict.values())
# val2_dict = list(dict.values())

# key_dict.sort(key=str.lower)
# d2 = {}

# for key in key_dict:
#     val = dict[key]
#     d2[key] = val
# print(d2)

# val1_dict.sort()
# print(val1_dict)

# r=[]
# for val1 in val1_dict:
#     for val2 in val2_dict:
#         if val1 == val2:
#             r.append(val2_dict.index(val2))
# print(r)
# d2 = {}
# for j in r:
#     d2[key_dict[j]] = val2_dict[j]
# print(d2)
            

# st = "Jai Sharma"
# l1 = list(st.lower())
# l1.remove(" ")
# print(l1)
# d = {}
# for m in range(len(l1)):
#     d[l1[m]] = l1.count(l1[m])
# print(d)

# row_1 = int(input())
# col_1 = int(input())
# mat_a = []
# for i in range(1,row_1+1):
#     mat_1 = []
#     for j in range(1,col_1+1):
#         n =  int(input(f'Enter the element {i}{j}: '))
#         mat_1.append(n)
#     mat_a.append(mat_1)

# for q in range(len(mat_a)):
#     print(mat_a[q])

# row_2 = int(input())
# col_2 = int(input())
# mat_b = []
# for i in range(1,row_1+1):
#     mat_2 = []
#     for j in range(1,col_1+1):
#         n =  int(input(f'Enter the element {i}{j}: '))
#         mat_2.append(n)
#     mat_b.append(mat_1)

# for q in range(len(mat_b)):
#     print(mat_b[q])

# if row_1 == row_2 and col_1 == col_2:
#     mat_sum = []
#     for i in range(row_1):
#         mat_s = []
#         for j in range(col_1):
#             sum = mat_a[i][j] + mat_b[i][j]
#             mat_s.append(sum)
#         mat_sum.append(mat_s)
            
# print('Matrix sum is:')
# for l in mat_sum:
#     print(l)

# print('Matrix multiplication is:')
# if row_2 == col_1 and row_1 == col_2:
#     mat_mult = []
#     for i in range(row_1):
#         mat_m = []
#         for j in range(col_2):
#             mult = mat_a[i][j]*mat_b[i][j]
#             mat_m.append(mult)
#         mat_mult.append(mat_m)

# for l in mat_mult:
#     print(l)          

# s={1,2,3,4}
# s.add('abc')
# print(s)

# set1 = {"a", "b" , "c"}
# set2 = {1, 2, 3}
# set3 = set1.union(set2)
# print(set3)

# set1 = {"a", "b" , "c"}
# set2 = {1, 2, 3}
# set3 = set1.intersection(set2)
# print(set3)

# x = {"apple", "banana", "cherry"}
# y = {"google", "microsoft", "apple"}
# l = x.union(y)
# print(l)
# x.update(y)
# print(x)
# l = x.intersection(y)
# print(l)
# x.intersection_update(y)
# print(x)
# l = x.symmetric_difference(y)
# print(l)
# x.symmetric_difference_update(y)
# print(x)
# l = x.difference(y)
# print(l)
# x.difference_update(y)
# print(x)
