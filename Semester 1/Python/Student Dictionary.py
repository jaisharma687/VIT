num=int(input('Enter the number of inputs: '))
student={}
for i in range(1,num+1):
    l=input('Enter registration number, name, grade: ').split(';')
    data={l[0]:l[1]}
    student.update(data)
print(student)