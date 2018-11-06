section	.text
   global _ft_tolower

_ft_tolower:
	mov rax, rdi

	sub rdi, 0x41	; rdi - 'a'
	cmp rdi, 26		; if we are not in the alphabet return
	jae .end

	add rax, 0x20	; to upper
	.end:
		ret
