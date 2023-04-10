section .data

n1 db 4h
n2 db 2h
mov al,00h
cnt db 05h

%macro print 2
mov rax,01
mov rdi,01
mov rsi,%1
mov rdx,%2
syscall
%endmacro

section .bss
larg resb 16

section .text
global _start
_start:

mov al,byte[n1]
sub al,byte[n2]

hexAscii:
mov rbp,larg
mov byte[cnt],02h
up:
rol al,04
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

print larg,2
mov rax,60	; exit system call
mov rdi,00
syscall
