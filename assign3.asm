global _start

section .data
	msg db "Program to Fint greatest of the numbers in Arrray: ", 0xA
	lenMsg equ $ - msg
	
	msgIn db "Enter 5 numbers: ", 0xA
	lenMsgIn equ $ -msgIn
	
	msgOut db "The Greatest Number is :", 0xA
	lenMsgOut equ $ -msgOut
	
	cnt db 5
	
section .bss
	num resb 10

section .text

_start:
MSG:	
	;Print Title
	mov rax, 01
	mov rdi, 01
	mov rsi, msg
	mov rdx, lenMsg
	syscall
	
	;take array input
	
Input_Call:
	mov rax, 01
	mov rdi, 01
	mov rsi, msgIn
	mov rdx,lenMsgIn
	syscall
	
	mov r8, num ; pointer
	
Input_Num:
	mov rax, 00
	mov rdi, 00
	mov rsi, r8
	mov rdx, 17
	syscall
	
	add r8, 17
	dec byte[cnt]
	jnz Input_Num 

Output_Call:
	mov rax, 01
	mov rdi, 01
	mov rsi, msgOut
	mov rdx, lenMsgOut
	syscall
	
	
	mov byte[cnt], 5
	mov r8, num

Output_Num:
	mov rax, 01
	mov rdi, 01
	mov rsi, r8
	mov rdx, 17
	syscall
	
	add r8, 17
	dec byte[cnt]
	jnz Output_Num
	
Exit:
	mov rax, 60
	mov rdi, 60
	syscall
	
