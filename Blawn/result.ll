; ModuleID = 'Blawn'
source_filename = "Blawn"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%Struct = type { i16, i64 }
%TestClass = type { %T1* }
%T1 = type { i64 }
%NestStruct.0 = type { i16, i16, %Struct }
%struct.String = type { i8*, i64 }
%ct = type { i16**, i64 }
%Person = type { %struct.String* }
%NestStruct = type { i16, i16, %Struct }
%struct.List = type { i64, i64, i64, i8* }

@0 = private unnamed_addr constant [5 x i8] c"John\00"
@1 = private unnamed_addr constant [5 x i8] c"Tom!\00"
@2 = private unnamed_addr constant [7 x i8] c"person\00"
@3 = private unnamed_addr constant [1 x i8] zeroinitializer
@4 = private unnamed_addr constant [10 x i8] c"succeed!!\00"
@pass = global i64 0
@5 = private unnamed_addr constant [2 x i8] c"a\00"
@false = global i1 false
@.str = private unnamed_addr constant [73 x i8] c"\1B[31mCRITICAL ERROR:\1B[39m failed to realloc at appending element to list\00", align 1
@.str.1 = private unnamed_addr constant [31 x i8] c"Error: list index out of range\00", align 1
@.str.2 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@.str.3 = private unnamed_addr constant [5 x i8] c"%lld\00", align 1
@.str.4 = private unnamed_addr constant [4 x i8] c"%lf\00", align 1

declare i64* @malloc(i64)

declare void @free(i64*)

define i8 @main() {
entry:
  %"@member" = alloca i16
  store i16 0, i16* %"@member"
  %0 = load i16, i16* %"@member"
  %"@member2" = alloca i64
  store i64 0, i64* %"@member2"
  %1 = load i64, i64* %"@member2"
  %2 = alloca %Struct
  %3 = load %Struct, %Struct* %2
  %"@member1" = alloca i16
  store i16 0, i16* %"@member1"
  %4 = load i16, i16* %"@member1"
  %"@member22" = alloca i16
  store i16 0, i16* %"@member22"
  %5 = load i16, i16* %"@member22"
  %6 = alloca %Struct
  %7 = load %Struct, %Struct* %6
  %"@s" = alloca %Struct
  store %Struct %7, %Struct* %"@s"
  %8 = load %Struct, %Struct* %"@s"
  %9 = call %TestClass* @TestClass.5()
  %ti = alloca %TestClass*
  store %TestClass* %9, %TestClass** %ti
  %10 = load %TestClass*, %TestClass** %ti
  %11 = call %NestStruct.0* @NestStruct.7()
  %ns = alloca %NestStruct.0*
  store %NestStruct.0* %11, %NestStruct.0** %ns
  %12 = load %NestStruct.0*, %NestStruct.0** %ns
  %13 = load %TestClass*, %TestClass** %ti
  %14 = getelementptr inbounds %TestClass, %TestClass* %13, i32 0, i32 0
  %15 = load %T1*, %T1** %14
  %16 = getelementptr inbounds %T1, %T1* %15, i32 0, i32 0
  %17 = load i64, i64* %16
  %18 = call %struct.String* @int_to_str(i64 %17)
  call void @print(%struct.String* %18)
  %19 = call %ct* @ct.9()
  %insct = alloca %ct*
  store %ct* %19, %ct** %insct
  %20 = load %ct*, %ct** %insct
  %21 = load %ct*, %ct** %insct
  %22 = getelementptr inbounds %ct, %ct* %21, i32 0, i32 1
  %23 = load i64, i64* %22
  %24 = call %struct.String* @int_to_str(i64 %23)
  call void @print(%struct.String* %24)
  %25 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @0, i32 0, i32 0), i64 4)
  %26 = call %Person* @Person.11(%struct.String* %25)
  %p = alloca %Person*
  store %Person* %26, %Person** %p
  %27 = load %Person*, %Person** %p
  %28 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @1, i32 0, i32 0), i64 4)
  %29 = call %Person* @Person.11(%struct.String* %28)
  %p2 = alloca %Person*
  store %Person* %29, %Person** %p2
  %30 = load %Person*, %Person** %p2
  %i = alloca i64
  store i64 0, i64* %i
  %31 = load i64, i64* %i
  %32 = load i64, i64* %i
  %33 = add i64 %32, 1
  store i64 %33, i64* %i
  %34 = load i64, i64* %i
  br label %for

