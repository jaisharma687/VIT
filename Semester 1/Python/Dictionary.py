county={'Delhi':'India','Bangkok':'Thailand','Tokyo':'Japan','Washington D.C.':'America'}
user_input=input('Enter the capital: ')
print(county[user_input])
del county['Washington D.C.']
print(county)
if 'India' in county:
    print('True')
else:
    print('LOL')
l1=list(county.keys())
l2=list(county.values())
dict1={i:j for (i,j) in zip(l1,l2)}
print(dict1)
print(list(dict1.items()))

#update in dictionary is the same as append in lists only we use update between 2 dictionaries only

#pop is used to delete dictionary item but key is required, it does not work like list

#methods to create dictionary:
d=dict(A='1',B='2')
print(d)

d1=dict([('A',1),('B',2)])
print(d1)