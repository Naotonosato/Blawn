	.text
	.file	"Blawn"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movl	$9, %edi
	callq	twice.4
	movq	%rax, 8(%rsp)
	movl	$9, %edi
	callq	twice.4
	addq	$9, 8(%rsp)
	movl	$9, %edi
	callq	twice.4
	movq	$0, 16(%rsp)
	xorl	%eax, %eax
	addq	$24, %rsp
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.globl	add                     # -- Begin function add
	.p2align	4, 0x90
	.type	add,@function
add:                                    # @add
	.cfi_startproc
# %bb.0:                                # %empty_entry
	retq
.Lfunc_end1:
	.size	add, .Lfunc_end1-add
	.cfi_endproc
                                        # -- End function
	.globl	twice                   # -- Begin function twice
	.p2align	4, 0x90
	.type	twice,@function
twice:                                  # @twice
	.cfi_startproc
# %bb.0:                                # %empty_entry
	retq
.Lfunc_end2:
	.size	twice, .Lfunc_end2-twice
	.cfi_endproc
                                        # -- End function
	.globl	add.3                   # -- Begin function add.3
	.p2align	4, 0x90
	.type	add.3,@function
add.3:                                  # @add.3
	.cfi_startproc
# %bb.0:                                # %entry
	addq	%rsi, %rdi
	movq	%rdi, -8(%rsp)
	movq	%rdi, %rax
	retq
.Lfunc_end3:
	.size	add.3, .Lfunc_end3-add.3
	.cfi_endproc
                                        # -- End function
	.globl	twice.4                 # -- Begin function twice.4
	.p2align	4, 0x90
	.type	twice.4,@function
twice.4:                                # @twice.4
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movq	%rdi, %rsi
	callq	add.3
	movq	%rax, (%rsp)
	popq	%rcx
	retq
.Lfunc_end4:
	.size	twice.4, .Lfunc_end4-twice.4
	.cfi_endproc
                                        # -- End function

	.section	".note.GNU-stack","",@progbits
