	.text
	.file	"./good.cpp"
	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI0_0:
	.quad	4607182418800017408     # double 1
.LCPI0_1:
	.quad	4634274385308418048     # double 65
	.text
	.globl	_Z5factri
	.align	16, 0x90
	.type	_Z5factri,@function
_Z5factri:                              # @_Z5factri
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
	subq	$32, %rsp
	xorps	%xmm0, %xmm0
	movsd	.LCPI0_0, %xmm1         # xmm1 = mem[0],zero
	movsd	.LCPI0_1, %xmm2         # xmm2 = mem[0],zero
	movl	%edi, -8(%rbp)
	movsd	%xmm2, -16(%rbp)
	addsd	-16(%rbp), %xmm1
	movsd	%xmm1, -16(%rbp)
	movsd	-16(%rbp), %xmm1        # xmm1 = mem[0],zero
	ucomisd	%xmm0, %xmm1
	jne	.LBB0_1
	jp	.LBB0_1
	jmp	.LBB0_2
.LBB0_1:
	movl	$1, -4(%rbp)
	jmp	.LBB0_3
.LBB0_2:
	movl	-8(%rbp), %eax
	movl	-8(%rbp), %ecx
	subl	$1, %ecx
	movl	%ecx, %edi
	movl	%eax, -20(%rbp)         # 4-byte Spill
	callq	_Z5factri
	movl	-20(%rbp), %ecx         # 4-byte Reload
	imull	%eax, %ecx
	movl	%ecx, -4(%rbp)
.LBB0_3:
	movl	-4(%rbp), %eax
	addq	$32, %rsp
	popq	%rbp
	retq
.Lfunc_end0:
	.size	_Z5factri, .Lfunc_end0-_Z5factri
	.cfi_endproc

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp3:
	.cfi_def_cfa_offset 16
.Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$7, %edi
	movl	$0, -4(%rbp)
	callq	_Z5factri
	xorl	%edi, %edi
	movl	%eax, -8(%rbp)
	movl	%edi, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc


	.ident	"clang version 3.8.0-2ubuntu3 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
