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
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%r15
	.cfi_def_cfa_offset 24
	pushq	%r14
	.cfi_def_cfa_offset 32
	pushq	%r12
	.cfi_def_cfa_offset 40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	subq	$1600, %rsp             # imm = 0x640
	.cfi_def_cfa_offset 1648
	.cfi_offset %rbx, -48
	.cfi_offset %r12, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	.cfi_offset %rbp, -16
	movq	$0, 1424(%rsp)
	movq	$0, 1416(%rsp)
	movq	$0, 1408(%rsp)
	movq	$0, 1400(%rsp)
	movq	$0, 1392(%rsp)
	movq	$0, 1384(%rsp)
	movq	$0, 1376(%rsp)
	movq	$0, 1368(%rsp)
	movq	$0, 1360(%rsp)
	movq	$0, 1352(%rsp)
	movq	$0, 1344(%rsp)
	movq	$0, 1336(%rsp)
	movq	$0, 1328(%rsp)
	movq	$0, 1320(%rsp)
	movq	$0, 1312(%rsp)
	movq	$0, 1304(%rsp)
	movq	$0, 1296(%rsp)
	movq	$0, 1288(%rsp)
	movq	$0, 1280(%rsp)
	movq	$0, 1272(%rsp)
	movq	$0, 1264(%rsp)
	movq	$0, 1256(%rsp)
	movq	$0, 1248(%rsp)
	movq	$0, 1240(%rsp)
	movq	$0, 1232(%rsp)
	movq	$0, 1224(%rsp)
	movq	$0, 1216(%rsp)
	movq	$0, 1208(%rsp)
	movq	$0, 1200(%rsp)
	movq	$0, 1192(%rsp)
	movq	$0, 1184(%rsp)
	movq	$0, 1176(%rsp)
	movq	$0, 1168(%rsp)
	movq	$0, 1160(%rsp)
	movq	$0, 1152(%rsp)
	movq	$0, 1144(%rsp)
	movb	$0, 23(%rsp)
	movq	$0, 1136(%rsp)
	movl	$0, 340(%rsp)
	movl	$0, 336(%rsp)
	movq	1128(%rsp), %rax
	movq	%rax, 1120(%rsp)
	movq	$0, 1112(%rsp)
	movq	$0, 1104(%rsp)
	movq	$0, 1096(%rsp)
	movl	$0, 332(%rsp)
	movl	$0, 328(%rsp)
	movl	$0, 324(%rsp)
	movq	$0, 1088(%rsp)
	movw	$0, 108(%rsp)
	movl	$0, 104(%rsp)
	movw	$0, 100(%rsp)
	movl	$0, 96(%rsp)
	movw	$0, 38(%rsp)
	movw	$0, 36(%rsp)
	movq	$0, 1080(%rsp)
	movl	$0, 320(%rsp)
	movl	$0, 316(%rsp)
	movq	$0, 1072(%rsp)
	movq	$0, 1064(%rsp)
	movq	$0, 1056(%rsp)
	movq	$0, 1048(%rsp)
	movq	$0, 1040(%rsp)
	movq	$0, 1032(%rsp)
	movq	$0, 1024(%rsp)
	movq	$0, 1016(%rsp)
	movq	$0, 1008(%rsp)
	movq	$0, 1000(%rsp)
	movq	$0, 992(%rsp)
	movq	$0, 984(%rsp)
	movq	$0, 976(%rsp)
	movq	$0, 968(%rsp)
	movq	$0, 960(%rsp)
	movq	$0, 952(%rsp)
	movq	$0, 944(%rsp)
	movq	$0, 936(%rsp)
	movq	$0, 928(%rsp)
	movq	$0, 920(%rsp)
	movq	$0, 904(%rsp)
	movq	$0, 896(%rsp)
	movq	$0, 888(%rsp)
	movq	$0, 880(%rsp)
	movq	$0, 912(%rsp)
	movq	$0, 872(%rsp)
	movq	$0, 864(%rsp)
	movq	$0, 856(%rsp)
	movq	$0, 848(%rsp)
	movq	$0, 840(%rsp)
	movq	$0, 832(%rsp)
	movq	$0, 824(%rsp)
	movq	$0, 816(%rsp)
	movq	$0, 808(%rsp)
	movq	$0, 800(%rsp)
	movl	$0, 312(%rsp)
	movl	$0, 308(%rsp)
	movq	$0, 792(%rsp)
	movq	$0, 784(%rsp)
	movl	$0, 304(%rsp)
	movq	$0, 776(%rsp)
	movq	$0, 768(%rsp)
	movl	$0, 300(%rsp)
	movb	$0, 22(%rsp)
	movl	$0, 296(%rsp)
	movw	$0, 34(%rsp)
	movb	$0, 21(%rsp)
	movb	$0, 20(%rsp)
	movw	$0, 32(%rsp)
	movw	$0, 30(%rsp)
	movl	$0, 292(%rsp)
	movq	$0, 760(%rsp)
	movq	$0, 752(%rsp)
	movl	$0, 288(%rsp)
	movw	$0, 28(%rsp)
	movw	$0, 26(%rsp)
	movq	$0, 744(%rsp)
	movq	$0, 736(%rsp)
	movl	$0, 284(%rsp)
	movl	$0, 280(%rsp)
	movl	$0, 276(%rsp)
	movq	$0, 728(%rsp)
	movq	$0, 720(%rsp)
	movq	$0, 712(%rsp)
	movq	$0, 704(%rsp)
	movq	$0, 696(%rsp)
	movq	$0, 688(%rsp)
	movq	$0, 680(%rsp)
	movq	$0, 672(%rsp)
	movq	$0, 664(%rsp)
	movq	$0, 656(%rsp)
	movq	$0, 648(%rsp)
	movl	$0, 272(%rsp)
	movl	$0, 268(%rsp)
	movl	$0, 264(%rsp)
	movb	$0, 19(%rsp)
	movb	$0, 18(%rsp)
	movb	$0, 17(%rsp)
	movb	$0, 16(%rsp)
	movq	$0, 640(%rsp)
	movl	$0, 260(%rsp)
	movl	$0, 256(%rsp)
	movq	$0, 632(%rsp)
	movb	$0, 15(%rsp)
	movb	$0, 14(%rsp)
	movw	$0, 24(%rsp)
	movl	$0, 252(%rsp)
	movl	$0, 248(%rsp)
	movl	$0, 244(%rsp)
	movl	$0, 240(%rsp)
	movb	$0, 13(%rsp)
	movb	$0, 12(%rsp)
	movb	$0, 11(%rsp)
	movb	$0, 10(%rsp)
	movb	$0, 9(%rsp)
	movb	$0, 8(%rsp)
	movb	$0, 7(%rsp)
	movb	$0, 6(%rsp)
	movl	$0, 236(%rsp)
	movq	$0, 624(%rsp)
	movl	$0, 232(%rsp)
	movl	$0, 228(%rsp)
	movl	$0, 224(%rsp)
	movl	$0, 220(%rsp)
	movl	$0, 216(%rsp)
	movl	$0, 212(%rsp)
	movl	$0, 208(%rsp)
	movq	$0, 616(%rsp)
	movl	$0, 204(%rsp)
	movl	$0, 200(%rsp)
	movl	$0, 196(%rsp)
	movq	$0, 608(%rsp)
	movq	$0, 600(%rsp)
	movl	$0, 192(%rsp)
	movq	$0, 592(%rsp)
	movq	576(%rsp), %rax
	movq	584(%rsp), %rcx
	movq	%rcx, 568(%rsp)
	movq	%rax, 560(%rsp)
	movq	$0, 552(%rsp)
	movl	$0, 188(%rsp)
	movl	$0, 184(%rsp)
	movl	$0, 180(%rsp)
	movl	$0, 176(%rsp)
	movl	$0, 172(%rsp)
	movq	$0, 544(%rsp)
	movq	$0, 536(%rsp)
	movq	$0, 528(%rsp)
	movl	$0, 168(%rsp)
	movq	$0, 520(%rsp)
	movq	$0, 512(%rsp)
	movq	$0, 504(%rsp)
	movq	$0, 496(%rsp)
	movq	$0, 488(%rsp)
	movl	$0, 164(%rsp)
	movq	$0, 480(%rsp)
	movq	$0, 472(%rsp)
	movq	$0, 464(%rsp)
	movl	$0, 160(%rsp)
	movl	$0, 156(%rsp)
	movl	$0, 152(%rsp)
	movq	$0, 456(%rsp)
	movq	$0, 448(%rsp)
	movb	$0, 94(%rsp)
	movw	$0, 92(%rsp)
	movl	$0, 88(%rsp)
	movq	$0, 80(%rsp)
	movq	$0, 440(%rsp)
	movq	$0, 432(%rsp)
	movl	$0, 148(%rsp)
	movl	$0, 144(%rsp)
	movq	$0, 424(%rsp)
	movq	$0, 416(%rsp)
	movq	$0, 408(%rsp)
	movq	$0, 400(%rsp)
	movq	$0, 392(%rsp)
	movq	$0, 384(%rsp)
	movq	$0, 376(%rsp)
	movq	$0, 368(%rsp)
	movl	$0, 140(%rsp)
	movl	$0, 136(%rsp)
	movl	$0, 132(%rsp)
	movb	$0, 5(%rsp)
	movl	72(%rsp), %eax
	movl	%eax, 64(%rsp)
	movl	48(%rsp), %eax
	movb	52(%rsp), %cl
	movb	%cl, 44(%rsp)
	movl	%eax, 40(%rsp)
	movb	$0, 4(%rsp)
	movb	$0, 3(%rsp)
	movb	$0, 2(%rsp)
	movl	$0, 128(%rsp)
	movl	$0, 124(%rsp)
	movl	$0, 120(%rsp)
	movl	$0, 116(%rsp)
	movq	$0, 360(%rsp)
	movq	$0, 352(%rsp)
	movl	$.LTESTES, %edi
	movl	$6, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	print
	callq	show
	movl	%eax, %edi
	callq	i32_to_i64
	movq	%rax, 56(%rsp)
	movl	$.Lwinddow, %edi
	movl	$7, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	to_char_ptr
	movq	%rax, %r14
	movl	$500, %edi              # imm = 0x1F4
	callq	i64_to_i32
	movl	%eax, %r15d
	movl	$500, %edi              # imm = 0x1F4
	callq	i64_to_i32
	movl	%eax, %r12d
	movl	$640, %edi              # imm = 0x280
	callq	i64_to_i32
	movl	%eax, %ebp
	movl	$480, %edi              # imm = 0x1E0
	callq	i64_to_i32
	movl	%eax, %ebx
	movl	$2, %edi
	callq	i64_to_i32
	movq	%r14, %rdi
	movl	%r15d, %esi
	movl	%r12d, %edx
	movl	%ebp, %ecx
	movl	%ebx, %r8d
	movl	%eax, %r9d
	callq	SDL_CreateWindow
	movq	%rax, 344(%rsp)
	movl	$".Lis succeeded:", %edi
	movl	$13, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	print
	movq	56(%rsp), %rdi
	callq	int_to_str
	movq	%rax, %rdi
	callq	print
	movl	$7, %edi
	callq	i64_to_i8
	movzbl	%al, %edi
	callq	i8_to_i64
	movq	%rax, %rdi
	callq	int_to_str
	movq	%rax, %rdi
	callq	print
	movl	$.Laa, %edi
	movl	$2, %esi
	callq	string_constructor
	movq	%rax, %rdi
	callq	print
	xorl	%eax, %eax
	addq	$1600, %rsp             # imm = 0x640
	popq	%rbx
	popq	%r12
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end6:
	.size	main, .Lfunc_end6-main
	.cfi_endproc
                                        # -- End function
	.globl	fd_set.1                # -- Begin function fd_set.1
	.p2align	4, 0x90
	.type	fd_set.1,@function
fd_set.1:                               # @fd_set.1
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$128, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end7:
	.size	fd_set.1, .Lfunc_end7-fd_set.1
	.cfi_endproc
                                        # -- End function
	.globl	fd_set.2                # -- Begin function fd_set.2
	.p2align	4, 0x90
	.type	fd_set.2,@function
fd_set.2:                               # @fd_set.2
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$128, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end8:
	.size	fd_set.2, .Lfunc_end8-fd_set.2
	.cfi_endproc
                                        # -- End function
	.globl	fd_set.3                # -- Begin function fd_set.3
	.p2align	4, 0x90
	.type	fd_set.3,@function
