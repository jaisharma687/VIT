# An anagram is a word or phrase formed by rearranging the letters in another word or phrase. 
# Take two words or phrase from the user and display if they are "anagram" or "not anagram".
# Input Format:
# First word or phrase
# Second word or phrase
# Output Format:
# "anagram" or "not anagram"

first_wrd = input()
second_wrd = input()
first_word = list(first_wrd)
second_word = list(second_wrd)
if len(first_word) == len(second_word):
    first_word.sort()
    second_word.sort()
    if first_word == second_word:
        print("anagram")
    else:
        print("Not anagram")
else:
    print("not anagram")