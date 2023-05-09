%macro IO 4   ;Macro to print data
mov rax, %1   ;system call
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall		
%endmacro

section .data
	msg db "Arithmetic Operations 1. Add 2. Sub  3.Mult 4.Div", 0xA
	msglen equ $-msg
	
	newLine db "", 0xA
	newLen equ $-newLine
	
	madd db "Addition :"
	maddLen equ $-madd
	
	msub db "Subraction :"
	msubLen equ $-msub
	
	mmult db "Multiplication :"
	mmultLen equ $-mmult
	
	mdiv db "Division :"
	mdivLen equ $-mdiv
	
	
	n1 dq 4 ; number2
	n2 dq 2 ; number1 
section .bss
	_output resb 4	
	choice resb 1
	
section .text
	global _start
_start:

	IO 1,1, msg, msglen
	
	IO 0,0, choice, 2
	
	cmp byte[choice], '1'
	je add
	
	cmp byte[choice], '2'
	je sub
	
	cmp byte[choice], '3'
	je mult 
	
	cmp byte[choice], '4'
	je div
	
	
	
add:
	mov rax, qword[n1]
	mov rbx, qword[n2]
	add rax, rbx
	
	IO 1,1, madd, maddLen
	call hex_to_ascii
	IO 1,1,_output,16

	;print new line char
	IO 1,1,newLine, newLen
	je exit
sub:
	mov rax, qword[n1]
	mov rbx, qword[n2]
	sbb rax, rbx
	
	IO 1,1, madd, maddLen
	call hex_to_ascii
	IO 1,1,_output,16

	;print new line char
	IO 1,1,newLine, newLen
	je exit

mult:
	mov rax, qword[n1]
	mov rbx, qword[n2]
	mul rbx
	
	IO 1,1, mmult, mmultLen
	call hex_to_ascii
	IO 1,1, _output, 16
	IO 1,1,newLine, newLen
	je exit
	
	
div:
	xor rdx, rdx
	mov rax, qword[n1]
	mov ebx, dword[n2]
	
	div ebx
	
	IO 1,1, mdiv, mdivLen
	call hex_to_ascii
	
	IO 1,1, _output, 16
	IO 1,1,newLine, newLen
	je exit
	
	

exit:
	mov rax, 60
	mov rdx, 60
	syscall



;procedure to convert hex to ascii
hex_to_ascii:
	mov rsi, _output+15
	mov rcx, 2
letter2:
	xor rdx, rdx
	mov rbx, 10
	div rbx
	cmp dl, 09h
	jbe add30
add30:
	add dl, 30h
	mov [rsi], dl
	dec rsi
	dec rcx
	jnz letter2
ret
	
	
