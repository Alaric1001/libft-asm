extern _malloc
extern _free
extern _ft_memcpy

%define BUFF_SIZE 0x400

section .text
global _ft_cat

_ft_cat:
	push rbp
	mov rbp, rsp
	sub rsp, 0x20			; stack frame has to be aligned with 0x10 for malloc

	test edi, edi
	js .end

	mov [rbp-0x8], rdi		; save the fd in the stack
	mov rdi, BUFF_SIZE		; we will malloc the buffer here
	call _malloc
	test rax, rax			; if malloc fail, return
	je .end
	mov [rbp-0x10], rax		; save the buffer ptr in the stack

	.read_loop:
	mov rax, 0x2000003		;
	mov rdi, [rbp-0x8]		;
	mov rsi, [rbp-0x10]		;
	mov rdx, BUFF_SIZE		;
	syscall					; read(fd, buff, buff_s);

	mov [rbp-0x18], rax		; saving the return of read

	mov rsi, [rbp-0x10]		;
	mov rdx, rax			;
	call write_s			; write(1, buff, read_ret)
	test rax, rax
	jl .free

	cmp qword [rbp-0x18], 0x0
	jg .read_loop			; if read_ret > 0

	.free:
		mov rdi, [rbp-0x10]	;
		call _free			; free buffk

	.end:
		xor rax, rax
		mov rsp, rbp		; destroy the stack frame and ret
		pop rbp
		ret

write_s:
	mov rax, 0x2000004
	mov rdi, 0x1
	syscall
	ret
