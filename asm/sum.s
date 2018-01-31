	.file	"sum.c"
	.section	.rodata
.LC0:
	.string	"sum = %ld\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	$0, -16(%rbp)
	movq	$0, -8(%rbp)
	jmp	.L2
.L3:
	movq	-8(%rbp), %rax
	addq	%rax, -16(%rbp)
	addq	$1, -8(%rbp)
.L2:
	cmpq	$999999, -8(%rbp)
	jle	.L3
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Gentoo 4.8.3 p1.1, pie-0.5.9) 4.8.3"
	.section	.note.GNU-stack,"",@progbits
