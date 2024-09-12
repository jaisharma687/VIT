import collections

year = {
    "january": 31,
    "february": 28,
    "march": 31,
    "april": 30,
    "may": 31,
    "june": 30,
    "july": 31,
    "august": 31,
    "september": 30,
    "october": 31,
    "november": 30,
    "december": 31
}

# user_inp = input("Enter the month name: ").lower()
# for month in year:
#     if month == user_inp:
#         print(f"Number of days in the month of {user_inp.upper()} are {year[user_inp]} days")

# sorted_dict = collections.OrderedDict(sorted(year.items()))
# print(sorted_dict)

# for key in year:
#     if year[key] == 31:
#         print(key)

dict = sorted(year.items(), key=lambda item: item[1])
print(dict)
