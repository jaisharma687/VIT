# A physician wants to check the health status of the patient after performing a few medical 
# tests. Providing the number of tests, get the names of each test, minimum and maximum 
# values corresponding to each one. Further, with the help of the given test name and the 
# observed value of the test of an individual patient, write an algorithm and the subsequent 
# Python program to print if the test result is normal or abnormal. The patient report is normal 
# if the observed value of the test lies in between the maximum and minimum value.
# Input Format:
# Number of tests
# Name of the test
# Minimum value of test
# Maximum value of test
# Name of the observed test 
# Observed value of the test
# Output Format:
# Abnormal or Normal

empty_dict = {}
dict_obs = {}
num_tests = int(input("Enter number of tests: "))


cond_1 = 1
cond_2 = 1
while cond_1 <= num_tests:
    name_test = input("Enter the name of the test: ")
    min_value = int(input("Enter min value: "))
    max_value = int(input("Enter max value: "))
    list = [min_value, max_value]
    empty_dict[name_test] = list
    cond_1 += 1
while cond_2 <= num_tests:
    name_obs_test = input("Enter the name of the observed test: ")
    obs_value = int(input("Enter value of obserevd test: "))
    dict_obs[name_obs_test] = obs_value
    for key in dict_obs:
        if key == name_test:
            if  obs_value in range(list[0],list[1]+1):
                print(f"Normal for obs test {key}")
            else:
                print(f"Abnormal for obs test {key}")
    cond_2 += 1