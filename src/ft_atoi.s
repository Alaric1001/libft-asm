 extern _ft_isspace
 section	.text
   global _ft_atoi

_ft_atoi:
	push rbp
	mov rbp, rsp
	sub rsp, 0x9
	
	mov qword [rbp-0x8], 0x0	; ret var
	mov byte [rbp-0x9], 0x0		; this byte is on 1 whenever the read number is negative
	
	mov rsi, rdi				; saving rdi
	.l1:						;
		xor rdi, rdi			;
		mov dil, [rsi]			;
		call _ft_isspace		;	loop througth all spaces
		cmp al, 0x0				;
		je .l1out				;
		inc rsi					;
		jmp .l1					;
	.l1out:
		mov rdi, rsi			;
		xor rsi, rsi			;
		cmp byte [rdi], '-'		;
		je .neg					; check the sign of the number if it exists
		cmp byte [rdi], '+'		;
		jne .atoi				;
	.inc:
		inc rdi
	.atoi:
		mov sil, [rdi]
		sub sil, 0x30
		cmp sil, 0x9			; if the current char isnt a number return
		ja .end
		mov rax, [rbp-0x8]
		mov rdx, 0xa
		mul rdx 				; rax * 10
		add rax, rsi 			; rax + rsi
		mov [rbp-0x8], rax
		jmp .inc
	.end:
		cmp byte [rbp-0x9], 0x0	;
		je .skip_neg			; negate the number if needed
		neg qword [rbp-0x8]		;
		.skip_neg:
		mov rax, [rbp-0x8]
		mov rsp, rbp
		pop rbp
		ret
	.neg:
		mov byte [rbp-0x9], 0x1	; set the neg byte at 1
		jmp .inc
