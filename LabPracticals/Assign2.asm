;To display length of the String
section .data

msg db "To display length of the String",0xA
len equ $-msg

msg1 db "Enter a string:" ,0xA
len1 equ $-msg

msg2 db "Length of string:" ,0xA
len2 equ $-msg2

cnt db 05h

section .bss
str : resb 16h
length resb 16h

section .text

global _start

_start :

; Display "To display length of the String"
mov rax,01
mov rdi,01
mov rsi,msg
mov rdx,len
syscall

; Display "Enter a string:"
mov rax,01
mov rdi,01
mov rsi,msg1
mov rdx,len1
syscall

; Read string
mov rax,00
mov rdi,00
mov rsi,str
mov rdx,16
syscall


; Display "To display length of the String"
mov rax,01
mov rdi,01
mov rsi,msg2
mov rdx,len2
syscall


; Convert hex to ascii and store in length buffer

; rax contains the length of the input string in hexadecimal
; cnt is used as a counter to keep track of the number of nibbles processed

dec rax             ; decrement rax to start processing the last nibble first
mov r8, length      ; r8 points to the beginning of the length buffer
mov byte[cnt],16    ; initialize the counter to 16 (the length of the buffer)

up:
rol rax,04          ; rotate rax left by 4 bits to get the next nibble
mov bl,al           ; move the rotated value to bl
AND bl,0Fh          ; keep only the last nibble of the value

cmp bl,09h          ; compare bl with 09h (the ASCII value for '9')
jbe l1              ; if bl is less than or equal to '9', jump to label l1
add bl,7h           ; add 7 to bl to convert the hex digit to the appropriate letter from A to F

l1:
add bl,30h          ; add 30h to bl to convert the hex digit to its corresponding ASCII value
mov byte[r8], bl   ; move the ASCII value to the current position in the length buffer
inc r8              ; move to the next position in the length buffer
dec byte [cnt]     ; decrement the counter
jnz up              ; if there are more nibbles to process, jump to label up

; Display length of string
mov rax,01
mov rdi,01
mov rsi,length
mov rdx,16
syscall

; Exit program
mov rax,60
mov rdi,00
syscall