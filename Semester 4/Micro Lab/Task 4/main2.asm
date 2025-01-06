ORG 0000H
LJMP MAIN
ORG 000BH
CPL P3.6
RETI
ORG 23H ;
LJMP SERIAL
ORG 30H
MAIN: MOV P2,#0FFH
MOV TMOD,#22H
MOV TH1,#0FDH
MOV SCON,#50H
MOV TH0,#-231
MOV IE,#10010010B
SETB TR1
SETB TR0
BACK: MOV A,P2
MOV SBUF,A
MOV P0,A
SJMP BACK
ORG 100H
SERIAL:JB TI,TRANS
MOV A,SBUF
MOV P1,A
CLR RI
RETI
TRANS: CLR TI 
RETI
END