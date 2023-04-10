section .data
msg db "Enter 5 numbers to find maximum:" ,0xA
len1 equ $-msg

msg1 db "Maximum number in the array is:" ,0xA
len2 equ $-msg1

cnt db 05h
mov al,00h
mov r8,00h
num dq 10h,02h,03h,04h,05h

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



find_max:
mov byte[cnt],05h
mov r8,num
mov al,00h
l3:
cmp al,byte[r8]
ja l4
mov al,byte[r8]
l4:
inc r8
dec byte[cnt]
jnz l3

hexAscii:
;mov bl,al
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

print msg1,len2
print larg,2

mov rax,60	; exit system call
mov rdi,00
syscall
