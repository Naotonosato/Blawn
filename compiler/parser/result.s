	.text
	.file	"Blawn"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$.L__unnamed_1, %edi
	movl	$4, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	Person.2
	movq	%rax, -24(%rbp)
	movl	$.L__unnamed_2, %edi
	movl	$4, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	Person.2
	movq	%rax, -32(%rbp)
	movq	-24(%rbp), %rdi
	callq	List.4
	movq	%rax, -8(%rbp)
	movq	$1, -16(%rbp)
	.p2align	4, 0x90
.LBB0_1:                                # %for
                                        # =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rdi
	movq	-24(%rbp), %rsi
	callq	append.6
	movq	-16(%rbp), %rax
	cmpq	$100, %rax
	leaq	1(%rax), %rax
	movq	%rax, -16(%rbp)
	jl	.LBB0_1
# %bb.2:                                # %"merge of for"
	movq	-8(%rbp), %rdi
	movq	-32(%rbp), %rsi
	movl	$20, %edx
	callq	set.7
	movq	-8(%rbp), %rdi
	movl	$20, %esi
	callq	get.8
	movq	(%rax), %rdi
	movq	%rsp, %rax
	leaq	-16(%rax), %rsp
	movq	%rdi, -16(%rax)
	callq	print
	xorl	%eax, %eax
	movq	%rbp, %rsp
	popq	%rbp
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.globl	Person.2                # -- Begin function Person.2
	.p2align	4, 0x90
	.type	Person.2,@function
Person.2:                               # @Person.2
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
	.size	Person.2, .Lfunc_end1-Person.2
	.cfi_endproc
                                        # -- End function
	.globl	destructor_of_Person    # -- Begin function destructor_of_Person
	.p2align	4, 0x90
	.type	destructor_of_Person,@function
destructor_of_Person:                   # @destructor_of_Person
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	callq	free
	popq	%rax
	retq
.Lfunc_end2:
	.size	destructor_of_Person, .Lfunc_end2-destructor_of_Person
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
	movq	%rdi, %rbx
	movq	$0, 40(%rsp)
	movq	$1, 32(%rsp)
	movq	%rbx, 24(%rsp)
	movq	$8, 16(%rsp)
	movq	$1, 8(%rsp)
	movq	$0, (%rsp)
	movl	$48, %edi
	callq	malloc
	movq	$0, (%rax)
	movq	$1, 8(%rax)
	movq	%rbx, 16(%rax)
	movq	$8, 24(%rax)
	movq	$1, 32(%rax)
	movq	$0, 40(%rax)
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
	movq	8(%rbx), %rdx
	movq	24(%rbx), %rsi
	addq	%rdx, %rdx
	movq	%rdx, 8(%rbx)
	movq	40(%rbx), %rdi
	callq	blawn_realloc
	movq	%rax, 40(%rbx)
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
	cmpq	$1, 32(%rbx)
	je	.LBB6_2
# %bb.1:                                # %"then of if expr"
	movl	$.L__unnamed_3, %edi
	movl	$43, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	print
.LBB6_2:                                # %"merge of if_expr"
	movq	(%rbx), %rax
	incq	%rax
	cmpq	8(%rbx), %rax
	jl	.LBB6_4
# %bb.3:                                # %"then of if expr1"
	movq	%rbx, %rdi
	callq	resize.5
.LBB6_4:                                # %"merge of if_expr3"
	movq	40(%rbx), %rdi
	movq	(%rbx), %rsi
	movq	24(%rbx), %rdx
	movq	%r14, %rcx
	callq	blawn_memcpy
	incq	(%rbx)
	addq	$8, %rsp
	popq	%rbx
	popq	%r14
	retq
.Lfunc_end6:
	.size	append.6, .Lfunc_end6-append.6
	.cfi_endproc
                                        # -- End function
	.globl	set.7                   # -- Begin function set.7
	.p2align	4, 0x90
	.type	set.7,@function
set.7:                                  # @set.7
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movq	%rdx, %r8
	movq	%rsi, %rcx
	movq	40(%rdi), %rax
	movq	(%rdi), %rsi
	movq	24(%rdi), %rdx
	movq	%rax, %rdi
	callq	blawn_set_element
	popq	%rax
	retq
.Lfunc_end7:
	.size	set.7, .Lfunc_end7-set.7
	.cfi_endproc
                                        # -- End function
	.globl	get.8                   # -- Begin function get.8
	.p2align	4, 0x90
	.type	get.8,@function
get.8:                                  # @get.8
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r14
	pushq	%rbx
	.cfi_offset %rbx, -32
	.cfi_offset %r14, -24
	movq	%rsi, %r14
	movq	%rdi, %rbx
	cmpq	$0, (%rbx)
	jne	.LBB8_2
# %bb.1:                                # %"then of if expr"
	movl	$.L__unnamed_4, %edi
	movl	$3, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	print
