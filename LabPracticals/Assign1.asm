section .data
msg db "Enter 5 numbers:" ,0xA
len1 equ $-msg
msg1 db "Displaying 5 numbers:" ,0xA
len2 equ $-msg1

cnt db 05h
mov r8,00h

section .bss
num resb 16

section .text

global _start

_start : 

mov rax,01	; write instruction
mov rdi,01
mov rsi,msg
mov rdx,len1
syscall

mov r8,num	; r8 pointing to num array
l1:			
mov rax,00	; reading 5 elements of the array
mov rdi,00
mov rsi,r8
mov rdx,17
syscall
add r8,17	; add 17 to the pointer to move to the next position
dec byte[cnt]
jnz l1

mov rax,01	; write system call
mov rdi,01
mov rsi,msg1
mov rdx,len2
syscall

mov byte[cnt],05h	; reinitialize cnt to 05
mov r8,num		; point r8 to start of num array
l2:
mov rax,01		; print elements of the array
mov rdi,01
mov rsi,r8
mov rdx,17
syscall
add r8,17		
dec byte[cnt]
jnz l2

mov rax,60	; exit system call
mov rdi,0
syscall
