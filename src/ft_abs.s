 section	.text
   global _ft_abs

_ft_abs:
	test edi, edi
	jns .end
	neg edi
	.end:
		mov rax, rdi
		ret
