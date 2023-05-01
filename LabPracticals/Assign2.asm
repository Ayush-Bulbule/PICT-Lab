section .data
msg db "Enter a string:" ,0xA
len1 equ $-msg

msg1 db "Length of string:" ,0xA
len2 equ $-msg1
cnt db 05h

section .bss
str : resb 16h
length resb 16h

section .text

global _start

_start : 

mov rax,01	; write instruction
mov rdi,01
mov rsi,msg
mov rdx,len1
syscall
			
mov rax,00	; read string
mov rdi,00
mov rsi,str
mov rdx,16
syscall

dec rax
mov r8, length
mov byte[cnt],16

up:		; convert hex to ascii
rol rax,04	; roatate rax left by 4 times
mov bl,al	; mov rotated contents to bl
AND bl,0Fh	; remove tens place

cmp bl,09h	;compare bl with 09h
jbe l1		; jump,if b1 is less or equal to 09h, to label l1
add bl,7h	; add 7 if hex number is between A and F

l1:
add bl,30h	; add 30h to bl 
mov byte[r8], bl
inc r8
dec byte [cnt]
jnz up

mov rax,01	; write instruction
mov rdi,01
mov rsi,length
mov rdx,16
syscall

mov rax,60	; exit system call
mov rdi,00
syscall