fd_set.3:                               # @fd_set.3
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$128, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end9:
	.size	fd_set.3, .Lfunc_end9-fd_set.3
	.cfi_endproc
                                        # -- End function
	.globl	timeval.4               # -- Begin function timeval.4
	.p2align	4, 0x90
	.type	timeval.4,@function
timeval.4:                              # @timeval.4
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end10:
	.size	timeval.4, .Lfunc_end10-timeval.4
	.cfi_endproc
                                        # -- End function
	.globl	fd_set.5                # -- Begin function fd_set.5
	.p2align	4, 0x90
	.type	fd_set.5,@function
fd_set.5:                               # @fd_set.5
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$128, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end11:
	.size	fd_set.5, .Lfunc_end11-fd_set.5
	.cfi_endproc
                                        # -- End function
	.globl	fd_set.6                # -- Begin function fd_set.6
	.p2align	4, 0x90
	.type	fd_set.6,@function
fd_set.6:                               # @fd_set.6
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$128, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end12:
	.size	fd_set.6, .Lfunc_end12-fd_set.6
	.cfi_endproc
                                        # -- End function
	.globl	fd_set.7                # -- Begin function fd_set.7
	.p2align	4, 0x90
	.type	fd_set.7,@function
fd_set.7:                               # @fd_set.7
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$128, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end13:
	.size	fd_set.7, .Lfunc_end13-fd_set.7
	.cfi_endproc
                                        # -- End function
	.globl	timespec.8              # -- Begin function timespec.8
	.p2align	4, 0x90
	.type	timespec.8,@function
timespec.8:                             # @timespec.8
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end14:
	.size	timespec.8, .Lfunc_end14-timespec.8
	.cfi_endproc
                                        # -- End function
	.globl	__sigset_t.9            # -- Begin function __sigset_t.9
	.p2align	4, 0x90
	.type	__sigset_t.9,@function
__sigset_t.9:                           # @__sigset_t.9
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$128, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end15:
	.size	__sigset_t.9, .Lfunc_end15-__sigset_t.9
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
	.globl	_IO_FILE.63             # -- Begin function _IO_FILE.63
	.p2align	4, 0x90
	.type	_IO_FILE.63,@function
_IO_FILE.63:                            # @_IO_FILE.63
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end69:
	.size	_IO_FILE.63, .Lfunc_end69-_IO_FILE.63
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.64             # -- Begin function _IO_FILE.64
	.p2align	4, 0x90
	.type	_IO_FILE.64,@function
_IO_FILE.64:                            # @_IO_FILE.64
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end70:
	.size	_IO_FILE.64, .Lfunc_end70-_IO_FILE.64
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
	.globl	_IO_FILE.66             # -- Begin function _IO_FILE.66
	.p2align	4, 0x90
	.type	_IO_FILE.66,@function
_IO_FILE.66:                            # @_IO_FILE.66
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end72:
	.size	_IO_FILE.66, .Lfunc_end72-_IO_FILE.66
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
	.globl	__mbstate_t.72          # -- Begin function __mbstate_t.72
	.p2align	4, 0x90
	.type	__mbstate_t.72,@function
__mbstate_t.72:                         # @__mbstate_t.72
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$8, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end78:
	.size	__mbstate_t.72, .Lfunc_end78-__mbstate_t.72
	.cfi_endproc
                                        # -- End function
	.globl	_G_fpos_t.73            # -- Begin function _G_fpos_t.73
	.p2align	4, 0x90
	.type	_G_fpos_t.73,@function
_G_fpos_t.73:                           # @_G_fpos_t.73
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end79:
	.size	_G_fpos_t.73, .Lfunc_end79-_G_fpos_t.73
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
	.globl	_G_fpos_t.75            # -- Begin function _G_fpos_t.75
	.p2align	4, 0x90
	.type	_G_fpos_t.75,@function
_G_fpos_t.75:                           # @_G_fpos_t.75
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end81:
	.size	_G_fpos_t.75, .Lfunc_end81-_G_fpos_t.75
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
	.globl	_IO_FILE.80             # -- Begin function _IO_FILE.80
	.p2align	4, 0x90
	.type	_IO_FILE.80,@function
_IO_FILE.80:                            # @_IO_FILE.80
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end86:
	.size	_IO_FILE.80, .Lfunc_end86-_IO_FILE.80
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.81             # -- Begin function _IO_FILE.81
	.p2align	4, 0x90
	.type	_IO_FILE.81,@function
_IO_FILE.81:                            # @_IO_FILE.81
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end87:
	.size	_IO_FILE.81, .Lfunc_end87-_IO_FILE.81
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.82             # -- Begin function _IO_FILE.82
	.p2align	4, 0x90
	.type	_IO_FILE.82,@function
_IO_FILE.82:                            # @_IO_FILE.82
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end88:
	.size	_IO_FILE.82, .Lfunc_end88-_IO_FILE.82
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.83             # -- Begin function _IO_FILE.83
	.p2align	4, 0x90
	.type	_IO_FILE.83,@function
_IO_FILE.83:                            # @_IO_FILE.83
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end89:
	.size	_IO_FILE.83, .Lfunc_end89-_IO_FILE.83
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.84             # -- Begin function _IO_FILE.84
	.p2align	4, 0x90
	.type	_IO_FILE.84,@function
_IO_FILE.84:                            # @_IO_FILE.84
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end90:
	.size	_IO_FILE.84, .Lfunc_end90-_IO_FILE.84
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.85             # -- Begin function _IO_FILE.85
	.p2align	4, 0x90
	.type	_IO_FILE.85,@function
_IO_FILE.85:                            # @_IO_FILE.85
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end91:
	.size	_IO_FILE.85, .Lfunc_end91-_IO_FILE.85
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.86             # -- Begin function _IO_FILE.86
	.p2align	4, 0x90
	.type	_IO_FILE.86,@function
_IO_FILE.86:                            # @_IO_FILE.86
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end92:
	.size	_IO_FILE.86, .Lfunc_end92-_IO_FILE.86
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.87             # -- Begin function _IO_FILE.87
	.p2align	4, 0x90
	.type	_IO_FILE.87,@function
_IO_FILE.87:                            # @_IO_FILE.87
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end93:
	.size	_IO_FILE.87, .Lfunc_end93-_IO_FILE.87
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.88             # -- Begin function _IO_FILE.88
	.p2align	4, 0x90
	.type	_IO_FILE.88,@function
_IO_FILE.88:                            # @_IO_FILE.88
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end94:
	.size	_IO_FILE.88, .Lfunc_end94-_IO_FILE.88
	.cfi_endproc
                                        # -- End function
	.globl	random_data.89          # -- Begin function random_data.89
	.p2align	4, 0x90
	.type	random_data.89,@function
random_data.89:                         # @random_data.89
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$48, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end95:
	.size	random_data.89, .Lfunc_end95-random_data.89
	.cfi_endproc
                                        # -- End function
	.globl	random_data.90          # -- Begin function random_data.90
	.p2align	4, 0x90
	.type	random_data.90,@function
random_data.90:                         # @random_data.90
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$48, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end96:
	.size	random_data.90, .Lfunc_end96-random_data.90
	.cfi_endproc
                                        # -- End function
	.globl	random_data.91          # -- Begin function random_data.91
	.p2align	4, 0x90
	.type	random_data.91,@function
random_data.91:                         # @random_data.91
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$48, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end97:
	.size	random_data.91, .Lfunc_end97-random_data.91
	.cfi_endproc
                                        # -- End function
	.globl	random_data.92          # -- Begin function random_data.92
	.p2align	4, 0x90
	.type	random_data.92,@function
random_data.92:                         # @random_data.92
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$48, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end98:
	.size	random_data.92, .Lfunc_end98-random_data.92
	.cfi_endproc
                                        # -- End function
	.globl	drand48_data.93         # -- Begin function drand48_data.93
	.p2align	4, 0x90
	.type	drand48_data.93,@function
drand48_data.93:                        # @drand48_data.93
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$28, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end99:
	.size	drand48_data.93, .Lfunc_end99-drand48_data.93
	.cfi_endproc
                                        # -- End function
	.globl	drand48_data.94         # -- Begin function drand48_data.94
	.p2align	4, 0x90
	.type	drand48_data.94,@function
drand48_data.94:                        # @drand48_data.94
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$28, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end100:
	.size	drand48_data.94, .Lfunc_end100-drand48_data.94
	.cfi_endproc
                                        # -- End function
	.globl	drand48_data.95         # -- Begin function drand48_data.95
	.p2align	4, 0x90
	.type	drand48_data.95,@function
drand48_data.95:                        # @drand48_data.95
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$28, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end101:
	.size	drand48_data.95, .Lfunc_end101-drand48_data.95
	.cfi_endproc
                                        # -- End function
	.globl	drand48_data.96         # -- Begin function drand48_data.96
	.p2align	4, 0x90
	.type	drand48_data.96,@function
drand48_data.96:                        # @drand48_data.96
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$28, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end102:
	.size	drand48_data.96, .Lfunc_end102-drand48_data.96
	.cfi_endproc
                                        # -- End function
	.globl	drand48_data.97         # -- Begin function drand48_data.97
	.p2align	4, 0x90
	.type	drand48_data.97,@function
drand48_data.97:                        # @drand48_data.97
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$28, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end103:
	.size	drand48_data.97, .Lfunc_end103-drand48_data.97
	.cfi_endproc
                                        # -- End function
	.globl	drand48_data.98         # -- Begin function drand48_data.98
	.p2align	4, 0x90
	.type	drand48_data.98,@function
drand48_data.98:                        # @drand48_data.98
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$28, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end104:
	.size	drand48_data.98, .Lfunc_end104-drand48_data.98
	.cfi_endproc
                                        # -- End function
	.globl	drand48_data.99         # -- Begin function drand48_data.99
	.p2align	4, 0x90
	.type	drand48_data.99,@function
drand48_data.99:                        # @drand48_data.99
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$28, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end105:
	.size	drand48_data.99, .Lfunc_end105-drand48_data.99
	.cfi_endproc
                                        # -- End function
	.globl	drand48_data.100        # -- Begin function drand48_data.100
	.p2align	4, 0x90
	.type	drand48_data.100,@function
drand48_data.100:                       # @drand48_data.100
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$28, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end106:
	.size	drand48_data.100, .Lfunc_end106-drand48_data.100
	.cfi_endproc
                                        # -- End function
	.globl	drand48_data.101        # -- Begin function drand48_data.101
	.p2align	4, 0x90
	.type	drand48_data.101,@function
drand48_data.101:                       # @drand48_data.101
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$28, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end107:
	.size	drand48_data.101, .Lfunc_end107-drand48_data.101
	.cfi_endproc
                                        # -- End function
	.globl	div_t.104               # -- Begin function div_t.104
	.p2align	4, 0x90
	.type	div_t.104,@function
div_t.104:                              # @div_t.104
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$8, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end108:
	.size	div_t.104, .Lfunc_end108-div_t.104
	.cfi_endproc
                                        # -- End function
	.globl	ldiv_t.105              # -- Begin function ldiv_t.105
	.p2align	4, 0x90
	.type	ldiv_t.105,@function
ldiv_t.105:                             # @ldiv_t.105
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end109:
	.size	ldiv_t.105, .Lfunc_end109-ldiv_t.105
	.cfi_endproc
                                        # -- End function
	.globl	lldiv_t.106             # -- Begin function lldiv_t.106
	.p2align	4, 0x90
	.type	lldiv_t.106,@function
lldiv_t.106:                            # @lldiv_t.106
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end110:
	.size	lldiv_t.106, .Lfunc_end110-lldiv_t.106
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.107     # -- Begin function __locale_struct.107
	.p2align	4, 0x90
	.type	__locale_struct.107,@function
__locale_struct.107:                    # @__locale_struct.107
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end111:
	.size	__locale_struct.107, .Lfunc_end111-__locale_struct.107
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.108     # -- Begin function __locale_struct.108
	.p2align	4, 0x90
	.type	__locale_struct.108,@function
__locale_struct.108:                    # @__locale_struct.108
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end112:
	.size	__locale_struct.108, .Lfunc_end112-__locale_struct.108
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.109     # -- Begin function __locale_struct.109
	.p2align	4, 0x90
	.type	__locale_struct.109,@function
__locale_struct.109:                    # @__locale_struct.109
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end113:
	.size	__locale_struct.109, .Lfunc_end113-__locale_struct.109
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.110     # -- Begin function __locale_struct.110
	.p2align	4, 0x90
	.type	__locale_struct.110,@function
