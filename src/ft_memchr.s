section	.text
   global _ft_memchr

_ft_memchr:
	test rdx, rdx
	jz .null			; if n == 0 do nothing

	mov rcx, rdx		;
	mov al, sil			; setup registers for scasb

	cld
	repne scasb			; seek al in rdi for rcx bytes
	jne .null			; if the char isnt found return null

	mov rax, rdi		; return rdi
	dec rax				; scasb increment even if the char is found
	ret
	.null:
		xor rax, rax
		ret
