	.file	"vectorize.c"
	.text
	.p2align 4
	.globl	test
	.type	test, @function
test:
.LFB0:
	.cfi_startproc
	leaq	15(%rsi), %rax
	subq	%rdi, %rax
	cmpq	$30, %rax
	movl	$0, %eax
	jbe	.L2
	.p2align 4,,10
	.p2align 3
.L3:
	vmovdqu	(%rsi,%rax), %xmm1
	vpslld	$1, %xmm1, %xmm0
	vmovups	%xmm0, (%rdi,%rax)
	addq	$16, %rax
	cmpq	$400, %rax
	jne	.L3
	ret
	.p2align 4,,10
	.p2align 3
.L2:
	movl	(%rsi,%rax), %ecx
	leal	(%rcx,%rcx), %edx
	movl	%edx, (%rdi,%rax)
	addq	$4, %rax
	cmpq	$400, %rax
	jne	.L2
	ret
	.cfi_endproc
.LFE0:
	.size	test, .-test
	.ident	"GCC: (Gentoo 9.3.0-r1 p3) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
