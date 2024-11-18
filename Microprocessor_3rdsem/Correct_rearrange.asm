;<Finding minimum and maximum of n numers n>= 2>
lxi sp,0ff00h
lxi h, 9000h
mov e,m; E contains the number of integers n
mov a,l
add e
mov e,a
mov d,h ; now DE points to end of array
push d
push h
call rearrange
pop h 
pop d
inx h
inx d
call minimum
inx d
call maximum

hlt

rearrange: mov a,m ;a=n
           rrc ;divide by 2
	   ani 7fh ; make msb 0
	   mvi b,00h
           mov c,a ; c=floor(n/2)
           push b
           inx h
 nxt: mov b,m
      ldax d
      cmp b
      jnc noswap
      mov m,a
      mov a,b 
      stax d ; swap the numbers pointed by DE and HL
noswap: inx h
        dcx d
        dcr c
        jnz nxt
        pop b
	ret
;subroutine to find minimum
minimum: push b
	mov b,m
        dcr c
        inx h
next:   mov a,m
	cmp b
	jnc nswp
	mov b,a
nswp: 	inx h
	dcr c
	jnz next
	mov a,b
        stax d
	pop b
 	ret

;subroutine to find maximum
maximum: push b
	mov a,m
	dcr c
	inx h
nxtt:   cmp m
	jnc swapno
	mov a,m
swapno: inx h
        dcr c
        jnz nxtt
	inx h
	stax d
	pop b
	ret 