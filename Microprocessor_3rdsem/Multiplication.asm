lxi h, data
mov e, m
inx h
mov d, m
inx h
mov a, m
inx h
mov b, m
lxi h, 0000h
mvi c, 08h
call nxtbit
mov a, b
mvi c, 08h
call nxtbit
hlt

nxtbit:	rrc
	jnc noadd
	dad d
noadd:	xchg
	dad h
	xchg
	dcr c
	jnz nxtbit
ret

data: db 01h, 0ffh, 7eh, 00h