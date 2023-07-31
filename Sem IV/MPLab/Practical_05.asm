section .data
    msg1 db "Count of Positive numbers:"
    len1 equ $-msg1

    msg2 db "Count of Negative numbers:"
    len2 equ $-msg2

    array db 10, 12, -21, -12, -19, -34, 41

    nLine db "", 0xA
    lenNLine equ $-nLine

%macro print 2
    mov rax, 01
    mov rdi, 01
    mov rsi, %1
    mov rdx, %2
    syscall
%endmacro

%macro newLine 0
    mov rax, 01
    mov rdi, 01
    mov rsi, nLine
    mov rdx, lenNLine
    syscall
%endmacro

section .bss
    count resb 2
    positiveCount resb 2
    negativeCount resb 2
    totalCount resb 2

section .text
global _start
_start:
    ; Initialize counters and array pointer
    mov byte[count], 07
    mov byte[positiveCount], 00
    mov byte[negativeCount], 00
    mov rsi, array

Up:
    ; Process each element of the array
    mov al, 00
    add al, [rsi]
    js negative
    inc byte[positiveCount]
    jmp Down
negative:
    inc byte[negativeCount]

Down:
    ; Move to the next element and decrement the counter
    add rsi, 01
    dec byte[count]
    jnz Up

    ; Print the results
    mov bl, [positiveCount]
    mov dl, [negativeCount]

b1:
    ; Display count of positive numbers
    print msg1, len1
    mov bh, [positiveCount]
    call displayCount

    newLine

    ; Display count of negative numbers
    print msg2, len2
    mov bh, [negativeCount]
    call displayCount
    newLine

    jmp Exit

displayCount:
    ; Convert the count to ASCII and print it
    mov byte[count], 02
loop:
    rol bh, 04
    mov al, bh
    AND al, 0FH
    cmp al, 09
    jbe l1
    add al, 07h
l1:
    add al, 30h
    mov [totalCount], al
    print totalCount, 02
    dec byte[count]
    jnz loop
    ret

Exit:
    ; Exit the program
    mov rax, 60
    mov rdi, 00
    syscall