for:                                              ; preds = %for, %entry
  %35 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @2, i32 0, i32 0), i64 6)
  %36 = call %Person* @Person.11(%struct.String* %35)
  %new = alloca %Person*
  store %Person* %36, %Person** %new
  %37 = load %Person*, %Person** %new
  %38 = bitcast %Person* %36 to i64*
  call void @free(i64* %38)
  %39 = load i64, i64* %i
  %40 = icmp slt i64 %39, 100
  %41 = icmp eq i1 false, %40
  %42 = load i64, i64* %i
  %43 = load i64, i64* %i
  %44 = add i64 %43, 1
  store i64 %44, i64* %i
  %45 = load i64, i64* %i
  br i1 %41, label %"merge of for", label %for

"merge of for":                                   ; preds = %for
  %46 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([1 x i8], [1 x i8]* @3, i32 0, i32 0), i64 0)
  %d = alloca %struct.String*
  store %struct.String* %46, %struct.String** %d
  %47 = load %struct.String*, %struct.String** %d
  %48 = load %struct.String*, %struct.String** %d
  call void @print(%struct.String* %48)
  %49 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @4, i32 0, i32 0), i64 9)
  call void @print(%struct.String* %49)
  store i64 0, i64* @pass
  %50 = load i64, i64* @pass
  br label %for3

for3:                                             ; preds = %for3, %"merge of for"
  %51 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @5, i32 0, i32 0), i64 1)
  call void @print(%struct.String* %51)
  %52 = bitcast %Person* %36 to i64*
  call void @free(i64* %52)
  store i1 false, i1* @false
  %53 = load i1, i1* @false
  %54 = icmp eq i1 false, %53
  %55 = load i64, i64* @pass
  br i1 %54, label %"merge of for4", label %for3

"merge of for4":                                  ; preds = %for3
  %56 = load %Person*, %Person** %p
  call void @f.13(%Person* %56)
  %57 = bitcast %Person* %29 to i64*
  call void @free(i64* %57)
  %58 = bitcast %Person* %26 to i64*
  call void @free(i64* %58)
  %59 = bitcast %ct* %19 to i64*
  call void @free(i64* %59)
  %60 = bitcast %NestStruct.0* %11 to i64*
  call void @free(i64* %60)
  %61 = bitcast %TestClass* %9 to i64*
  call void @free(i64* %61)
  ret i8 0
}

declare void @Struct()

declare void @NestStruct()

declare %Struct @load(%Struct*)

declare i16 @main.1()

declare i16 @TEST_no_arg_func()

declare i16 @TEST_arg_func(i16)

declare i16 @TEST_struct_arg_func(%Struct*)

declare %Struct* @TEST_return_struct_func()

declare i16 @TEST_arg_nest_struct(%NestStruct*)

declare %NestStruct* @TEST_return_nest_struct()

declare void @T1()

declare void @TestClass()

define %T1* @T1.4() {
entry:
  %"@num" = alloca i64
  store i64 0, i64* %"@num"
  %0 = load i64, i64* %"@num"
  %1 = call i64* @malloc(i64 8)
  %2 = bitcast i64* %1 to %T1*
  %3 = getelementptr inbounds %T1, %T1* %2, i32 0, i32 0
  store i64 %0, i64* %3
  ret %T1* %2
}

define void @"destructor<T1>"(%T1*) {
entry:
  %1 = bitcast %T1* %0 to i64*
  call void @free(i64* %1)
  ret void
}

