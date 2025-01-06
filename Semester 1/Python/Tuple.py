tests={'test1':(20,30),'test2':(35.5,40),'test3':(12,15),'test4':(120,150),'test5':(80,120)}
test=input('Enter the test: ')
if test=='test1':
    test1_result=int(input('Enter the value of the result'))
    if tests['test1'][0]>test1_result:
        print('Value too low')
    elif tests['test1'][0]<test1_result<tests['test1'][1]:
        print('Value is normal')
    elif test['test1'][1]>test1_result:
        print['Value too high']
elif test=='test2':
    test1_result=int(input('Enter the value of the result'))
    if tests['test2'][0]>test1_result:
        print('Value too low')
    elif tests['test2'][0]<test1_result<tests['test2'][1]:
        print('Value is normal')
    elif test['test2'][1]>test1_result:
        print['Value too high']
elif test=='test3':
    test1_result=int(input('Enter the value of the result'))
    if tests['test3'][0]>test1_result:
        print('Value too low')
    elif tests['test3'][0]<test1_result<tests['test3'][1]:
        print('Value is normal')
    elif test['test3'][1]>test1_result:
        print['Value too high']
if test=='test4':
    test1_result=int(input('Enter the value of the result'))
    if tests['test4'][0]>test1_result:
        print('Value too low')
    elif tests['test4'][0]<test1_result<tests['test4'][1]:
        print('Value is normal')
    elif test['test4'][1]>test1_result:
        print['Value too high']
if test=='test5':
    test1_result=int(input('Enter the value of the result'))
    if tests['test5'][0]>test1_result:
        print('Value too low')
    elif tests['test5'][0]<test1_result<tests['test5'][1]:
        print('Value is normal')
    elif test['test5'][1]>test1_result:
        print['Value too high']
print('Die')
    