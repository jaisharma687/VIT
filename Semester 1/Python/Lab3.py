hours_worked=int(input('Please enter the number of hours worked by the labour: '))
wages_per_hour=int(input('Please enter the wages per hour: '))
table_number=int(input('Please enter the number of tables: '))
table_cost=int(input('Please enter the cost of each table: '))
chair_number=int(input('Please enter the number of chairs: '))
chair_cost=int(input('Please enter the cost of each chair: '))
computer_cost=int(input('Please enter the cost of each computer: '))
computer_number=int(input('Please enter the number of computers: '))


cost_labour=hours_worked*wages_per_hour
cost_furniture=table_number*table_cost+chair_number*chair_cost
cost_computer=computer_cost*computer_number
print('Cost of labour is ', cost_labour)
print('Cost of furniture is ', cost_furniture)
print('Cost of computers is ', cost_computer)

total_expenditure=cost_computer+cost_labour+cost_furniture
print('Total cost to setup the lab is ',total_expenditure)