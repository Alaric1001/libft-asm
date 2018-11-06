
section	.text
   global _ft_isascii

_ft_isascii:
	xor rax, rax	; set rax to 0

	cmp rdi, 0x7f		; the char isn't ascii return
	ja .end

	mov al, 0x1	
	.end:
		ret
