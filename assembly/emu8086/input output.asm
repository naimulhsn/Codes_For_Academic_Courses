

    mov ah,1
    int 21h
    mov bl,al
    
    mov ah,2
    mov dl,32      
    int 21h
    
    mov ah,1
    int 21h
    mov bh,al
    
    mov ah,2
    mov dl,10     ; 10 line feed 
    int 21h
    mov dl,13     ; 13 for carriage return 
    int 21h
    
    push bx   ;so that bl's value can be retrived after any change
    
    add bl,bh
    sub bl,30h  ; 30h==48
    
    
    mov ah,2
    mov dl,bl
    int 21h       ; output add
    
    mov dl,32       ; 32 for space
    int 21h
    
    pop bx    ; retrive bl's original value
    
    sub bl,bh
    add bl,48
    
    mov ah,2
    mov dl,bl
    int 21h         ; output sub
    
    mov ah,4ch
    int 21h
