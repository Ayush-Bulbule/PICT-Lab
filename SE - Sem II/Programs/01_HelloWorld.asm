;sample program to print hello world
global _start
section .data
    msg db "Hello This is first Nasm Program",0xa
    msgLen equ $- msg

section .text
_start:
    mov rax, 01
    mov rdi, 01
    mov rsi, msg
    mov rdx, msgLen
    syscall

exit:
    mov rax, 60
    mov rdx,60
    syscall
    