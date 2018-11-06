section	.text
   global _ft_toupper

_ft_toupper:
	mov rax, rdi

	sub rdi, 0x61	; rdi - 'A'
	cmp rdi, 26		; if we are not in the alphabet return
	jae .end

	sub rax, 0x20	; to upper
	.end:
		ret
