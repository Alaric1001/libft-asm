
section	.text
   global _ft_isspace

_ft_isspace:
	xor rax, rax	; set rax to 0

	sub rdi, 0x9	; rdi - '0'
	cmp rdi, 4		; if its a blank char return true
	jbe .true
	cmp rdi, 0x17	; space comp
	jne .end

	.true:
		mov al, 0x1	
	.end:
	ret
