.DATA
msg db "Hello World!$"
.CODE

NAIM:

mov ax, seg msg
mov ds, ax
mov dx, offset msg

mov ah, 9
int 21h

mov ah, 4ch
int 21h

END NAIM