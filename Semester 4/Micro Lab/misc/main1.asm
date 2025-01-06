ORG 0000H
MAIN: 
		MOV TMOD,#20H; timer 1 mode 3
		MOV SCON,#50H; serial port
		MOV R1,#14; ;length of string
		SETB TR1; start timer 1
		JB P1.0,CHANCE; check SW
PLACE: 					;SW = 0 	
		MOV DPTR,#Learn ; DPTR = 200H
		MOV TH1,#-3 ;9600 baud rate
		ACALL LOOP ; call loop
		SJMP MAIN
CHANCE: 				;SW = 1
		MOV DPTR,#Grow ; DPTR = 400H
		MOV TH1,#-6 ;4800 baud rate
		ACALL LOOP ; call loop
		SJMP MAIN
LOOP: 
		CLR A
		MOVC A,@A+DPTR
		MOV SBUF,A
HERE: 
		JNB TI,HERE
		CLR TI
		INC DPTR
		DJNZ R1,LOOP
		RET
		
ORG 0200H
Learn: DB "PLACE TO LEARN"
ORG 0400H
Grow: DB "CHANCE TO GROW" 
END