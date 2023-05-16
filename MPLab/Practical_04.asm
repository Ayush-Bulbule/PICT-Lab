;Yet To Impliment
section .data
	msgNum db "Numbers =", 0xA	;msg to display numbers
	msgNumLen equ $-msgNum
	
	newLine db 0xA
	newLineLen equ $-newLine
	
	msgAdd db "Addition = "
	msgAddLen equ $-msgAdd
	
	msgSub db "Subtraction = "
	msgSubLen equ $-msgSub
	
	msgMul db "Multiplication = "
	msgMulLen equ $-msgMul
	
	msgDiv db "Quotient = "
	msgDivLen equ $-msgDiv
	
	msgRem db "Remainder = "
	msgRemLen equ $-msgRem
	
	msgMenu db "---- MENU ----", 0xA, "1. Addition", 0xA, "2. Subtraction", 0xA, "3. Multiplication", 0xA, "4. Division", 0xA
	msgMenuLen equ $-msgMenu
	
	msgChoice db "Enter choice = "
	msgChoiceLen equ $-msgChoice
	
	n1 dq 16		
	n2 dq 10
	
	cnt db 0


section .bss
	result: resq 1
	choice: resb 1

	Print:
	%macro print 2
		mov rax, 01
		mov rdi, 01
		mov rsi, %1	;result
		mov rdx, %2	;8
		syscall
	%endmacro
	
	%macro newline 0
		mov rax, 01
		mov rdi, 01
		mov rsi, newLine
		mov rdx, newLineLen
		syscall
	%endmacro
	
	%macro input 2
		mov rax, 00
		mov rdi, 00
		mov rsi, %1
		mov rdx, %2
		syscall
	%endmacro
	
	
section .text
global _start

_start:

	call ShowNum
	
	call Menu
	
_exit:
	mov rax, 60			;exit system call
	mov rdx, 00
	syscall
	
; ---- SUB-ROUTINES ----

HexToAscii:
	mov byte[cnt], 2           
	mov rdi, result        	 ;pointer at result

	Loop4:
		rol al, 4               ;rotate B by 4 bits to left
		mov bl, al  
		and bl, 0fh             ;mask at lower byte

		cmp bl, 09h
		jbe BELOW_9
		add bl, 07h

	BELOW_9:    
		add bl, 30h
		mov [rdi], bl           ;store hex-ascii value into result

		inc rdi                 ;increment result pointer 
		dec byte[cnt]           ;decrement counter
		jnz Loop4               ;repeat LOOP till cnt becomes zero (16 times)
	ret

Addition:
	mov rax, [n1]		
	mov rbx, [n2]
	add rax, rbx
	
	call HexToAscii
	print msgAdd, msgAddLen
	print result, 2
	newline
	
	ret

Subtraction:
	mov rax, [n1]		
	mov rbx, [n2]
	sub rax, rbx
	
	call HexToAscii
	print msgSub, msgSubLen
	print result, 2
	newline
	
	ret
	
Multiplication:
	mov rax, qword[n1]
	mov rbx, qword[n2]
	
	mul rbx
	push rax
	mov rax, rdx
	
	call HexToAscii
	print msgMul, msgMulLen
	print result, 2
	
	pop rax
	call HexToAscii
	print result, 2
	newline
	
	ret
	
Division:
	xor rdx, rdx
	mov rax, qword[n1]
	mov ebx, dword[n2]
	
	div ebx
	
	push rax
	mov rax, rdx
	call HexToAscii
	print msgDiv, msgDivLen
	print result, 2
	newline
	
	pop rax
	call HexToAscii
	print msgRem, msgRemLen
	print result, 2
	newline
	
	ret
	
ShowNum:
	print msgNum, msgNumLen

	mov rax, qword[n1]
	call HexToAscii
	print result, 2
	newline
	
	mov rax, qword[n2]
	call HexToAscii
	print result, 2
	newline
	
	ret
	
Menu:
	print msgMenu, msgMenuLen
	newline
	
	print msgChoice, msgChoiceLen
	newline
	
	input choice, 1
	
	cmp byte[choice], '1'
	je Add
	
	cmp byte[choice], '2'
	je Sub
	
	cmp byte[choice], '3'
	je Mul
	
	cmp byte[choice], '4'
	je Div
	
	jmp _exit
	
	Add:
		call Addition
		jmp _exit
	
	Sub:
		call Subtraction
		jmp _exit
	
	Mul:
		call Multiplication
		jmp _exit
		
	Div:
		call Division 
		jmp _exit
	
	ret
	