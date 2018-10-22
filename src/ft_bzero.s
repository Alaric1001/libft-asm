section	.text
   global _ft_bzero

_ft_bzero:
	;push rbp					; Save ebp on the stack
	;mov rbp, rsp				; Replace ebp with esp
	;sub rsp, 0x4				; sub the size of the local var
	.loop:
		dec rsi					; --rsi
		cmp rsi, 0x0
		jl .done;				; exit loop if rsi <= 0
		mov byte [rdi+rsi], 0x0	; set 0 in the current byte of edx
		jmp .loop				; loop

	.done:
		;mov rsp, rbp
		;pop rbp				; restore ebp
		ret						; return, eax is empty
