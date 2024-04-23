;To display greatest number from given array element

section .data
msg db "Enter 5 numbers to find maximum:" ,0xA
len1 equ $-msg

msg1 db "Maximum number in the array is:" ,0xA
len2 equ $-msg1

; Counter for looping
cnt db 05h

; Initialize 'al' and 'r8' registers to 0
mov al,00h
mov r8,00h

; Array containing 5 numbers
num dq 10h,02h,03h,04h,05h

; Display message
%macro print 2
    mov rax,01
    mov rdi,01
    mov rsi,%1
    mov rdx,%2
    syscall
%endmacro

section .bss
; Buffer to store the maximum number in the array
larg resb 16

section .text
global _start
_start:

; Loop through the array to find the maximum number
find_max:
mov byte[cnt],05h
mov r8,num ;point to the array
mov al,00h ;al = 0
loop_start: 
cmp al,byte[r8] 
ja loop_end ;al>byte[r8] then jump
mov al,byte[r8] ; al = byte[r8]
loop_end: 
inc r8          ; [r8]++
dec byte[cnt] ;cnt --
jnz loop_start ; if cnt != 0 

; Convert the maximum number to ASCII and store it in 'larg' buffer 
; al contains largest number

hex_to_ascii:
mov rbp,larg ;point to variable larg
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

; Display the maximum number in the array
print msg1,len2
print larg,2

; Exit program
mov rax,60
mov rdi,00
syscall
