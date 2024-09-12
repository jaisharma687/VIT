while True:
    basic_pay = int(input('Please enter the basic pay of the employee: '))
    dearness_pay = basic_pay*80/100
    house_rent_allowance = basic_pay*30/100
    deductions = basic_pay*12/100
    gross_pay = basic_pay+dearness_pay+house_rent_allowance
    net_pay = gross_pay-deductions

    print('Gross pay of the employee is ',gross_pay)
    print('Net pay of the employee is ',net_pay)
    if net_pay<100000:
        print('Man get a better job')
    else:
        print('GG')