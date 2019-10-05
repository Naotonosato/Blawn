	.text
	.file	"Blawn"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%r14
	.cfi_def_cfa_offset 16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	subq	$24, %rsp
	.cfi_def_cfa_offset 48
	.cfi_offset %rbx, -24
	.cfi_offset %r14, -16
	movq	$0, C_INT(%rip)
	movq	$0, 16(%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$5, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	print
	movl	$.L__unnamed_2, %edi
	movl	$4, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	P.2
	movq	%rax, %r14
	movq	%r14, 8(%rsp)
	movl	$.L__unnamed_3, %edi
	movl	$2, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	P.2
	movq	%rax, %rbx
	movq	%rbx, (%rsp)
	callq	t.4
	movq	%rbx, %rdi
	callq	free
	movq	%r14, %rdi
	callq	free
	xorl	%eax, %eax
	addq	$24, %rsp
	popq	%rbx
	popq	%r14
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.globl	P.2                     # -- Begin function P.2
	.p2align	4, 0x90
	.type	P.2,@function
P.2:                                    # @P.2
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rbx
	.cfi_def_cfa_offset 16
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -16
	movq	%rdi, %rbx
	movq	%rbx, 8(%rsp)
	movl	$8, %edi
	callq	malloc
	movq	%rbx, (%rax)
	addq	$16, %rsp
	popq	%rbx
	retq
.Lfunc_end1:
	.size	P.2, .Lfunc_end1-P.2
	.cfi_endproc
                                        # -- End function
	.globl	"destructor<P>"         # -- Begin function destructor<P>
	.p2align	4, 0x90
	.type	"destructor<P>",@function
"destructor<P>":                        # @"destructor<P>"
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	callq	free
	popq	%rax
	retq
.Lfunc_end2:
	.size	"destructor<P>", .Lfunc_end2-"destructor<P>"
	.cfi_endproc
                                        # -- End function
	.globl	t.4                     # -- Begin function t.4
	.p2align	4, 0x90
	.type	t.4,@function
t.4:                                    # @t.4
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rbx
	.cfi_def_cfa_offset 16
	subq	$32, %rsp
	.cfi_def_cfa_offset 48
	.cfi_offset %rbx, -16
	movl	$.L__unnamed_4, %edi
	movl	$4, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	P.2
	movq	%rax, %rbx
	movq	%rbx, 8(%rsp)
	movq	%rbx, 24(%rsp)
	movl	$.L__unnamed_5, %edi
	movl	$3, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	P.2
	movq	%rax, 16(%rsp)
	movq	%rax, %rdi
	callq	free
	movq	%rbx, %rdi
	callq	free
	movq	8(%rsp), %rax
	addq	$32, %rsp
	popq	%rbx
	retq
.Lfunc_end3:
	.size	t.4, .Lfunc_end3-t.4
	.cfi_endproc
                                        # -- End function
	.globl	list_constructor        # -- Begin function list_constructor
	.p2align	4, 0x90
	.type	list_constructor,@function
list_constructor:                       # @list_constructor
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -16(%rbp)
	movl	$32, %edi
	callq	malloc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$0, 24(%rax)
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	%rax, 16(%rcx)
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	movq	-8(%rbp), %rax
	movq	$1, 8(%rax)
	movq	-8(%rbp), %rax
	addq	$16, %rsp
	popq	%rbp
	retq
.Lfunc_end4:
	.size	list_constructor, .Lfunc_end4-list_constructor
	.cfi_endproc
                                        # -- End function
	.globl	blawn_realloc           # -- Begin function blawn_realloc
	.p2align	4, 0x90
	.type	blawn_realloc,@function
blawn_realloc:                          # @blawn_realloc
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -32(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -16(%rbp)
	movq	-32(%rbp), %rdi
	movq	-24(%rbp), %rsi
	imulq	-16(%rbp), %rsi
	callq	realloc
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.LBB5_2
# %bb.1:
	movabsq	$.L.str, %rdi
	callq	puts
	movl	$1, %edi
	callq	exit
.LBB5_2:
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	retq
.Lfunc_end5:
	.size	blawn_realloc, .Lfunc_end5-blawn_realloc
	.cfi_endproc
                                        # -- End function
	.globl	blawn_memcpy            # -- Begin function blawn_memcpy
	.p2align	4, 0x90
	.type	blawn_memcpy,@function
blawn_memcpy:                           # @blawn_memcpy
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	leaq	-16(%rbp), %rax
	movq	%rdi, -32(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -8(%rbp)
	movq	%rcx, -16(%rbp)
	movq	-32(%rbp), %rdi
	movq	-24(%rbp), %rcx
	imulq	-8(%rbp), %rcx
	addq	%rcx, %rdi
	movq	-8(%rbp), %rdx
	movq	%rax, %rsi
	callq	memcpy
	addq	$32, %rsp
	popq	%rbp
	retq
.Lfunc_end6:
	.size	blawn_memcpy, .Lfunc_end6-blawn_memcpy
	.cfi_endproc
                                        # -- End function
	.globl	blawn_index             # -- Begin function blawn_index
	.p2align	4, 0x90
	.type	blawn_index,@function
blawn_index:                            # @blawn_index
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	xorl	%eax, %eax
	movq	%rdi, -32(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -16(%rbp)
	movq	%rcx, -8(%rbp)
	cmpq	-8(%rbp), %rax
	jg	.LBB7_3
# %bb.1:
	movq	-8(%rbp), %rax
	cmpq	-24(%rbp), %rax
	jge	.LBB7_3
# %bb.2:
	movq	-32(%rbp), %rax
	movq	-16(%rbp), %rcx
	imulq	-8(%rbp), %rcx
	addq	%rcx, %rax
	addq	$32, %rsp
	popq	%rbp
	retq
.LBB7_3:
	movabsq	$.L.str.1, %rdi
	callq	puts
	movl	$1, %edi
	callq	exit
.Lfunc_end7:
	.size	blawn_index, .Lfunc_end7-blawn_index
	.cfi_endproc
                                        # -- End function
	.globl	blawn_set_element       # -- Begin function blawn_set_element
	.p2align	4, 0x90
	.type	blawn_set_element,@function
blawn_set_element:                      # @blawn_set_element
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	xorl	%eax, %eax
	movq	%rdi, -40(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -16(%rbp)
	movq	%r8, -8(%rbp)
	cmpq	-8(%rbp), %rax
	jg	.LBB8_3
# %bb.1:
	movq	-8(%rbp), %rax
	cmpq	-32(%rbp), %rax
	jge	.LBB8_3
# %bb.2:
	movq	-16(%rbp), %rax
	movq	-40(%rbp), %rcx
	movq	-24(%rbp), %rdx
	imulq	-8(%rbp), %rdx
	movq	%rax, (%rcx,%rdx)
	jmp	.LBB8_4
.LBB8_3:
	movabsq	$.L.str.1, %rdi
	callq	puts
	movl	$1, %edi
	callq	exit
.LBB8_4:
	addq	$48, %rsp
	popq	%rbp
	retq
.Lfunc_end8:
	.size	blawn_set_element, .Lfunc_end8-blawn_set_element
	.cfi_endproc
                                        # -- End function
	.globl	print                   # -- Begin function print
	.p2align	4, 0x90
	.type	print,@function
print:                                  # @print
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movabsq	$.L.str.2, %rax
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	(%rcx), %rsi
	movq	%rax, %rdi
	movb	$0, %al
	callq	printf
	addq	$16, %rsp
	popq	%rbp
	retq
.Lfunc_end9:
	.size	print, .Lfunc_end9-print
	.cfi_endproc
                                        # -- End function
	.globl	string_constructor      # -- Begin function string_constructor
	.p2align	4, 0x90
	.type	string_constructor,@function
string_constructor:                     # @string_constructor
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$16, %edi
	callq	malloc
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	%rax, 8(%rcx)
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	retq
.Lfunc_end10:
	.size	string_constructor, .Lfunc_end10-string_constructor
	.cfi_endproc
                                        # -- End function
	.globl	append_string           # -- Begin function append_string
	.p2align	4, 0x90
	.type	append_string,@function
append_string:                          # @append_string
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	8(%rax), %rdi
	movq	-24(%rbp), %rax
	addq	8(%rax), %rdi
	callq	malloc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movb	$0, (%rax)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rax
	movq	(%rax), %rsi
	callq	strcat
	movq	-8(%rbp), %rdi
	movq	-24(%rbp), %rax
	movq	(%rax), %rsi
	callq	strcat
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	-16(%rbp), %rcx
	addq	8(%rcx), %rax
	movq	%rax, 8(%rcx)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rcx
	movq	%rax, (%rcx)
	addq	$32, %rsp
	popq	%rbp
	retq
.Lfunc_end11:
	.size	append_string, .Lfunc_end11-append_string
	.cfi_endproc
                                        # -- End function
	.globl	int_to_str              # -- Begin function int_to_str
	.p2align	4, 0x90
	.type	int_to_str,@function
int_to_str:                             # @int_to_str
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, -32(%rbp)
	cmpq	$0, -8(%rbp)
	jl	.LBB12_5
# %bb.1:
	movq	$0, -16(%rbp)
.LBB12_2:                               # =>This Inner Loop Header: Depth=1
	cmpq	$0, -8(%rbp)
	je	.LBB12_4
# %bb.3:                                #   in Loop: Header=BB12_2 Depth=1
	movl	$10, %ecx
	movq	-8(%rbp), %rax
	cqto
	idivq	%rcx
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -16(%rbp)
	jmp	.LBB12_2
.LBB12_4:
	jmp	.LBB12_9
.LBB12_5:
	xorl	%eax, %eax
	movq	$1, -16(%rbp)
	subq	-8(%rbp), %rax
	movq	%rax, -8(%rbp)
.LBB12_6:                               # =>This Inner Loop Header: Depth=1
	cmpq	$0, -8(%rbp)
	je	.LBB12_8
# %bb.7:                                #   in Loop: Header=BB12_6 Depth=1
	movl	$10, %ecx
	movq	-8(%rbp), %rax
	cqto
	idivq	%rcx
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -16(%rbp)
	jmp	.LBB12_6
.LBB12_8:
	jmp	.LBB12_9
.LBB12_9:
	movq	-16(%rbp), %rdi
	callq	malloc
	movabsq	$.L.str.3, %rdx
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rdi
	movq	-16(%rbp), %rsi
	addq	$1, %rsi
	movq	-32(%rbp), %rcx
	movb	$0, %al
	callq	snprintf
	movq	-24(%rbp), %rdi
	movq	-16(%rbp), %rsi
	callq	string_constructor
	addq	$32, %rsp
	popq	%rbp
	retq
.Lfunc_end12:
	.size	int_to_str, .Lfunc_end12-int_to_str
	.cfi_endproc
                                        # -- End function
	.globl	float_to_str            # -- Begin function float_to_str
	.p2align	4, 0x90
	.type	float_to_str,@function
float_to_str:                           # @float_to_str
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movsd	%xmm0, -24(%rbp)
	movl	$16, -4(%rbp)
	movslq	-4(%rbp), %rdi
	callq	malloc
	movabsq	$.L.str.4, %rdx
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rdi
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rsi
	movsd	-24(%rbp), %xmm0        # xmm0 = mem[0],zero
	movb	$1, %al
	callq	snprintf
	movq	-16(%rbp), %rdi
	movslq	-4(%rbp), %rsi
	callq	string_constructor
	addq	$32, %rsp
	popq	%rbp
	retq
.Lfunc_end13:
	.size	float_to_str, .Lfunc_end13-float_to_str
	.cfi_endproc
                                        # -- End function
	.type	C_INT,@object           # @C_INT
	.bss
	.globl	C_INT
	.p2align	3
C_INT:
	.quad	0                       # 0x0
	.size	C_INT, 8

	.type	.L__unnamed_1,@object   # @0
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_1:
	.asciz	"start"
	.size	.L__unnamed_1, 6

	.type	.L__unnamed_2,@object   # @1
.L__unnamed_2:
	.asciz	"name"
	.size	.L__unnamed_2, 5

	.type	.L__unnamed_3,@object   # @2
.L__unnamed_3:
	.asciz	"aa"
	.size	.L__unnamed_3, 3

	.type	.L__unnamed_4,@object   # @3
.L__unnamed_4:
	.asciz	"name"
	.size	.L__unnamed_4, 5

	.type	.L__unnamed_5,@object   # @4
.L__unnamed_5:
	.asciz	"aaa"
	.size	.L__unnamed_5, 4

	.type	.L.str,@object          # @.str
.L.str:
	.asciz	"\033[31mCRITICAL ERROR:\033[39m failed to realloc at appending element to list"
	.size	.L.str, 73

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"Error: list index out of range"
	.size	.L.str.1, 31

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"%s\n"
	.size	.L.str.2, 4

	.type	.L.str.3,@object        # @.str.3
.L.str.3:
	.asciz	"%lld"
	.size	.L.str.3, 5

	.type	.L.str.4,@object        # @.str.4
.L.str.4:
	.asciz	"%lf"
	.size	.L.str.4, 4


	.ident	"clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final)"
	.section	".note.GNU-stack","",@progbits
