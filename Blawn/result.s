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
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$136, %rsp
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	movw	$0, -46(%rbp)
	movq	$0, -152(%rbp)
	movw	$0, -44(%rbp)
	movw	$0, -42(%rbp)
	movzwl	-144(%rbp), %eax
	movq	-136(%rbp), %rcx
	movq	%rcx, -120(%rbp)
	movw	%ax, -128(%rbp)
	callq	TestClass.5
	movq	%rax, -72(%rbp)         # 8-byte Spill
	movq	%rax, -88(%rbp)
	callq	NestStruct.7
	movq	%rax, -64(%rbp)         # 8-byte Spill
	movq	%rax, -112(%rbp)
	movq	-88(%rbp), %rax
	movq	(%rax), %rax
	movq	(%rax), %rdi
	callq	int_to_str
	movq	%rax, %rdi
	callq	print
	callq	ct.9
	movq	%rax, %r13
	movq	%r13, -104(%rbp)
	movq	8(%r13), %rdi
	callq	int_to_str
	movq	%rax, %rdi
	callq	print
	movl	$.L__unnamed_1, %edi
	movl	$4, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	Person.11
	movq	%rax, %r12
	movq	%r12, -80(%rbp)
	movl	$.L__unnamed_2, %edi
	movl	$4, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	Person.11
	movq	%rax, %rbx
	movq	%rbx, -96(%rbp)
	movq	$1, -56(%rbp)
	.p2align	4, 0x90
.LBB0_1:                                # %for
                                        # =>This Inner Loop Header: Depth=1
	movl	$.L__unnamed_3, %edi
	movl	$6, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	Person.11
	movq	%rax, %r14
	movq	%rsp, %rax
	leaq	-16(%rax), %rsp
	movq	%r14, -16(%rax)
	movq	%r14, %rdi
	callq	free
	movq	-56(%rbp), %rax
	cmpq	$100, %rax
	leaq	1(%rax), %rax
	movq	%rax, -56(%rbp)
	jl	.LBB0_1
# %bb.2:                                # %"merge of for"
	xorl	%r15d, %r15d
	movl	$.L__unnamed_4, %edi
	xorl	%esi, %esi
	callq	string_constructor
	movq	%rsp, %rcx
	leaq	-16(%rcx), %rsp
	movq	%rax, -16(%rcx)
	movq	%rax, %rdi
	callq	print
	movl	$.L__unnamed_5, %edi
	movl	$9, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	print
	movq	$0, pass(%rip)
	.p2align	4, 0x90
.LBB0_3:                                # %for3
                                        # =>This Inner Loop Header: Depth=1
	movl	$.L__unnamed_6, %edi
	movl	$1, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	print
	movq	%r14, %rdi
	callq	free
	movb	$0, false(%rip)
	testb	%r15b, %r15b
	jne	.LBB0_3
