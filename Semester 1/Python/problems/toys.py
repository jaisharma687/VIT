import collections
# covert the toys dict into input format
toys = {
    "T1": 31,
    "T2": 28,
    "T3": 34,
    "T4": 39,
    "T5": 27,
    "T6": 20,
    "T7": 45,
    "T8": 17,
    "T9": 32,
    "T10": 23,
}

# sorted_dict = collections.OrderedDict(sorted(toys.items()))
# print(sorted_dict)
print(len(toys))
list_1 = sorted(toys.items(), key=lambda item: item[1])
key_list = []
for key in list_1:
    key_list += list(key)
for i in range(1,19,2):
    print(key_list[i])