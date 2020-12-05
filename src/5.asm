; See 5.c for prototypes

extern fgets
extern feof
extern puts
extern printf

section .text

; rdi : val
; rsi : len
; rdx : high
; cl : upper
; rbx : low
; r12 : i
; r13 : mid
; r10b : val[i] (scratch)
global getPos
getPos:
    push rbp
    mov rbp, rsp

    push rbx
    push r12
    push r13

    ; low = i = 0
    xor rbx, rbx
    mov r12, rbx
.loop:
    ; Loop with i from 0 up to len
    cmp r12, rsi
    jge .done

    ; Compute mid
    mov r13, rbx
    add r13, rdx
    shr r13, 1

    ; Test char upper / lower
    mov rax, rdi
    add rax, r12
    mov r10b, [rax]
    cmp r10b, cl
    jne .lower

.upper:
    ; This is the upper character
    ; low = mid + 1
    mov rbx, r13
    inc rbx

    jmp .iter
.lower:
    mov rdx, r13

.iter:
    inc r12
    jmp .loop
.done:
    ; Return low
    mov rax, rbx

    pop r13
    pop r12
    pop rbx

    leave
    ret


; rdi : val
global getId
getId:
    push rbp
    mov rbp, rsp

    push rdi

    ; Compute row
    mov rsi, 7
    mov rdx, 127
    mov cl, 'B'
    call getPos

    pop rdi

    ; Save result
    push rax

    ; Compute col
    add rdi, 7
    mov rsi, 3
    mov rdx, 7
    mov cl, 'R'
    call getPos

    ; Return row * 8 + col == row << 3 + col
    ; rdx = row
    pop rdx
    shl rdx, 3
    add rax, rdx

    leave
    ret


; stdin : rdi, r14
; mx : r12
; buf : r13 = rbp - 16
global part1
part1:
    push rbp
    mov rbp, rsp
    sub rsp, 16

    mov rax, rbp
    sub rax, 16

    push r12
    push r13
    push r14

    mov r13, rax
    mov r14, rdi

    xor r12, r12
.loop:
    ; Get line within buffer
    mov rdi, r13
    mov rsi, 16
    mov rdx, r14
    call fgets

    ; Check eof
    mov rdi, r14
    call feof

    cmp rax, 0
    jne .done

    ; Get id
    mov rdi, r13
    call getId

    ; Update max
    cmp rax, r12
    jle .loop

    mov r12, rax
    jmp .loop

.done:
    ; Return max
    mov rax, r12

    pop r14
    pop r13
    pop r12

    leave
    ret
