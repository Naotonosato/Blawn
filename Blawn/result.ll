; ModuleID = 'Blawn'
source_filename = "Blawn"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%M = type { i64 }
%S = type { i64, %M* }
%Person = type { i64, %S* }
%struct.String = type { i8*, i64 }
%struct.List = type { i64, i64, i64, i8* }

@0 = private unnamed_addr constant [6 x i8] c"start\00"
@m = global %M* null
@si = global %S* null
@p = global %Person* null
@true = global i1 false
@.str = private unnamed_addr constant [73 x i8] c"\1B[31mCRITICAL ERROR:\1B[39m failed to realloc at appending element to list\00", align 1
@.str.1 = private unnamed_addr constant [31 x i8] c"Error: list index out of range\00", align 1
@.str.2 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@.str.3 = private unnamed_addr constant [5 x i8] c"%lld\00", align 1
@.str.4 = private unnamed_addr constant [4 x i8] c"%lf\00", align 1

declare i64* @malloc(i64)

declare void @free(i64*)

define i8 @main() {
entry:
  %0 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @0, i32 0, i32 0), i64 5)
  call void @print(%struct.String* %0)
  %1 = call %M* @M.2(i64 0)
  store %M* %1, %M** @m
  %2 = load %M*, %M** @m
  %3 = call %S* @S.4(i64 0, %M* %2)
  store %S* %3, %S** @si
  %4 = load %S*, %S** @si
  %5 = call %Person* @Person.6(i64 0, %S* %4)
  store %Person* %5, %Person** @p
  %6 = load %Person*, %Person** @p
  call void @f.8(%Person* %6)
  %7 = bitcast %Person* %5 to i64*
  call void @free(i64* %7)
  %8 = bitcast %S* %3 to i64*
  call void @free(i64* %8)
  %9 = bitcast %M* %1 to i64*
  call void @free(i64* %9)
  ret i8 0
}

declare void @M()

declare void @S()

declare void @Person()

declare void @n()

declare void @f()

define %M* @M.2(i64 %idm) {
entry:
  %0 = alloca i64
  store i64 %idm, i64* %0
  %1 = load i64, i64* %0
  %"@idm" = alloca i64
  store i64 %1, i64* %"@idm"
  %2 = load i64, i64* %"@idm"
  %3 = call i64* @malloc(i64 8)
  %4 = bitcast i64* %3 to %M*
  %5 = getelementptr inbounds %M, %M* %4, i32 0, i32 0
  store i64 %2, i64* %5
  ret %M* %4
}

define void @"destructor<M>"(%M*) {
entry:
  %1 = bitcast %M* %0 to i64*
  call void @free(i64* %1)
  ret void
}

define %S* @S.4(i64 %id, %M* %m) {
entry:
  %0 = alloca i64
  store i64 %id, i64* %0
  %1 = alloca %M*
  store %M* %m, %M** %1
  %2 = load i64, i64* %0
  %"@id" = alloca i64
  store i64 %2, i64* %"@id"
  %3 = load i64, i64* %"@id"
  %4 = load %M*, %M** %1
  %"@m" = alloca %M*
  store %M* %4, %M** %"@m"
  %5 = load %M*, %M** %"@m"
  %6 = call i64* @malloc(i64 16)
  %7 = bitcast i64* %6 to %S*
  %8 = getelementptr inbounds %S, %S* %7, i32 0, i32 0
  store i64 %3, i64* %8
  %9 = getelementptr inbounds %S, %S* %7, i32 0, i32 1
  store %M* %5, %M** %9
  ret %S* %7
}

define void @"destructor<S>"(%S*) {
entry:
  %1 = bitcast %S* %0 to i64*
  call void @free(i64* %1)
  ret void
}

define %Person* @Person.6(i64 %id, %S* %m) {
entry:
  %0 = alloca i64
  store i64 %id, i64* %0
  %1 = alloca %S*
  store %S* %m, %S** %1
  %2 = load i64, i64* %0
  %"@id" = alloca i64
  store i64 %2, i64* %"@id"
  %3 = load i64, i64* %"@id"
  %4 = load %S*, %S** %1
  %"@m" = alloca %S*
  store %S* %4, %S** %"@m"
  %5 = load %S*, %S** %"@m"
  %6 = call i64* @malloc(i64 16)
  %7 = bitcast i64* %6 to %Person*
  %8 = getelementptr inbounds %Person, %Person* %7, i32 0, i32 0
  store i64 %3, i64* %8
  %9 = getelementptr inbounds %Person, %Person* %7, i32 0, i32 1
  store %S* %5, %S** %9
  ret %Person* %7
}

define void @"destructor<Person>"(%Person*) {
entry:
  %1 = bitcast %Person* %0 to i64*
  call void @free(i64* %1)
  ret void
}

