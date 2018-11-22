extern _malloc
extern _ft_strlen
extern _ft_memcpy

section .text
global _ft_strdup

_ft_strdup:
	push rbp
	mov rbp, rsp
	sub rsp, 0x10			; two 64bits ptr size on the stack frame

	mov [rbp-0x8], rdi		; save the source ptr

	call _ft_strlen			; strlen of the source ptr
	inc rax					; reserve a byte for the null char
	mov [rbp-0x10], rax		; save the len in the stack frame

	mov rdi, rax			; set the len in the first param register of malloc
	call _malloc
	test rax, rax			; if malloc fail, return null
	je .err

	mov rdi, rax			; first memcpy param: dest ptr
	mov rsi, [rbp-0x8]		; 2nd memcpy param: source ptr
	mov rdx, [rbp-0x10]		; last memccpy param: string len
	call _ft_memcpy

	.end:
		mov rsp, rbp		; destroy the stack frame and ret 
     	pop rbp	
		ret
	.err:
		xor rax, rax		; empty rax and end
		jmp .end
