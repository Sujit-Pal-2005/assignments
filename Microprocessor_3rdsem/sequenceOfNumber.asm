
;<Program title>
lxi h,data
mov a,m
mov b,a
inx h
mov e,m
inx h
xra e
mvi e,08h
mvi d,01h
mvi c,00h
push h
;store all vectore
vector: rrc
	jnc skip
	mov m,d
	inx h
        inr c
skip:	push psw
	mov a,d
	rlc
	mov d,a
	pop psw
	dcr e
	jnz vector
xchg;de locate to next location
pop h;hl locate to vector location
mov a,c
outerLOOP:	push psw 
		push b
		push h
		mov a,b
loop: 	xra m
	stax d
	inx d
	inx h
	dcr c
	jnz loop
	pop h
	pop b
	call rotate
	pop psw
	dcr a
	jnz outerLOOP	

        hlt


rotate: push h 
	push b
	mov a,m
	dcr c
loop2:  inx h
	mov b,m
	mov m,a
	mov a,b
	dcr c
	jnz loop2
	pop b
	pop h
	mov m,a
	ret
data: db 26h,56h

