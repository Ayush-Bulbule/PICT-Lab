;Program to print a simple message
global _start

section .data
    msg db "Hello Welcome to Assembly!",0xa
    len equ $-msg


section .text
_start:
    mov rax, 01
    mov rdi, 01
    mov rsi, msg
    mov rdx, len
    syscall

    mov rax, 60
    mov rdx, 00
    syscall

