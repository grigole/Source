	.file	"randwalk.c"
	.section	.rodata
.LC1:
	.string	"%ld : Heads %lf, tails %lf\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	$0, -32(%rbp)
	movq	$0, -40(%rbp)
	movl	$0, %edi
	movl	$0, %eax
	call	time
	movl	%eax, %edi
	call	srand
	movq	$0, -24(%rbp)
	jmp	.L2
.L5:
	call	rand
	movl	%eax, %ecx
	movl	$1374389535, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$5, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	movl	%edx, %ebx
	subl	%eax, %ebx
	movl	%ebx, %eax
	imull	$100, %eax, %eax
	movl	%ecx, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	cltq
	movq	%rax, -48(%rbp)
	cmpq	$49, -48(%rbp)
	jg	.L3
	addq	$1, -40(%rbp)
	jmp	.L4
.L3:
	addq	$1, -32(%rbp)
.L4:
	addq	$1, -24(%rbp)
.L2:
	cmpq	$999999999, -24(%rbp)
	jle	.L5
	cvtsi2sdq	-40(%rbp), %xmm0
	cvtsi2sdq	-24(%rbp), %xmm1
	divsd	%xmm1, %xmm0
	movsd	.LC0(%rip), %xmm1
	mulsd	%xmm0, %xmm1
	cvtsi2sdq	-32(%rbp), %xmm0
	cvtsi2sdq	-24(%rbp), %xmm2
	divsd	%xmm2, %xmm0
	movsd	.LC0(%rip), %xmm2
	mulsd	%xmm2, %xmm0
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$2, %eax
	call	printf
	movl	$0, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1079574528
	.ident	"GCC: (Gentoo 4.7.3-r1 p1.5, pie-0.5.5) 4.7.3"
	.section	.note.GNU-stack,"",@progbits
