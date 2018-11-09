section	.text
   global _ft_strcat

_ft_strcat:
	mov rax, rdi				; move the string begin in the ret reg.

	.l1:						;
		cmp byte[rdi], 0x0		;
		je .endl1				; increment rdi until we find a null char
		inc rdi					;
		jmp .l1					;
	.endl1:

	.l2:						;
		cmp byte [rsi], 0x0		;
		je .endl2				;
		mov dl, byte[rsi]		;
		mov byte[rdi], dl		; cpy the content of rsi at the end of rdi
		inc rdi					;
		inc rsi					;
		jmp .l2					;
	.endl2:
	mov byte[rdi], 0x0			; add the last null char at the end of rdi

	.end:
	ret							; return rax
