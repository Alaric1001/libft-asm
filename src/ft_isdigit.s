section	.text
   global _ft_isdigit

_ft_isdigit:
	xor rax, rax	; set rax to 0

	sub rdi, 0x30	; rdi - '0'
	cmp rdi, 0x9	; if we are in [0, 9] return true
	ja .end

	mov al, 0x1	
	.end:
		ret
