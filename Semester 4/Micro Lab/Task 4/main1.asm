ORG 0000H
LJMP MAIN
ORG 23H 
LJMP SERIAL
ORG 30H
MAIN: MOV P1,#0FFH
MOV TMOD,#20H
MOV TH1,#0FDH
MOV SCON,#50H
MOV IE,#10010000B
SETB TR1
BACK: MOV A,P1 
MOV P2,A
SJMP BACK
ORG 100H
SERIAL: JB TI,TRANS
MOV A,SBUF
MOV P0,A
CLR RI
RETI
TRANS: CLR TI
RETI
END