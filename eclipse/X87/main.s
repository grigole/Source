	.file	"main.c"
	.text
	.section	.rodata
.LC2:
	.string	"result = %lf\n"
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
	subq	$32, %rsp
	vmovsd	.LC0(%rip), %xmm0
	vmovsd	%xmm0, -24(%rbp)
	vmovsd	.LC1(%rip), %xmm0
	vmovsd	%xmm0, -16(%rbp)
	vmovsd	-16(%rbp), %xmm0
	movq	-24(%rbp), %rax
	vmovapd	%xmm0, %xmm1
	vmovq	%rax, %xmm0
	call	func@PLT
	vmovq	%xmm0, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	vmovq	%rax, %xmm0
	leaq	.LC2(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1073741824
	.align 8
.LC1:
	.long	0
	.long	1074266112
	.ident	"GCC: (Gentoo 9.3.0-r1 p3) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
