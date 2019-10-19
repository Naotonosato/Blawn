	.text
	.file	"Blawn"
	.globl	i64_to_i8               # -- Begin function i64_to_i8
	.p2align	4, 0x90
	.type	i64_to_i8,@function
i64_to_i8:                              # @i64_to_i8
	.cfi_startproc
# %bb.0:                                # %i64_to_i8
	movl	%edi, %eax
	retq
.Lfunc_end0:
	.size	i64_to_i8, .Lfunc_end0-i64_to_i8
	.cfi_endproc
                                        # -- End function
	.globl	i64_to_i32              # -- Begin function i64_to_i32
	.p2align	4, 0x90
	.type	i64_to_i32,@function
i64_to_i32:                             # @i64_to_i32
	.cfi_startproc
# %bb.0:                                # %i64_to_i32
	movl	%edi, %eax
	retq
.Lfunc_end1:
	.size	i64_to_i32, .Lfunc_end1-i64_to_i32
	.cfi_endproc
                                        # -- End function
	.globl	i32_to_i8               # -- Begin function i32_to_i8
	.p2align	4, 0x90
	.type	i32_to_i8,@function
i32_to_i8:                              # @i32_to_i8
	.cfi_startproc
# %bb.0:                                # %i32_to_i8
	movl	%edi, %eax
	retq
.Lfunc_end2:
	.size	i32_to_i8, .Lfunc_end2-i32_to_i8
	.cfi_endproc
                                        # -- End function
	.globl	i8_to_i32               # -- Begin function i8_to_i32
	.p2align	4, 0x90
	.type	i8_to_i32,@function
i8_to_i32:                              # @i8_to_i32
	.cfi_startproc
# %bb.0:                                # %i8_to_i32
	movzbl	%dil, %eax
	retq
.Lfunc_end3:
	.size	i8_to_i32, .Lfunc_end3-i8_to_i32
	.cfi_endproc
                                        # -- End function
	.globl	i32_to_i64              # -- Begin function i32_to_i64
	.p2align	4, 0x90
	.type	i32_to_i64,@function
i32_to_i64:                             # @i32_to_i64
	.cfi_startproc
# %bb.0:                                # %i32_to_i64
	movl	%edi, %eax
	retq
.Lfunc_end4:
	.size	i32_to_i64, .Lfunc_end4-i32_to_i64
	.cfi_endproc
                                        # -- End function
	.globl	i8_to_i64               # -- Begin function i8_to_i64
	.p2align	4, 0x90
	.type	i8_to_i64,@function
i8_to_i64:                              # @i8_to_i64
	.cfi_startproc
# %bb.0:                                # %i8_to_i64
	movzbl	%dil, %eax
	retq
.Lfunc_end5:
	.size	i8_to_i64, .Lfunc_end5-i8_to_i64
	.cfi_endproc
                                        # -- End function
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	subq	$40, %rsp
	.cfi_def_cfa_offset 48
	movb	$0, 7(%rsp)
	movq	$0, 32(%rsp)
	movl	$0, 12(%rsp)
	movl	$0, 8(%rsp)
	movq	24(%rsp), %rax
	movq	%rax, 16(%rsp)
	callq	c_function
	movl	$.L__unnamed_1, %edi
	movl	$33, %esi
	callq	string_constructor
	movq	(%rax), %rdi
	callq	puts
	xorl	%eax, %eax
	addq	$40, %rsp
	retq
.Lfunc_end6:
	.size	main, .Lfunc_end6-main
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.1              # -- Begin function _IO_FILE.1
	.p2align	4, 0x90
	.type	_IO_FILE.1,@function
_IO_FILE.1:                             # @_IO_FILE.1
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end7:
	.size	_IO_FILE.1, .Lfunc_end7-_IO_FILE.1
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.2              # -- Begin function _IO_FILE.2
	.p2align	4, 0x90
	.type	_IO_FILE.2,@function
_IO_FILE.2:                             # @_IO_FILE.2
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end8:
	.size	_IO_FILE.2, .Lfunc_end8-_IO_FILE.2
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.3              # -- Begin function _IO_FILE.3
	.p2align	4, 0x90
	.type	_IO_FILE.3,@function
_IO_FILE.3:                             # @_IO_FILE.3
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end9:
	.size	_IO_FILE.3, .Lfunc_end9-_IO_FILE.3
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.4              # -- Begin function _IO_FILE.4
	.p2align	4, 0x90
	.type	_IO_FILE.4,@function
