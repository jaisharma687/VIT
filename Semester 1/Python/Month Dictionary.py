number_input=int(input('Enter the number of months: '))
month=[]
days=[]
month_dict={}
for i in range(1,number_input+1):
    month_name=input('Enter the name of the month: ')
    month_days=input('Enter the days of the month: ')
    month.append(month_name)
    days.append(month_days)
    month_temp={i:j for (i,j) in zip(month,days)}
    month_dict.update(month_temp)
print(month_dict)
print(month_dict.keys())
month_name_list=list(month_dict.keys())
print(sorted(month_name_list))