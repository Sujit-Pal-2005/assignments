 mov cx,6745h
 mov bx,0ff00h
 
 looop: mov al,bh
        sub al,bl
        clc
        ror al,01h
        add al,bl
        mov dh,al
        mul al
        cmp ax,cx
        ja skip1
        jz end
        mov bl,dh
        inc bl
        jmp check  
        
skip1:  mov bh,dh
        dec bh
        
check:  cmp bl,bh
        jbe looop
        
end:    hlt
        