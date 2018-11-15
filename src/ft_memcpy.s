section .text
global _ft_memcpy

_ft_memcpy:
;	mov rax, rdi	; we will return the base ptr
	mov r8, rdi

	mov rax, rdx	;
	xor rdx, rdx	;
	mov rbx, 0x4	;
	div rbx			; div rax with rbx, quotient ->rax, remainder -> rdx

	cld				; clear  right direction flag

	; first we cpy the trailing bytes 1 by 1
	mov rcx, rdx	; remainder of the div will be the length of the bytes to cpy
	rep movsb		; copy the content of rsi in rdi until rcx is 0

	; then we cpy dwords by dwords
	mov rcx, rax	; quotient of the div will be the length of the dwords to cpy
	rep movsd		; copy the content of rsi in rdi until rcx is 0

	mov rax, r8
	ret				; return rax
