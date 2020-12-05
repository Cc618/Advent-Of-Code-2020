; See 5.c for prototypes

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
