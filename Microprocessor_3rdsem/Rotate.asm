
;<rotate through 0,0+r,0+2r, .... >
lxi sp,0ff00h


; c=4,e=2,b=10,d=5
mvi b,0ah ; n=10 numbers
mvi c,04h ; rotate by r=4

push b
call gcd
mov e,c ; save gcd at e for division
pop b ; now b=n and c=r
call divide; d gets n/gcd


mvi a,00h
lxi h,data
loop: 	push d
	mov e,m ; e=0; 
	call rotate
	inx h
	pop d
	dcr e
	jnz loop
	hlt

data: db 0,1,2,3,4,5,6,7,8,9

gcd: mov a,b 
subagain: sub c
     jnc subagain
     add c ;adjust excess subtraction 
     rz ; if zero c is the gcd
     mov b,c
     mov c,a
     call gcd
     ret

divide: mov a,b ;divide b by e
        mvi d,00h
again:  inr d
        sub e
        jnz again
        ret

rotate: add c ;subroutine to rotate a=4
        cmp b
        jc nomod ; generate (a+c)%b
        sub b
nomod:  push h
        call addha
       call  onemov
        pop h
         dcr d
         jnz rotate
         ret

onemov: push b
        mov b,m
        mov m,e
        mov e,b
        pop  b
        ret        

addha: push psw ; generate next address
       add l
       mov l,a
       jnc noinch
       inr h
noinch: pop psw
        ret

