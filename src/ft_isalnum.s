section	.text
   global _ft_isalnum

_ft_isalnum:
	xor rax, rax	; set rax to 0

	sub rdi, 0x30	; rdi - '0'
	cmp rdi, 9		; if we are in [0, 9] return true
	jbe .true
	sub rdi, 0x11	; sub whats remain in rdi until 'A'
	cmp rdi, 26		; if we are in the alphabet return true
	jb .true
	sub rdi, 0x20	; sub whats remain in rdi until 'a'
	cmp rdi, 26  	; if we aren't in the alphabet end
	jae .end

	.true:
		mov al, 0x1	
	.end:
		ret
