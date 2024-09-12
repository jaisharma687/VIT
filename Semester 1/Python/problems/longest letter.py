# Write a Python function that takes a list of words and return the longest word and the length 
# of the longest one.
# Sample Output:
# Longest word: Exercises
# Length of the longest word: 9

list = input().split(", ")
longest_letter_len = ""
for element in list:
    if len(element) > len(longest_letter_len):
        longest_letter_len = element
    else:
        longest_letter_len = longest_letter_len

print(longest_letter_len)
print(len(longest_letter_len))