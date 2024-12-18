
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
;store all vectore
call vector
cma
push b
mvi e,08h
mvi d,01h
mvi c,00h 
push h
call vector
xchg;de locate to next location
pop h;hl locate to vector location
mov a,c
pop b
push psw 
mov a,c
;for storing k disjoint sequence
outerLOOP:	push psw 
		mov a,b
		stax d
		inx d
		call again
		call rotate
		pop psw
		dcr a
		jnz outerLOOP
mvi a,00h
stax d
inx d
pop psw		
 ;for storing 8-k disjoint sequence
outerLoop2:	push psw 
		mov a,b
		stax d
		inx d
		xra m
		stax d
		inx d
		call again
		xra m
		stax d
		inx d
		inx h
		pop psw
		dcr a
		jnz outerLoop2
		hlt


;subroutine for storing vector
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
	ret
;subroutine for xor with vector
again:  push h
	push b
	lxi h,data
	inx h
	inx h
loop: 	xra m
	stax d
	inx d
	inx h
	dcr c
	jnz loop
	pop b
	pop h
	ret
;subroutine for rotate vector
rotate: push h 
	push b
	lxi h,data
	inx h
	inx h
	push h
	mov a,m
	dcr c
loop2:  inx h
	mov b,m
	mov m,a
	mov a,b
	dcr c
	jnz loop2
	pop h
	mov m,a
	pop b
	pop h
	ret
data: db 26h,56h