//
//	first_sum.c - x86 assembler code to do some
//				  basic addition
//
//	Nov 11 2014 - Greg Rigole
//	- original
//

	.global main

//	.def    main; .scl    2;      .type   32;     .endef

	.text

main:

	movq $1, %rax

	mov     $.LC0, %rdi           # set 1st parameter (format)
        mov     %rax, %rsi           
	mov	$0, %rax
        call    printf

	ret

.LC0:
    .ascii "rax = %ld\12\0"
