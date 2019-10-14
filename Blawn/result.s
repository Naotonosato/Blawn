	.text
	.file	"Blawn"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%r15
	.cfi_def_cfa_offset 16
	pushq	%r14
	.cfi_def_cfa_offset 24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -32
	.cfi_offset %r14, -24
	.cfi_offset %r15, -16
	movl	$.L__unnamed_1, %edi
	movl	$5, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	print
	xorl	%edi, %edi
	callq	M.2
	movq	%rax, %r14
	movq	%r14, m(%rip)
	xorl	%edi, %edi
	movq	%r14, %rsi
	callq	S.4
	movq	%rax, %r15
	movq	%r15, si(%rip)
	xorl	%edi, %edi
	movq	%r15, %rsi
	callq	Person.6
	movq	%rax, %rbx
	movq	%rbx, p(%rip)
	movq	%rbx, %rdi
	callq	f.8
	movq	%rbx, %rdi
	callq	free
	movq	%r15, %rdi
	callq	free
	movq	%r14, %rdi
	callq	free
	xorl	%eax, %eax
	popq	%rbx
	popq	%r14
	popq	%r15
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.globl	M.2                     # -- Begin function M.2
	.p2align	4, 0x90
	.type	M.2,@function
M.2:                                    # @M.2
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rbx
	.cfi_def_cfa_offset 16
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -16
	movq	%rdi, %rbx
	movq	%rbx, 8(%rsp)
	movq	%rbx, (%rsp)
	movl	$8, %edi
	callq	malloc
	movq	%rbx, (%rax)
	addq	$16, %rsp
	popq	%rbx
	retq
.Lfunc_end1:
	.size	M.2, .Lfunc_end1-M.2
	.cfi_endproc
                                        # -- End function
	.globl	"destructor<M>"         # -- Begin function destructor<M>
	.p2align	4, 0x90
	.type	"destructor<M>",@function
"destructor<M>":                        # @"destructor<M>"
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	callq	free
	popq	%rax
	retq
.Lfunc_end2:
	.size	"destructor<M>", .Lfunc_end2-"destructor<M>"
	.cfi_endproc
                                        # -- End function
	.globl	S.4                     # -- Begin function S.4
	.p2align	4, 0x90
	.type	S.4,@function
S.4:                                    # @S.4
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%r14
	.cfi_def_cfa_offset 16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	subq	$40, %rsp
	.cfi_def_cfa_offset 64
	.cfi_offset %rbx, -24
	.cfi_offset %r14, -16
	movq	%rsi, %r14
	movq	%rdi, %rbx
	movq	%rbx, 32(%rsp)
	movq	%r14, 24(%rsp)
	movq	%rbx, 16(%rsp)
	movq	%r14, 8(%rsp)
	movl	$16, %edi
	callq	malloc
	movq	%rbx, (%rax)
	movq	%r14, 8(%rax)
	addq	$40, %rsp
	popq	%rbx
	popq	%r14
	retq
.Lfunc_end3:
	.size	S.4, .Lfunc_end3-S.4
	.cfi_endproc
                                        # -- End function
	.globl	"destructor<S>"         # -- Begin function destructor<S>
	.p2align	4, 0x90
	.type	"destructor<S>",@function
"destructor<S>":                        # @"destructor<S>"
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	callq	free
	popq	%rax
	retq
.Lfunc_end4:
	.size	"destructor<S>", .Lfunc_end4-"destructor<S>"
	.cfi_endproc
                                        # -- End function
	.globl	Person.6                # -- Begin function Person.6
	.p2align	4, 0x90
	.type	Person.6,@function
Person.6:                               # @Person.6
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%r14
	.cfi_def_cfa_offset 16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	subq	$40, %rsp
	.cfi_def_cfa_offset 64
	.cfi_offset %rbx, -24
	.cfi_offset %r14, -16
	movq	%rsi, %r14
	movq	%rdi, %rbx
	movq	%rbx, 32(%rsp)
	movq	%r14, 24(%rsp)
	movq	%rbx, 16(%rsp)
	movq	%r14, 8(%rsp)
	movl	$16, %edi
	callq	malloc
	movq	%rbx, (%rax)
	movq	%r14, 8(%rax)
	addq	$40, %rsp
	popq	%rbx
	popq	%r14
	retq
.Lfunc_end5:
	.size	Person.6, .Lfunc_end5-Person.6
	.cfi_endproc
                                        # -- End function
	.globl	"destructor<Person>"    # -- Begin function destructor<Person>
	.p2align	4, 0x90
	.type	"destructor<Person>",@function
"destructor<Person>":                   # @"destructor<Person>"
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	callq	free
	popq	%rax
	retq
.Lfunc_end6:
	.size	"destructor<Person>", .Lfunc_end6-"destructor<Person>"
	.cfi_endproc
                                        # -- End function
	.globl	f.8                     # -- Begin function f.8
	.p2align	4, 0x90
	.type	f.8,@function
f.8:                                    # @f.8
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	movq	%rdi, -72(%rbp)
	movl	$10, %edi
	callq	M.2
	movq	%rax, %r14
	movq	%r14, -64(%rbp)
	movl	$10, %edi
	movq	%r14, %rsi
	callq	S.4
	movq	%rax, %r13
	movq	%r13, -56(%rbp)
	movl	$10, %edi
	movq	%r13, %rsi
	callq	Person.6
	movq	%rax, %r15
	movq	%r15, -48(%rbp)
	movb	$1, true(%rip)
	xorl	%eax, %eax
	testb	%al, %al
	jne	.LBB7_2
