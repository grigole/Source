	.file	"mpfr_sample.c"
	.text
	.section	.rodata
.LC0:
	.string	"x  = %ld\n"
.LC1:
	.string	"y  = %ld\n"
.LC2:
	.string	"z  = %ld\n"
.LC3:
	.string	"1000000000000000000000000"
.LC4:
	.string	"xx = "
	.text
	.globl	main
	.type	main, @function
main:
.LFB20:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	$1000000000, -72(%rbp)
	movabsq	$9223372036854775807, %rax
	movq	%rax, -64(%rbp)
	movabsq	$-457092405402533889, %rax
	movq	%rax, -56(%rbp)
	movq	-72(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-64(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-56(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-48(%rbp), %rax
	movl	$200, %esi
	movq	%rax, %rdi
	call	mpfr_init2@PLT
	leaq	-48(%rbp), %rax
	movl	$0, %ecx
	movl	$10, %edx
	leaq	.LC3(%rip), %rsi
	movq	%rax, %rdi
	call	mpfr_set_str@PLT
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	stdout(%rip), %rax
	leaq	-48(%rbp), %rdx
	movl	$3, %r8d
	movq	%rdx, %rcx
	movl	$0, %edx
	movl	$10, %esi
	movq	%rax, %rdi
	call	__gmpfr_out_str@PLT
	movl	$10, %edi
	call	putchar@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE20:
	.size	main, .-main
	.ident	"GCC: (Gentoo 12.3.1_p20230526 p2) 12.3.1 20230526"
	.section	.note.GNU-stack,"",@progbits
