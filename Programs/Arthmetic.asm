;Arithmetic Operations in Assembly

section .data
    msgNum db "hello ", 0xA
    msgLen equ $-msgNum


    nline db 0xA
    lenNline equ $-nline

    msgAdd db "Addition = "
    lenMsgAdd equ $-msgAdd

    msgSub db "Suibtraction = "
    lenMsgSub equ $-msgSub

    msgMult db "Multiplication = "
    lenMsgMult equ $-msgMult

    msgDiv db "Division = "
    lenMsgAdd equ $-msgDiv

    ;
    msgMain db "1. Addition",0xA,"2. Subtraction",0xA,"3. Multiplication",0xA,"4. Division",0xA
    lenMsgMain equ $-msgMain


    msgChoice db "Enter Your Choice = "
    lenMsgChoice equ $-msgChoice


    n1 dq 16
    n2 dq 10

    cnt db 0

section .bss
    result: resq 1
    choice: resb 1

;to print data
Print:
%macro print 2
    mov rax, 01
    mov rdi, 01
    mov rsi, %1
    mov rdx, %2
    syscall
%endmacro

;macro for new line
%macro newLine 0
    mov rax, 01
    mov rdi, 01
    mov rsi, nline
    mov rdx, lenNline
    syscall
%endmacro

;macro to take input
%macro read 2
    mov rax, 00
    mov rdi, 00
    mov rsi, %1
    mov rdi, %2
    syscall
%endmacro


section .text
global _start
_start: 

Main:
	print msgMain, lenMsgMain
	newLine
	
	print msgChoice, msgChoiceLen
	newLine
	
	read choice, 1
	
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
		jmp EXIT
	
	Sub:
		call Subtraction
		jmp EXIT
	
	Mul:
		call Multiplication
		jmp EXIT
		
	Div:
		call Division 
		jmp EXIT
	
	ret

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
	newLine
	
	ret

Subtraction:
	mov rax, [n1]		
	mov rbx, [n2]
	sub rax, rbx
	
	call HexToAscii
	print msgSub, msgSubLen
	print result, 2
	newLine
	
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
	newLine
	
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
	newLine
	
	pop rax
	call HexToAscii
	print msgRem, msgRemLen
	print result, 2
	newLine
	
	ret
	
ShowNum:
	print msgNum, msgNumLen

	mov rax, qword[n1]
	call HexToAscii
	print result, 2
	newLine
	
	mov rax, qword[n2]
	call HexToAscii
	print result, 2
	newLine
	
	ret

EXIT:
    mov rax, 60
    mov rdx, 01
    syscall