define %TestClass* @TestClass.5() {
entry:
  %0 = call %T1* @T1.4()
  %"@c_m" = alloca %T1*
  store %T1* %0, %T1** %"@c_m"
  %1 = load %T1*, %T1** %"@c_m"
  %2 = call i64* @malloc(i64 8)
  %3 = bitcast i64* %2 to %TestClass*
  %4 = getelementptr inbounds %TestClass, %TestClass* %3, i32 0, i32 0
  store %T1* %1, %T1** %4
  ret %TestClass* %3
}

define void @"destructor<TestClass>"(%TestClass*) {
entry:
  %1 = bitcast %TestClass* %0 to i64*
  call void @free(i64* %1)
  ret void
}

define %NestStruct.0* @NestStruct.7() {
entry:
  %"@member" = alloca i16
  store i16 0, i16* %"@member"
  %0 = load i16, i16* %"@member"
  %"@member2" = alloca i16
  store i16 0, i16* %"@member2"
  %1 = load i16, i16* %"@member2"
  %2 = alloca %Struct
  %3 = load %Struct, %Struct* %2
  %"@s" = alloca %Struct
  store %Struct %3, %Struct* %"@s"
  %4 = load %Struct, %Struct* %"@s"
  %5 = call i64* @malloc(i64 16)
  %6 = bitcast i64* %5 to %NestStruct.0*
  %7 = getelementptr inbounds %NestStruct.0, %NestStruct.0* %6, i32 0, i32 0
  store i16 %0, i16* %7
  %8 = getelementptr inbounds %NestStruct.0, %NestStruct.0* %6, i32 0, i32 1
  store i16 %1, i16* %8
  %9 = getelementptr inbounds %NestStruct.0, %NestStruct.0* %6, i32 0, i32 2
  store %Struct %4, %Struct* %9
  ret %NestStruct.0* %6
}

define void @"destructor<NestStruct>"(%NestStruct.0*) {
entry:
  %1 = bitcast %NestStruct.0* %0 to i64*
  call void @free(i64* %1)
  ret void
}

declare void @ct()

declare void @nnn()

define %ct* @ct.9() {
entry:
  %"@n" = alloca i16**
  store i16** null, i16*** %"@n"
  %0 = load i16**, i16*** %"@n"
  %"@ctmem" = alloca i64
  store i64 0, i64* %"@ctmem"
  %1 = load i64, i64* %"@ctmem"
  %2 = call i64* @malloc(i64 16)
  %3 = bitcast i64* %2 to %ct*
  %4 = getelementptr inbounds %ct, %ct* %3, i32 0, i32 0
  store i16** %0, i16*** %4
  %5 = getelementptr inbounds %ct, %ct* %3, i32 0, i32 1
  store i64 %1, i64* %5
  ret %ct* %3
}

define void @"destructor<ct>"(%ct*) {
entry:
  %1 = bitcast %ct* %0 to i64*
  call void @free(i64* %1)
  ret void
}

declare i16 @dx_init()

declare i16 @dx_waitkey()

declare i16 @dx_end()

declare void @type()

declare void @List()

declare void @Person()

define %Person* @Person.11(%struct.String* %name) {
entry:
  %"@name" = alloca %struct.String*
  store %struct.String* %name, %struct.String** %"@name"
  %0 = load %struct.String*, %struct.String** %"@name"
  %1 = call i64* @malloc(i64 8)
  %2 = bitcast i64* %1 to %Person*
  %3 = getelementptr inbounds %Person, %Person* %2, i32 0, i32 0
  store %struct.String* %0, %struct.String** %3
  ret %Person* %2
}

define void @"destructor<Person>"(%Person*) {
entry:
  %1 = bitcast %Person* %0 to i64*
  call void @free(i64* %1)
  ret void
}

declare void @f()

