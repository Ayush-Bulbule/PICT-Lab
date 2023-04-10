global _start

section .data
    msg1 db "Program to read a Number and Display it.", 0xA
    len1 equ $ - msg1

    msgIn db "Enter a number = ", 0xA
    msgInLen equ $ - msgIn

    msgOut db "You Entered = ", 0xA
    msgOutLen equ $ - msgOut


section .bss
    num resb 2

section .text
_start:

MSG1:                ; prinit msg
    mov rax, 01
    mov rdi, 01
    mov rsi, msg1
    mov rdx, len1
    syscall

    ; print msg1 
    mov rax, 01
    mov rdi, 01
    mov rsi, msgIn
    mov rdx, msgInLen
    syscall

    mov r8, num     ; pointer to variable

    ; take input
    mov rax, 00
    mov rdi, 00
    mov rsi, r8
    mov rdx, 16
    syscall

msg2:        ; print msg2
    mov rax, 01
    mov rdi, 01
    mov rsi, msgOut
    mov rdx, msgOutLen
    syscall


Output_NUM:          ; print numbers
    mov rax, 01
    mov rdi, 01
    mov rsi, r8
    mov rdx, 16
    syscall

Exit:               ; exit 
    mov rax, 60
    mov rdx, 00
    syscall