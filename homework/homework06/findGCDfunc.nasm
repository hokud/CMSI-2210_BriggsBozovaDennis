global _findGCDfunc              ; make function visible to C

section .text
_findGCDfunc:
  push rbp                       ; save base pointer
  mov rbp, rsp                   ; establish new base pointer
  push rbx                       ; save rbx (callee-saved)

  mov rax, rdi                   ; a = first argument
  mov rbx, rsi                   ; b = second argument

gcd_loop:
  cmp rbx, 0                     ; while (b != 0)
  je gcd_done                    ; if b == 0, done

  xor rdx, rdx                   ; clear high bits of dividend
  div rbx                        ; (rdx:rax) / b, remainder in rdx

  mov rax, rbx                   ; a = b
  mov rbx, rdx                   ; b = remainder
  jmp gcd_loop                   ; repeat

gcd_done:
  pop rbx                        ; restore rbx
  mov rsp, rbp                   ; restore stack pointer
  pop rbp                        ; restore base pointer
  ret                            ; return a in rax (GCD)

