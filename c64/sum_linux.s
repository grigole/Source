	.file	"sum.c"
	.section	.rodata
.LC0:
	.string	"Start..."
.LC1:
	.string	"Done"
.LC2:
	.string	"sum = %d\n"
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
	movq	$0, -8(%rbp)
	movl	$.LC0, %edi
	call	puts
	movl	$0, -12(%rbp)
	jmp	.L2
.L3:
	movl	-12(%rbp), %eax
	cltq
	addq	%rax, -8(%rbp)
	addl	$1, -12(%rbp)
.L2:
	cmpl	$9999, -12(%rbp)
	jle	.L3
	movl	$.LC1, %edi
	call	puts
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
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