.LBB8_2:                                # %"merge of if_expr"
	movq	40(%rbx), %rdi
	movq	(%rbx), %rsi
	movq	24(%rbx), %rdx
	movq	%r14, %rcx
	callq	blawn_index
	movq	%rsp, %rcx
	leaq	-16(%rcx), %rsp
	movq	%rax, -16(%rcx)
	movq	(%rax), %rax
	movq	%rsp, %rcx
	leaq	-16(%rcx), %rsp
	movq	%rax, -16(%rcx)
	leaq	-16(%rbp), %rsp
	popq	%rbx
	popq	%r14
	popq	%rbp
	retq
.Lfunc_end8:
	.size	get.8, .Lfunc_end8-get.8
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
.Lfunc_end9:
	.size	list_constructor, .Lfunc_end9-list_constructor
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
	jne	.LBB10_2
# %bb.1:
	movabsq	$.L.str, %rdi
	callq	puts
	movl	$1, %edi
	callq	exit
.LBB10_2:
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	retq
.Lfunc_end10:
	.size	blawn_realloc, .Lfunc_end10-blawn_realloc
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
.Lfunc_end11:
	.size	blawn_memcpy, .Lfunc_end11-blawn_memcpy
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
	jg	.LBB12_3
# %bb.1:
	movq	-8(%rbp), %rax
	cmpq	-24(%rbp), %rax
	jge	.LBB12_3
# %bb.2:
	movq	-32(%rbp), %rax
	movq	-16(%rbp), %rcx
	imulq	-8(%rbp), %rcx
	addq	%rcx, %rax
	addq	$32, %rsp
	popq	%rbp
	retq
.LBB12_3:
	movabsq	$.L.str.1, %rdi
	callq	puts
	movl	$1, %edi
	callq	exit
.Lfunc_end12:
	.size	blawn_index, .Lfunc_end12-blawn_index
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
	jg	.LBB13_3
# %bb.1:
	movq	-8(%rbp), %rax
	cmpq	-32(%rbp), %rax
	jge	.LBB13_3
# %bb.2:
	movq	-16(%rbp), %rax
	movq	-40(%rbp), %rcx
	movq	-24(%rbp), %rdx
	imulq	-8(%rbp), %rdx
	movq	%rax, (%rcx,%rdx)
	jmp	.LBB13_4
.LBB13_3:
	movabsq	$.L.str.1, %rdi
	callq	puts
	movl	$1, %edi
	callq	exit
.LBB13_4:
	addq	$48, %rsp
	popq	%rbp
	retq
.Lfunc_end13:
	.size	blawn_set_element, .Lfunc_end13-blawn_set_element
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
.Lfunc_end14:
	.size	print, .Lfunc_end14-print
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
.Lfunc_end15:
	.size	string_constructor, .Lfunc_end15-string_constructor
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
.Lfunc_end16:
	.size	append_string, .Lfunc_end16-append_string
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
	jl	.LBB17_5
# %bb.1:
	movq	$0, -16(%rbp)
.LBB17_2:                               # =>This Inner Loop Header: Depth=1
	cmpq	$0, -8(%rbp)
	je	.LBB17_4
# %bb.3:                                #   in Loop: Header=BB17_2 Depth=1
	movl	$10, %ecx
	movq	-8(%rbp), %rax
	cqto
	idivq	%rcx
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -16(%rbp)
	jmp	.LBB17_2
.LBB17_4:
	jmp	.LBB17_9
.LBB17_5:
	xorl	%eax, %eax
	movq	$1, -16(%rbp)
	subq	-8(%rbp), %rax
	movq	%rax, -8(%rbp)
.LBB17_6:                               # =>This Inner Loop Header: Depth=1
	cmpq	$0, -8(%rbp)
	je	.LBB17_8
# %bb.7:                                #   in Loop: Header=BB17_6 Depth=1
	movl	$10, %ecx
	movq	-8(%rbp), %rax
	cqto
	idivq	%rcx
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -16(%rbp)
	jmp	.LBB17_6
.LBB17_8:
	jmp	.LBB17_9
.LBB17_9:
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
.Lfunc_end17:
	.size	int_to_str, .Lfunc_end17-int_to_str
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
.Lfunc_end18:
	.size	float_to_str, .Lfunc_end18-float_to_str
	.cfi_endproc
                                        # -- End function
	.type	.L__unnamed_1,@object   # @0
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_1:
	.asciz	"John"
	.size	.L__unnamed_1, 5

	.type	.L__unnamed_2,@object   # @1
.L__unnamed_2:
	.asciz	"Tom!"
	.size	.L__unnamed_2, 5

	.type	.L__unnamed_3,@object   # @2
	.section	.rodata.str1.16,"aMS",@progbits,1
	.p2align	4
.L__unnamed_3:
	.asciz	"Error: append invalid type element to list."
	.size	.L__unnamed_3, 44

	.type	.L__unnamed_4,@object   # @3
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_4:
	.asciz	"err"
	.size	.L__unnamed_4, 4

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