_IO_FILE.4:                             # @_IO_FILE.4
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end10:
	.size	_IO_FILE.4, .Lfunc_end10-_IO_FILE.4
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.5              # -- Begin function _IO_FILE.5
	.p2align	4, 0x90
	.type	_IO_FILE.5,@function
_IO_FILE.5:                             # @_IO_FILE.5
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end11:
	.size	_IO_FILE.5, .Lfunc_end11-_IO_FILE.5
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.6              # -- Begin function _IO_FILE.6
	.p2align	4, 0x90
	.type	_IO_FILE.6,@function
_IO_FILE.6:                             # @_IO_FILE.6
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end12:
	.size	_IO_FILE.6, .Lfunc_end12-_IO_FILE.6
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.7              # -- Begin function _IO_FILE.7
	.p2align	4, 0x90
	.type	_IO_FILE.7,@function
_IO_FILE.7:                             # @_IO_FILE.7
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end13:
	.size	_IO_FILE.7, .Lfunc_end13-_IO_FILE.7
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.8              # -- Begin function _IO_FILE.8
	.p2align	4, 0x90
	.type	_IO_FILE.8,@function
_IO_FILE.8:                             # @_IO_FILE.8
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end14:
	.size	_IO_FILE.8, .Lfunc_end14-_IO_FILE.8
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.9              # -- Begin function _IO_FILE.9
	.p2align	4, 0x90
	.type	_IO_FILE.9,@function
_IO_FILE.9:                             # @_IO_FILE.9
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end15:
	.size	_IO_FILE.9, .Lfunc_end15-_IO_FILE.9
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.10             # -- Begin function _IO_FILE.10
	.p2align	4, 0x90
	.type	_IO_FILE.10,@function
_IO_FILE.10:                            # @_IO_FILE.10
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end16:
	.size	_IO_FILE.10, .Lfunc_end16-_IO_FILE.10
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.11             # -- Begin function _IO_FILE.11
	.p2align	4, 0x90
	.type	_IO_FILE.11,@function
_IO_FILE.11:                            # @_IO_FILE.11
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end17:
	.size	_IO_FILE.11, .Lfunc_end17-_IO_FILE.11
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.12             # -- Begin function _IO_FILE.12
	.p2align	4, 0x90
	.type	_IO_FILE.12,@function
_IO_FILE.12:                            # @_IO_FILE.12
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end18:
	.size	_IO_FILE.12, .Lfunc_end18-_IO_FILE.12
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.13             # -- Begin function _IO_FILE.13
	.p2align	4, 0x90
	.type	_IO_FILE.13,@function
_IO_FILE.13:                            # @_IO_FILE.13
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end19:
	.size	_IO_FILE.13, .Lfunc_end19-_IO_FILE.13
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.14             # -- Begin function _IO_FILE.14
	.p2align	4, 0x90
	.type	_IO_FILE.14,@function
_IO_FILE.14:                            # @_IO_FILE.14
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end20:
	.size	_IO_FILE.14, .Lfunc_end20-_IO_FILE.14
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.15             # -- Begin function _IO_FILE.15
	.p2align	4, 0x90
	.type	_IO_FILE.15,@function
_IO_FILE.15:                            # @_IO_FILE.15
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end21:
	.size	_IO_FILE.15, .Lfunc_end21-_IO_FILE.15
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.16             # -- Begin function _IO_FILE.16
	.p2align	4, 0x90
	.type	_IO_FILE.16,@function
_IO_FILE.16:                            # @_IO_FILE.16
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end22:
	.size	_IO_FILE.16, .Lfunc_end22-_IO_FILE.16
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.17             # -- Begin function _IO_FILE.17
	.p2align	4, 0x90
	.type	_IO_FILE.17,@function
_IO_FILE.17:                            # @_IO_FILE.17
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end23:
	.size	_IO_FILE.17, .Lfunc_end23-_IO_FILE.17
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.18             # -- Begin function _IO_FILE.18
	.p2align	4, 0x90
	.type	_IO_FILE.18,@function
_IO_FILE.18:                            # @_IO_FILE.18
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end24:
	.size	_IO_FILE.18, .Lfunc_end24-_IO_FILE.18
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.19             # -- Begin function _IO_FILE.19
	.p2align	4, 0x90
	.type	_IO_FILE.19,@function
_IO_FILE.19:                            # @_IO_FILE.19
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end25:
	.size	_IO_FILE.19, .Lfunc_end25-_IO_FILE.19
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.20             # -- Begin function _IO_FILE.20
	.p2align	4, 0x90
	.type	_IO_FILE.20,@function
