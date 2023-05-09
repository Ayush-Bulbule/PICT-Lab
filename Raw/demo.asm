section .data
    msg1 db "Array in Assembly Language", 0xA
    msg1Len equ $-msg1

    ; declaring an array
    numarray db 1, 2, 3, 4, 5, 6, 7, 8
    numarrayLen equ $-numarray

section .bss
    ; declaring a counter variable
    counter resb 1

section .text
_start:
    ; print the message
    mov rax, 01
    mov rdi, 01
    mov rsi, msg1
    mov rdx, msg1Len
    syscall

    ; print the array
    mov rdi, 1             ; file descriptor for stdout
    mov rsi, numarray
    mov byte [counter], numarrayLen   ; initialize counter variable to length of array
print_loop:
    cmp byte [counter], 0             ; check if counter variable is zero
    jle end_print_loop                ; exit loop if counter is zero or negative
    mov rax, 4                        ; system call for write
    mov rdx, 1                        ; length of element to print
    syscall
    dec byte [counter]                ; decrement counter variable
    add rsi, 1                        ; move to next element in array
    jmp print_loop                    ; jump to beginning of loop
end_print_loop:

    ; print a newline character
    mov rax, 4
    mov rdi, 1
    mov rsi, 0xA
    mov rdx, 1
    syscall

    ; exit the program
    mov rax, 60
    xor rdi, rdi
    syscall
