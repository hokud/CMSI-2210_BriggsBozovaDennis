global _main
extern _scanf
extern _printf

section .data
fmt_in    db "%ld %ld", 0        ; input format
fmt_out   db "GCD is %ld", 10, 0 ; output format
num1      dq 0                   ; storage for first input
num2      dq 0                   ; storage for second input

section .text
_main:
  push rbp                       ; save base pointer
  mov rbp, rsp                   ; set new base pointer
  push rbx                       ; save rbx (callee-saved)

  ; read two numbers: scanf("%ld %ld", &num1, &num2)
  lea rdi, [rel fmt_in]          ; format string
  lea rsi, [rel num1]            ; address of num1
  lea rdx, [rel num2]            ; address of num2
  xor eax, eax                   ; varargs: clear eax
  call _scanf                    ; call scanf

  ; load inputs into registers
  mov rax, [rel num1]            ; a = num1
  mov rbx, [rel num2]            ; b = num2

gcd_loop:
  cmp rbx, 0                     ; while (b != 0)
  je gcd_done                    ; if b == 0, done

  xor rdx, rdx                   ; clear high 64 bits for division
  div rbx                        ; divide a / b → remainder in rdx

  mov rax, rbx                   ; a = b
  mov rbx, rdx                   ; b = remainder
  jmp gcd_loop                   ; repeat loop

gcd_done:
  ; print result: printf("GCD is %ld\n", a)
  lea rdi, [rel fmt_out]         ; format string
  mov rsi, rax                   ; result to print
  xor eax, eax                   ; varargs: clear eax
  call _printf                   ; print

  pop rbx                        ; restore rbx
  mov rsp, rbp                   ; restore stack pointer
  pop rbp                        ; restore base pointer
  ret                            ; return

