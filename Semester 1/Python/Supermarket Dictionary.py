product_amount=int(input('Enter the numebr of products: '))
val=[]
name=[]
for i in range(1,product_amount+1):
    product_name=input('Enter the name of the product: ')
    product_value=input('Enter the price of the product: ')
    name.append(product_name)
    val.append(product_value)
    dictionary={i:j for (i,j) in zip(name,val)}
    product={}
    product.update(dictionary)
print(product)
a=True
while a==True:
    ext=input('Enter Exit to exit the code: ')
    if ext=='Exit':
        break
    else:
        prod=input('Enter the product name: ')
        if prod in product:
            print(product[prod])
        else:
            print('The product is not available in the list')
