	.text
	.file	"Blawn"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %"merge of if_expr"
	subq	$40, %rsp
	.cfi_def_cfa_offset 48
	callq	V.2
	movq	%rax, 32(%rsp)
	callq	V.2
	movq	%rax, 8(%rsp)
	movl	$.L__unnamed_1, %edi
	movl	$9, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	print
	movq	32(%rsp), %rdi
	callq	List.4
	movq	%rax, 16(%rsp)
	movq	8(%rsp), %rsi
	movq	%rax, %rdi
	callq	append.6
	movq	16(%rsp), %rdi
	movq	8(%rsp), %rsi
	callq	append.6
	movq	$1, 24(%rsp)
	.p2align	4, 0x90
.LBB0_1:                                # %for
                                        # =>This Inner Loop Header: Depth=1
	movl	$.L__unnamed_2, %edi
	movl	$10, %esi
	callq	string_constructor
	movq	16(%rsp), %rdi
	movq	8(%rsp), %rsi
	callq	append.6
	movq	16(%rsp), %rdi
	movq	8(%rsp), %rsi
	callq	append.6
	movq	24(%rsp), %rax
	cmpq	$10, %rax
	leaq	1(%rax), %rax
	movq	%rax, 24(%rsp)
	jl	.LBB0_1
# %bb.2:                                # %"merge of for"
	xorl	%eax, %eax
	addq	$40, %rsp
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.globl	V.2                     # -- Begin function V.2
	.p2align	4, 0x90
	.type	V.2,@function
V.2:                                    # @V.2
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movq	$0, (%rsp)
	movl	$8, %edi
	callq	malloc
	movq	$0, (%rax)
	popq	%rcx
	retq
.Lfunc_end1:
	.size	V.2, .Lfunc_end1-V.2
	.cfi_endproc
                                        # -- End function
	.globl	destructor_of_V         # -- Begin function destructor_of_V
	.p2align	4, 0x90
	.type	destructor_of_V,@function
destructor_of_V:                        # @destructor_of_V
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	callq	free
	popq	%rax
	retq
.Lfunc_end2:
	.size	destructor_of_V, .Lfunc_end2-destructor_of_V
	.cfi_endproc
                                        # -- End function
	.globl	List.4                  # -- Begin function List.4
	.p2align	4, 0x90
	.type	List.4,@function
List.4:                                 # @List.4
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rbx
	.cfi_def_cfa_offset 16
	subq	$48, %rsp
	.cfi_def_cfa_offset 64
	.cfi_offset %rbx, -16
	movq	$0, 40(%rsp)
	movq	$1, 32(%rsp)
	movq	$8, 24(%rsp)
	leaq	8(%rsp), %rbx
	movq	%rbx, 16(%rsp)
	movl	$32, %edi
	callq	malloc
	movq	$0, (%rax)
	movq	$1, 8(%rax)
	movq	$8, 16(%rax)
	movq	%rbx, 24(%rax)
	addq	$48, %rsp
	popq	%rbx
	retq
.Lfunc_end3:
	.size	List.4, .Lfunc_end3-List.4
	.cfi_endproc
                                        # -- End function
	.globl	destructor_of_List      # -- Begin function destructor_of_List
	.p2align	4, 0x90
	.type	destructor_of_List,@function
destructor_of_List:                     # @destructor_of_List
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	callq	free
	popq	%rax
	retq
.Lfunc_end4:
	.size	destructor_of_List, .Lfunc_end4-destructor_of_List
	.cfi_endproc
                                        # -- End function
	.globl	resize.5                # -- Begin function resize.5
	.p2align	4, 0x90
	.type	resize.5,@function
resize.5:                               # @resize.5
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset %rbx, -16
	movq	%rdi, %rbx
	movl	$.L__unnamed_3, %edi
	movl	$8, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	print
	movq	8(%rbx), %rdx
	movq	16(%rbx), %rsi
	addq	%rdx, %rdx
	movq	%rdx, 8(%rbx)
	movq	24(%rbx), %rdi
	callq	blawn_realloc
	movq	%rax, 24(%rbx)
	popq	%rbx
	retq
.Lfunc_end5:
	.size	resize.5, .Lfunc_end5-resize.5
	.cfi_endproc
                                        # -- End function
	.globl	append.6                # -- Begin function append.6
	.p2align	4, 0x90
	.type	append.6,@function
append.6:                               # @append.6
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%r14
	.cfi_def_cfa_offset 16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	pushq	%rax
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -24
	.cfi_offset %r14, -16
	movq	%rsi, %r14
	movq	%rdi, %rbx
	movq	(%rbx), %rax
	incq	%rax
	cmpq	8(%rbx), %rax
	jl	.LBB6_2
# %bb.1:                                # %"then of if expr"
	movl	$.L__unnamed_4, %edi
	movl	$7, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	print
	movq	%rbx, %rdi
	callq	resize.5
	movl	$.L__unnamed_5, %edi
	movl	$7, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	print
