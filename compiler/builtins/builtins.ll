; ModuleID = '../builtins/builtins.c'
source_filename = "../builtins/builtins.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.List = type { i64, i64, i64, i8* }
%struct.String = type { i8*, i64 }

@.str = private unnamed_addr constant [73 x i8] c"\1B[31mCRITICAL ERROR:\1B[39m failed to realloc at appending element to list\00", align 1
@.str.1 = private unnamed_addr constant [31 x i8] c"Error: list index out of range\00", align 1
@.str.2 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@.str.3 = private unnamed_addr constant [5 x i8] c"%lld\00", align 1
@.str.4 = private unnamed_addr constant [4 x i8] c"%lf\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define %struct.List* @list_constructor(i64) #0 {
  %2 = alloca i64, align 8
  %3 = alloca %struct.List*, align 8
  store i64 %0, i64* %2, align 8
  %4 = call noalias i8* @malloc(i64 32) #5
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

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #1

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
  %19 = ptrtoint i8* %18 to i8
  %20 = load i8*, i8** %6, align 8
  %21 = load i64, i64* %8, align 8
  %22 = load i64, i64* %10, align 8
  %23 = mul nsw i64 %21, %22
  %24 = getelementptr inbounds i8, i8* %20, i64 %23
  store i8 %19, i8* %24, align 1
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
  %6 = call noalias i8* @malloc(i64 16) #5
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
  %13 = call noalias i8* @malloc(i64 %12) #5
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
  store i64 0, i64* %4, align 8
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
  store i64 1, i64* %4, align 8
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
  %33 = call noalias i8* @malloc(i64 %32) #5
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
  %7 = call noalias i8* @malloc(i64 %6) #5
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

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final)"}
