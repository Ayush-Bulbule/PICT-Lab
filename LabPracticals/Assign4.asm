section .data

n1 dq 6h
n2 dq 4h
mov al,00h
cnt db 05h
menu db "Choose one of the following operations:",0xA
     db "1 for Addition",0xA
     db "2 for Subtraction",0xA
     db "3 for Multiplication",0xA
     db "4 for Division",0xA
len equ $ - menu
msg1 db "Addition is:",0xA
len1 equ $ - msg1
msg2 db "Subtraction is:",0xA
len2 equ $ - msg2
msg3 db "Multiplication is:",0xA
len3 equ $ - msg3
msg4 db "Remainder is:",0xA
len4 equ $ - msg4
msg5 db "Quotient is:",0xA
len5 equ $ - msg5
msg6 db "",0xA
len6 equ $ - msg6

%macro print 2
mov rax,01
mov rdi,01
mov rsi,%1
mov rdx,%2
syscall
%endmacro

section .bss
result resb 16
option resb 2

section .text
global _start
_start:

ShowMenu:
print menu,len

mov rax,00
mov rdi,00
mov rsi,option
mov rdx,2
syscall

cmp byte[option],'1'
je addition

cmp byte[option],'2'
je subtraction

cmp byte[option],'3'
je multiplication

cmp byte[option],'4'
je division

addition:
mov rax,qword[n1]
mov rbx,qword[n2]
add rax,rbx
call hexAscii
print msg1,len1
print result,16
print msg6,len6
jmp exit

subtraction:
mov rax,qword[n1]
mov rbx,qword[n2]
sub rax,rbx
call hexAscii
print msg2,len2
print result,16
print msg6,len6
jmp exit

multiplication:
mov rax,qword[n1]
mov rbx,qword[n2]
mul rbx
push rax
mov rax,rdx
call hexAscii
print msg3,len3
print result,16
pop rax
call hexAscii
print result,16
print msg6,len6
jmp exit

division:
xor rdx,rdx
mov rax,qword[n1]
mov ebx,dword[n2]
div ebx
push rax
mov rax,rdx
call hexAscii
print msg4,len4
print result,16
print msg6,len6
pop rax
call hexAscii
print msg5,len5
print result,16
print msg6,len6
jmp exit

exit:
mov rax,60	; exit system call
mov rdi,00
syscall


hexAscii:
mov rbp,result
mov byte[cnt],16h
up:
rol rax,04
mov dl,al
and dl,0Fh
cmp dl,09h
jbe down
add dl,07h
down:
add dl,30h
mov byte[rbp],dl
inc rbp
dec byte[cnt]
jnz up
ret



