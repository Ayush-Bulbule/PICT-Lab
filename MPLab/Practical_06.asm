; Write X86/64 ALP to convert 4-digit Hex number into its equivalent BCD number and 5-digit BCD number into its equivalent HEX number.
; Make your program user friendly to accept the choice from user for: (a) HEX to BCD b) BCD to HEX (c) EXIT. Display proper strings to
; prompt the user while accepting the input and displaying the result. (wherever necessary, use 64-bit registers)

section .data
    msg : db "1.HEX to BCD ", 0x0A
          db "2.BCD to HEX ", 0x0A
          db "3.Exit",0x0A
    len equ $-msg
    msg1 db "Enter your Choice : "
    len1 equ $-msg1
    msg2 db "Enter HEX number : "
    len2 equ $-msg2
    msg3 db "Enter BCD number : "
    len3 equ $-msg3
    msg4 db "Equivalent BCD number is : "
    len4 equ $-msg4
 
    msg5: db "Equivalent HEX number is : "
    len5: equ $-msg5
    m: db " ",0x0A
    l: equ $-m

section .bss

    num: resb 6
    result: resb 4
    ans : resb 4
    digitcount : resb 01
    choice : resb 02
 
section .txt
global _start
_start:

menu:
    mov rax,1
    mov rdi,1
    mov rsi,m                  ;Newline
    mov rdx,l
    syscall
 
    mov rax,1
    mov rdi,1
    mov rsi,m                  ;Newline
    mov rdx,l
    syscall
 
    mov rax,1
    mov rdi,1
    mov rsi,msg             
    mov rdx,len
    syscall
 
    mov rax,1
    mov rdi,1
    mov rsi,msg1
    mov rdx,len1
    syscall
 
    mov rax,0
    mov rdi,0
    mov rsi,choice
    mov rdx,02
    syscall
 
    cmp byte[choice],31H
    je case1
 
    cmp byte[choice],32H
    je case2
 
    cmp byte[choice],33H
    je case3
 
    
case2:

    mov rax,1
    mov rdi,1
    mov rsi,msg3
    mov rdx,len3
    syscall
 
 
    mov rax,0
    mov rdi,0
    mov rsi,num
    mov rdx,6
    syscall
 
    xor rax,rax
    mov rbx,10
    mov rcx,05

up2: 
    xor rdx,rdx
    mul ebx
    xor rdx,rdx
    mov dl,[rsi]
    sub dl,30H
    add rax,rdx
    inc rsi
    dec rcx
    jnz up2
 
    mov [result],ax
 
    mov rax,1
    mov rdi,1
    mov rsi,msg5
    mov rdx,len5
    syscall
 
    mov ax,[result]
    call display
 
    jmp menu
 
case1: 
    mov rax,1
    mov rdi,1
    mov rsi,msg2
    mov rdx,len2
    syscall
 
    call accept
 
    mov ax,bx

    mov rbx,10
back:
    xor rdx,rdx
    div rbx

    push dx
    inc byte[digitcount]

    cmp rax,0h
    jne back
 
print:
    pop dx
    add dl,30h   
    mov [result],dl

    mov rax,1
    mov rdi,1
    mov rsi,result
    mov rdx,1
    syscall

    dec byte[digitcount]
    jnz print
 
    jmp menu
 
 
accept:

    mov rax,0
    mov rdi,0
    mov rsi,num
    mov rdx,5
    syscall 
     
    xor bx,bx
    mov rcx,4
    mov rsi,num

next_digit:

    rol bx,04
    mov al,[rsi]
    cmp al,39h
    jbe sub30
    sub al,7h

sub30:  sub al,30h
   
    add bx,ax   
    inc rsi   
    loop next_digit
ret

 
display: 
    mov rsi,ans+3
    mov rcx,4
 
count:

    mov rdx,0
    mov rbx,16
    div rbx
    cmp dl,09H
    jbe skip2
    add dl,07H
 
skip2:
    add dl,30H
    mov [rsi],dl
    dec rsi
    dec rcx
    jnz count
 
    mov rax,1
    mov rbx,1
    mov rsi,ans
    mov rdx,4
    syscall
    ret 
 


 case3:
    mov rax,60
    mov rdi,0
    syscall
 