global _start
section .data
    msg1 db  "Printing Numbers in Assembly",0xA
    msg1Len equ $ -msg1

    num db 2

section .text
_start:
    mov rax, 01
    mov rdi, 01
    mov rsi, msg1
    mov rdx, msg1Len
    syscall

    mov r8, num

    ; convert num to ASCII representation
    add r8, 48

    ; write the ASCII representation to stdout
    mov rax, 01
    mov rdi, 01
    mov rsi, r8
    mov rdx, 16
    syscall

exit:
    mov rax, 60
    xor rdi, rdi
    syscall