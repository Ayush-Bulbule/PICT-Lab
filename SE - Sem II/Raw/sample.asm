global _start

section .data
    num db 9


section .text
_start:

    
    add byte [num], 4
    add byte [num], '0'

    

    mov rax, 01
    mov rdi, 01
    mov rsi, num
    mov rdx, 01
    syscall

exit:
    mov rax, 60
    mov rdx, 60
    syscall
