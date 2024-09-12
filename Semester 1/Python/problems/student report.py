# . Given details of 'n' students, design a flowchart/algorithm and write the Python code to 
# determine the average marks scored by each student. The details of the student include 
# name, register number, and five marks. Write a function to determine the total marks scored 
# by the student and don't let the function to modify the marks.
# Input Format
# Number of students
# Register number of student1
# Five marks of student1
# ....
# Output Format
# Details of student as a list with name, register number, marks and total

num_student = int(input("Number of students: "))
cond = 0
list_1 = []
while cond < num_student:
    key = input("Enter the name of the Student: ")
    value_1 = input("Enter the Register Number: ")
    marks_1 = int(input("Enter marks1: "))
    marks_2 = int(input("Enter marks2: "))
    marks_3 = int(input("Enter marks3: "))
    marks_4 = int(input("Enter marks4: "))
    marks_5 = int(input("Enter marks5: "))
    total = marks_1 + marks_2 + marks_3 + marks_4 + marks_5
    average =  float(format(total/5,'.2f'))
    list_1.append([key,value_1,marks_1,marks_2,marks_3,marks_4,marks_5,total,average])
    cond += 1

print(list_1)