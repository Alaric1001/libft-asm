section	.text
   global _ft_isalpha

_ft_isalpha:
	xor rax, rax	; set rax to 0

	sub rdi, 0x41	; rdi - 'A'
	cmp rdi, 26		; if we are in the alphabet return true
	jb .true
	sub rdi, 0x20	; sub whats remain in rdi until 'a'
	cmp rdi, 26  	; if we aren't in the alphabet end
	jae .end

	.true:
		mov al, 0x1	
	.end:
		ret
