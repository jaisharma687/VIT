ORG 000H
MOV DPTR, #200H
MOV A, #03H
MOV R1, A
MOV R0,A
ADD A, R1
MOV R1, A
MOV A, R0
MOVC A, @A+DPTR
ADD A,#09H
ADD A, R1
MOV R2, A
HERE: SJMP HERE
ORG 200H
DB 00H,01H,04H,09H,10H,19H,24H,31H,40H,51H
END