define void @f.8(%Person* %arg) {
entry:
  %0 = alloca %Person*
  store %Person* %arg, %Person** %0
  %1 = call %M* @M.2(i64 10)
  %m2 = alloca %M*
  store %M* %1, %M** %m2
  %2 = load %M*, %M** %m2
  %3 = load %M*, %M** %m2
  %4 = call %S* @S.4(i64 10, %M* %3)
  %s2 = alloca %S*
  store %S* %4, %S** %s2
  %5 = load %S*, %S** %s2
  %6 = load %S*, %S** %s2
  %7 = call %Person* @Person.6(i64 10, %S* %6)
  %p2 = alloca %Person*
  store %Person* %7, %Person** %p2
  %8 = load %Person*, %Person** %p2
  store i1 true, i1* @true
  %9 = load i1, i1* @true
  br i1 %9, label %"then of if expr", label %"else of if_expr"

"then of if expr":                                ; preds = %entry
  %10 = call %M* @M.2(i64 30)
  %m3 = alloca %M*
  store %M* %10, %M** %m3
  %11 = load %M*, %M** %m3
  %12 = load %M*, %M** %m3
  %13 = call %S* @S.4(i64 30, %M* %12)
  %s3 = alloca %S*
  store %S* %13, %S** %s3
  %14 = load %S*, %S** %s3
  %15 = load %S*, %S** %s3
  %16 = call %Person* @Person.6(i64 30, %S* %15)
  %p3 = alloca %Person*
  store %Person* %16, %Person** %p3
  %17 = load %Person*, %Person** %p3
  %18 = load %Person*, %Person** %p2
  %19 = load %Person*, %Person** %p3
  %20 = load %Person, %Person* %19
  %21 = load %Person*, %Person** %p2
  %22 = getelementptr inbounds %Person, %Person* %21, i32 0, i32 0
  %23 = load i64, i64* %22
  %24 = load %Person*, %Person** %p2
  %25 = getelementptr inbounds %Person, %Person* %24, i32 0, i32 0
  %26 = load i64, i64* %25
  %27 = load %Person*, %Person** %p3
  %28 = getelementptr inbounds %Person, %Person* %27, i32 0, i32 0
  %29 = load i64, i64* %28
  %30 = load %Person*, %Person** %p2
  %31 = getelementptr inbounds %Person, %Person* %30, i32 0, i32 1
  %32 = load %S*, %S** %31
  %33 = load %Person*, %Person** %p2
  %34 = getelementptr inbounds %Person, %Person* %33, i32 0, i32 1
  %35 = load %S*, %S** %34
  %36 = load %Person*, %Person** %p2
  %37 = getelementptr inbounds %Person, %Person* %36, i32 0, i32 1
  %38 = load %S*, %S** %37
  %39 = getelementptr inbounds %S, %S* %38, i32 0, i32 0
  %40 = load i64, i64* %39
  %41 = load %Person*, %Person** %p2
  %42 = getelementptr inbounds %Person, %Person* %41, i32 0, i32 1
  %43 = load %S*, %S** %42
  %44 = getelementptr inbounds %S, %S* %43, i32 0, i32 0
  %45 = load i64, i64* %44
  %46 = load %Person*, %Person** %p3
  %47 = getelementptr inbounds %Person, %Person* %46, i32 0, i32 1
  %48 = load %S*, %S** %47
  %49 = getelementptr inbounds %S, %S* %48, i32 0, i32 0
  %50 = load i64, i64* %49
  %51 = load %Person*, %Person** %p2
  %52 = getelementptr inbounds %Person, %Person* %51, i32 0, i32 1
  %53 = load %S*, %S** %52
  %54 = getelementptr inbounds %S, %S* %53, i32 0, i32 1
  %55 = load %M*, %M** %54
  %56 = load %Person*, %Person** %p2
  %57 = getelementptr inbounds %Person, %Person* %56, i32 0, i32 1
  %58 = load %S*, %S** %57
  %59 = getelementptr inbounds %S, %S* %58, i32 0, i32 1
  %60 = load %M*, %M** %59
  %61 = load %Person*, %Person** %p2
  %62 = getelementptr inbounds %Person, %Person* %61, i32 0, i32 1
  %63 = load %S*, %S** %62
  %64 = getelementptr inbounds %S, %S* %63, i32 0, i32 1
  %65 = load %M*, %M** %64
  %66 = getelementptr inbounds %M, %M* %65, i32 0, i32 0
  %67 = load i64, i64* %66
  %68 = load %Person*, %Person** %p2
  %69 = getelementptr inbounds %Person, %Person* %68, i32 0, i32 1
  %70 = load %S*, %S** %69
  %71 = getelementptr inbounds %S, %S* %70, i32 0, i32 1
  %72 = load %M*, %M** %71
  %73 = getelementptr inbounds %M, %M* %72, i32 0, i32 0
  %74 = load i64, i64* %73
  %75 = load %Person*, %Person** %p3
  %76 = getelementptr inbounds %Person, %Person* %75, i32 0, i32 1
  %77 = load %S*, %S** %76
  %78 = getelementptr inbounds %S, %S* %77, i32 0, i32 1
  %79 = load %M*, %M** %78
  %80 = getelementptr inbounds %M, %M* %79, i32 0, i32 0
  %81 = load i64, i64* %80
  store i64 %29, i64* %25
  store i64 %50, i64* %44
  store i64 %81, i64* %73
  %82 = bitcast %Person* %16 to i64*
  call void @free(i64* %82)
  %83 = bitcast %S* %13 to i64*
  call void @free(i64* %83)
  %84 = bitcast %M* %10 to i64*
  call void @free(i64* %84)
  br label %"merge of if_expr"

"else of if_expr":                                ; preds = %entry
  br label %"merge of if_expr"

"merge of if_expr":                               ; preds = %"else of if_expr", %"then of if expr"
  %85 = load %Person*, %Person** %p2
  %86 = getelementptr inbounds %Person, %Person* %85, i32 0, i32 1
  %87 = load %S*, %S** %86
  %88 = getelementptr inbounds %S, %S* %87, i32 0, i32 1
  %89 = load %M*, %M** %88
  %90 = getelementptr inbounds %M, %M* %89, i32 0, i32 0
  %91 = load i64, i64* %90
  %92 = call %struct.String* @int_to_str(i64 %91)
  call void @print(%struct.String* %92)
  %93 = bitcast %Person* %7 to i64*
  call void @free(i64* %93)
  %94 = bitcast %S* %4 to i64*
  call void @free(i64* %94)
  %95 = bitcast %M* %1 to i64*
  call void @free(i64* %95)
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
