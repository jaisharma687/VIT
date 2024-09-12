list_1 = [1, 2, 5, 4, 7, 10, 11]#pair for which diff is const
diff = [1]
counter = 0
for i in list_1:
    for j in list_1:
        if i - j == diff[0]:
            counter += 1
            print(f"pair is {i} and {j}")
print(counter)