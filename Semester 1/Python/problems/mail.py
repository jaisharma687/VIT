# The CTS in VIT Vellore wants to create email id to all the first-year students. Assume that 
# they get the current email id of the students, separate the username from it and append the 
# new domain as "vit.ac.in" to create the new vit account. Given a personal mail id of student, 
# design a flowchart and write the Python code to automatically generate the new mail id. If 
# the current mail id is deepakshah@gmail.com then the new mail id to be generated is 
# deepakshah@vit.ac.in
# Input Format
# Current email id
# Output Format
# New email id

mail_user = input().split("@")
mail_user[1] = "vit.ac.in"
new_mail = '@'.join(mail_user)
print(new_mail)
