	.file	"main.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC2:
	.string	"result = %lf\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB23:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	vmovsd	.LC0(%rip), %xmm1
	vmovsd	.LC1(%rip), %xmm0
	call	func@PLT
	movl	$1, %edi
	movl	$1, %eax
	leaq	.LC2(%rip), %rsi
	call	__printf_chk@PLT
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE23:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	0
	.long	1074266112
	.align 8
.LC1:
	.long	0
	.long	1073741824
	.ident	"GCC: (Gentoo 9.3.0-r1 p3) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