__locale_struct.110:                    # @__locale_struct.110
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end114:
	.size	__locale_struct.110, .Lfunc_end114-__locale_struct.110
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.111     # -- Begin function __locale_struct.111
	.p2align	4, 0x90
	.type	__locale_struct.111,@function
__locale_struct.111:                    # @__locale_struct.111
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end115:
	.size	__locale_struct.111, .Lfunc_end115-__locale_struct.111
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.112     # -- Begin function __locale_struct.112
	.p2align	4, 0x90
	.type	__locale_struct.112,@function
__locale_struct.112:                    # @__locale_struct.112
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end116:
	.size	__locale_struct.112, .Lfunc_end116-__locale_struct.112
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.113     # -- Begin function __locale_struct.113
	.p2align	4, 0x90
	.type	__locale_struct.113,@function
__locale_struct.113:                    # @__locale_struct.113
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end117:
	.size	__locale_struct.113, .Lfunc_end117-__locale_struct.113
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.114     # -- Begin function __locale_struct.114
	.p2align	4, 0x90
	.type	__locale_struct.114,@function
__locale_struct.114:                    # @__locale_struct.114
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end118:
	.size	__locale_struct.114, .Lfunc_end118-__locale_struct.114
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.115     # -- Begin function __locale_struct.115
	.p2align	4, 0x90
	.type	__locale_struct.115,@function
__locale_struct.115:                    # @__locale_struct.115
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end119:
	.size	__locale_struct.115, .Lfunc_end119-__locale_struct.115
	.cfi_endproc
                                        # -- End function
	.globl	__mbstate_t.116         # -- Begin function __mbstate_t.116
	.p2align	4, 0x90
	.type	__mbstate_t.116,@function
__mbstate_t.116:                        # @__mbstate_t.116
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$8, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end120:
	.size	__mbstate_t.116, .Lfunc_end120-__mbstate_t.116
	.cfi_endproc
                                        # -- End function
	.globl	__mbstate_t.117         # -- Begin function __mbstate_t.117
	.p2align	4, 0x90
	.type	__mbstate_t.117,@function
__mbstate_t.117:                        # @__mbstate_t.117
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$8, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end121:
	.size	__mbstate_t.117, .Lfunc_end121-__mbstate_t.117
	.cfi_endproc
                                        # -- End function
	.globl	__mbstate_t.118         # -- Begin function __mbstate_t.118
	.p2align	4, 0x90
	.type	__mbstate_t.118,@function
__mbstate_t.118:                        # @__mbstate_t.118
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$8, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end122:
	.size	__mbstate_t.118, .Lfunc_end122-__mbstate_t.118
	.cfi_endproc
                                        # -- End function
	.globl	__mbstate_t.119         # -- Begin function __mbstate_t.119
	.p2align	4, 0x90
	.type	__mbstate_t.119,@function
__mbstate_t.119:                        # @__mbstate_t.119
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$8, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end123:
	.size	__mbstate_t.119, .Lfunc_end123-__mbstate_t.119
	.cfi_endproc
                                        # -- End function
	.globl	__mbstate_t.120         # -- Begin function __mbstate_t.120
	.p2align	4, 0x90
	.type	__mbstate_t.120,@function
__mbstate_t.120:                        # @__mbstate_t.120
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$8, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end124:
	.size	__mbstate_t.120, .Lfunc_end124-__mbstate_t.120
	.cfi_endproc
                                        # -- End function
	.globl	__mbstate_t.121         # -- Begin function __mbstate_t.121
	.p2align	4, 0x90
	.type	__mbstate_t.121,@function
__mbstate_t.121:                        # @__mbstate_t.121
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$8, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end125:
	.size	__mbstate_t.121, .Lfunc_end125-__mbstate_t.121
	.cfi_endproc
                                        # -- End function
	.globl	__mbstate_t.122         # -- Begin function __mbstate_t.122
	.p2align	4, 0x90
	.type	__mbstate_t.122,@function
__mbstate_t.122:                        # @__mbstate_t.122
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$8, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end126:
	.size	__mbstate_t.122, .Lfunc_end126-__mbstate_t.122
	.cfi_endproc
                                        # -- End function
	.globl	__mbstate_t.123         # -- Begin function __mbstate_t.123
	.p2align	4, 0x90
	.type	__mbstate_t.123,@function
__mbstate_t.123:                        # @__mbstate_t.123
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$8, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end127:
	.size	__mbstate_t.123, .Lfunc_end127-__mbstate_t.123
	.cfi_endproc
                                        # -- End function
	.globl	__mbstate_t.124         # -- Begin function __mbstate_t.124
	.p2align	4, 0x90
	.type	__mbstate_t.124,@function
__mbstate_t.124:                        # @__mbstate_t.124
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$8, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end128:
	.size	__mbstate_t.124, .Lfunc_end128-__mbstate_t.124
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.125            # -- Begin function _IO_FILE.125
	.p2align	4, 0x90
	.type	_IO_FILE.125,@function
_IO_FILE.125:                           # @_IO_FILE.125
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end129:
	.size	_IO_FILE.125, .Lfunc_end129-_IO_FILE.125
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.126            # -- Begin function _IO_FILE.126
	.p2align	4, 0x90
	.type	_IO_FILE.126,@function
_IO_FILE.126:                           # @_IO_FILE.126
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end130:
	.size	_IO_FILE.126, .Lfunc_end130-_IO_FILE.126
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.127            # -- Begin function _IO_FILE.127
	.p2align	4, 0x90
	.type	_IO_FILE.127,@function
_IO_FILE.127:                           # @_IO_FILE.127
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end131:
	.size	_IO_FILE.127, .Lfunc_end131-_IO_FILE.127
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.128            # -- Begin function _IO_FILE.128
	.p2align	4, 0x90
	.type	_IO_FILE.128,@function
_IO_FILE.128:                           # @_IO_FILE.128
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end132:
	.size	_IO_FILE.128, .Lfunc_end132-_IO_FILE.128
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.129            # -- Begin function _IO_FILE.129
	.p2align	4, 0x90
	.type	_IO_FILE.129,@function
_IO_FILE.129:                           # @_IO_FILE.129
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end133:
	.size	_IO_FILE.129, .Lfunc_end133-_IO_FILE.129
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.130            # -- Begin function _IO_FILE.130
	.p2align	4, 0x90
	.type	_IO_FILE.130,@function
_IO_FILE.130:                           # @_IO_FILE.130
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end134:
	.size	_IO_FILE.130, .Lfunc_end134-_IO_FILE.130
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.131            # -- Begin function _IO_FILE.131
	.p2align	4, 0x90
	.type	_IO_FILE.131,@function
_IO_FILE.131:                           # @_IO_FILE.131
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end135:
	.size	_IO_FILE.131, .Lfunc_end135-_IO_FILE.131
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.132            # -- Begin function _IO_FILE.132
	.p2align	4, 0x90
	.type	_IO_FILE.132,@function
_IO_FILE.132:                           # @_IO_FILE.132
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end136:
	.size	_IO_FILE.132, .Lfunc_end136-_IO_FILE.132
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.133            # -- Begin function _IO_FILE.133
	.p2align	4, 0x90
	.type	_IO_FILE.133,@function
_IO_FILE.133:                           # @_IO_FILE.133
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end137:
	.size	_IO_FILE.133, .Lfunc_end137-_IO_FILE.133
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.134            # -- Begin function _IO_FILE.134
	.p2align	4, 0x90
	.type	_IO_FILE.134,@function
_IO_FILE.134:                           # @_IO_FILE.134
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end138:
	.size	_IO_FILE.134, .Lfunc_end138-_IO_FILE.134
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.135            # -- Begin function _IO_FILE.135
	.p2align	4, 0x90
	.type	_IO_FILE.135,@function
_IO_FILE.135:                           # @_IO_FILE.135
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end139:
	.size	_IO_FILE.135, .Lfunc_end139-_IO_FILE.135
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.136            # -- Begin function _IO_FILE.136
	.p2align	4, 0x90
	.type	_IO_FILE.136,@function
_IO_FILE.136:                           # @_IO_FILE.136
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end140:
	.size	_IO_FILE.136, .Lfunc_end140-_IO_FILE.136
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.137            # -- Begin function _IO_FILE.137
	.p2align	4, 0x90
	.type	_IO_FILE.137,@function
_IO_FILE.137:                           # @_IO_FILE.137
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end141:
	.size	_IO_FILE.137, .Lfunc_end141-_IO_FILE.137
	.cfi_endproc
                                        # -- End function
	.globl	imaxdiv_t.138           # -- Begin function imaxdiv_t.138
	.p2align	4, 0x90
	.type	imaxdiv_t.138,@function
imaxdiv_t.138:                          # @imaxdiv_t.138
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end142:
	.size	imaxdiv_t.138, .Lfunc_end142-imaxdiv_t.138
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.139     # -- Begin function __locale_struct.139
	.p2align	4, 0x90
	.type	__locale_struct.139,@function
__locale_struct.139:                    # @__locale_struct.139
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end143:
	.size	__locale_struct.139, .Lfunc_end143-__locale_struct.139
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.140     # -- Begin function __locale_struct.140
	.p2align	4, 0x90
	.type	__locale_struct.140,@function
__locale_struct.140:                    # @__locale_struct.140
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end144:
	.size	__locale_struct.140, .Lfunc_end144-__locale_struct.140
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.141     # -- Begin function __locale_struct.141
	.p2align	4, 0x90
	.type	__locale_struct.141,@function
__locale_struct.141:                    # @__locale_struct.141
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end145:
	.size	__locale_struct.141, .Lfunc_end145-__locale_struct.141
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.142     # -- Begin function __locale_struct.142
	.p2align	4, 0x90
	.type	__locale_struct.142,@function
__locale_struct.142:                    # @__locale_struct.142
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end146:
	.size	__locale_struct.142, .Lfunc_end146-__locale_struct.142
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.143     # -- Begin function __locale_struct.143
	.p2align	4, 0x90
	.type	__locale_struct.143,@function
__locale_struct.143:                    # @__locale_struct.143
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end147:
	.size	__locale_struct.143, .Lfunc_end147-__locale_struct.143
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.144     # -- Begin function __locale_struct.144
	.p2align	4, 0x90
	.type	__locale_struct.144,@function
__locale_struct.144:                    # @__locale_struct.144
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end148:
	.size	__locale_struct.144, .Lfunc_end148-__locale_struct.144
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.145     # -- Begin function __locale_struct.145
	.p2align	4, 0x90
	.type	__locale_struct.145,@function
__locale_struct.145:                    # @__locale_struct.145
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end149:
	.size	__locale_struct.145, .Lfunc_end149-__locale_struct.145
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.146     # -- Begin function __locale_struct.146
	.p2align	4, 0x90
	.type	__locale_struct.146,@function
__locale_struct.146:                    # @__locale_struct.146
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end150:
	.size	__locale_struct.146, .Lfunc_end150-__locale_struct.146
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.147     # -- Begin function __locale_struct.147
	.p2align	4, 0x90
	.type	__locale_struct.147,@function
__locale_struct.147:                    # @__locale_struct.147
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end151:
	.size	__locale_struct.147, .Lfunc_end151-__locale_struct.147
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.148     # -- Begin function __locale_struct.148
	.p2align	4, 0x90
	.type	__locale_struct.148,@function
__locale_struct.148:                    # @__locale_struct.148
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end152:
	.size	__locale_struct.148, .Lfunc_end152-__locale_struct.148
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.149     # -- Begin function __locale_struct.149
	.p2align	4, 0x90
	.type	__locale_struct.149,@function
__locale_struct.149:                    # @__locale_struct.149
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end153:
	.size	__locale_struct.149, .Lfunc_end153-__locale_struct.149
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.150     # -- Begin function __locale_struct.150
	.p2align	4, 0x90
	.type	__locale_struct.150,@function
__locale_struct.150:                    # @__locale_struct.150
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end154:
	.size	__locale_struct.150, .Lfunc_end154-__locale_struct.150
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.151     # -- Begin function __locale_struct.151
	.p2align	4, 0x90
	.type	__locale_struct.151,@function
__locale_struct.151:                    # @__locale_struct.151
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end155:
	.size	__locale_struct.151, .Lfunc_end155-__locale_struct.151
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.152     # -- Begin function __locale_struct.152
	.p2align	4, 0x90
	.type	__locale_struct.152,@function