_IO_FILE.20:                            # @_IO_FILE.20
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end26:
	.size	_IO_FILE.20, .Lfunc_end26-_IO_FILE.20
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.21             # -- Begin function _IO_FILE.21
	.p2align	4, 0x90
	.type	_IO_FILE.21,@function
_IO_FILE.21:                            # @_IO_FILE.21
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end27:
	.size	_IO_FILE.21, .Lfunc_end27-_IO_FILE.21
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.22             # -- Begin function _IO_FILE.22
	.p2align	4, 0x90
	.type	_IO_FILE.22,@function
_IO_FILE.22:                            # @_IO_FILE.22
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end28:
	.size	_IO_FILE.22, .Lfunc_end28-_IO_FILE.22
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.23             # -- Begin function _IO_FILE.23
	.p2align	4, 0x90
	.type	_IO_FILE.23,@function
_IO_FILE.23:                            # @_IO_FILE.23
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end29:
	.size	_IO_FILE.23, .Lfunc_end29-_IO_FILE.23
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.24             # -- Begin function _IO_FILE.24
	.p2align	4, 0x90
	.type	_IO_FILE.24,@function
_IO_FILE.24:                            # @_IO_FILE.24
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end30:
	.size	_IO_FILE.24, .Lfunc_end30-_IO_FILE.24
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.25             # -- Begin function _IO_FILE.25
	.p2align	4, 0x90
	.type	_IO_FILE.25,@function
_IO_FILE.25:                            # @_IO_FILE.25
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end31:
	.size	_IO_FILE.25, .Lfunc_end31-_IO_FILE.25
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.26             # -- Begin function _IO_FILE.26
	.p2align	4, 0x90
	.type	_IO_FILE.26,@function
_IO_FILE.26:                            # @_IO_FILE.26
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end32:
	.size	_IO_FILE.26, .Lfunc_end32-_IO_FILE.26
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.27             # -- Begin function _IO_FILE.27
	.p2align	4, 0x90
	.type	_IO_FILE.27,@function
_IO_FILE.27:                            # @_IO_FILE.27
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end33:
	.size	_IO_FILE.27, .Lfunc_end33-_IO_FILE.27
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.28             # -- Begin function _IO_FILE.28
	.p2align	4, 0x90
	.type	_IO_FILE.28,@function
_IO_FILE.28:                            # @_IO_FILE.28
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end34:
	.size	_IO_FILE.28, .Lfunc_end34-_IO_FILE.28
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.29             # -- Begin function _IO_FILE.29
	.p2align	4, 0x90
	.type	_IO_FILE.29,@function
_IO_FILE.29:                            # @_IO_FILE.29
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end35:
	.size	_IO_FILE.29, .Lfunc_end35-_IO_FILE.29
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.30             # -- Begin function _IO_FILE.30
	.p2align	4, 0x90
	.type	_IO_FILE.30,@function
_IO_FILE.30:                            # @_IO_FILE.30
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end36:
	.size	_IO_FILE.30, .Lfunc_end36-_IO_FILE.30
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.31             # -- Begin function _IO_FILE.31
	.p2align	4, 0x90
	.type	_IO_FILE.31,@function
_IO_FILE.31:                            # @_IO_FILE.31
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end37:
	.size	_IO_FILE.31, .Lfunc_end37-_IO_FILE.31
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.32             # -- Begin function _IO_FILE.32
	.p2align	4, 0x90
	.type	_IO_FILE.32,@function
_IO_FILE.32:                            # @_IO_FILE.32
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end38:
	.size	_IO_FILE.32, .Lfunc_end38-_IO_FILE.32
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.33             # -- Begin function _IO_FILE.33
	.p2align	4, 0x90
	.type	_IO_FILE.33,@function
_IO_FILE.33:                            # @_IO_FILE.33
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end39:
	.size	_IO_FILE.33, .Lfunc_end39-_IO_FILE.33
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.34             # -- Begin function _IO_FILE.34
	.p2align	4, 0x90
	.type	_IO_FILE.34,@function
_IO_FILE.34:                            # @_IO_FILE.34
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end40:
	.size	_IO_FILE.34, .Lfunc_end40-_IO_FILE.34
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.35             # -- Begin function _IO_FILE.35
	.p2align	4, 0x90
	.type	_IO_FILE.35,@function
