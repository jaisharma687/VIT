ORG 0000H
MOV TMOD,#01H
HERE: MOV TH0,#0FCH
MOV TL0,#66H
CPL P1.3
ACALL DELAY
SJMP HERE

DELAY: SETB TR0
LOOP: JNB TF0,LOOP
CLR TR0
CLR TF0
RET

END