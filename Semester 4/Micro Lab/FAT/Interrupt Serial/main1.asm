ORG 0000H
LJMP MAIN
ORG 0023H
LOOP: JNB RI,LOOP
MOV A,SBUF
MOV P2,A
CLR RI
RETI

ORG 0030H
MAIN: MOV TMOD,#20H
MOV TH1,#-3
MOV SCON,#50H
MOV IE,#10010000B
AGAIN:
JB P1.2, SETPORT
SJMP CLRPORT
SETPORT: SETB P1.7
SJMP AGAIN
CLRPORT: CLR P1.7
SJMP AGAIN
SJMP $

END