define void @f.13(%Person* %arg) {
entry:
  %0 = getelementptr inbounds %Person, %Person* %arg, i32 0, i32 0
  %1 = load %struct.String*, %struct.String** %0
  call void @print(%struct.String* %1)
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define %struct.List* @list_constructor(i64) #0 {
  %2 = alloca i64, align 8
  %3 = alloca %struct.List*, align 8
  store i64 %0, i64* %2, align 8
  %4 = call noalias i8* bitcast (i64* (i64)* @malloc to i8* (i64)*)(i64 32) #5
  %5 = bitcast i8* %4 to %struct.List*
  store %struct.List* %5, %struct.List** %3, align 8
  %6 = load %struct.List*, %struct.List** %3, align 8
  %7 = getelementptr inbounds %struct.List, %struct.List* %6, i32 0, i32 3
  store i8* null, i8** %7, align 8
  %8 = load i64, i64* %2, align 8
  %9 = load %struct.List*, %struct.List** %3, align 8
  %10 = getelementptr inbounds %struct.List, %struct.List* %9, i32 0, i32 2
  store i64 %8, i64* %10, align 8
  %11 = load %struct.List*, %struct.List** %3, align 8
  %12 = getelementptr inbounds %struct.List, %struct.List* %11, i32 0, i32 0
  store i64 0, i64* %12, align 8
  %13 = load %struct.List*, %struct.List** %3, align 8
  %14 = getelementptr inbounds %struct.List, %struct.List* %13, i32 0, i32 1
  store i64 1, i64* %14, align 8
  %15 = load %struct.List*, %struct.List** %3, align 8
  ret %struct.List* %15
}

; Function Attrs: noinline nounwind optnone uwtable
define i8* @blawn_realloc(i8*, i64, i64) #0 {
  %4 = alloca i8*, align 8
  %5 = alloca i64, align 8
  %6 = alloca i64, align 8
  %7 = alloca i8*, align 8
  store i8* %0, i8** %4, align 8
  store i64 %1, i64* %5, align 8
  store i64 %2, i64* %6, align 8
  %8 = load i8*, i8** %4, align 8
  %9 = load i64, i64* %5, align 8
  %10 = load i64, i64* %6, align 8
  %11 = mul nsw i64 %9, %10
  %12 = call i8* @realloc(i8* %8, i64 %11) #5
  store i8* %12, i8** %7, align 8
  %13 = load i8*, i8** %7, align 8
  %14 = icmp eq i8* %13, null
  br i1 %14, label %15, label %17

; <label>:15:                                     ; preds = %3
  %16 = call i32 @puts(i8* getelementptr inbounds ([73 x i8], [73 x i8]* @.str, i32 0, i32 0))
  call void @exit(i32 1) #6
  unreachable

; <label>:17:                                     ; preds = %3
  %18 = load i8*, i8** %7, align 8
  ret i8* %18
}

; Function Attrs: nounwind
declare i8* @realloc(i8*, i64) #1

declare i32 @puts(i8*) #2

; Function Attrs: noreturn nounwind
declare void @exit(i32) #3

; Function Attrs: noinline nounwind optnone uwtable
define void @blawn_memcpy(i8*, i64, i64, i8*) #0 {
  %5 = alloca i8*, align 8
  %6 = alloca i64, align 8
  %7 = alloca i64, align 8
  %8 = alloca i8*, align 8
  store i8* %0, i8** %5, align 8
  store i64 %1, i64* %6, align 8
  store i64 %2, i64* %7, align 8
  store i8* %3, i8** %8, align 8
  %9 = load i8*, i8** %5, align 8
  %10 = load i64, i64* %6, align 8
  %11 = load i64, i64* %7, align 8
  %12 = mul nsw i64 %10, %11
  %13 = getelementptr i8, i8* %9, i64 %12
  %14 = bitcast i8** %8 to i8*
  %15 = load i64, i64* %7, align 8
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %13, i8* %14, i64 %15, i32 1, i1 false)
  ret void
}

; Function Attrs: argmemonly nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture writeonly, i8* nocapture readonly, i64, i32, i1) #4

