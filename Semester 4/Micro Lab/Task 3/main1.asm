ORG 0000H
MAIN:
    MOV A, P1
    JB P1.2, SEND_DATA
    SJMP RECEIVE_DATA
SEND_DATA:
    MOV DPTR, #DATA_STR
    MOV TMOD, #20H
    MOV TH1, #-3
    MOV SCON, #50H
    SETB TR1
    MOV R1, #14
SEND_LOOP:
    CLR A
    MOVC A, @A+DPTR
    MOV SBUF, A
WAIT_FOR_TX:
    JNB TI, WAIT_FOR_TX
    CLR TI
    INC DPTR
    DJNZ R1, SEND_LOOP
    SJMP MAIN
RECEIVE_DATA:
    MOV TMOD, #20H
    MOV TH1, #-6
    MOV SCON, #50H
    SETB TR1
RECEIVE_LOOP:
    JNB RI, RECEIVE_LOOP
    MOV A, SBUF
    MOV P2, A
    CLR RI
    SJMP MAIN
P1_2_HIGH: SJMP SEND_DATA
DATA_STR: DB "VIT University"

END