# %bb.1:                                # %"then of if expr"
	movl	$30, %edi
	callq	M.2
	movq	%rax, %r12
	movq	%rsp, %rax
	leaq	-16(%rax), %rsp
	movq	%r12, -16(%rax)
	movl	$30, %edi
	movq	%r12, %rsi
	callq	S.4
	movq	%rax, %rbx
	movq	%rsp, %rax
	leaq	-16(%rax), %rsp
	movq	%rbx, -16(%rax)
	movl	$30, %edi
	movq	%rbx, %rsi
	callq	Person.6
	movq	%rsp, %rcx
	leaq	-16(%rcx), %rsp
	movq	%rax, -16(%rcx)
	movq	-48(%rbp), %rcx
	movq	(%rax), %r8
	movq	8(%rax), %rsi
	movq	8(%rcx), %rdi
	movq	8(%rdi), %r9
	movq	(%rsi), %rdx
	movq	8(%rsi), %rsi
	movq	(%rsi), %rsi
	movq	%r8, (%rcx)
	movq	%rdx, (%rdi)
	movq	%rsi, (%r9)
	movq	%rax, %rdi
	callq	free
	movq	%rbx, %rdi
	callq	free
	movq	%r12, %rdi
	callq	free
.LBB7_2:                                # %"merge of if_expr"
	movq	-48(%rbp), %rax
	movq	8(%rax), %rax
	movq	8(%rax), %rax
	movq	(%rax), %rdi
	callq	int_to_str
	movq	%rax, %rdi
	callq	print
	movq	%r15, %rdi
	callq	free
	movq	%r13, %rdi
	callq	free
	movq	%r14, %rdi
	callq	free
	leaq	-40(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end7:
	.size	f.8, .Lfunc_end7-f.8
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
.Lfunc_end8:
	.size	list_constructor, .Lfunc_end8-list_constructor
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
	jne	.LBB9_2
# %bb.1:
	movabsq	$.L.str, %rdi
	callq	puts
	movl	$1, %edi
	callq	exit
.LBB9_2:
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	retq
.Lfunc_end9:
	.size	blawn_realloc, .Lfunc_end9-blawn_realloc
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
.Lfunc_end10:
	.size	blawn_memcpy, .Lfunc_end10-blawn_memcpy
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
	jg	.LBB11_3
# %bb.1:
	movq	-8(%rbp), %rax
	cmpq	-24(%rbp), %rax
	jge	.LBB11_3
# %bb.2:
	movq	-32(%rbp), %rax
	movq	-16(%rbp), %rcx
	imulq	-8(%rbp), %rcx
	addq	%rcx, %rax
	addq	$32, %rsp
	popq	%rbp
	retq
.LBB11_3:
	movabsq	$.L.str.1, %rdi
	callq	puts
	movl	$1, %edi
	callq	exit
.Lfunc_end11:
	.size	blawn_index, .Lfunc_end11-blawn_index
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
	jg	.LBB12_3
# %bb.1:
	movq	-8(%rbp), %rax
	cmpq	-32(%rbp), %rax
	jge	.LBB12_3
# %bb.2:
	movq	-16(%rbp), %rax
	movq	-40(%rbp), %rcx
	movq	-24(%rbp), %rdx
	imulq	-8(%rbp), %rdx
	movq	%rax, (%rcx,%rdx)
	jmp	.LBB12_4
.LBB12_3:
	movabsq	$.L.str.1, %rdi
	callq	puts
	movl	$1, %edi
	callq	exit
.LBB12_4:
	addq	$48, %rsp
	popq	%rbp
	retq
.Lfunc_end12:
	.size	blawn_set_element, .Lfunc_end12-blawn_set_element
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
.Lfunc_end13:
	.size	print, .Lfunc_end13-print
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
.Lfunc_end14:
	.size	string_constructor, .Lfunc_end14-string_constructor
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
.Lfunc_end15:
	.size	append_string, .Lfunc_end15-append_string
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
	jl	.LBB16_5
# %bb.1:
	movq	$1, -16(%rbp)
.LBB16_2:                               # =>This Inner Loop Header: Depth=1
	cmpq	$0, -8(%rbp)
	je	.LBB16_4
# %bb.3:                                #   in Loop: Header=BB16_2 Depth=1
	movl	$10, %ecx
	movq	-8(%rbp), %rax
	cqto
	idivq	%rcx
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -16(%rbp)
	jmp	.LBB16_2
.LBB16_4:
	jmp	.LBB16_9
.LBB16_5:
	xorl	%eax, %eax
	movq	$2, -16(%rbp)
	subq	-8(%rbp), %rax
	movq	%rax, -8(%rbp)
.LBB16_6:                               # =>This Inner Loop Header: Depth=1
	cmpq	$0, -8(%rbp)
	je	.LBB16_8
# %bb.7:                                #   in Loop: Header=BB16_6 Depth=1
	movl	$10, %ecx
	movq	-8(%rbp), %rax
	cqto
	idivq	%rcx
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -16(%rbp)
	jmp	.LBB16_6
.LBB16_8:
	jmp	.LBB16_9
.LBB16_9:
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
.Lfunc_end16:
	.size	int_to_str, .Lfunc_end16-int_to_str
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
.Lfunc_end17:
	.size	float_to_str, .Lfunc_end17-float_to_str
	.cfi_endproc
                                        # -- End function
	.type	.L__unnamed_1,@object   # @0
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_1:
	.asciz	"start"
	.size	.L__unnamed_1, 6

	.type	m,@object               # @m
	.bss
	.globl	m
	.p2align	3
m:
	.quad	0
	.size	m, 8

	.type	si,@object              # @si
	.globl	si
	.p2align	3
si:
	.quad	0
	.size	si, 8

	.type	p,@object               # @p
	.globl	p
	.p2align	3
p:
	.quad	0
	.size	p, 8

	.type	true,@object            # @true
	.globl	true
true:
	.byte	0                       # 0x0
	.size	true, 1

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
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