; Function Attrs: noinline nounwind optnone uwtable
define i8* @blawn_index(i8*, i64, i64, i64) #0 {
  %5 = alloca i8*, align 8
  %6 = alloca i64, align 8
  %7 = alloca i64, align 8
  %8 = alloca i64, align 8
  store i8* %0, i8** %5, align 8
  store i64 %1, i64* %6, align 8
  store i64 %2, i64* %7, align 8
  store i64 %3, i64* %8, align 8
  %9 = load i64, i64* %8, align 8
  %10 = icmp sle i64 0, %9
  br i1 %10, label %11, label %21

; <label>:11:                                     ; preds = %4
  %12 = load i64, i64* %8, align 8
  %13 = load i64, i64* %6, align 8
  %14 = icmp slt i64 %12, %13
  br i1 %14, label %15, label %21

; <label>:15:                                     ; preds = %11
  %16 = load i8*, i8** %5, align 8
  %17 = load i64, i64* %7, align 8
  %18 = load i64, i64* %8, align 8
  %19 = mul nsw i64 %17, %18
  %20 = getelementptr inbounds i8, i8* %16, i64 %19
  ret i8* %20

; <label>:21:                                     ; preds = %11, %4
  %22 = call i32 @puts(i8* getelementptr inbounds ([31 x i8], [31 x i8]* @.str.1, i32 0, i32 0))
  call void @exit(i32 1) #6
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define void @blawn_set_element(i8*, i64, i64, i8*, i64) #0 {
  %6 = alloca i8*, align 8
  %7 = alloca i64, align 8
  %8 = alloca i64, align 8
  %9 = alloca i8*, align 8
  %10 = alloca i64, align 8
  store i8* %0, i8** %6, align 8
  store i64 %1, i64* %7, align 8
  store i64 %2, i64* %8, align 8
  store i8* %3, i8** %9, align 8
  store i64 %4, i64* %10, align 8
  %11 = load i64, i64* %10, align 8
  %12 = icmp sle i64 0, %11
  br i1 %12, label %13, label %25

; <label>:13:                                     ; preds = %5
  %14 = load i64, i64* %10, align 8
  %15 = load i64, i64* %7, align 8
  %16 = icmp slt i64 %14, %15
  br i1 %16, label %17, label %25

; <label>:17:                                     ; preds = %13
  %18 = load i8*, i8** %9, align 8
  %19 = load i8*, i8** %6, align 8
  %20 = load i64, i64* %8, align 8
  %21 = load i64, i64* %10, align 8
  %22 = mul nsw i64 %20, %21
  %23 = getelementptr inbounds i8, i8* %19, i64 %22
  %24 = bitcast i8* %23 to i8**
  store i8* %18, i8** %24, align 8
  br label %27

; <label>:25:                                     ; preds = %13, %5
  %26 = call i32 @puts(i8* getelementptr inbounds ([31 x i8], [31 x i8]* @.str.1, i32 0, i32 0))
  call void @exit(i32 1) #6
  unreachable

; <label>:27:                                     ; preds = %17
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define void @print(%struct.String*) #0 {
  %2 = alloca %struct.String*, align 8
  store %struct.String* %0, %struct.String** %2, align 8
  %3 = load %struct.String*, %struct.String** %2, align 8
  %4 = getelementptr inbounds %struct.String, %struct.String* %3, i32 0, i32 0
  %5 = load i8*, i8** %4, align 8
  %6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.2, i32 0, i32 0), i8* %5)
  ret void
}

declare i32 @printf(i8*, ...) #2

