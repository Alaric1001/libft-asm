
section	.text
   global _ft_isprint

_ft_isprint:
	xor rax, rax	; set rax to 0

	sub rdi, 0x20	; rdi - ' '
	cmp rdi, 0x5f	; if we are in [0, 127-32]
	jae .end

	mov al, 0x1	
	.end:
		ret
