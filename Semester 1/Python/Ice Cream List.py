ice_fl=["Mango","Chocolate","Vanilla","Strawberry","Blueberry","Orange","Nuts"]
x=input('Enter the prices of the ice cream: ').split(',')
cost = []
for i in x:
    cost.append(int(i))
money=int(input('Enter the amount you have: '))
for i in range(0,len(cost)):#0,1,2
    for j in range(i+1,len(cost)):
        if cost[i]+cost[j]==money:
            print(ice_fl[i],ice_fl[j])