	.text
	.file	"Blawn"
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3               # -- Begin function main
.LCPI0_0:
	.quad	4606281698874543309     # double 0.90000000000000002
.LCPI0_1:
	.quad	4576918229304087675     # double 0.01
	.text
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rbx
	.cfi_def_cfa_offset 16
	subq	$48, %rsp
	.cfi_def_cfa_offset 64
	.cfi_offset %rbx, -16
	movl	$1, %edi
	callq	twice.4
	movq	%rax, 40(%rsp)
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	twice.8
	movsd	%xmm0, 32(%rsp)
	movl	$7, %edi
	callq	Test.10
	movq	%rax, 24(%rsp)
	movsd	.LCPI0_1(%rip), %xmm0   # xmm0 = mem[0],zero
	callq	Test.12
	movq	%rax, 16(%rsp)
	xorl	%edi, %edi
	callq	ui.15
	movq	%rax, %rbx
	movq	%rbx, 8(%rsp)
	movq	%rbx, %rdi
	callq	destructor_of_Test
	movq	%rbx, %rdi
	callq	destructor_of_Test
	movq	%rbx, %rdi
	callq	destructor_of_Test
	movl	$12, %edi
	callq	malloc
	movq	%rax, %rbx
	movl	$120, %edi
	callq	putchar
	movq	%rbx, %rdi
	callq	free
	movq	%rbx, %rdi
	callq	free
	movl	$120, %edi
	callq	putchar
	movq	%rbx, %rdi
	callq	free
	xorl	%eax, %eax
	addq	$48, %rsp
	popq	%rbx
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
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
.Lfunc_end1:
	.size	add.3, .Lfunc_end1-add.3
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
.Lfunc_end2:
	.size	twice.4, .Lfunc_end2-twice.4
	.cfi_endproc
                                        # -- End function
	.globl	add.7                   # -- Begin function add.7
	.p2align	4, 0x90
	.type	add.7,@function
add.7:                                  # @add.7
	.cfi_startproc
# %bb.0:                                # %entry
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rsp)
	retq
.Lfunc_end3:
	.size	add.7, .Lfunc_end3-add.7
	.cfi_endproc
                                        # -- End function
	.globl	twice.8                 # -- Begin function twice.8
	.p2align	4, 0x90
	.type	twice.8,@function
twice.8:                                # @twice.8
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movaps	%xmm0, %xmm1
	callq	add.7
	movsd	%xmm0, (%rsp)
	popq	%rax
	retq
.Lfunc_end4:
	.size	twice.8, .Lfunc_end4-twice.8
	.cfi_endproc
                                        # -- End function
	.globl	Test.10                 # -- Begin function Test.10
	.p2align	4, 0x90
	.type	Test.10,@function
Test.10:                                # @Test.10
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%r15
	.cfi_def_cfa_offset 16
	pushq	%r14
	.cfi_def_cfa_offset 24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	subq	$32, %rsp
	.cfi_def_cfa_offset 64
	.cfi_offset %rbx, -32
	.cfi_offset %r14, -24
	.cfi_offset %r15, -16
	movq	%rdi, %rbx
	movq	%rbx, 24(%rsp)
	movabsq	$4602678819172646912, %r15 # imm = 0x3FE0000000000000
	movq	%r15, 16(%rsp)
	callq	twice.4
	movq	%rax, %r14
	movq	%r14, 8(%rsp)
	movl	$24, %edi
	callq	malloc
	movq	%rbx, (%rax)
	movq	%r15, 8(%rax)
	movq	%r14, 16(%rax)
	addq	$32, %rsp
	popq	%rbx
	popq	%r14
	popq	%r15
	retq
.Lfunc_end5:
	.size	Test.10, .Lfunc_end5-Test.10
	.cfi_endproc
                                        # -- End function
	.globl	destructor_of_Test      # -- Begin function destructor_of_Test
	.p2align	4, 0x90
	.type	destructor_of_Test,@function
destructor_of_Test:                     # @destructor_of_Test
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	callq	free
	popq	%rax
	retq
.Lfunc_end6:
	.size	destructor_of_Test, .Lfunc_end6-destructor_of_Test
	.cfi_endproc
                                        # -- End function
	.globl	Test.12                 # -- Begin function Test.12
	.p2align	4, 0x90
	.type	Test.12,@function
Test.12:                                # @Test.12
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rbx
	.cfi_def_cfa_offset 16
	subq	$48, %rsp
	.cfi_def_cfa_offset 64
	.cfi_offset %rbx, -16
	movsd	%xmm0, 16(%rsp)         # 8-byte Spill
	movsd	%xmm0, 40(%rsp)
	movabsq	$4602678819172646912, %rbx # imm = 0x3FE0000000000000
	movq	%rbx, 32(%rsp)
	callq	twice.8
	movsd	%xmm0, 8(%rsp)          # 8-byte Spill
	movsd	%xmm0, 24(%rsp)
	movl	$24, %edi
	callq	malloc
	movsd	16(%rsp), %xmm0         # 8-byte Reload
                                        # xmm0 = mem[0],zero
	movsd	%xmm0, (%rax)
	movq	%rbx, 8(%rax)
	movsd	8(%rsp), %xmm0          # 8-byte Reload
                                        # xmm0 = mem[0],zero
	movsd	%xmm0, 16(%rax)
	addq	$48, %rsp
	popq	%rbx
	retq
.Lfunc_end7:
	.size	Test.12, .Lfunc_end7-Test.12
	.cfi_endproc
                                        # -- End function
	.globl	"#destructor_of_Test.13" # -- Begin function #destructor_of_Test.13
	.p2align	4, 0x90
	.type	"#destructor_of_Test.13",@function
"#destructor_of_Test.13":               # @"#destructor_of_Test.13"
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	callq	free
	popq	%rax
	retq
.Lfunc_end8:
	.size	"#destructor_of_Test.13", .Lfunc_end8-"#destructor_of_Test.13"
	.cfi_endproc
                                        # -- End function
	.globl	ui.15                   # -- Begin function ui.15
	.p2align	4, 0x90
	.type	ui.15,@function
ui.15:                                  # @ui.15
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rbx
	.cfi_def_cfa_offset 16
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -16
	movq	%rdi, %rbx
	movl	$9, %edi
	callq	Test.10
	movq	%rbx, %rdi
	callq	Test.10
	movq	%rax, 8(%rsp)
	addq	$16, %rsp
	popq	%rbx
	retq
.Lfunc_end9:
	.size	ui.15, .Lfunc_end9-ui.15
	.cfi_endproc
                                        # -- End function

	.section	".note.GNU-stack","",@progbits
