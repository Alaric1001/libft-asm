section .text
global _ft_memmove

_ft_memmove:
	mov rax, rdi			; we will return the base ptr

	mov rcx, rdx			; length given in parameter

	lea rsi, [rsi+rdx-1]	;
	lea rdi, [rdi+rdx-1]	; point to the end of the string

	std						; movsb will decrement rdi and rsi
	rep movsb				; copy the content of rsi in rdi until rcx is 0

	ret