; Function Attrs: noinline nounwind optnone uwtable
define %struct.String* @string_constructor(i8*, i64) #0 {
  %3 = alloca i8*, align 8
  %4 = alloca i64, align 8
  %5 = alloca %struct.String*, align 8
  store i8* %0, i8** %3, align 8
  store i64 %1, i64* %4, align 8
  %6 = call noalias i8* bitcast (i64* (i64)* @malloc to i8* (i64)*)(i64 16) #5
  %7 = bitcast i8* %6 to %struct.String*
  store %struct.String* %7, %struct.String** %5, align 8
  %8 = load i8*, i8** %3, align 8
  %9 = load %struct.String*, %struct.String** %5, align 8
  %10 = getelementptr inbounds %struct.String, %struct.String* %9, i32 0, i32 0
  store i8* %8, i8** %10, align 8
  %11 = load i64, i64* %4, align 8
  %12 = load %struct.String*, %struct.String** %5, align 8
  %13 = getelementptr inbounds %struct.String, %struct.String* %12, i32 0, i32 1
  store i64 %11, i64* %13, align 8
  %14 = load %struct.String*, %struct.String** %5, align 8
  ret %struct.String* %14
}

; Function Attrs: noinline nounwind optnone uwtable
define void @append_string(%struct.String*, %struct.String*) #0 {
  %3 = alloca %struct.String*, align 8
  %4 = alloca %struct.String*, align 8
  %5 = alloca i8*, align 8
  store %struct.String* %0, %struct.String** %3, align 8
  store %struct.String* %1, %struct.String** %4, align 8
  %6 = load %struct.String*, %struct.String** %3, align 8
  %7 = getelementptr inbounds %struct.String, %struct.String* %6, i32 0, i32 1
  %8 = load i64, i64* %7, align 8
  %9 = load %struct.String*, %struct.String** %4, align 8
  %10 = getelementptr inbounds %struct.String, %struct.String* %9, i32 0, i32 1
  %11 = load i64, i64* %10, align 8
  %12 = add nsw i64 %8, %11
  %13 = call noalias i8* bitcast (i64* (i64)* @malloc to i8* (i64)*)(i64 %12) #5
  store i8* %13, i8** %5, align 8
  %14 = load i8*, i8** %5, align 8
  %15 = getelementptr inbounds i8, i8* %14, i64 0
  store i8 0, i8* %15, align 1
  %16 = load i8*, i8** %5, align 8
  %17 = load %struct.String*, %struct.String** %3, align 8
  %18 = getelementptr inbounds %struct.String, %struct.String* %17, i32 0, i32 0
  %19 = load i8*, i8** %18, align 8
  %20 = call i8* @strcat(i8* %16, i8* %19) #5
  %21 = load i8*, i8** %5, align 8
  %22 = load %struct.String*, %struct.String** %4, align 8
  %23 = getelementptr inbounds %struct.String, %struct.String* %22, i32 0, i32 0
  %24 = load i8*, i8** %23, align 8
  %25 = call i8* @strcat(i8* %21, i8* %24) #5
  %26 = load %struct.String*, %struct.String** %4, align 8
  %27 = getelementptr inbounds %struct.String, %struct.String* %26, i32 0, i32 1
  %28 = load i64, i64* %27, align 8
  %29 = load %struct.String*, %struct.String** %3, align 8
  %30 = getelementptr inbounds %struct.String, %struct.String* %29, i32 0, i32 1
  %31 = load i64, i64* %30, align 8
  %32 = add nsw i64 %31, %28
  store i64 %32, i64* %30, align 8
  %33 = load i8*, i8** %5, align 8
  %34 = load %struct.String*, %struct.String** %3, align 8
  %35 = getelementptr inbounds %struct.String, %struct.String* %34, i32 0, i32 0
  store i8* %33, i8** %35, align 8
  ret void
}

; Function Attrs: nounwind
declare i8* @strcat(i8*, i8*) #1

; Function Attrs: noinline nounwind optnone uwtable
define %struct.String* @int_to_str(i64) #0 {
  %2 = alloca i64, align 8
  %3 = alloca i64, align 8
  %4 = alloca i64, align 8
  %5 = alloca i8*, align 8
  store i64 %0, i64* %2, align 8
  %6 = load i64, i64* %2, align 8
  store i64 %6, i64* %3, align 8
  %7 = load i64, i64* %2, align 8
  %8 = icmp sge i64 %7, 0
  br i1 %8, label %9, label %19

