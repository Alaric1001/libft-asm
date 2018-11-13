
section	.text
   global _ft_strcmp

_ft_strcmp:
	xor rax, rax		;
	xor rdx, rdx		; empty two utils registers
	.loop:
		lodsb			; pop the first character of rsi and put it in al
		or al, al		;
		jz .ret			; is al 0 ? if yes, end of string, return
		cmp al, [rdi]	;
		jne .ret		; if al != [rdi], break
		inc rdi			; ++rdi
		jmp .loop
	.ret:
		mov dl, al		; 
		mov al, [rdi]	;
		sub eax, edx	; perform substitution in the good order
		ret