__locale_struct.152:                    # @__locale_struct.152
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end156:
	.size	__locale_struct.152, .Lfunc_end156-__locale_struct.152
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.153     # -- Begin function __locale_struct.153
	.p2align	4, 0x90
	.type	__locale_struct.153,@function
__locale_struct.153:                    # @__locale_struct.153
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end157:
	.size	__locale_struct.153, .Lfunc_end157-__locale_struct.153
	.cfi_endproc
                                        # -- End function
	.globl	__locale_struct.154     # -- Begin function __locale_struct.154
	.p2align	4, 0x90
	.type	__locale_struct.154,@function
__locale_struct.154:                    # @__locale_struct.154
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$232, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end158:
	.size	__locale_struct.154, .Lfunc_end158-__locale_struct.154
	.cfi_endproc
                                        # -- End function
	.globl	SDL_AssertData.155      # -- Begin function SDL_AssertData.155
	.p2align	4, 0x90
	.type	SDL_AssertData.155,@function
SDL_AssertData.155:                     # @SDL_AssertData.155
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$48, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end159:
	.size	SDL_AssertData.155, .Lfunc_end159-SDL_AssertData.155
	.cfi_endproc
                                        # -- End function
	.globl	SDL_AssertData.156      # -- Begin function SDL_AssertData.156
	.p2align	4, 0x90
	.type	SDL_AssertData.156,@function
SDL_AssertData.156:                     # @SDL_AssertData.156
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$48, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end160:
	.size	SDL_AssertData.156, .Lfunc_end160-SDL_AssertData.156
	.cfi_endproc
                                        # -- End function
	.globl	SDL_atomic_t.157        # -- Begin function SDL_atomic_t.157
	.p2align	4, 0x90
	.type	SDL_atomic_t.157,@function
SDL_atomic_t.157:                       # @SDL_atomic_t.157
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$4, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end161:
	.size	SDL_atomic_t.157, .Lfunc_end161-SDL_atomic_t.157
	.cfi_endproc
                                        # -- End function
	.globl	SDL_atomic_t.158        # -- Begin function SDL_atomic_t.158
	.p2align	4, 0x90
	.type	SDL_atomic_t.158,@function
SDL_atomic_t.158:                       # @SDL_atomic_t.158
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$4, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end162:
	.size	SDL_atomic_t.158, .Lfunc_end162-SDL_atomic_t.158
	.cfi_endproc
                                        # -- End function
	.globl	SDL_atomic_t.159        # -- Begin function SDL_atomic_t.159
	.p2align	4, 0x90
	.type	SDL_atomic_t.159,@function
SDL_atomic_t.159:                       # @SDL_atomic_t.159
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$4, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end163:
	.size	SDL_atomic_t.159, .Lfunc_end163-SDL_atomic_t.159
	.cfi_endproc
                                        # -- End function
	.globl	SDL_atomic_t.160        # -- Begin function SDL_atomic_t.160
	.p2align	4, 0x90
	.type	SDL_atomic_t.160,@function
SDL_atomic_t.160:                       # @SDL_atomic_t.160
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$4, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end164:
	.size	SDL_atomic_t.160, .Lfunc_end164-SDL_atomic_t.160
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.161           # -- Begin function SDL_RWops.161
	.p2align	4, 0x90
	.type	SDL_RWops.161,@function
SDL_RWops.161:                          # @SDL_RWops.161
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end165:
	.size	SDL_RWops.161, .Lfunc_end165-SDL_RWops.161
	.cfi_endproc
                                        # -- End function
	.globl	_IO_FILE.162            # -- Begin function _IO_FILE.162
	.p2align	4, 0x90
	.type	_IO_FILE.162,@function
_IO_FILE.162:                           # @_IO_FILE.162
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end166:
	.size	_IO_FILE.162, .Lfunc_end166-_IO_FILE.162
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.163           # -- Begin function SDL_RWops.163
	.p2align	4, 0x90
	.type	SDL_RWops.163,@function
SDL_RWops.163:                          # @SDL_RWops.163
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end167:
	.size	SDL_RWops.163, .Lfunc_end167-SDL_RWops.163
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.164           # -- Begin function SDL_RWops.164
	.p2align	4, 0x90
	.type	SDL_RWops.164,@function
SDL_RWops.164:                          # @SDL_RWops.164
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end168:
	.size	SDL_RWops.164, .Lfunc_end168-SDL_RWops.164
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.165           # -- Begin function SDL_RWops.165
	.p2align	4, 0x90
	.type	SDL_RWops.165,@function
SDL_RWops.165:                          # @SDL_RWops.165
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end169:
	.size	SDL_RWops.165, .Lfunc_end169-SDL_RWops.165
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.166           # -- Begin function SDL_RWops.166
	.p2align	4, 0x90
	.type	SDL_RWops.166,@function
SDL_RWops.166:                          # @SDL_RWops.166
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end170:
	.size	SDL_RWops.166, .Lfunc_end170-SDL_RWops.166
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.167           # -- Begin function SDL_RWops.167
	.p2align	4, 0x90
	.type	SDL_RWops.167,@function
SDL_RWops.167:                          # @SDL_RWops.167
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end171:
	.size	SDL_RWops.167, .Lfunc_end171-SDL_RWops.167
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.168           # -- Begin function SDL_RWops.168
	.p2align	4, 0x90
	.type	SDL_RWops.168,@function
SDL_RWops.168:                          # @SDL_RWops.168
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end172:
	.size	SDL_RWops.168, .Lfunc_end172-SDL_RWops.168
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.169           # -- Begin function SDL_RWops.169
	.p2align	4, 0x90
	.type	SDL_RWops.169,@function
SDL_RWops.169:                          # @SDL_RWops.169
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end173:
	.size	SDL_RWops.169, .Lfunc_end173-SDL_RWops.169
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.170           # -- Begin function SDL_RWops.170
	.p2align	4, 0x90
	.type	SDL_RWops.170,@function
SDL_RWops.170:                          # @SDL_RWops.170
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end174:
	.size	SDL_RWops.170, .Lfunc_end174-SDL_RWops.170
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.171           # -- Begin function SDL_RWops.171
	.p2align	4, 0x90
	.type	SDL_RWops.171,@function
SDL_RWops.171:                          # @SDL_RWops.171
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end175:
	.size	SDL_RWops.171, .Lfunc_end175-SDL_RWops.171
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.172           # -- Begin function SDL_RWops.172
	.p2align	4, 0x90
	.type	SDL_RWops.172,@function
SDL_RWops.172:                          # @SDL_RWops.172
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end176:
	.size	SDL_RWops.172, .Lfunc_end176-SDL_RWops.172
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.173           # -- Begin function SDL_RWops.173
	.p2align	4, 0x90
	.type	SDL_RWops.173,@function
SDL_RWops.173:                          # @SDL_RWops.173
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end177:
	.size	SDL_RWops.173, .Lfunc_end177-SDL_RWops.173
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.174           # -- Begin function SDL_RWops.174
	.p2align	4, 0x90
	.type	SDL_RWops.174,@function
SDL_RWops.174:                          # @SDL_RWops.174
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end178:
	.size	SDL_RWops.174, .Lfunc_end178-SDL_RWops.174
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.175           # -- Begin function SDL_RWops.175
	.p2align	4, 0x90
	.type	SDL_RWops.175,@function
SDL_RWops.175:                          # @SDL_RWops.175
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end179:
	.size	SDL_RWops.175, .Lfunc_end179-SDL_RWops.175
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.176           # -- Begin function SDL_RWops.176
	.p2align	4, 0x90
	.type	SDL_RWops.176,@function
SDL_RWops.176:                          # @SDL_RWops.176
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end180:
	.size	SDL_RWops.176, .Lfunc_end180-SDL_RWops.176
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.177           # -- Begin function SDL_RWops.177
	.p2align	4, 0x90
	.type	SDL_RWops.177,@function
SDL_RWops.177:                          # @SDL_RWops.177
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end181:
	.size	SDL_RWops.177, .Lfunc_end181-SDL_RWops.177
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.178           # -- Begin function SDL_RWops.178
	.p2align	4, 0x90
	.type	SDL_RWops.178,@function
SDL_RWops.178:                          # @SDL_RWops.178
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end182:
	.size	SDL_RWops.178, .Lfunc_end182-SDL_RWops.178
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.179           # -- Begin function SDL_RWops.179
	.p2align	4, 0x90
	.type	SDL_RWops.179,@function
SDL_RWops.179:                          # @SDL_RWops.179
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end183:
	.size	SDL_RWops.179, .Lfunc_end183-SDL_RWops.179
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.180           # -- Begin function SDL_RWops.180
	.p2align	4, 0x90
	.type	SDL_RWops.180,@function
SDL_RWops.180:                          # @SDL_RWops.180
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end184:
	.size	SDL_RWops.180, .Lfunc_end184-SDL_RWops.180
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.181           # -- Begin function SDL_RWops.181
	.p2align	4, 0x90
	.type	SDL_RWops.181,@function
SDL_RWops.181:                          # @SDL_RWops.181
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end185:
	.size	SDL_RWops.181, .Lfunc_end185-SDL_RWops.181
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.182           # -- Begin function SDL_RWops.182
	.p2align	4, 0x90
	.type	SDL_RWops.182,@function
SDL_RWops.182:                          # @SDL_RWops.182
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end186:
	.size	SDL_RWops.182, .Lfunc_end186-SDL_RWops.182
	.cfi_endproc
                                        # -- End function
	.globl	SDL_AudioSpec.183       # -- Begin function SDL_AudioSpec.183
	.p2align	4, 0x90
	.type	SDL_AudioSpec.183,@function
SDL_AudioSpec.183:                      # @SDL_AudioSpec.183
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$32, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end187:
	.size	SDL_AudioSpec.183, .Lfunc_end187-SDL_AudioSpec.183
	.cfi_endproc
                                        # -- End function
	.globl	SDL_AudioSpec.184       # -- Begin function SDL_AudioSpec.184
	.p2align	4, 0x90
	.type	SDL_AudioSpec.184,@function
SDL_AudioSpec.184:                      # @SDL_AudioSpec.184
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$32, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end188:
	.size	SDL_AudioSpec.184, .Lfunc_end188-SDL_AudioSpec.184
	.cfi_endproc
                                        # -- End function
	.globl	SDL_AudioSpec.185       # -- Begin function SDL_AudioSpec.185
	.p2align	4, 0x90
	.type	SDL_AudioSpec.185,@function
SDL_AudioSpec.185:                      # @SDL_AudioSpec.185
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$32, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end189:
	.size	SDL_AudioSpec.185, .Lfunc_end189-SDL_AudioSpec.185
	.cfi_endproc
                                        # -- End function
	.globl	SDL_AudioSpec.186       # -- Begin function SDL_AudioSpec.186
	.p2align	4, 0x90
	.type	SDL_AudioSpec.186,@function
SDL_AudioSpec.186:                      # @SDL_AudioSpec.186
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$32, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end190:
	.size	SDL_AudioSpec.186, .Lfunc_end190-SDL_AudioSpec.186
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.187           # -- Begin function SDL_RWops.187
	.p2align	4, 0x90
	.type	SDL_RWops.187,@function
SDL_RWops.187:                          # @SDL_RWops.187
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end191:
	.size	SDL_RWops.187, .Lfunc_end191-SDL_RWops.187
	.cfi_endproc
                                        # -- End function
	.globl	SDL_AudioSpec.188       # -- Begin function SDL_AudioSpec.188
	.p2align	4, 0x90
	.type	SDL_AudioSpec.188,@function
SDL_AudioSpec.188:                      # @SDL_AudioSpec.188
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$32, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end192:
	.size	SDL_AudioSpec.188, .Lfunc_end192-SDL_AudioSpec.188
	.cfi_endproc
                                        # -- End function
	.globl	SDL_AudioSpec.189       # -- Begin function SDL_AudioSpec.189
	.p2align	4, 0x90
	.type	SDL_AudioSpec.189,@function
SDL_AudioSpec.189:                      # @SDL_AudioSpec.189
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$32, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end193:
	.size	SDL_AudioSpec.189, .Lfunc_end193-SDL_AudioSpec.189
	.cfi_endproc
                                        # -- End function
	.globl	SDL_AudioCVT.190        # -- Begin function SDL_AudioCVT.190
	.p2align	4, 0x90
	.type	SDL_AudioCVT.190,@function