; <label>:9:                                      ; preds = %1
  store i64 1, i64* %4, align 8
  br label %10

; <label>:10:                                     ; preds = %13, %9
  %11 = load i64, i64* %2, align 8
  %12 = icmp ne i64 %11, 0
  br i1 %12, label %13, label %18

; <label>:13:                                     ; preds = %10
  %14 = load i64, i64* %2, align 8
  %15 = sdiv i64 %14, 10
  store i64 %15, i64* %2, align 8
  %16 = load i64, i64* %4, align 8
  %17 = add nsw i64 %16, 1
  store i64 %17, i64* %4, align 8
  br label %10

; <label>:18:                                     ; preds = %10
  br label %31

; <label>:19:                                     ; preds = %1
  store i64 2, i64* %4, align 8
  %20 = load i64, i64* %2, align 8
  %21 = sub nsw i64 0, %20
  store i64 %21, i64* %2, align 8
  br label %22

; <label>:22:                                     ; preds = %25, %19
  %23 = load i64, i64* %2, align 8
  %24 = icmp ne i64 %23, 0
  br i1 %24, label %25, label %30

; <label>:25:                                     ; preds = %22
  %26 = load i64, i64* %2, align 8
  %27 = sdiv i64 %26, 10
  store i64 %27, i64* %2, align 8
  %28 = load i64, i64* %4, align 8
  %29 = add nsw i64 %28, 1
  store i64 %29, i64* %4, align 8
  br label %22

; <label>:30:                                     ; preds = %22
  br label %31

; <label>:31:                                     ; preds = %30, %18
  %32 = load i64, i64* %4, align 8
  %33 = call noalias i8* bitcast (i64* (i64)* @malloc to i8* (i64)*)(i64 %32) #5
  store i8* %33, i8** %5, align 8
  %34 = load i8*, i8** %5, align 8
  %35 = load i64, i64* %4, align 8
  %36 = add nsw i64 %35, 1
  %37 = load i64, i64* %3, align 8
  %38 = call i32 (i8*, i64, i8*, ...) @snprintf(i8* %34, i64 %36, i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.3, i32 0, i32 0), i64 %37) #5
  %39 = load i8*, i8** %5, align 8
  %40 = load i64, i64* %4, align 8
  %41 = call %struct.String* @string_constructor(i8* %39, i64 %40)
  ret %struct.String* %41
}

; Function Attrs: nounwind
declare i32 @snprintf(i8*, i64, i8*, ...) #1

; Function Attrs: noinline nounwind optnone uwtable
define %struct.String* @float_to_str(double) #0 {
  %2 = alloca double, align 8
  %3 = alloca i32, align 4
  %4 = alloca i8*, align 8
  store double %0, double* %2, align 8
  store i32 16, i32* %3, align 4
  %5 = load i32, i32* %3, align 4
  %6 = sext i32 %5 to i64
  %7 = call noalias i8* bitcast (i64* (i64)* @malloc to i8* (i64)*)(i64 %6) #5
  store i8* %7, i8** %4, align 8
  %8 = load i8*, i8** %4, align 8
  %9 = load i32, i32* %3, align 4
  %10 = add nsw i32 %9, 1
  %11 = sext i32 %10 to i64
  %12 = load double, double* %2, align 8
  %13 = call i32 (i8*, i64, i8*, ...) @snprintf(i8* %8, i64 %11, i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.4, i32 0, i32 0), double %12) #5
  %14 = load i8*, i8** %4, align 8
  %15 = load i32, i32* %3, align 4
  %16 = sext i32 %15 to i64
  %17 = call %struct.String* @string_constructor(i8* %14, i64 %16)
  ret %struct.String* %17
}

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { noreturn nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { argmemonly nounwind }
attributes #5 = { nounwind }
attributes #6 = { noreturn nounwind }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final)"}
!1 = !{i32 1, !"wchar_size", i32 4}
