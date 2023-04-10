%macro IO 4 ;creating a macro for input and output
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

section .data
    msg db ""