SDL_AudioCVT.190:                       # @SDL_AudioCVT.190
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$136, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end194:
	.size	SDL_AudioCVT.190, .Lfunc_end194-SDL_AudioCVT.190
	.cfi_endproc
                                        # -- End function
	.globl	SDL_AudioCVT.191        # -- Begin function SDL_AudioCVT.191
	.p2align	4, 0x90
	.type	SDL_AudioCVT.191,@function
SDL_AudioCVT.191:                       # @SDL_AudioCVT.191
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$136, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end195:
	.size	SDL_AudioCVT.191, .Lfunc_end195-SDL_AudioCVT.191
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Color.192           # -- Begin function SDL_Color.192
	.p2align	4, 0x90
	.type	SDL_Color.192,@function
SDL_Color.192:                          # @SDL_Color.192
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$4, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end196:
	.size	SDL_Color.192, .Lfunc_end196-SDL_Color.192
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Palette.193         # -- Begin function SDL_Palette.193
	.p2align	4, 0x90
	.type	SDL_Palette.193,@function
SDL_Palette.193:                        # @SDL_Palette.193
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$24, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end197:
	.size	SDL_Palette.193, .Lfunc_end197-SDL_Palette.193
	.cfi_endproc
                                        # -- End function
	.globl	SDL_PixelFormat.194     # -- Begin function SDL_PixelFormat.194
	.p2align	4, 0x90
	.type	SDL_PixelFormat.194,@function
SDL_PixelFormat.194:                    # @SDL_PixelFormat.194
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$56, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end198:
	.size	SDL_PixelFormat.194, .Lfunc_end198-SDL_PixelFormat.194
	.cfi_endproc
                                        # -- End function
	.globl	SDL_PixelFormat.195     # -- Begin function SDL_PixelFormat.195
	.p2align	4, 0x90
	.type	SDL_PixelFormat.195,@function
SDL_PixelFormat.195:                    # @SDL_PixelFormat.195
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$56, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end199:
	.size	SDL_PixelFormat.195, .Lfunc_end199-SDL_PixelFormat.195
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Palette.196         # -- Begin function SDL_Palette.196
	.p2align	4, 0x90
	.type	SDL_Palette.196,@function
SDL_Palette.196:                        # @SDL_Palette.196
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$24, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end200:
	.size	SDL_Palette.196, .Lfunc_end200-SDL_Palette.196
	.cfi_endproc
                                        # -- End function
	.globl	SDL_PixelFormat.197     # -- Begin function SDL_PixelFormat.197
	.p2align	4, 0x90
	.type	SDL_PixelFormat.197,@function
SDL_PixelFormat.197:                    # @SDL_PixelFormat.197
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$56, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end201:
	.size	SDL_PixelFormat.197, .Lfunc_end201-SDL_PixelFormat.197
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Palette.198         # -- Begin function SDL_Palette.198
	.p2align	4, 0x90
	.type	SDL_Palette.198,@function
SDL_Palette.198:                        # @SDL_Palette.198
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$24, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end202:
	.size	SDL_Palette.198, .Lfunc_end202-SDL_Palette.198
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Palette.199         # -- Begin function SDL_Palette.199
	.p2align	4, 0x90
	.type	SDL_Palette.199,@function
SDL_Palette.199:                        # @SDL_Palette.199
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$24, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end203:
	.size	SDL_Palette.199, .Lfunc_end203-SDL_Palette.199
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Color.200           # -- Begin function SDL_Color.200
	.p2align	4, 0x90
	.type	SDL_Color.200,@function
SDL_Color.200:                          # @SDL_Color.200
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$4, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end204:
	.size	SDL_Color.200, .Lfunc_end204-SDL_Color.200
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Palette.201         # -- Begin function SDL_Palette.201
	.p2align	4, 0x90
	.type	SDL_Palette.201,@function
SDL_Palette.201:                        # @SDL_Palette.201
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$24, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end205:
	.size	SDL_Palette.201, .Lfunc_end205-SDL_Palette.201
	.cfi_endproc
                                        # -- End function
	.globl	SDL_PixelFormat.202     # -- Begin function SDL_PixelFormat.202
	.p2align	4, 0x90
	.type	SDL_PixelFormat.202,@function
SDL_PixelFormat.202:                    # @SDL_PixelFormat.202
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$56, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end206:
	.size	SDL_PixelFormat.202, .Lfunc_end206-SDL_PixelFormat.202
	.cfi_endproc
                                        # -- End function
	.globl	SDL_PixelFormat.203     # -- Begin function SDL_PixelFormat.203
	.p2align	4, 0x90
	.type	SDL_PixelFormat.203,@function
SDL_PixelFormat.203:                    # @SDL_PixelFormat.203
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$56, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end207:
	.size	SDL_PixelFormat.203, .Lfunc_end207-SDL_PixelFormat.203
	.cfi_endproc
                                        # -- End function
	.globl	SDL_PixelFormat.204     # -- Begin function SDL_PixelFormat.204
	.p2align	4, 0x90
	.type	SDL_PixelFormat.204,@function
SDL_PixelFormat.204:                    # @SDL_PixelFormat.204
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$56, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end208:
	.size	SDL_PixelFormat.204, .Lfunc_end208-SDL_PixelFormat.204
	.cfi_endproc
                                        # -- End function
	.globl	SDL_PixelFormat.205     # -- Begin function SDL_PixelFormat.205
	.p2align	4, 0x90
	.type	SDL_PixelFormat.205,@function
SDL_PixelFormat.205:                    # @SDL_PixelFormat.205
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$56, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end209:
	.size	SDL_PixelFormat.205, .Lfunc_end209-SDL_PixelFormat.205
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Point.206           # -- Begin function SDL_Point.206
	.p2align	4, 0x90
	.type	SDL_Point.206,@function
SDL_Point.206:                          # @SDL_Point.206
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$8, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end210:
	.size	SDL_Point.206, .Lfunc_end210-SDL_Point.206
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.207            # -- Begin function SDL_Rect.207
	.p2align	4, 0x90
	.type	SDL_Rect.207,@function
SDL_Rect.207:                           # @SDL_Rect.207
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end211:
	.size	SDL_Rect.207, .Lfunc_end211-SDL_Rect.207
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.208            # -- Begin function SDL_Rect.208
	.p2align	4, 0x90
	.type	SDL_Rect.208,@function
SDL_Rect.208:                           # @SDL_Rect.208
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end212:
	.size	SDL_Rect.208, .Lfunc_end212-SDL_Rect.208
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.209            # -- Begin function SDL_Rect.209
	.p2align	4, 0x90
	.type	SDL_Rect.209,@function
SDL_Rect.209:                           # @SDL_Rect.209
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end213:
	.size	SDL_Rect.209, .Lfunc_end213-SDL_Rect.209
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.210            # -- Begin function SDL_Rect.210
	.p2align	4, 0x90
	.type	SDL_Rect.210,@function
SDL_Rect.210:                           # @SDL_Rect.210
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end214:
	.size	SDL_Rect.210, .Lfunc_end214-SDL_Rect.210
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.211            # -- Begin function SDL_Rect.211
	.p2align	4, 0x90
	.type	SDL_Rect.211,@function
SDL_Rect.211:                           # @SDL_Rect.211
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end215:
	.size	SDL_Rect.211, .Lfunc_end215-SDL_Rect.211
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.212            # -- Begin function SDL_Rect.212
	.p2align	4, 0x90
	.type	SDL_Rect.212,@function
SDL_Rect.212:                           # @SDL_Rect.212
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end216:
	.size	SDL_Rect.212, .Lfunc_end216-SDL_Rect.212
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.213            # -- Begin function SDL_Rect.213
	.p2align	4, 0x90
	.type	SDL_Rect.213,@function
SDL_Rect.213:                           # @SDL_Rect.213
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end217:
	.size	SDL_Rect.213, .Lfunc_end217-SDL_Rect.213
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.214            # -- Begin function SDL_Rect.214
	.p2align	4, 0x90
	.type	SDL_Rect.214,@function
SDL_Rect.214:                           # @SDL_Rect.214
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end218:
	.size	SDL_Rect.214, .Lfunc_end218-SDL_Rect.214
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.215            # -- Begin function SDL_Rect.215
	.p2align	4, 0x90
	.type	SDL_Rect.215,@function
SDL_Rect.215:                           # @SDL_Rect.215
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end219:
	.size	SDL_Rect.215, .Lfunc_end219-SDL_Rect.215
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.216            # -- Begin function SDL_Rect.216
	.p2align	4, 0x90
	.type	SDL_Rect.216,@function
SDL_Rect.216:                           # @SDL_Rect.216
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end220:
	.size	SDL_Rect.216, .Lfunc_end220-SDL_Rect.216
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.217            # -- Begin function SDL_Rect.217
	.p2align	4, 0x90
	.type	SDL_Rect.217,@function
SDL_Rect.217:                           # @SDL_Rect.217
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end221:
	.size	SDL_Rect.217, .Lfunc_end221-SDL_Rect.217
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.218            # -- Begin function SDL_Rect.218
	.p2align	4, 0x90
	.type	SDL_Rect.218,@function
SDL_Rect.218:                           # @SDL_Rect.218
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end222:
	.size	SDL_Rect.218, .Lfunc_end222-SDL_Rect.218
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Point.219           # -- Begin function SDL_Point.219
	.p2align	4, 0x90
	.type	SDL_Point.219,@function
SDL_Point.219:                          # @SDL_Point.219
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$8, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end223:
	.size	SDL_Point.219, .Lfunc_end223-SDL_Point.219
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.220            # -- Begin function SDL_Rect.220
	.p2align	4, 0x90
	.type	SDL_Rect.220,@function
SDL_Rect.220:                           # @SDL_Rect.220
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end224:
	.size	SDL_Rect.220, .Lfunc_end224-SDL_Rect.220
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.221            # -- Begin function SDL_Rect.221
	.p2align	4, 0x90
	.type	SDL_Rect.221,@function
SDL_Rect.221:                           # @SDL_Rect.221
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end225:
	.size	SDL_Rect.221, .Lfunc_end225-SDL_Rect.221
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.222            # -- Begin function SDL_Rect.222
	.p2align	4, 0x90
	.type	SDL_Rect.222,@function
SDL_Rect.222:                           # @SDL_Rect.222
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end226:
	.size	SDL_Rect.222, .Lfunc_end226-SDL_Rect.222
	.cfi_endproc
                                        # -- End function
	.globl	SDL_PixelFormat.223     # -- Begin function SDL_PixelFormat.223
	.p2align	4, 0x90
	.type	SDL_PixelFormat.223,@function
SDL_PixelFormat.223:                    # @SDL_PixelFormat.223
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$56, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end227:
	.size	SDL_PixelFormat.223, .Lfunc_end227-SDL_PixelFormat.223
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.224            # -- Begin function SDL_Rect.224
	.p2align	4, 0x90
	.type	SDL_Rect.224,@function
SDL_Rect.224:                           # @SDL_Rect.224
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end228:
	.size	SDL_Rect.224, .Lfunc_end228-SDL_Rect.224
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.225         # -- Begin function SDL_Surface.225
	.p2align	4, 0x90
	.type	SDL_Surface.225,@function
SDL_Surface.225:                        # @SDL_Surface.225
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end229:
	.size	SDL_Surface.225, .Lfunc_end229-SDL_Surface.225
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.226         # -- Begin function SDL_Surface.226
	.p2align	4, 0x90
	.type	SDL_Surface.226,@function
SDL_Surface.226:                        # @SDL_Surface.226
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end230:
	.size	SDL_Surface.226, .Lfunc_end230-SDL_Surface.226
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.227         # -- Begin function SDL_Surface.227
	.p2align	4, 0x90
	.type	SDL_Surface.227,@function
SDL_Surface.227:                        # @SDL_Surface.227
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end231:
	.size	SDL_Surface.227, .Lfunc_end231-SDL_Surface.227
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.228         # -- Begin function SDL_Surface.228
	.p2align	4, 0x90
	.type	SDL_Surface.228,@function
SDL_Surface.228:                        # @SDL_Surface.228
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end232:
	.size	SDL_Surface.228, .Lfunc_end232-SDL_Surface.228
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.229         # -- Begin function SDL_Surface.229
	.p2align	4, 0x90
	.type	SDL_Surface.229,@function
SDL_Surface.229:                        # @SDL_Surface.229
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end233:
	.size	SDL_Surface.229, .Lfunc_end233-SDL_Surface.229
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.230         # -- Begin function SDL_Surface.230
	.p2align	4, 0x90
	.type	SDL_Surface.230,@function
