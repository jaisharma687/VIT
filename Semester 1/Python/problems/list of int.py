# Consider an application that allows the user to enter a list of integers of 'n' integers. If the 
# user tends to enter a value which is already in the list, then the user is not allowed to enter 
# the values further and stops execution with a message “Duplicate”. Otherwise after entering 
# all elements, the message “Unique” is displayed. Design a flowchart/ pseudocode and 
# develop the Python code for the application.
# Input Format:
# The first line will contain the number of integers, N
# The next ‘N’ lines will contain the integers 
# Output Format:
# Duplicate or Unique
# Boundary Conditions:
# Input is a list of integers

num_list = int(input("Enetr the number "))
list_1 = []
for n in range(0,num_list):
    l = int(input())
    if l in list_1:
        print("Duplicate")
        break
    else:
        list_1.append(l)
else:
    print("Unique")
    
