# Write a pseudo code and Python program to create a user defined dictionary to map name of 
# countries to their capital. Further perform swapping of ith and jth key's values in the 
# dictionary.
# Input Format:
# Number of Elements in a dictionary
# Key and value pairs of dictionaries
# Value of i
# Value of j
# Output Format:
# Display dictionary after swapping the values

# empty_dict = {}
# cond = True
# while cond == True:
#     key = input("Enter the name of the country: ")
#     value = input("Enter the name of country capital: ")
#     empty_dict[key] = value
#     continue_cond = input("To add more value type yes and if not type no: ").lower()
#     if continue_cond == "yes":
#         cond = True
#     elif continue_cond == "no":
#         cond = False
empty_dict = {"India": "Delhi", "Pakistan": "Islamabad", "USA": "Washinghton DC", "UK": "London"}   
print(len(empty_dict))
i_value = input("Enter the value of i: ")
j_value = input("Enter the value of j: ")
key_1 = list(empty_dict.keys())[list(empty_dict.values()).index(j_value)]
key_2 = list(empty_dict.keys())[list(empty_dict.values()).index(i_value)]
empty_dict[key_1] = i_value
empty_dict[key_2] = j_value
# print(key_1)
# print(key_2)
print(empty_dict)