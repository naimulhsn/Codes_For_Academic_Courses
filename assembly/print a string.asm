.model small
.stack 100h
.data
s db "BSMRSTU $"
.code

main proc
    
    mov ax,@data
    mov ds, ax
    
    mov ah,09h
    mov dx, offset s
    int 21h
    
    mov ah,4ch
    int 21h
    main endp
end main