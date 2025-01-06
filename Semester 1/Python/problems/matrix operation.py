# Given a square matrix of size N×N, devise an algorithm and write the Python code to 
# calculate the absolute difference of the sums across the two main diagonals. For example, 
# given a 3 X 3 matrix as below:
# 11 2 4
# 4 5 6
# 10 8 -12
# Sum across the first diagonal = 11+5-12= 4
# Sum across the second diagonal = 4+5+10 = 19 
# Absolute Difference: |4-19| =15
# Input format:
# read no of rows
# read no of columns
# read elements of the n*n matrix
# Output format:
# print the absolute difference between the sum of both the diagonals
# Boundary conditions:
# rows >0
# columns>0
# and rows should be equal to columns
row_1 = int(input())
col_1 = int(input())
matrix1 = []
for i in range(0,row_1):
    mat_1 = []
    for j in range(0,col_1):
        element = int(input(f"Element {i+1}{j+1}: "))
        mat_1.append(element)
    matrix1.append(mat_1)
for q in matrix1:
    print(q)


row_2 = int(input())
col_2 = int(input())
matrix2 = []
for i in range(0,row_2):
    mat_2 = []
    for j in range(0,col_2):
        element = int(input(f"Element {i+1}{j+1}: "))
        mat_2.append(element)
    matrix2.append(mat_2)
for q in matrix2:
    print(matrix2)

#matrix sum
if row_1 == row_2 and col_1 == col_2:
        mat_sum = []
        for i in range(0,row_1):
            mat_a = []
            for j in range(0,col_1):
                a = matrix1[i][j] + matrix2[i][j]
                mat_a.append(a)
            mat_sum.append(mat_a)
        print(mat_sum)
else:
    print("invalid")
        

#matrix multiplication
if row_1 == col_1 and col_2 == row_2:
        mat_mult = []
        for i in range(0,row_1):
            mat_a = []
            for j in range(0,col_2):
                a = matrix1[i][j] + matrix2[j][i]
                mat_a.append(a)
            mat_mult.append(mat_a)
        print(mat_mult)
else:
    print("invalid")

#diagonal sum for matrix 1
d1 = 0
d2 = 0
for i in range(0,row_1):
    d1 += matrix1[i][i]
    d2 += matrix1[i][row_1-i-1]
print(f"d1 is {d1}")
print(f"d2 is {d2}")
print(f"diff is {d1-d2}")