_IO_FILE.35:                            # @_IO_FILE.35
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end41:
	.size	_IO_FILE.35, .Lfunc_end41-_IO_FILE.35
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.36             # -- Begin function _IO_FILE.36
	.p2align	4, 0x90
	.type	_IO_FILE.36,@function
_IO_FILE.36:                            # @_IO_FILE.36
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end42:
	.size	_IO_FILE.36, .Lfunc_end42-_IO_FILE.36
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.37             # -- Begin function _IO_FILE.37
	.p2align	4, 0x90
	.type	_IO_FILE.37,@function
_IO_FILE.37:                            # @_IO_FILE.37
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end43:
	.size	_IO_FILE.37, .Lfunc_end43-_IO_FILE.37
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.38             # -- Begin function _IO_FILE.38
	.p2align	4, 0x90
	.type	_IO_FILE.38,@function
_IO_FILE.38:                            # @_IO_FILE.38
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end44:
	.size	_IO_FILE.38, .Lfunc_end44-_IO_FILE.38
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.39             # -- Begin function _IO_FILE.39
	.p2align	4, 0x90
	.type	_IO_FILE.39,@function
_IO_FILE.39:                            # @_IO_FILE.39
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end45:
	.size	_IO_FILE.39, .Lfunc_end45-_IO_FILE.39
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.40             # -- Begin function _IO_FILE.40
	.p2align	4, 0x90
	.type	_IO_FILE.40,@function
_IO_FILE.40:                            # @_IO_FILE.40
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end46:
	.size	_IO_FILE.40, .Lfunc_end46-_IO_FILE.40
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.41             # -- Begin function _IO_FILE.41
	.p2align	4, 0x90
	.type	_IO_FILE.41,@function
_IO_FILE.41:                            # @_IO_FILE.41
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end47:
	.size	_IO_FILE.41, .Lfunc_end47-_IO_FILE.41
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.42             # -- Begin function _IO_FILE.42
	.p2align	4, 0x90
	.type	_IO_FILE.42,@function
_IO_FILE.42:                            # @_IO_FILE.42
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end48:
	.size	_IO_FILE.42, .Lfunc_end48-_IO_FILE.42
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.43             # -- Begin function _IO_FILE.43
	.p2align	4, 0x90
	.type	_IO_FILE.43,@function
_IO_FILE.43:                            # @_IO_FILE.43
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end49:
	.size	_IO_FILE.43, .Lfunc_end49-_IO_FILE.43
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.44             # -- Begin function _IO_FILE.44
	.p2align	4, 0x90
	.type	_IO_FILE.44,@function
_IO_FILE.44:                            # @_IO_FILE.44
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end50:
	.size	_IO_FILE.44, .Lfunc_end50-_IO_FILE.44
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.45             # -- Begin function _IO_FILE.45
	.p2align	4, 0x90
	.type	_IO_FILE.45,@function
_IO_FILE.45:                            # @_IO_FILE.45
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end51:
	.size	_IO_FILE.45, .Lfunc_end51-_IO_FILE.45
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.46             # -- Begin function _IO_FILE.46
	.p2align	4, 0x90
	.type	_IO_FILE.46,@function
_IO_FILE.46:                            # @_IO_FILE.46
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end52:
	.size	_IO_FILE.46, .Lfunc_end52-_IO_FILE.46
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.47             # -- Begin function _IO_FILE.47
	.p2align	4, 0x90
	.type	_IO_FILE.47,@function
_IO_FILE.47:                            # @_IO_FILE.47
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end53:
	.size	_IO_FILE.47, .Lfunc_end53-_IO_FILE.47
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.48             # -- Begin function _IO_FILE.48
	.p2align	4, 0x90
	.type	_IO_FILE.48,@function
_IO_FILE.48:                            # @_IO_FILE.48
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end54:
	.size	_IO_FILE.48, .Lfunc_end54-_IO_FILE.48
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.49             # -- Begin function _IO_FILE.49
	.p2align	4, 0x90
	.type	_IO_FILE.49,@function
_IO_FILE.49:                            # @_IO_FILE.49
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end55:
	.size	_IO_FILE.49, .Lfunc_end55-_IO_FILE.49
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.50             # -- Begin function _IO_FILE.50
	.p2align	4, 0x90
	.type	_IO_FILE.50,@function
_IO_FILE.50:                            # @_IO_FILE.50
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end56:
	.size	_IO_FILE.50, .Lfunc_end56-_IO_FILE.50
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.51             # -- Begin function _IO_FILE.51
	.p2align	4, 0x90
	.type	_IO_FILE.51,@function