SDL_Surface.230:                        # @SDL_Surface.230
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end234:
	.size	SDL_Surface.230, .Lfunc_end234-SDL_Surface.230
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Palette.231         # -- Begin function SDL_Palette.231
	.p2align	4, 0x90
	.type	SDL_Palette.231,@function
SDL_Palette.231:                        # @SDL_Palette.231
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$24, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end235:
	.size	SDL_Palette.231, .Lfunc_end235-SDL_Palette.231
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.232         # -- Begin function SDL_Surface.232
	.p2align	4, 0x90
	.type	SDL_Surface.232,@function
SDL_Surface.232:                        # @SDL_Surface.232
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end236:
	.size	SDL_Surface.232, .Lfunc_end236-SDL_Surface.232
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.233         # -- Begin function SDL_Surface.233
	.p2align	4, 0x90
	.type	SDL_Surface.233,@function
SDL_Surface.233:                        # @SDL_Surface.233
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end237:
	.size	SDL_Surface.233, .Lfunc_end237-SDL_Surface.233
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.234           # -- Begin function SDL_RWops.234
	.p2align	4, 0x90
	.type	SDL_RWops.234,@function
SDL_RWops.234:                          # @SDL_RWops.234
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end238:
	.size	SDL_RWops.234, .Lfunc_end238-SDL_RWops.234
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.235         # -- Begin function SDL_Surface.235
	.p2align	4, 0x90
	.type	SDL_Surface.235,@function
SDL_Surface.235:                        # @SDL_Surface.235
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end239:
	.size	SDL_Surface.235, .Lfunc_end239-SDL_Surface.235
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.236         # -- Begin function SDL_Surface.236
	.p2align	4, 0x90
	.type	SDL_Surface.236,@function
SDL_Surface.236:                        # @SDL_Surface.236
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end240:
	.size	SDL_Surface.236, .Lfunc_end240-SDL_Surface.236
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.237           # -- Begin function SDL_RWops.237
	.p2align	4, 0x90
	.type	SDL_RWops.237,@function
SDL_RWops.237:                          # @SDL_RWops.237
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end241:
	.size	SDL_RWops.237, .Lfunc_end241-SDL_RWops.237
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.238         # -- Begin function SDL_Surface.238
	.p2align	4, 0x90
	.type	SDL_Surface.238,@function
SDL_Surface.238:                        # @SDL_Surface.238
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end242:
	.size	SDL_Surface.238, .Lfunc_end242-SDL_Surface.238
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.239         # -- Begin function SDL_Surface.239
	.p2align	4, 0x90
	.type	SDL_Surface.239,@function
SDL_Surface.239:                        # @SDL_Surface.239
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end243:
	.size	SDL_Surface.239, .Lfunc_end243-SDL_Surface.239
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.240         # -- Begin function SDL_Surface.240
	.p2align	4, 0x90
	.type	SDL_Surface.240,@function
SDL_Surface.240:                        # @SDL_Surface.240
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end244:
	.size	SDL_Surface.240, .Lfunc_end244-SDL_Surface.240
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.241         # -- Begin function SDL_Surface.241
	.p2align	4, 0x90
	.type	SDL_Surface.241,@function
SDL_Surface.241:                        # @SDL_Surface.241
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end245:
	.size	SDL_Surface.241, .Lfunc_end245-SDL_Surface.241
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.242         # -- Begin function SDL_Surface.242
	.p2align	4, 0x90
	.type	SDL_Surface.242,@function
SDL_Surface.242:                        # @SDL_Surface.242
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end246:
	.size	SDL_Surface.242, .Lfunc_end246-SDL_Surface.242
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.243         # -- Begin function SDL_Surface.243
	.p2align	4, 0x90
	.type	SDL_Surface.243,@function
SDL_Surface.243:                        # @SDL_Surface.243
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end247:
	.size	SDL_Surface.243, .Lfunc_end247-SDL_Surface.243
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.244         # -- Begin function SDL_Surface.244
	.p2align	4, 0x90
	.type	SDL_Surface.244,@function
SDL_Surface.244:                        # @SDL_Surface.244
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end248:
	.size	SDL_Surface.244, .Lfunc_end248-SDL_Surface.244
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.245         # -- Begin function SDL_Surface.245
	.p2align	4, 0x90
	.type	SDL_Surface.245,@function
SDL_Surface.245:                        # @SDL_Surface.245
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end249:
	.size	SDL_Surface.245, .Lfunc_end249-SDL_Surface.245
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.246         # -- Begin function SDL_Surface.246
	.p2align	4, 0x90
	.type	SDL_Surface.246,@function
SDL_Surface.246:                        # @SDL_Surface.246
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end250:
	.size	SDL_Surface.246, .Lfunc_end250-SDL_Surface.246
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.247         # -- Begin function SDL_Surface.247
	.p2align	4, 0x90
	.type	SDL_Surface.247,@function
SDL_Surface.247:                        # @SDL_Surface.247
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end251:
	.size	SDL_Surface.247, .Lfunc_end251-SDL_Surface.247
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.248            # -- Begin function SDL_Rect.248
	.p2align	4, 0x90
	.type	SDL_Rect.248,@function
SDL_Rect.248:                           # @SDL_Rect.248
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end252:
	.size	SDL_Rect.248, .Lfunc_end252-SDL_Rect.248
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.249         # -- Begin function SDL_Surface.249
	.p2align	4, 0x90
	.type	SDL_Surface.249,@function
SDL_Surface.249:                        # @SDL_Surface.249
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end253:
	.size	SDL_Surface.249, .Lfunc_end253-SDL_Surface.249
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.250            # -- Begin function SDL_Rect.250
	.p2align	4, 0x90
	.type	SDL_Rect.250,@function
SDL_Rect.250:                           # @SDL_Rect.250
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end254:
	.size	SDL_Rect.250, .Lfunc_end254-SDL_Rect.250
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.251         # -- Begin function SDL_Surface.251
	.p2align	4, 0x90
	.type	SDL_Surface.251,@function
SDL_Surface.251:                        # @SDL_Surface.251
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end255:
	.size	SDL_Surface.251, .Lfunc_end255-SDL_Surface.251
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.252         # -- Begin function SDL_Surface.252
	.p2align	4, 0x90
	.type	SDL_Surface.252,@function
SDL_Surface.252:                        # @SDL_Surface.252
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end256:
	.size	SDL_Surface.252, .Lfunc_end256-SDL_Surface.252
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.253         # -- Begin function SDL_Surface.253
	.p2align	4, 0x90
	.type	SDL_Surface.253,@function
SDL_Surface.253:                        # @SDL_Surface.253
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end257:
	.size	SDL_Surface.253, .Lfunc_end257-SDL_Surface.253
	.cfi_endproc
                                        # -- End function
	.globl	SDL_PixelFormat.254     # -- Begin function SDL_PixelFormat.254
	.p2align	4, 0x90
	.type	SDL_PixelFormat.254,@function
SDL_PixelFormat.254:                    # @SDL_PixelFormat.254
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$56, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end258:
	.size	SDL_PixelFormat.254, .Lfunc_end258-SDL_PixelFormat.254
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.255         # -- Begin function SDL_Surface.255
	.p2align	4, 0x90
	.type	SDL_Surface.255,@function
SDL_Surface.255:                        # @SDL_Surface.255
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end259:
	.size	SDL_Surface.255, .Lfunc_end259-SDL_Surface.255
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.256         # -- Begin function SDL_Surface.256
	.p2align	4, 0x90
	.type	SDL_Surface.256,@function
SDL_Surface.256:                        # @SDL_Surface.256
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end260:
	.size	SDL_Surface.256, .Lfunc_end260-SDL_Surface.256
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.257         # -- Begin function SDL_Surface.257
	.p2align	4, 0x90
	.type	SDL_Surface.257,@function
SDL_Surface.257:                        # @SDL_Surface.257
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end261:
	.size	SDL_Surface.257, .Lfunc_end261-SDL_Surface.257
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.258         # -- Begin function SDL_Surface.258
	.p2align	4, 0x90
	.type	SDL_Surface.258,@function
SDL_Surface.258:                        # @SDL_Surface.258
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end262:
	.size	SDL_Surface.258, .Lfunc_end262-SDL_Surface.258
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.259            # -- Begin function SDL_Rect.259
	.p2align	4, 0x90
	.type	SDL_Rect.259,@function
SDL_Rect.259:                           # @SDL_Rect.259
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end263:
	.size	SDL_Rect.259, .Lfunc_end263-SDL_Rect.259
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.260         # -- Begin function SDL_Surface.260
	.p2align	4, 0x90
	.type	SDL_Surface.260,@function
SDL_Surface.260:                        # @SDL_Surface.260
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end264:
	.size	SDL_Surface.260, .Lfunc_end264-SDL_Surface.260
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.261            # -- Begin function SDL_Rect.261
	.p2align	4, 0x90
	.type	SDL_Rect.261,@function
SDL_Rect.261:                           # @SDL_Rect.261
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end265:
	.size	SDL_Rect.261, .Lfunc_end265-SDL_Rect.261
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.262         # -- Begin function SDL_Surface.262
	.p2align	4, 0x90
	.type	SDL_Surface.262,@function
SDL_Surface.262:                        # @SDL_Surface.262
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end266:
	.size	SDL_Surface.262, .Lfunc_end266-SDL_Surface.262
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.263            # -- Begin function SDL_Rect.263
	.p2align	4, 0x90
	.type	SDL_Rect.263,@function
SDL_Rect.263:                           # @SDL_Rect.263
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end267:
	.size	SDL_Rect.263, .Lfunc_end267-SDL_Rect.263
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.264         # -- Begin function SDL_Surface.264
	.p2align	4, 0x90
	.type	SDL_Surface.264,@function
SDL_Surface.264:                        # @SDL_Surface.264
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end268:
	.size	SDL_Surface.264, .Lfunc_end268-SDL_Surface.264
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.265            # -- Begin function SDL_Rect.265
	.p2align	4, 0x90
	.type	SDL_Rect.265,@function
SDL_Rect.265:                           # @SDL_Rect.265
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end269:
	.size	SDL_Rect.265, .Lfunc_end269-SDL_Rect.265
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.266         # -- Begin function SDL_Surface.266
	.p2align	4, 0x90
	.type	SDL_Surface.266,@function
SDL_Surface.266:                        # @SDL_Surface.266
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end270:
	.size	SDL_Surface.266, .Lfunc_end270-SDL_Surface.266
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.267            # -- Begin function SDL_Rect.267
	.p2align	4, 0x90
	.type	SDL_Rect.267,@function
SDL_Rect.267:                           # @SDL_Rect.267
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end271:
	.size	SDL_Rect.267, .Lfunc_end271-SDL_Rect.267
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.268         # -- Begin function SDL_Surface.268
	.p2align	4, 0x90
	.type	SDL_Surface.268,@function
SDL_Surface.268:                        # @SDL_Surface.268
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end272:
	.size	SDL_Surface.268, .Lfunc_end272-SDL_Surface.268
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.269            # -- Begin function SDL_Rect.269
	.p2align	4, 0x90
	.type	SDL_Rect.269,@function
SDL_Rect.269:                           # @SDL_Rect.269
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end273:
	.size	SDL_Rect.269, .Lfunc_end273-SDL_Rect.269
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.270         # -- Begin function SDL_Surface.270
	.p2align	4, 0x90
	.type	SDL_Surface.270,@function
SDL_Surface.270:                        # @SDL_Surface.270
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end274:
	.size	SDL_Surface.270, .Lfunc_end274-SDL_Surface.270
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.271            # -- Begin function SDL_Rect.271
	.p2align	4, 0x90
	.type	SDL_Rect.271,@function
SDL_Rect.271:                           # @SDL_Rect.271
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end275:
	.size	SDL_Rect.271, .Lfunc_end275-SDL_Rect.271
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.272         # -- Begin function SDL_Surface.272
	.p2align	4, 0x90
	.type	SDL_Surface.272,@function
SDL_Surface.272:                        # @SDL_Surface.272
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end276:
	.size	SDL_Surface.272, .Lfunc_end276-SDL_Surface.272
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.273            # -- Begin function SDL_Rect.273
	.p2align	4, 0x90
	.type	SDL_Rect.273,@function
