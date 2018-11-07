section .text
global _ft_memset

_ft_memset:
	push rdi		; we want to keep the base ptr to return it
	mov rdi, [rsp]	

	mov al, sil		; put the char to copy in al
	mov rsi, rdi	; source string (dest string is rdi)
	mov rcx, rdx	; length of the string
	rep stosb		; copy the content of al in rdi until rcx is 0

	pop rdi			; pop rdi and cpy its content in rax
	mov rax, rdi
	ret				; return rax
