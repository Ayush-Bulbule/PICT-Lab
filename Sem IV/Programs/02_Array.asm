global _start

section .data
    msg1 db "Array in Assembly Language", 0xA
    msg1Len equ $-msg1

    ;declaring an array
    numarray db 1, 2, 3, 4, 5, 6, 7, 8

    ;declaring variable containing count of array
    numarrayLen equ $-numarray

section .bss
    ;declaring a counter variable
    counter resb 1


section .text
_start:
    ; to print the message
    mov rax, 01
    mov rdi, 01
    mov rsi, msg1
    mov rdx, msg1Len
    syscall

    mov r8, numarray        ;pointer to array
    mov byte[counter], 8    ;setting counter to length or arr

    ;print array
loop_arr:
    ;print each num
    mov rax, 01
    mov rdi, 01
    mov rsi, r8
    mov rdx, 16
    syscall

    add r8, 16
    dec byte[counter]
    jnz loop_arr

exit:               ;Exit directives
    mov rax, 60
    mov rdx, 60
    syscall