SDL_Rect.273:                           # @SDL_Rect.273
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end277:
	.size	SDL_Rect.273, .Lfunc_end277-SDL_Rect.273
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.274         # -- Begin function SDL_Surface.274
	.p2align	4, 0x90
	.type	SDL_Surface.274,@function
SDL_Surface.274:                        # @SDL_Surface.274
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end278:
	.size	SDL_Surface.274, .Lfunc_end278-SDL_Surface.274
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.275            # -- Begin function SDL_Rect.275
	.p2align	4, 0x90
	.type	SDL_Rect.275,@function
SDL_Rect.275:                           # @SDL_Rect.275
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end279:
	.size	SDL_Rect.275, .Lfunc_end279-SDL_Rect.275
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.276         # -- Begin function SDL_Surface.276
	.p2align	4, 0x90
	.type	SDL_Surface.276,@function
SDL_Surface.276:                        # @SDL_Surface.276
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end280:
	.size	SDL_Surface.276, .Lfunc_end280-SDL_Surface.276
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.277            # -- Begin function SDL_Rect.277
	.p2align	4, 0x90
	.type	SDL_Rect.277,@function
SDL_Rect.277:                           # @SDL_Rect.277
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end281:
	.size	SDL_Rect.277, .Lfunc_end281-SDL_Rect.277
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.278         # -- Begin function SDL_Surface.278
	.p2align	4, 0x90
	.type	SDL_Surface.278,@function
SDL_Surface.278:                        # @SDL_Surface.278
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end282:
	.size	SDL_Surface.278, .Lfunc_end282-SDL_Surface.278
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.279            # -- Begin function SDL_Rect.279
	.p2align	4, 0x90
	.type	SDL_Rect.279,@function
SDL_Rect.279:                           # @SDL_Rect.279
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end283:
	.size	SDL_Rect.279, .Lfunc_end283-SDL_Rect.279
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.280         # -- Begin function SDL_Surface.280
	.p2align	4, 0x90
	.type	SDL_Surface.280,@function
SDL_Surface.280:                        # @SDL_Surface.280
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end284:
	.size	SDL_Surface.280, .Lfunc_end284-SDL_Surface.280
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.281            # -- Begin function SDL_Rect.281
	.p2align	4, 0x90
	.type	SDL_Rect.281,@function
SDL_Rect.281:                           # @SDL_Rect.281
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end285:
	.size	SDL_Rect.281, .Lfunc_end285-SDL_Rect.281
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.282            # -- Begin function SDL_Rect.282
	.p2align	4, 0x90
	.type	SDL_Rect.282,@function
SDL_Rect.282:                           # @SDL_Rect.282
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end286:
	.size	SDL_Rect.282, .Lfunc_end286-SDL_Rect.282
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.283            # -- Begin function SDL_Rect.283
	.p2align	4, 0x90
	.type	SDL_Rect.283,@function
SDL_Rect.283:                           # @SDL_Rect.283
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end287:
	.size	SDL_Rect.283, .Lfunc_end287-SDL_Rect.283
	.cfi_endproc
                                        # -- End function
	.globl	SDL_DisplayMode.284     # -- Begin function SDL_DisplayMode.284
	.p2align	4, 0x90
	.type	SDL_DisplayMode.284,@function
SDL_DisplayMode.284:                    # @SDL_DisplayMode.284
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$24, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end288:
	.size	SDL_DisplayMode.284, .Lfunc_end288-SDL_DisplayMode.284
	.cfi_endproc
                                        # -- End function
	.globl	SDL_DisplayMode.285     # -- Begin function SDL_DisplayMode.285
	.p2align	4, 0x90
	.type	SDL_DisplayMode.285,@function
SDL_DisplayMode.285:                    # @SDL_DisplayMode.285
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$24, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end289:
	.size	SDL_DisplayMode.285, .Lfunc_end289-SDL_DisplayMode.285
	.cfi_endproc
                                        # -- End function
	.globl	SDL_DisplayMode.286     # -- Begin function SDL_DisplayMode.286
	.p2align	4, 0x90
	.type	SDL_DisplayMode.286,@function
SDL_DisplayMode.286:                    # @SDL_DisplayMode.286
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$24, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end290:
	.size	SDL_DisplayMode.286, .Lfunc_end290-SDL_DisplayMode.286
	.cfi_endproc
                                        # -- End function
	.globl	SDL_DisplayMode.287     # -- Begin function SDL_DisplayMode.287
	.p2align	4, 0x90
	.type	SDL_DisplayMode.287,@function
SDL_DisplayMode.287:                    # @SDL_DisplayMode.287
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$24, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end291:
	.size	SDL_DisplayMode.287, .Lfunc_end291-SDL_DisplayMode.287
	.cfi_endproc
                                        # -- End function
	.globl	SDL_DisplayMode.288     # -- Begin function SDL_DisplayMode.288
	.p2align	4, 0x90
	.type	SDL_DisplayMode.288,@function
SDL_DisplayMode.288:                    # @SDL_DisplayMode.288
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$24, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end292:
	.size	SDL_DisplayMode.288, .Lfunc_end292-SDL_DisplayMode.288
	.cfi_endproc
                                        # -- End function
	.globl	SDL_DisplayMode.289     # -- Begin function SDL_DisplayMode.289
	.p2align	4, 0x90
	.type	SDL_DisplayMode.289,@function
SDL_DisplayMode.289:                    # @SDL_DisplayMode.289
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$24, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end293:
	.size	SDL_DisplayMode.289, .Lfunc_end293-SDL_DisplayMode.289
	.cfi_endproc
                                        # -- End function
	.globl	SDL_DisplayMode.290     # -- Begin function SDL_DisplayMode.290
	.p2align	4, 0x90
	.type	SDL_DisplayMode.290,@function
SDL_DisplayMode.290:                    # @SDL_DisplayMode.290
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$24, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end294:
	.size	SDL_DisplayMode.290, .Lfunc_end294-SDL_DisplayMode.290
	.cfi_endproc
                                        # -- End function
	.globl	SDL_DisplayMode.291     # -- Begin function SDL_DisplayMode.291
	.p2align	4, 0x90
	.type	SDL_DisplayMode.291,@function
SDL_DisplayMode.291:                    # @SDL_DisplayMode.291
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$24, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end295:
	.size	SDL_DisplayMode.291, .Lfunc_end295-SDL_DisplayMode.291
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.292         # -- Begin function SDL_Surface.292
	.p2align	4, 0x90
	.type	SDL_Surface.292,@function
SDL_Surface.292:                        # @SDL_Surface.292
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end296:
	.size	SDL_Surface.292, .Lfunc_end296-SDL_Surface.292
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.293         # -- Begin function SDL_Surface.293
	.p2align	4, 0x90
	.type	SDL_Surface.293,@function
SDL_Surface.293:                        # @SDL_Surface.293
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end297:
	.size	SDL_Surface.293, .Lfunc_end297-SDL_Surface.293
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.294            # -- Begin function SDL_Rect.294
	.p2align	4, 0x90
	.type	SDL_Rect.294,@function
SDL_Rect.294:                           # @SDL_Rect.294
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end298:
	.size	SDL_Rect.294, .Lfunc_end298-SDL_Rect.294
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.295            # -- Begin function SDL_Rect.295
	.p2align	4, 0x90
	.type	SDL_Rect.295,@function
SDL_Rect.295:                           # @SDL_Rect.295
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end299:
	.size	SDL_Rect.295, .Lfunc_end299-SDL_Rect.295
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.296         # -- Begin function SDL_Surface.296
	.p2align	4, 0x90
	.type	SDL_Surface.296,@function
SDL_Surface.296:                        # @SDL_Surface.296
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end300:
	.size	SDL_Surface.296, .Lfunc_end300-SDL_Surface.296
	.cfi_endproc
                                        # -- End function
	.globl	SDL_JoystickGUID.297    # -- Begin function SDL_JoystickGUID.297
	.p2align	4, 0x90
	.type	SDL_JoystickGUID.297,@function
SDL_JoystickGUID.297:                   # @SDL_JoystickGUID.297
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end301:
	.size	SDL_JoystickGUID.297, .Lfunc_end301-SDL_JoystickGUID.297
	.cfi_endproc
                                        # -- End function
	.globl	SDL_JoystickGUID.298    # -- Begin function SDL_JoystickGUID.298
	.p2align	4, 0x90
	.type	SDL_JoystickGUID.298,@function
SDL_JoystickGUID.298:                   # @SDL_JoystickGUID.298
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end302:
	.size	SDL_JoystickGUID.298, .Lfunc_end302-SDL_JoystickGUID.298
	.cfi_endproc
                                        # -- End function
	.globl	SDL_JoystickGUID.299    # -- Begin function SDL_JoystickGUID.299
	.p2align	4, 0x90
	.type	SDL_JoystickGUID.299,@function
SDL_JoystickGUID.299:                   # @SDL_JoystickGUID.299
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end303:
	.size	SDL_JoystickGUID.299, .Lfunc_end303-SDL_JoystickGUID.299
	.cfi_endproc
                                        # -- End function
	.globl	SDL_JoystickGUID.300    # -- Begin function SDL_JoystickGUID.300
	.p2align	4, 0x90
	.type	SDL_JoystickGUID.300,@function
SDL_JoystickGUID.300:                   # @SDL_JoystickGUID.300
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end304:
	.size	SDL_JoystickGUID.300, .Lfunc_end304-SDL_JoystickGUID.300
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.301           # -- Begin function SDL_RWops.301
	.p2align	4, 0x90
	.type	SDL_RWops.301,@function
SDL_RWops.301:                          # @SDL_RWops.301
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end305:
	.size	SDL_RWops.301, .Lfunc_end305-SDL_RWops.301
	.cfi_endproc
                                        # -- End function
	.globl	SDL_JoystickGUID.302    # -- Begin function SDL_JoystickGUID.302
	.p2align	4, 0x90
	.type	SDL_JoystickGUID.302,@function
SDL_JoystickGUID.302:                   # @SDL_JoystickGUID.302
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end306:
	.size	SDL_JoystickGUID.302, .Lfunc_end306-SDL_JoystickGUID.302
	.cfi_endproc
                                        # -- End function
	.globl	SDL_GameControllerButtonBind.303 # -- Begin function SDL_GameControllerButtonBind.303
	.p2align	4, 0x90
	.type	SDL_GameControllerButtonBind.303,@function
SDL_GameControllerButtonBind.303:       # @SDL_GameControllerButtonBind.303
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$12, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end307:
	.size	SDL_GameControllerButtonBind.303, .Lfunc_end307-SDL_GameControllerButtonBind.303
	.cfi_endproc
                                        # -- End function
	.globl	SDL_GameControllerButtonBind.304 # -- Begin function SDL_GameControllerButtonBind.304
	.p2align	4, 0x90
	.type	SDL_GameControllerButtonBind.304,@function
SDL_GameControllerButtonBind.304:       # @SDL_GameControllerButtonBind.304
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$12, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end308:
	.size	SDL_GameControllerButtonBind.304, .Lfunc_end308-SDL_GameControllerButtonBind.304
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Finger.305          # -- Begin function SDL_Finger.305
	.p2align	4, 0x90
	.type	SDL_Finger.305,@function
SDL_Finger.305:                         # @SDL_Finger.305
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$32, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end309:
	.size	SDL_Finger.305, .Lfunc_end309-SDL_Finger.305
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.306           # -- Begin function SDL_RWops.306
	.p2align	4, 0x90
	.type	SDL_RWops.306,@function
SDL_RWops.306:                          # @SDL_RWops.306
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end310:
	.size	SDL_RWops.306, .Lfunc_end310-SDL_RWops.306
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.307           # -- Begin function SDL_RWops.307
	.p2align	4, 0x90
	.type	SDL_RWops.307,@function
SDL_RWops.307:                          # @SDL_RWops.307
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end311:
	.size	SDL_RWops.307, .Lfunc_end311-SDL_RWops.307
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RWops.308           # -- Begin function SDL_RWops.308
	.p2align	4, 0x90
	.type	SDL_RWops.308,@function
SDL_RWops.308:                          # @SDL_RWops.308
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end312:
	.size	SDL_RWops.308, .Lfunc_end312-SDL_RWops.308
	.cfi_endproc
                                        # -- End function
	.globl	SDL_MessageBoxButtonData.309 # -- Begin function SDL_MessageBoxButtonData.309
	.p2align	4, 0x90
	.type	SDL_MessageBoxButtonData.309,@function
