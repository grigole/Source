	.text
	.file	"sum.c"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Lcfi0:
	.cfi_def_cfa_offset 16
.Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Lcfi2:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movq	$0, -16(%rbp)
	movq	$0, -24(%rbp)
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	cmpq	$1000000, -24(%rbp)     # imm = 0xF4240
	jge	.LBB0_4
# BB#2:                                 #   in Loop: Header=BB0_1 Depth=1
	movq	-24(%rbp), %rax
	addq	-16(%rbp), %rax
	movq	%rax, -16(%rbp)
# BB#3:                                 #   in Loop: Header=BB0_1 Depth=1
	movq	-24(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -24(%rbp)
	jmp	.LBB0_1
.LBB0_4:
	movabsq	$.L.str, %rdi
	movq	-16(%rbp), %rsi
	movb	$0, %al
	callq	printf
	movl	-4(%rbp), %ecx
	movl	%eax, -28(%rbp)         # 4-byte Spill
	movl	%ecx, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"sum = %ld\n"
	.size	.L.str, 11


	.ident	"clang version 5.0.1 (tags/RELEASE_501/final)"
	.section	".note.GNU-stack","",@progbits
