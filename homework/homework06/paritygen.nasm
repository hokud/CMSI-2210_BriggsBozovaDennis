
global _main
extern _printf

section .data
    data_byte   db  01101001b      ; test byte; change as needed
    fmt         db  "%d", 10, 0    ; "%d\n"

section .text

_main:
    push rbp
    mov  rbp, rsp

    ; Load the byte (zero-extended) into EAX
    movzx eax, byte [rel data_byte]
    mov   bl, al           ; work with BL so we can shift
    xor   edx, edx         ; EDX = count of 1 bits = 0
    mov   ecx, 8           ; 8 bits in the byte

count_loop:
    test  bl, 1
    jz    .skip_inc
    inc   edx              ; found a 1-bit
.skip_inc:
    shr   bl, 1
    loop  count_loop

    ; EDX holds the number of 1 bits
    and   edx, 1           ; EDX = 0 if even, 1 if odd
    xor   edx, 1           ; odd parity bit: even->1, odd->0

    ; Call printf("%d\n", parity_bit)
    lea   rdi, [rel fmt]   ; first arg: pointer to format string
    mov   esi, edx         ; second arg: parity bit (int)
    xor   eax, eax         ; required before calling variadic funcs
    call  _printf

    mov   eax, 0
    pop   rbp
    ret
