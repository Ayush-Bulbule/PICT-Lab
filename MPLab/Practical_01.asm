;Display the five 64 bit Hexadecimal numbers from the user 
section .data
    msg1 db "Program to accept 5 numbers and print them!",0xA ; message to be printed at the beginning of the program
    len1 equ $-msg1 ; length of msg1

    msg2 db "Enter 5 numbers:" ,0xA ; message to prompt the user to enter the numbers
    len2 equ $-msg2 ; length of msg2

    msg3 db "Displaying 5 numbers:" ,0xA ; message to indicate that the numbers are being displayed
    len3 equ $-msg3 ; length of msg3

    cnt db 05h ; counter to track the number of times the loop needs to be executed
    mov r8,00h ; initializing r8 to 0

section .bss
    num resb 16 ; array to store the user input

section .text

global _start

_start :

Msg1:
    mov rax,01 ; write instruction
    mov rdi,01 ; stdout file descriptor
    mov rsi,msg1 ; message to print
    mov rdx,len1 ; length of message
    syscall ; system call to print the message

InputMsg:
    mov rax,01
    mov rdi,01 
    mov rsi,msg2 
    mov rdx,len2 
    syscall 

    mov r8,num ; r8 pointing to num array

InputNum:
    mov rax,00 ; read instruction
    mov rdi,00 ; stdin file descriptor
    mov rsi,r8 ; memory location where the input is to be stored
    mov rdx,17 ; number of bytes to be read (16 bytes for 64 bit hexadecimal number and 1 byte for newline character)
    syscall ; system call to read the input


    add r8,17 ; incrementing the pointer by 17 bytes to point to the next memory location to store the next input
    dec byte[cnt] ; decrementing the counter by 1
    jnz InputNum ; if counter is not zero, repeat the loop

OutputMsg:
    mov rax,01 
    mov rdi,01 
    mov rsi,msg3 
    mov rdx,len3 
    syscall 

    mov byte[cnt],05h ; reinitialize cnt to 05
    mov r8,num ; point r8 to start of num array

OutputNum:
    mov rax,01 
    mov rdi,01
    mov rsi,r8 
    mov rdx,17 
    syscall 

    add r8,17 ; incrementing the pointer by 17 bytes to point to the next memory
    dec byte[cnt] ; decrementing the counter by 1
    jnz OutputNum ; if counter is not zero, repeat the loop

Exit:
    mov rax,60 ; exit system call
    mov rdi,0 ; exit status
    syscall ; system call to exit the program
