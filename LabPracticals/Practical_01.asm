;Write X86/64 ALP to five hexadecimal numbers from
;user andstore them in an array and display the accepted
;numbers.

global _start
section .data
msg1 db "Enter 5 NUmbers: ", 0xA
len1 equ $-msg1

msg2 db "Displaying 5 Numbers: ", 0xA
len2 equ $-msg1

cnt db 05h
mov r8, 00h

section .bss
    num resb 16

section .text

_start:
    ;print msg
    mov rax, 01
    mov rdi, 01
    mov rsi, msg1
    mov rdx, len1
    syscall

    ;point r8, to num

    mov r8, num

    ;read data 16bits+1fro enter = 17
    loop1:
    mov rax, 00
    mov rdi, 00
    mov rsi, r8
    mov rdx, 17
    syscall

    add r8, 17; add the vale to r8 to move pointer to next location
    dec byte[cnt]
    jnz loop1

    mov rax, 01
    mov rdi, 01
    mov rsi, msg2
    mov rdx, len2 
    syscall

    mov byte[cnt], 05 ; reinitilize the count with 05

    mov r8, num  ; point to array

    loop2:
    mov rax, 01
    mov rdi, 01
    mov rsi, r8
    mov rdx, 17
    syscall

    add r8,17
    dec byte[cnt]
    jnz loop2

    mov rax, 60 ;exit
    mov rdi, 0
    syscall