.LBB6_2:                                # %"merge of if_expr"
	movl	$.L__unnamed_6, %edi
	movl	$8, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	print
	movq	24(%rbx), %rdi
	movq	(%rbx), %rsi
	movq	16(%rbx), %rdx
	movq	%r14, %rcx
	callq	blawn_memcpy
	movl	$.L__unnamed_7, %edi
	movl	$7, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	print
	incq	(%rbx)
	addq	$8, %rsp
	popq	%rbx
	popq	%r14
	retq
.Lfunc_end6:
	.size	append.6, .Lfunc_end6-append.6
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
.Lfunc_end7:
	.size	list_constructor, .Lfunc_end7-list_constructor
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
	jne	.LBB8_2
# %bb.1:
	movabsq	$.L.str, %rdi
	callq	puts
	movl	$1, %edi
	callq	exit
.LBB8_2:
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	retq
.Lfunc_end8:
	.size	blawn_realloc, .Lfunc_end8-blawn_realloc
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
.Lfunc_end9:
	.size	blawn_memcpy, .Lfunc_end9-blawn_memcpy
	.cfi_endproc
                                        # -- End function
	.globl	get_element             # -- Begin function get_element
	.p2align	4, 0x90
	.type	get_element,@function
get_element:                            # @get_element
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	xorl	%eax, %eax
	movq	%rdi, -16(%rbp)
	movq	%rsi, -8(%rbp)
	cmpq	-8(%rbp), %rax
	jg	.LBB10_3
# %bb.1:
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rcx
	cmpq	(%rcx), %rax
	jge	.LBB10_3
# %bb.2:
	movq	-16(%rbp), %rax
	movq	24(%rax), %rax
	movq	-16(%rbp), %rcx
	movq	16(%rcx), %rcx
	imulq	-8(%rbp), %rcx
	addq	%rcx, %rax
	addq	$16, %rsp
	popq	%rbp
	retq
.LBB10_3:
	movabsq	$.L.str.1, %rdi
	callq	puts
	movl	$1, %edi
	callq	exit
.Lfunc_end10:
	.size	get_element, .Lfunc_end10-get_element
	.cfi_endproc
                                        # -- End function
	.globl	set_element             # -- Begin function set_element
	.p2align	4, 0x90
	.type	set_element,@function
set_element:                            # @set_element
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	xorl	%eax, %eax
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -8(%rbp)
	cmpq	-8(%rbp), %rax
	jg	.LBB11_3
# %bb.1:
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rcx
	cmpq	(%rcx), %rax
	jge	.LBB11_3
# %bb.2:
	movq	-24(%rbp), %rax
	movq	-16(%rbp), %rcx
	movq	24(%rcx), %rcx
	movq	-16(%rbp), %rdx
	movq	16(%rdx), %rdx
	imulq	-8(%rbp), %rdx
	movb	%al, (%rcx,%rdx)
	jmp	.LBB11_4
.LBB11_3:
	movabsq	$.L.str.1, %rdi
	callq	puts
	movl	$1, %edi
	callq	exit
.LBB11_4:
	addq	$32, %rsp
	popq	%rbp
	retq
.Lfunc_end11:
	.size	set_element, .Lfunc_end11-set_element
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
.Lfunc_end12:
	.size	print, .Lfunc_end12-print
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
.Lfunc_end13:
	.size	string_constructor, .Lfunc_end13-string_constructor
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
.Lfunc_end14:
	.size	append_string, .Lfunc_end14-append_string
	.cfi_endproc
                                        # -- End function
	.globl	main_                   # -- Begin function main_
	.p2align	4, 0x90
	.type	main_,@function
main_:                                  # @main_
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	-4(%rbp), %eax
	popq	%rbp
	retq
.Lfunc_end15:
	.size	main_, .Lfunc_end15-main_
	.cfi_endproc
                                        # -- End function
	.type	.L__unnamed_1,@object   # @0
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_1:
	.asciz	"same size"
	.size	.L__unnamed_1, 10

	.type	.L__unnamed_4,@object   # @1
.L__unnamed_4:
	.asciz	"resize."
	.size	.L__unnamed_4, 8

	.type	.L__unnamed_3,@object   # @2
.L__unnamed_3:
	.asciz	"resizing"
	.size	.L__unnamed_3, 9

	.type	.L__unnamed_5,@object   # @3
.L__unnamed_5:
	.asciz	"resized"
	.size	.L__unnamed_5, 8

	.type	.L__unnamed_6,@object   # @4
.L__unnamed_6:
	.asciz	"succeed?"
	.size	.L__unnamed_6, 9

	.type	.L__unnamed_7,@object   # @5
.L__unnamed_7:
	.asciz	"succeed"
	.size	.L__unnamed_7, 8

	.type	.L__unnamed_2,@object   # @6
.L__unnamed_2:
	.asciz	"print(\"a\")"
	.size	.L__unnamed_2, 11

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


	.ident	"clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final)"
	.section	".note.GNU-stack","",@progbits
