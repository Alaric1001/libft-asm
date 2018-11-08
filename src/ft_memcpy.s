section .text
global _ft_memcpy

_ft_memcpy:
	mov rax, rdi	; we will return the base ptr

	mov rcx, rdx	; length given in parameter
	rep movsb		; copy the content of rsi in rdi until rcx is 0

	ret				; return rax
