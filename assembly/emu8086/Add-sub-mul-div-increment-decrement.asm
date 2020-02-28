
NAIM:

mov ah, 5
mov al, 3
add ah, al      ;adding


mov ax, 9
sub ax, 3       ; subtracting


mov ax, 0
mov al, 4       ; multiplies with al and stores in ax (16 bit)
mov bl, 2
imul bl        ; 8-bit Multiply


mov ax, 1111h    ; multiplies with ax and stores in dx:ax  (32 bit)
mov bx, 2
imul bx       ; 16 bit multiply


mov ax, 2222h    ;divides ax and stores quiotent in al and remainder in ah 
mov bl, 2       
idiv bl         ; 8 bit division

mov dx, 0001h
mov ax, 5AB4h 
mov bx, 1770h
idiv bx       ; 16 bit division


mov cx, 8
inc cx        ; increment
inc cx
dec cx        ; decrement


mov ah, 4ch
int 21h

END NAIM