stud_num=int(input('Please enter the number of students '))
clsavg=0
for i in range(0,stud_num):
    phy=int(input('Please enter Physics marks '))
    chem=int(input('Please enter Chemistry marks '))
    math=int(input('Please enter Mathematics marks '))
    avg=(phy+chem+math)/3
    print('Average marks of the student',i+1 , ' is ', format(avg,'.2f'))
    clsavg=clsavg+avg
avg_cls=clsavg/stud_num
print('Class average is ',format(avg_cls,'.2f'))