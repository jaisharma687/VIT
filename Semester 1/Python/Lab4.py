student=input('Please specify if the student is first graduate in the family\nYes or No: ')
if student=='Yes' or student=='yes' or student=='YES':
    math=int(input('Please enter the marks of Mathematics '))
    phy=int(input('Please enter the marks of Physics '))
    chem=int(input('Please enter the marks of Chemistry '))

    if math>98 and chem>98 and phy>98:
        print('The student is eligible for scholarship')
    else:
        print("Student is not eligible for scholarship")
elif student=='No' or student=='NO' or student=='no':
    print('Student is not eligible')

else:
    print('Bruh')