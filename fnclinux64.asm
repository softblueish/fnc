global _start

section .text

_start:

	pop rcx   ; argc
	cmp rcx,1
	je no_arg

	pop rax ; we don't care about the first argument

	dec rcx   ; we are parsing argc-1 arguments

	.argument_parse_loop:
				
		mov r12,rcx
		
		pop rdi   ; filename for the system call

		mov rax,2 ; open
		xor rsi,rsi ; readonly
		mov rdx,rdx ; mode
		
		syscall

		; rax now contains the file descriptor for the file.

		mov [filedescriptor],rax
		cmp rax,0
		jl .next

		.print_content:
			

			mov rdi,[filedescriptor]
			xor rax,rax 		; read()
			mov rsi,filereadbuffer
			mov rdx,1024

			syscall

			test rax,rax ; if end of file reached, go to the next file

			jz .print_done

			; rax contains the number of bytes read, so use that
			
			mov rdx,rax

			mov rax,1               ; write
			mov rdi,rax		; stdout
			mov rsi,filereadbuffer

			syscall
			jmp .print_content

	.print_done:

	.next:
	
	mov rcx,r12

	loop .argument_parse_loop
	
		
	mov rax,60   ; exit
	xor rdi,rdi  ; success

	syscall

no_arg:

	mov rax,1        ; write
	mov rdi,rax      ; stdout
	mov rsi,usage1
	mov rdx,usage1len

	syscall
	
	mov rax,1   ; write
	mov rdi,rax ; stdout
	mov rsi,usage2
	mov rdx,usage2len

	syscall

	mov rax,60 ; exit
	mov rdi,-1   ; no arg error code

	syscall
	
	jmp $
	
section .rodata

usage1: db "Arguments must be supplied!", 0xA
usage1len equ $-usage1
usage2: db 'Usage: " << argv[0] << " <file1> <file2> <file3...', 0xA
usage2len equ $-usage2

section .bss
	
	filedescriptor:
	resq 1
	filereadbuffer:
	resb 1024
