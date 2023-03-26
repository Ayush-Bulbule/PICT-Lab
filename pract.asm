global _start

section .data
	msg1 db "Program to Display 64 bit Hex Number:",0xA
	len1 equ $ - msg1
	
	msgIn db "Enter 5 Numbers: ", 0xA
	msgInLen equ $ - msgIn
	
	msgOut db "Numbers = ", 0xA
	msgOutLen equ $ - msgOut
	
	cnt db 5
	
section .bss
	num resb 10  ;to store the data
	
section .text
_start:

MSG1:
	mov rax, 01
	mov rdi, 01
	mov rsi, msg1
	mov rdx, len1
	syscall
	
Input_Call:
	mov rax, 01
	mov rdi, 01
	mov rsi, msgIn
	mov rdx, msgInLen
	
	mov r8, num  ; pointer to array

Input_Num:		;Read Number
	mov rax, 00
	mov rdi, 00
	mov rsi, r8
	mov rdx, 17  ; 16 bits + 1 bit of enter
	syscall
	
	
	add r8, 17
	dec byte[cnt]
	jnz Input_Num ; Jumps until count not equal to zero
	
Output_Call:
	mov rax, 01
	mov rdi, 01
	mov rsi, msgOut
	mov rdx, msgOutLen
	syscall
	
	;as out count is 0 we have to reinitalize it with 5
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
	
Exit:			;exit
	mov rax, 60
	mov rdx, 60
	syscall
	
