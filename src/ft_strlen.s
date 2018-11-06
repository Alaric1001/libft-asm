 section	.text
   global _ft_strlen

_ft_strlen:
	push rdi			; rdi should not move, thus we save it
	mov	rdi, [rsp]		; cpy the value that we just pushed in the stack into rdi

	xor rcx, rcx		;
	not rcx				; reverse rcx so its as a uint64_t max value

	xor al, al			; scasb will compare the current char to the al value

	cld					; clear direction flag (so the incrementation goes to the right)
	repne scasb			; decrement rcx until the value of al is found in rdi

	not rcx				; reverse rcx to have the string length
	dec rcx				; rcx count contain the \0 length so we decrement it once 

	pop rdi				; restore rdi to its initial value

	mov	rax, rcx		;
	ret					; return rax