# %bb.4:                                # %"merge of for4"
	movq	-80(%rbp), %rdi
	callq	f.13
	movq	%rbx, %rdi
	callq	free
	movq	%r12, %rdi
	callq	free
	movq	%r13, %rdi
	callq	free
	movq	-64(%rbp), %rdi         # 8-byte Reload
	callq	free
	movq	-72(%rbp), %rdi         # 8-byte Reload
	callq	free
	xorl	%eax, %eax
	leaq	-40(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.globl	T1.4                    # -- Begin function T1.4
	.p2align	4, 0x90
	.type	T1.4,@function
T1.4:                                   # @T1.4
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
	.size	T1.4, .Lfunc_end1-T1.4
	.cfi_endproc
                                        # -- End function
	.globl	"destructor<T1>"        # -- Begin function destructor<T1>
	.p2align	4, 0x90
	.type	"destructor<T1>",@function
"destructor<T1>":                       # @"destructor<T1>"
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	callq	free
	popq	%rax
	retq
.Lfunc_end2:
	.size	"destructor<T1>", .Lfunc_end2-"destructor<T1>"
	.cfi_endproc
                                        # -- End function
	.globl	TestClass.5             # -- Begin function TestClass.5
	.p2align	4, 0x90
	.type	TestClass.5,@function
TestClass.5:                            # @TestClass.5
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rbx
	.cfi_def_cfa_offset 16
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -16
	callq	T1.4
	movq	%rax, %rbx
	movq	%rbx, 8(%rsp)
	movl	$8, %edi
	callq	malloc
	movq	%rbx, (%rax)
	addq	$16, %rsp
	popq	%rbx
	retq
.Lfunc_end3:
	.size	TestClass.5, .Lfunc_end3-TestClass.5
	.cfi_endproc
                                        # -- End function
	.globl	"destructor<TestClass>" # -- Begin function destructor<TestClass>
	.p2align	4, 0x90
	.type	"destructor<TestClass>",@function
"destructor<TestClass>":                # @"destructor<TestClass>"
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	callq	free
	popq	%rax
	retq
.Lfunc_end4:
	.size	"destructor<TestClass>", .Lfunc_end4-"destructor<TestClass>"
	.cfi_endproc
                                        # -- End function
	.globl	NestStruct.7            # -- Begin function NestStruct.7
	.p2align	4, 0x90
	.type	NestStruct.7,@function
NestStruct.7:                           # @NestStruct.7
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	subq	$40, %rsp
	.cfi_def_cfa_offset 64
	.cfi_offset %rbx, -24
	.cfi_offset %rbp, -16
	movw	$0, 6(%rsp)
	movw	$0, 4(%rsp)
	movzwl	24(%rsp), %ebp
	movq	32(%rsp), %rbx
	movq	%rbx, 16(%rsp)
	movw	%bp, 8(%rsp)
	movl	$16, %edi
	callq	malloc
	movl	$0, (%rax)
	movq	%rbx, 16(%rax)
	movw	%bp, 8(%rax)
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	retq
.Lfunc_end5:
	.size	NestStruct.7, .Lfunc_end5-NestStruct.7
	.cfi_endproc
                                        # -- End function
	.globl	"destructor<NestStruct>" # -- Begin function destructor<NestStruct>
	.p2align	4, 0x90
	.type	"destructor<NestStruct>",@function
"destructor<NestStruct>":               # @"destructor<NestStruct>"
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	callq	free
	popq	%rax
	retq
.Lfunc_end6:
	.size	"destructor<NestStruct>", .Lfunc_end6-"destructor<NestStruct>"
	.cfi_endproc
                                        # -- End function
	.globl	ct.9                    # -- Begin function ct.9
	.p2align	4, 0x90
	.type	ct.9,@function
ct.9:                                   # @ct.9
	.cfi_startproc
# %bb.0:                                # %entry
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movq	$0, 16(%rsp)
	movq	$0, 8(%rsp)
	movl	$16, %edi
	callq	malloc
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	addq	$24, %rsp
	retq
.Lfunc_end7:
	.size	ct.9, .Lfunc_end7-ct.9
	.cfi_endproc
                                        # -- End function
	.globl	"destructor<ct>"        # -- Begin function destructor<ct>
	.p2align	4, 0x90
	.type	"destructor<ct>",@function
"destructor<ct>":                       # @"destructor<ct>"
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	callq	free
	popq	%rax
	retq
.Lfunc_end8:
	.size	"destructor<ct>", .Lfunc_end8-"destructor<ct>"
	.cfi_endproc
                                        # -- End function
	.globl	Person.11               # -- Begin function Person.11
	.p2align	4, 0x90
	.type	Person.11,@function
Person.11:                              # @Person.11
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
.Lfunc_end9:
	.size	Person.11, .Lfunc_end9-Person.11
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
.Lfunc_end10:
	.size	"destructor<Person>", .Lfunc_end10-"destructor<Person>"
	.cfi_endproc
                                        # -- End function
	.globl	f.13                    # -- Begin function f.13
	.p2align	4, 0x90
	.type	f.13,@function
f.13:                                   # @f.13
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movq	(%rdi), %rdi
	callq	print
	popq	%rax
	retq
.Lfunc_end11:
	.size	f.13, .Lfunc_end11-f.13
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
.Lfunc_end12:
	.size	list_constructor, .Lfunc_end12-list_constructor
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
	jne	.LBB13_2
# %bb.1:
	movabsq	$.L.str, %rdi
	callq	puts
	movl	$1, %edi
	callq	exit
.LBB13_2:
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	retq
.Lfunc_end13:
	.size	blawn_realloc, .Lfunc_end13-blawn_realloc
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
.Lfunc_end14:
	.size	blawn_memcpy, .Lfunc_end14-blawn_memcpy
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
	jg	.LBB15_3
# %bb.1:
	movq	-8(%rbp), %rax
	cmpq	-24(%rbp), %rax
	jge	.LBB15_3
# %bb.2:
	movq	-32(%rbp), %rax
	movq	-16(%rbp), %rcx
	imulq	-8(%rbp), %rcx
	addq	%rcx, %rax
	addq	$32, %rsp
	popq	%rbp
	retq
.LBB15_3:
	movabsq	$.L.str.1, %rdi
	callq	puts
	movl	$1, %edi
	callq	exit
.Lfunc_end15:
	.size	blawn_index, .Lfunc_end15-blawn_index
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
	jg	.LBB16_3
# %bb.1:
	movq	-8(%rbp), %rax
	cmpq	-32(%rbp), %rax
	jge	.LBB16_3
# %bb.2:
	movq	-16(%rbp), %rax
	movq	-40(%rbp), %rcx
	movq	-24(%rbp), %rdx
	imulq	-8(%rbp), %rdx
	movq	%rax, (%rcx,%rdx)
	jmp	.LBB16_4
.LBB16_3:
	movabsq	$.L.str.1, %rdi
	callq	puts
	movl	$1, %edi
	callq	exit
.LBB16_4:
	addq	$48, %rsp
	popq	%rbp
	retq
.Lfunc_end16:
	.size	blawn_set_element, .Lfunc_end16-blawn_set_element
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
.Lfunc_end17:
	.size	print, .Lfunc_end17-print
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
.Lfunc_end18:
	.size	string_constructor, .Lfunc_end18-string_constructor
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
.Lfunc_end19:
	.size	append_string, .Lfunc_end19-append_string
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
	jl	.LBB20_5
# %bb.1:
	movq	$1, -16(%rbp)
.LBB20_2:                               # =>This Inner Loop Header: Depth=1
	cmpq	$0, -8(%rbp)
	je	.LBB20_4
# %bb.3:                                #   in Loop: Header=BB20_2 Depth=1
	movl	$10, %ecx
	movq	-8(%rbp), %rax
	cqto
	idivq	%rcx
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -16(%rbp)
	jmp	.LBB20_2
.LBB20_4:
	jmp	.LBB20_9
.LBB20_5:
	xorl	%eax, %eax
	movq	$2, -16(%rbp)
	subq	-8(%rbp), %rax
	movq	%rax, -8(%rbp)
.LBB20_6:                               # =>This Inner Loop Header: Depth=1
	cmpq	$0, -8(%rbp)
	je	.LBB20_8
# %bb.7:                                #   in Loop: Header=BB20_6 Depth=1
	movl	$10, %ecx
	movq	-8(%rbp), %rax
	cqto
	idivq	%rcx
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -16(%rbp)
	jmp	.LBB20_6
.LBB20_8:
	jmp	.LBB20_9
.LBB20_9:
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
.Lfunc_end20:
	.size	int_to_str, .Lfunc_end20-int_to_str
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
.Lfunc_end21:
	.size	float_to_str, .Lfunc_end21-float_to_str
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
.L__unnamed_3:
	.asciz	"person"
	.size	.L__unnamed_3, 7

	.type	.L__unnamed_4,@object   # @3
.L__unnamed_4:
	.zero	1
	.size	.L__unnamed_4, 1

	.type	.L__unnamed_5,@object   # @4
.L__unnamed_5:
	.asciz	"succeed!!"
	.size	.L__unnamed_5, 10

	.type	pass,@object            # @pass
	.bss
	.globl	pass
	.p2align	3
pass:
	.quad	0                       # 0x0
	.size	pass, 8

	.type	.L__unnamed_6,@object   # @5
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_6:
	.asciz	"a"
	.size	.L__unnamed_6, 2

	.type	false,@object           # @false
	.bss
	.globl	false
false:
	.byte	0                       # 0x0
	.size	false, 1

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
