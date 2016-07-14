	.text
	.file	"./sascha.cpp"
	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI0_0:
	.quad	4607182418800017408     # double 1
	.text
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp0:
	.cfi_def_cfa_offset 16
.Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp2:
	.cfi_def_cfa_register %rbp
	movsd	.LCPI0_0, %xmm0         # xmm0 = mem[0],zero
	movl	$0, -4(%rbp)
	movsd	%xmm0, -16(%rbp)
	movl	$1, -8(%rbp)
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	movsd	.LCPI0_0, %xmm0         # xmm0 = mem[0],zero
	cvtsi2sdl	-8(%rbp), %xmm1
	addsd	-16(%rbp), %xmm0
	movsd	%xmm0, -16(%rbp)
	ucomisd	%xmm0, %xmm1
	jne	.LBB0_3
	jp	.LBB0_3
# BB#2:                                 #   in Loop: Header=BB0_1 Depth=1
	movl	$0, -8(%rbp)
	jmp	.LBB0_1
.LBB0_3:
	movl	$1, %eax
	popq	%rbp
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc


	.ident	"clang version 3.8.0-2ubuntu3 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
