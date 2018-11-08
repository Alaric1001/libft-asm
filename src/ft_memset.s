section .text
global _ft_memset

_ft_memset:
	push rbp
	mov rbp, rsp
	sub rsp, 0x8		; creating a 8bytes stack frame

	mov [rbp-0x8], rdi	; saving rdi in the stack to return it

	mov al, sil			; put the char to copy in al
	mov rsi, rdi		; source string (dest string is rdi)
	mov rcx, rdx		; length of the string
	rep stosb			; copy the content of al in rdi until rcx is 0

	mov rax, [rbp-0x8]	; we will return the base pt
	mov rsp, rbp		; destroy the stack frame and ret 
    pop rbp	
	ret				; return rax