SDL_MessageBoxButtonData.309:           # @SDL_MessageBoxButtonData.309
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end313:
	.size	SDL_MessageBoxButtonData.309, .Lfunc_end313-SDL_MessageBoxButtonData.309
	.cfi_endproc
                                        # -- End function
	.globl	SDL_MessageBoxColorScheme.310 # -- Begin function SDL_MessageBoxColorScheme.310
	.p2align	4, 0x90
	.type	SDL_MessageBoxColorScheme.310,@function
SDL_MessageBoxColorScheme.310:          # @SDL_MessageBoxColorScheme.310
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end314:
	.size	SDL_MessageBoxColorScheme.310, .Lfunc_end314-SDL_MessageBoxColorScheme.310
	.cfi_endproc
                                        # -- End function
	.globl	SDL_MessageBoxData.311  # -- Begin function SDL_MessageBoxData.311
	.p2align	4, 0x90
	.type	SDL_MessageBoxData.311,@function
SDL_MessageBoxData.311:                 # @SDL_MessageBoxData.311
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$56, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end315:
	.size	SDL_MessageBoxData.311, .Lfunc_end315-SDL_MessageBoxData.311
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RendererInfo.312    # -- Begin function SDL_RendererInfo.312
	.p2align	4, 0x90
	.type	SDL_RendererInfo.312,@function
SDL_RendererInfo.312:                   # @SDL_RendererInfo.312
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$88, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end316:
	.size	SDL_RendererInfo.312, .Lfunc_end316-SDL_RendererInfo.312
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.313         # -- Begin function SDL_Surface.313
	.p2align	4, 0x90
	.type	SDL_Surface.313,@function
SDL_Surface.313:                        # @SDL_Surface.313
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end317:
	.size	SDL_Surface.313, .Lfunc_end317-SDL_Surface.313
	.cfi_endproc
                                        # -- End function
	.globl	SDL_RendererInfo.314    # -- Begin function SDL_RendererInfo.314
	.p2align	4, 0x90
	.type	SDL_RendererInfo.314,@function
SDL_RendererInfo.314:                   # @SDL_RendererInfo.314
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$88, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end318:
	.size	SDL_RendererInfo.314, .Lfunc_end318-SDL_RendererInfo.314
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.315         # -- Begin function SDL_Surface.315
	.p2align	4, 0x90
	.type	SDL_Surface.315,@function
SDL_Surface.315:                        # @SDL_Surface.315
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end319:
	.size	SDL_Surface.315, .Lfunc_end319-SDL_Surface.315
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.316            # -- Begin function SDL_Rect.316
	.p2align	4, 0x90
	.type	SDL_Rect.316,@function
SDL_Rect.316:                           # @SDL_Rect.316
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end320:
	.size	SDL_Rect.316, .Lfunc_end320-SDL_Rect.316
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.317            # -- Begin function SDL_Rect.317
	.p2align	4, 0x90
	.type	SDL_Rect.317,@function
SDL_Rect.317:                           # @SDL_Rect.317
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end321:
	.size	SDL_Rect.317, .Lfunc_end321-SDL_Rect.317
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.318            # -- Begin function SDL_Rect.318
	.p2align	4, 0x90
	.type	SDL_Rect.318,@function
SDL_Rect.318:                           # @SDL_Rect.318
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end322:
	.size	SDL_Rect.318, .Lfunc_end322-SDL_Rect.318
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.319            # -- Begin function SDL_Rect.319
	.p2align	4, 0x90
	.type	SDL_Rect.319,@function
SDL_Rect.319:                           # @SDL_Rect.319
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end323:
	.size	SDL_Rect.319, .Lfunc_end323-SDL_Rect.319
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.320            # -- Begin function SDL_Rect.320
	.p2align	4, 0x90
	.type	SDL_Rect.320,@function
SDL_Rect.320:                           # @SDL_Rect.320
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end324:
	.size	SDL_Rect.320, .Lfunc_end324-SDL_Rect.320
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.321            # -- Begin function SDL_Rect.321
	.p2align	4, 0x90
	.type	SDL_Rect.321,@function
SDL_Rect.321:                           # @SDL_Rect.321
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end325:
	.size	SDL_Rect.321, .Lfunc_end325-SDL_Rect.321
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.322            # -- Begin function SDL_Rect.322
	.p2align	4, 0x90
	.type	SDL_Rect.322,@function
SDL_Rect.322:                           # @SDL_Rect.322
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end326:
	.size	SDL_Rect.322, .Lfunc_end326-SDL_Rect.322
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Point.323           # -- Begin function SDL_Point.323
	.p2align	4, 0x90
	.type	SDL_Point.323,@function
SDL_Point.323:                          # @SDL_Point.323
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$8, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end327:
	.size	SDL_Point.323, .Lfunc_end327-SDL_Point.323
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Point.324           # -- Begin function SDL_Point.324
	.p2align	4, 0x90
	.type	SDL_Point.324,@function
SDL_Point.324:                          # @SDL_Point.324
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$8, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end328:
	.size	SDL_Point.324, .Lfunc_end328-SDL_Point.324
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.325            # -- Begin function SDL_Rect.325
	.p2align	4, 0x90
	.type	SDL_Rect.325,@function
SDL_Rect.325:                           # @SDL_Rect.325
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end329:
	.size	SDL_Rect.325, .Lfunc_end329-SDL_Rect.325
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.326            # -- Begin function SDL_Rect.326
	.p2align	4, 0x90
	.type	SDL_Rect.326,@function
SDL_Rect.326:                           # @SDL_Rect.326
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end330:
	.size	SDL_Rect.326, .Lfunc_end330-SDL_Rect.326
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.327            # -- Begin function SDL_Rect.327
	.p2align	4, 0x90
	.type	SDL_Rect.327,@function
SDL_Rect.327:                           # @SDL_Rect.327
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end331:
	.size	SDL_Rect.327, .Lfunc_end331-SDL_Rect.327
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.328            # -- Begin function SDL_Rect.328
	.p2align	4, 0x90
	.type	SDL_Rect.328,@function
SDL_Rect.328:                           # @SDL_Rect.328
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end332:
	.size	SDL_Rect.328, .Lfunc_end332-SDL_Rect.328
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.329            # -- Begin function SDL_Rect.329
	.p2align	4, 0x90
	.type	SDL_Rect.329,@function
SDL_Rect.329:                           # @SDL_Rect.329
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end333:
	.size	SDL_Rect.329, .Lfunc_end333-SDL_Rect.329
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.330            # -- Begin function SDL_Rect.330
	.p2align	4, 0x90
	.type	SDL_Rect.330,@function
SDL_Rect.330:                           # @SDL_Rect.330
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end334:
	.size	SDL_Rect.330, .Lfunc_end334-SDL_Rect.330
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.331            # -- Begin function SDL_Rect.331
	.p2align	4, 0x90
	.type	SDL_Rect.331,@function
SDL_Rect.331:                           # @SDL_Rect.331
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end335:
	.size	SDL_Rect.331, .Lfunc_end335-SDL_Rect.331
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.332            # -- Begin function SDL_Rect.332
	.p2align	4, 0x90
	.type	SDL_Rect.332,@function
SDL_Rect.332:                           # @SDL_Rect.332
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end336:
	.size	SDL_Rect.332, .Lfunc_end336-SDL_Rect.332
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Point.333           # -- Begin function SDL_Point.333
	.p2align	4, 0x90
	.type	SDL_Point.333,@function
SDL_Point.333:                          # @SDL_Point.333
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$8, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end337:
	.size	SDL_Point.333, .Lfunc_end337-SDL_Point.333
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Rect.334            # -- Begin function SDL_Rect.334
	.p2align	4, 0x90
	.type	SDL_Rect.334,@function
SDL_Rect.334:                           # @SDL_Rect.334
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end338:
	.size	SDL_Rect.334, .Lfunc_end338-SDL_Rect.334
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Surface.335         # -- Begin function SDL_Surface.335
	.p2align	4, 0x90
	.type	SDL_Surface.335,@function
SDL_Surface.335:                        # @SDL_Surface.335
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$96, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end339:
	.size	SDL_Surface.335, .Lfunc_end339-SDL_Surface.335
	.cfi_endproc
                                        # -- End function
	.globl	SDL_Color.336           # -- Begin function SDL_Color.336
	.p2align	4, 0x90
	.type	SDL_Color.336,@function
SDL_Color.336:                          # @SDL_Color.336
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$4, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end340:
	.size	SDL_Color.336, .Lfunc_end340-SDL_Color.336
	.cfi_endproc
                                        # -- End function
	.globl	SDL_WindowShapeParams.337 # -- Begin function SDL_WindowShapeParams.337
	.p2align	4, 0x90
	.type	SDL_WindowShapeParams.337,@function
SDL_WindowShapeParams.337:              # @SDL_WindowShapeParams.337
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$5, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end341:
	.size	SDL_WindowShapeParams.337, .Lfunc_end341-SDL_WindowShapeParams.337
	.cfi_endproc
                                        # -- End function
	.globl	SDL_WindowShapeMode.338 # -- Begin function SDL_WindowShapeMode.338
	.p2align	4, 0x90
	.type	SDL_WindowShapeMode.338,@function
SDL_WindowShapeMode.338:                # @SDL_WindowShapeMode.338
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$12, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end342:
	.size	SDL_WindowShapeMode.338, .Lfunc_end342-SDL_WindowShapeMode.338
	.cfi_endproc
                                        # -- End function
	.globl	SDL_WindowShapeMode.339 # -- Begin function SDL_WindowShapeMode.339
	.p2align	4, 0x90
	.type	SDL_WindowShapeMode.339,@function
SDL_WindowShapeMode.339:                # @SDL_WindowShapeMode.339
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$12, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end343:
	.size	SDL_WindowShapeMode.339, .Lfunc_end343-SDL_WindowShapeMode.339
	.cfi_endproc
                                        # -- End function
	.globl	SDL_version.340         # -- Begin function SDL_version.340
	.p2align	4, 0x90
	.type	SDL_version.340,@function
SDL_version.340:                        # @SDL_version.340
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$3, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end344:
	.size	SDL_version.340, .Lfunc_end344-SDL_version.340
	.cfi_endproc
                                        # -- End function
	.globl	Struct.342              # -- Begin function Struct.342
	.p2align	4, 0x90
	.type	Struct.342,@function
Struct.342:                             # @Struct.342
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$8, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end345:
	.size	Struct.342, .Lfunc_end345-Struct.342
	.cfi_endproc
                                        # -- End function
	.globl	Struct.343              # -- Begin function Struct.343
	.p2align	4, 0x90
	.type	Struct.343,@function
Struct.343:                             # @Struct.343
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$8, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end346:
	.size	Struct.343, .Lfunc_end346-Struct.343
	.cfi_endproc
                                        # -- End function
	.globl	Struct.344              # -- Begin function Struct.344
	.p2align	4, 0x90
	.type	Struct.344,@function
Struct.344:                             # @Struct.344
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$8, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end347:
	.size	Struct.344, .Lfunc_end347-Struct.344
	.cfi_endproc
                                        # -- End function
	.globl	NestStruct.345          # -- Begin function NestStruct.345
	.p2align	4, 0x90
	.type	NestStruct.345,@function
NestStruct.345:                         # @NestStruct.345
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end348:
	.size	NestStruct.345, .Lfunc_end348-NestStruct.345
	.cfi_endproc
                                        # -- End function
	.globl	NestStruct.346          # -- Begin function NestStruct.346
	.p2align	4, 0x90
	.type	NestStruct.346,@function
NestStruct.346:                         # @NestStruct.346
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$16, %edi
	callq	malloc
	popq	%rcx
	retq
.Lfunc_end349:
	.size	NestStruct.346, .Lfunc_end349-NestStruct.346
	.cfi_endproc
                                        # -- End function
	.type	.LTESTES,@object        # @TESTES
	.section	.rodata.str1.1,"aMS",@progbits,1
.LTESTES:
	.asciz	"TESTES"
	.size	.LTESTES, 7

	.type	.Lwinddow,@object       # @winddow
.Lwinddow:
	.asciz	"winddow"
	.size	.Lwinddow, 8

	.type	".Lis succeeded:",@object # @"is succeeded:"
".Lis succeeded:":
	.asciz	"is succeeded:"
	.size	".Lis succeeded:", 14

	.type	.Laa,@object            # @aa
.Laa:
	.asciz	"aa"
	.size	.Laa, 3


	.section	".note.GNU-stack","",@progbits
