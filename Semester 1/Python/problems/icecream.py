flav = ["Mango","Chocolate","Vanilla","Strawberry","Blueberry","Orange","Nuts"]
x=input('Enter the prices of the ice cream: ').split(',')
value = []
for i in x:
    value.append(int(i))
# value = [5,15,5,25,10,5,15]
total_money= input()
for i in range(0,len(value)):
    for j in range(i+1,len(value)):
        if value[i]+value[j]==total_money:
            print(f"{flav[i]} and {flav[j]}")

