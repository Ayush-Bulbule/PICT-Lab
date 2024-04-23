section .data  
    msg1 db 10, "Enter the string : ",10
    msg1len equ $ - msg1
    
    msgop db 10, 10,"Length of the string is : " , 10
    msgoplen equ $ - msgop

section .bss
    string resb 50                      
    strl equ $-string 
    
    result resb 50
    
section .text
    global _start

_start:
    mov rax, 1
    mov rdi, 1
    mov rsi, msg1
    mov rdx,msg1len
    syscall
    
    
    mov rax, 0
    mov rdi, 0
    mov rsi, string
    mov rdx, 200
    syscall
    
    dec rax
    mov rbx,rax 
    mov rdi, result
    mov cx,16 
up1:
    rol rbx,04 
    mov al,bl 
    and al,0fh
    cmp al,09h 
    jg add_37 
    add al,30h
    jmp skip 

add_37 : add al,37h
skip:mov [rdi],al 
    inc rdi
    dec cx 
    jnz up1 
    
    mov rax, 1
    mov rdi, 1
    mov rsi, msgop
    mov rdx, msgopl en
    syscall
        
    mov rax,60
    mov rdi,0
    syscall
