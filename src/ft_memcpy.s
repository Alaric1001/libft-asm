section .text
global _ft_memcpy

_ft_memcpy:
	push rdi		; we want to keep the base ptr to return it
	mov rdi, [rsp]	

	mov rcx, rdx	; length given in parameter
	rep movsb		; copy the content of rsi in rdi until rcx is 0

	pop rdi			; pop rdi and cpy its content in rax
	mov rax, rdi
	ret				; return rax
