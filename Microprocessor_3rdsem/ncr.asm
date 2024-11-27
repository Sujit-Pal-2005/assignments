
;<Program title>
lxi h,data
mov b,m
inx h
mov c,m
lxi d,0000h
lxi h,0000h
call ncr
hlt

ncr: 	mov a,b
	sub c
	cmp c
	jc skip
	mov a,c
skip:	cpi 0h
	jnz skip1
	mvi d,00h
	mvi e,01h
	ret
skip1:	cpi 01h
	jnz skip2
	mvi d,00h
	mov e,b
	ret
skip2:	cmp b
	jnz skip3
	mvi d,00h
	mvi e,01h
	ret
skip3:	push b
	dcr b
	push h
	call ncr
	pop h
	xchg	
	pop b
	dcr b
	dcr c
	push b
	push h
	call ncr
	pop h
	dad d
	xchg
	pop b
	ret 
data: db 0bh, 07h
	