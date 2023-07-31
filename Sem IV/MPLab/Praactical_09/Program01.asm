section .data
    fname:      db 'abc.txt',0

    msg:        db "File opened successfully",0x0A
    len:        equ $-msg

    msg1:       db "File closed successfully",0x0A
    len1:       equ $-msg1

    msg2:       db "Error in opening file",0x0A
    len2:       equ $-msg2

    msg3:       db "Spaces:",0x0A
    len3:       equ $-msg3

    msg4:       db "NewLines:",0x0A
    len4:       equ $-msg4

    msg5:       db "Enter character",0x0A
    len5:       equ $-msg5

    msg6:       db "No of occurrences:",0x0A
    len6:       equ $-msg6

    new:        db "",0x0A
    new_len:    equ $-new

    scount:     db 0
    ncount:     db 0
    ccount:     db 0
    chacount:   db 0

section .bss
    fd:         resb 17
    buffer:     resb 200
    buf_len:    resb 17
    cnt:        resb 2
    cnt2:       resb 2
    cnt3:       resb 2
    cha:        resb 2

%macro scall 4
    mov rax, %1
    mov rdi, %2
    mov rsi, %3
    mov rdx, %4
    syscall
%endmacro

section .text
global _start

extern spaces
extern enters
extern occ

_start:
    ; Open the file
    mov rax, 2
    mov rdi, fname
    mov rsi, 2
    mov rdx, 0777
    syscall

    ; Check if file opened successfully
    test rax, rax
    js file_open_error

    ; File opened successfully
    scall 1, 1, msg, len

    ; Perform file operations
    jmp file_close

file_open_error:
    ; Error in opening file
    scall 1, 1, msg2, len2
    jmp exit

file_close:
    ; Close the file
    mov rax, 3
    mov rdi, [fd]
    syscall

    ; File closed successfully
    scall 1, 1, msg1, len1

    ; Perform operations on the file contents
    scall 1, 1, msg3, len3
    call spaces

    scall 1, 1, msg4, len4
    call enters

    scall 1, 1, msg5, len5
    scall 0, 1, cha, 2
    mov bl, byte[cha]
    call occ

exit:
    ; Exit the program
    mov rax, 60
    xor rdi, rdi
    syscall
