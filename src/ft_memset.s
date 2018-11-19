section .text
global _ft_memset

_ft_memset:
	mov r8, rdi			; saving rdi in the r8 register

	mov al, sil			; put the char to copy in al
	mov rsi, rdi		; source string (dest string is rdi)
	mov rcx, rdx		; length of the string
	rep stosb			; copy the content of al in rdi until rcx is 0

	mov rax, r8			; we will return the base pt
	ret				; return rax
