section .data
    menuMsg: db "1. HEX to BCD", 0x0A
             db "2. BCD to HEX", 0x0A
             db "3. Exit", 0x0A
    menuLen equ $ - menuMsg

    choicePrompt: db "Enter your Choice: "
    choicePromptLen equ $ - choicePrompt

    hexPrompt: db "Enter HEX number: "
    hexPromptLen equ $ - hexPrompt

    bcdPrompt: db "Enter BCD number: "
    bcdPromptLen equ $ - bcdPrompt

    bcdResultMsg: db "Equivalent BCD number is: "
    bcdResultLen equ $ - bcdResultMsg

    hexResultMsg: db "Equivalent HEX number is: "
    hexResultLen equ $ - hexResultMsg

    newLine: db " ", 0x0A
    newLineLen equ $ - newLine

section .bss
    number: resb 6
    result: resb 4
    answer: resb 4
    digitCount: resb 01
    userChoice: resb 02

section .text
global _start
_start:

menu:
    ; Display menu options
    mov rax, 1
    mov rdi, 1
    mov rsi, newLine ; Newline
    mov rdx, newLineLen
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, newLine ; Newline
    mov rdx, newLineLen
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, menuMsg
    mov rdx, menuLen
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, choicePrompt
    mov rdx, choicePromptLen
    syscall

    mov rax, 0
    mov rdi, 0
    mov rsi, userChoice
    mov rdx, 02
    syscall

    cmp byte[userChoice], 31H
    je case1

    cmp byte[userChoice], 32H
    je case2

    cmp byte[userChoice], 33H
    je case3

case2:
    ; BCD to HEX conversion
    mov rax, 1
    mov rdi, 1
    mov rsi, bcdPrompt
    mov rdx, bcdPromptLen
    syscall

    mov rax, 0
    mov rdi, 0
    mov rsi, number
    mov rdx, 6
    syscall

    xor rax, rax
    mov rbx, 10
    mov rcx, 5

bcdToHexLoop:
    xor rdx, rdx        ; Clear rdx register (used for intermediate calculations)
    mul ebx             ; Multiply rax by ebx (eax = eax * ebx), result stored in rdx:eax

    xor rdx, rdx        ; Clear rdx register again
    mov dl, [rsi]       ; Load the byte at the memory address pointed to by rsi into dl
    sub dl, 30H         ; Subtract 30H (48 in decimal) from dl to convert ASCII digit to numeric value

    add rax, rdx       ; Add the numeric value in dl to rax (accumulator)

    inc rsi             ; Increment rsi to point to the next byte in the input string
    dec rcx             ; Decrement rcx (loop counter) to keep track of remaining iterations
    jnz bcdToHexLoop    ; Jump to bcdToHexLoop if rcx is not zero (loop until rcx becomes zero)

    mov [result], ax    ; Store the final result in the variable 'result' (assuming it's a memory location)

    ; Output the result as a hexadecimal number
    mov rax, 1          ; System call number 1 (write)
    mov rdi, 1          ; File descriptor 1 (stdout)
    mov rsi, hexResultMsg ; Address of the message to be printed
    mov rdx, hexResultLen ; Length of the message
    syscall             ; Perform the system call to print the message

    mov ax, [result]    ; Load the result back into ax (assuming it's a 16-bit value)
    call displayNumber  ; Call a subroutine to display the number

    jmp menu            ; Jump to the 'menu' label (assuming it exists)


case1:
    ; HEX to BCD conversion
    mov rax,


;Test Case 1:
;BCD - 4391
;HEX - ABCD