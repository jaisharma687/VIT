ORG 0000H
MOV TMOD,#60H
MOV TH1,#0
SETB P3.6
MAIN: SETB TR1
BACK: MOV A,TL1
MOV P2,A
JNB TF1,BACK
CLR TR1
CLR TF1
SJMP MAIN
END