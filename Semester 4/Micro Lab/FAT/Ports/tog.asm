ORG 0000H
MAIN:
MOV P0,#55H
MOV P1,#55H
MOV P2,#55H
ACALL DELAY
MOV P0,#0AAH
MOV P1,#0AAH
MOV P2,#0AAH
ACALL DELAY
SJMP MAIN

DELAY: MOV R0,#0FFH
L1: MOV R1,#0FFH
L2: MOV R2,#0FFH
L3: DJNZ R2,L3
DJNZ R1,L2
DJNZ R0,L1
RET

END