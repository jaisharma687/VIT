ORG 0000H 
LJMP MAIN 
ORG 000BH
CPL P2.1
MOV TH0,#-47
RETI
ORG 0013H
INC TL1 
MOV A,TL1
MOV P0,A
RETI 
ORG 100H 
MAIN: 
MOV TMOD,#62H
MOV TH1,#00H
MOV TL1,#00H
MOV TH0,#-47
MOV IE,#10000110B
CLR IE1
SETB TR0
HERE: SJMP HERE
END