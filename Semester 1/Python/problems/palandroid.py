numb = input("Enter the number: ")
reverse_numb = ""
for i in range(0,len(numb)):
    reverse_numb = numb[i] + reverse_numb
print(reverse_numb)