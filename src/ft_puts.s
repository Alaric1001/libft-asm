extern _ft_strlen

section	.text
	global _ft_puts

_ft_puts:
	push rbp
	mov rbp, rsp
	sub rsp, 0x8			; creating the stack frame
	
	cmp rdi, 0x0			; if the string is null we jump to the display_null routine
	je .display_null

	mov [rbp-0x8], rdi		; save the base ptr in the stack

	call _ft_strlen			;  we get the string len in rax
	
	mov rdx, rax			; rdx contains the len of the string
	mov rsi, [rbp-0x8]		; rsi contains a ptr to the string
	call write_s			; do the syscall
	test rax, rax			; check if write didnt fail
	jl .error

	lea rsi, [rel line_break]	; just pick the \n of null_msg...
	mov rdx, 0x1			
	call write_s			; ...and write it
	test rax, rax
	jl .error

	.success:
		mov rax, 0xa		; puts return 10 on success
		jmp .end
	.error:
		mov rax, -1
	.end:
		mov rsp, rbp		; destroy the stack frame and ret 
     	pop rbp	
		ret					; return rax

	.display_null: 			; This part juste write "(null)\n" and return
		mov rdx, 0x7
		lea rsi, [rel null_msg]
		call write_s
		test rax, rax
		jl .error
		jmp .success
data:
	null_msg: db "(null)", 0ah
	line_break: db 0ah

write_s:
	mov rax, 0x2000004
	mov rdi, 0x1
	syscall
	ret