_IO_FILE.51:                            # @_IO_FILE.51
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end57:
	.size	_IO_FILE.51, .Lfunc_end57-_IO_FILE.51
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.52             # -- Begin function _IO_FILE.52
	.p2align	4, 0x90
	.type	_IO_FILE.52,@function
_IO_FILE.52:                            # @_IO_FILE.52
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end58:
	.size	_IO_FILE.52, .Lfunc_end58-_IO_FILE.52
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.53             # -- Begin function _IO_FILE.53
	.p2align	4, 0x90
	.type	_IO_FILE.53,@function
_IO_FILE.53:                            # @_IO_FILE.53
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end59:
	.size	_IO_FILE.53, .Lfunc_end59-_IO_FILE.53
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.54             # -- Begin function _IO_FILE.54
	.p2align	4, 0x90
	.type	_IO_FILE.54,@function
_IO_FILE.54:                            # @_IO_FILE.54
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end60:
	.size	_IO_FILE.54, .Lfunc_end60-_IO_FILE.54
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.55             # -- Begin function _IO_FILE.55
	.p2align	4, 0x90
	.type	_IO_FILE.55,@function
_IO_FILE.55:                            # @_IO_FILE.55
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end61:
	.size	_IO_FILE.55, .Lfunc_end61-_IO_FILE.55
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.56             # -- Begin function _IO_FILE.56
	.p2align	4, 0x90
	.type	_IO_FILE.56,@function
_IO_FILE.56:                            # @_IO_FILE.56
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end62:
	.size	_IO_FILE.56, .Lfunc_end62-_IO_FILE.56
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.57             # -- Begin function _IO_FILE.57
	.p2align	4, 0x90
	.type	_IO_FILE.57,@function
_IO_FILE.57:                            # @_IO_FILE.57
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end63:
	.size	_IO_FILE.57, .Lfunc_end63-_IO_FILE.57
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.58             # -- Begin function _IO_FILE.58
	.p2align	4, 0x90
	.type	_IO_FILE.58,@function
_IO_FILE.58:                            # @_IO_FILE.58
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end64:
	.size	_IO_FILE.58, .Lfunc_end64-_IO_FILE.58
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.59             # -- Begin function _IO_FILE.59
	.p2align	4, 0x90
	.type	_IO_FILE.59,@function
_IO_FILE.59:                            # @_IO_FILE.59
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end65:
	.size	_IO_FILE.59, .Lfunc_end65-_IO_FILE.59
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.60             # -- Begin function _IO_FILE.60
	.p2align	4, 0x90
	.type	_IO_FILE.60,@function
_IO_FILE.60:                            # @_IO_FILE.60
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end66:
	.size	_IO_FILE.60, .Lfunc_end66-_IO_FILE.60
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.61             # -- Begin function _IO_FILE.61
	.p2align	4, 0x90
	.type	_IO_FILE.61,@function
_IO_FILE.61:                            # @_IO_FILE.61
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end67:
	.size	_IO_FILE.61, .Lfunc_end67-_IO_FILE.61
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.62             # -- Begin function _IO_FILE.62
	.p2align	4, 0x90
	.type	_IO_FILE.62,@function
_IO_FILE.62:                            # @_IO_FILE.62
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end68:
	.size	_IO_FILE.62, .Lfunc_end68-_IO_FILE.62
	.cfi_endproc
                                        # -- End function
	.globl	__mbstate_t.63          # -- Begin function __mbstate_t.63
	.p2align	4, 0x90
	.type	__mbstate_t.63,@function
__mbstate_t.63:                         # @__mbstate_t.63
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$8, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end69:
	.size	__mbstate_t.63, .Lfunc_end69-__mbstate_t.63
	.cfi_endproc
                                        # -- End function
	.globl	_G_fpos_t.64            # -- Begin function _G_fpos_t.64
	.p2align	4, 0x90
	.type	_G_fpos_t.64,@function
_G_fpos_t.64:                           # @_G_fpos_t.64
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end70:
	.size	_G_fpos_t.64, .Lfunc_end70-_G_fpos_t.64
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.65             # -- Begin function _IO_FILE.65
	.p2align	4, 0x90
	.type	_IO_FILE.65,@function
