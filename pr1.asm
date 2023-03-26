;Program to print text

global _start

section .data
	msg db "Hello World", 0xA ;msg var storing text to print
	lenMsg equ $ -msg
	
section .text

_start:

	mov rax, 01
	mov rdx, 01
	mov rsi, msg
	mov rdx, lenMsg
	syscall

EXIT:	
	mov rax, 60
	mov rdx, 60
	syscall
