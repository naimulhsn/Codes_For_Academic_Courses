.model small
.stack 100h
.data
.code
main proc
    
    mov ah,1        ; ah,1 for input
    int 21h         ;intput   to al
    mov bl,al 
    
    
    
    mov ah,2
    mov dl,10                  ; 10 for new line
    int 21h                 ;new line
    mov dl,13               ; 13 for carrieg return
    int 21h
    
    sub bl,32        ; make upper case
    
    mov ah,2
    mov dl,bl        
    int 21h          ; print output from dl
    
    
    
    mov ah,4ch
    int 21h
    main endp
end main