_IO_FILE.65:                            # @_IO_FILE.65
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end71:
	.size	_IO_FILE.65, .Lfunc_end71-_IO_FILE.65
	.cfi_endproc
                                        # -- End function
	.globl	_G_fpos_t.66            # -- Begin function _G_fpos_t.66
	.p2align	4, 0x90
	.type	_G_fpos_t.66,@function
_G_fpos_t.66:                           # @_G_fpos_t.66
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end72:
	.size	_G_fpos_t.66, .Lfunc_end72-_G_fpos_t.66
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.67             # -- Begin function _IO_FILE.67
	.p2align	4, 0x90
	.type	_IO_FILE.67,@function
_IO_FILE.67:                            # @_IO_FILE.67
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end73:
	.size	_IO_FILE.67, .Lfunc_end73-_IO_FILE.67
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.68             # -- Begin function _IO_FILE.68
	.p2align	4, 0x90
	.type	_IO_FILE.68,@function
_IO_FILE.68:                            # @_IO_FILE.68
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end74:
	.size	_IO_FILE.68, .Lfunc_end74-_IO_FILE.68
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.69             # -- Begin function _IO_FILE.69
	.p2align	4, 0x90
	.type	_IO_FILE.69,@function
_IO_FILE.69:                            # @_IO_FILE.69
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end75:
	.size	_IO_FILE.69, .Lfunc_end75-_IO_FILE.69
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.70             # -- Begin function _IO_FILE.70
	.p2align	4, 0x90
	.type	_IO_FILE.70,@function
_IO_FILE.70:                            # @_IO_FILE.70
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end76:
	.size	_IO_FILE.70, .Lfunc_end76-_IO_FILE.70
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.71             # -- Begin function _IO_FILE.71
	.p2align	4, 0x90
	.type	_IO_FILE.71,@function
_IO_FILE.71:                            # @_IO_FILE.71
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end77:
	.size	_IO_FILE.71, .Lfunc_end77-_IO_FILE.71
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.72             # -- Begin function _IO_FILE.72
	.p2align	4, 0x90
	.type	_IO_FILE.72,@function
_IO_FILE.72:                            # @_IO_FILE.72
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end78:
	.size	_IO_FILE.72, .Lfunc_end78-_IO_FILE.72
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.73             # -- Begin function _IO_FILE.73
	.p2align	4, 0x90
	.type	_IO_FILE.73,@function
_IO_FILE.73:                            # @_IO_FILE.73
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end79:
	.size	_IO_FILE.73, .Lfunc_end79-_IO_FILE.73
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.74             # -- Begin function _IO_FILE.74
	.p2align	4, 0x90
	.type	_IO_FILE.74,@function
_IO_FILE.74:                            # @_IO_FILE.74
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end80:
	.size	_IO_FILE.74, .Lfunc_end80-_IO_FILE.74
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.75             # -- Begin function _IO_FILE.75
	.p2align	4, 0x90
	.type	_IO_FILE.75,@function
_IO_FILE.75:                            # @_IO_FILE.75
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end81:
	.size	_IO_FILE.75, .Lfunc_end81-_IO_FILE.75
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.76             # -- Begin function _IO_FILE.76
	.p2align	4, 0x90
	.type	_IO_FILE.76,@function
_IO_FILE.76:                            # @_IO_FILE.76
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end82:
	.size	_IO_FILE.76, .Lfunc_end82-_IO_FILE.76
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.77             # -- Begin function _IO_FILE.77
	.p2align	4, 0x90
	.type	_IO_FILE.77,@function
_IO_FILE.77:                            # @_IO_FILE.77
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end83:
	.size	_IO_FILE.77, .Lfunc_end83-_IO_FILE.77
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.78             # -- Begin function _IO_FILE.78
	.p2align	4, 0x90
	.type	_IO_FILE.78,@function
_IO_FILE.78:                            # @_IO_FILE.78
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end84:
	.size	_IO_FILE.78, .Lfunc_end84-_IO_FILE.78
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.79             # -- Begin function _IO_FILE.79
	.p2align	4, 0x90
	.type	_IO_FILE.79,@function
_IO_FILE.79:                            # @_IO_FILE.79
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end85:
	.size	_IO_FILE.79, .Lfunc_end85-_IO_FILE.79
	.cfi_endproc
                                        # -- End function
	.type	.L__unnamed_1,@object   # @0
	.section	.rodata.str1.16,"aMS",@progbits,1
	.p2align	4
.L__unnamed_1:
	.asciz	"function 'puts' called from blawn"
	.size	.L__unnamed_1, 34


	.section	".note.GNU-stack","",@progbits
