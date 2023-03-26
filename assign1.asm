global _start

section .data
    msg1 db "hello world", 0xA
    len1 equ $ - msg1

    msgIn db "Enter 5 numbers = ", 0xA
    msgInLen equ $ - msgIn

    msgOut db "Numbers = ", 0xA
    msgOutLen equ $ - msgOut

    cnt db 5

section .bss
    num resb 10

section .text
_start:

MSG1:                ; hello world
    mov rax, 01
    mov rdi, 01
    mov rsi, msg1
    mov rdx, len1
    syscall

Input_Call:         ; input call
    mov rax, 01
    mov rdi, 01
    mov rsi, msgIn
    mov rdx, msgInLen
    syscall

    mov r8, num     ; pointer to array

Input_NUM:          ; take input
    mov rax, 00
    mov rdi, 00
    mov rsi, r8
    mov rdx, 17
    syscall

    add r8, 17
    dec byte[cnt]
    jnz Input_NUM

Output_Call:        ; output call
    mov rax, 01
    mov rdi, 01
    mov rsi, msgOut
    mov rdx, msgOutLen
    syscall

    mov byte[cnt], 5
    mov r8, num

Output_NUM:          ; print numbers
    mov rax, 01
    mov rdi, 01
    mov rsi, r8
    mov rdx, 17
    syscall

    add r8, 17
    dec byte[cnt]
    jnz Output_NUM


Exit:               ; exit 
    mov rax, 60
    mov rdx, 00
    syscall
