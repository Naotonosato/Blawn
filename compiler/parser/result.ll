; ModuleID = 'Blawn'
source_filename = "Blawn"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%V = type { i64 }
%struct.String = type { i8*, i64 }
%List = type { i64, i64, i64, i8* }

@0 = private unnamed_addr constant [10 x i8] c"same size\00"
@1 = private unnamed_addr constant [7 x i8] c"resize\00"
@.str = private unnamed_addr constant [73 x i8] c"\1B[31mCRITICAL ERROR:\1B[39m failed to realloc at appending element to list\00", align 1
@.str.1 = private unnamed_addr constant [31 x i8] c"Error: list index out of range\00", align 1
@.str.2 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1

declare i64* @malloc(i64)

declare void @free(i64*)

define i8 @main() {
entry:
  %0 = call %V* @V.2()
  %v1 = alloca %V*
  store %V* %0, %V** %v1
  %1 = load %V*, %V** %v1
  %2 = call %V* @V.2()
  %v2 = alloca %V*
  store %V* %2, %V** %v2
  %3 = load %V*, %V** %v2
  %4 = load %V*, %V** %v1
  %5 = load %V*, %V** %v2
  br i1 true, label %"then of if expr", label %"else of if_expr"

"then of if expr":                                ; preds = %entry
  %6 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @0, i32 0, i32 0), i64 9)
  call void @print(%struct.String* %6)
  br label %"merge of if_expr"

"else of if_expr":                                ; preds = %entry
  br label %"merge of if_expr"

"merge of if_expr":                               ; preds = %"else of if_expr", %"then of if expr"
  %7 = load %V*, %V** %v1
  %8 = call %List* @List.4(%V* %7)
  %list = alloca %List*
  store %List* %8, %List** %list
  %9 = load %List*, %List** %list
  %10 = load %List*, %List** %list
  %11 = load %List*, %List** %list
  %12 = load %V*, %V** %v2
  call void @append.6(%List* %11, %V* %12)
  %13 = load %List*, %List** %list
  %14 = load %List*, %List** %list
  %15 = load %V*, %V** %v2
  call void @append.6(%List* %14, %V* %15)
  %i = alloca i64
  store i64 0, i64* %i
  %16 = load i64, i64* %i
  %17 = load i64, i64* %i
  %18 = add i64 %17, 1
  store i64 %18, i64* %i
  %19 = load i64, i64* %i
  br label %for

for:                                              ; preds = %for, %"merge of if_expr"
  %20 = load %List*, %List** %list
  %21 = load %List*, %List** %list
  %22 = load %V*, %V** %v1
  call void @append.6(%List* %21, %V* %22)
  %23 = load %List*, %List** %list
  %24 = load %List*, %List** %list
  %25 = load %V*, %V** %v2
  call void @append.6(%List* %24, %V* %25)
  %26 = load i64, i64* %i
  %27 = icmp slt i64 %26, 1000000
  %28 = icmp eq i1 false, %27
  %29 = load i64, i64* %i
  %30 = load i64, i64* %i
  %31 = add i64 %30, 1
  store i64 %31, i64* %i
  %32 = load i64, i64* %i
  br i1 %28, label %"merge of for", label %for

"merge of for":                                   ; preds = %for
  ret i8 0
}

declare void @List()

declare void @C()

declare void @Person()

declare void @V()

define %V* @V.2() {
entry:
  %"@n" = alloca i64
  store i64 0, i64* %"@n"
  %0 = load i64, i64* %"@n"
  %1 = call i64* @malloc(i64 8)
  %2 = bitcast i64* %1 to %V*
  %3 = getelementptr inbounds %V, %V* %2, i32 0, i32 0
  store i64 %0, i64* %3
  ret %V* %2
}

define void @destructor_of_V(%V*) {
entry:
  %1 = bitcast %V* %0 to i64*
  call void @free(i64* %1)
  ret void
}

define %List* @List.4(%V* %element) {
entry:
  %"@size" = alloca i64
  store i64 0, i64* %"@size"
  %0 = load i64, i64* %"@size"
  %"@allocated_size" = alloca i64
  store i64 1, i64* %"@allocated_size"
  %1 = load i64, i64* %"@allocated_size"
  %"@element_size" = alloca i64
  store i64 8, i64* %"@element_size"
  %2 = load i64, i64* %"@element_size"
  %"@array" = alloca i8*
  store i8* null, i8** %"@array"
  %3 = load i8*, i8** %"@array"
  %4 = call i64* @malloc(i64 32)
  %5 = bitcast i64* %4 to %List*
  %6 = getelementptr inbounds %List, %List* %5, i32 0, i32 0
  store i64 %0, i64* %6
  %7 = getelementptr inbounds %List, %List* %5, i32 0, i32 1
  store i64 %1, i64* %7
  %8 = getelementptr inbounds %List, %List* %5, i32 0, i32 2
  store i64 %2, i64* %8
  %9 = getelementptr inbounds %List, %List* %5, i32 0, i32 3
  store i8* %3, i8** %9
  ret %List* %5
}

define void @destructor_of_List(%List*) {
entry:
  %1 = bitcast %List* %0 to i64*
  call void @free(i64* %1)
  ret void
}

define void @resize.5(%List* %self) {
entry:
  %0 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @1, i32 0, i32 0), i64 6)
  call void @print(%struct.String* %0)
  %1 = getelementptr inbounds %List, %List* %self, i32 0, i32 1
  %2 = load i64, i64* %1
  %3 = getelementptr inbounds %List, %List* %self, i32 0, i32 1
  %4 = load i64, i64* %3
  %5 = mul i64 %4, 2
  store i64 %5, i64* %1
  %6 = load i64, i64* %1
  %7 = getelementptr inbounds %List, %List* %self, i32 0, i32 3
  %8 = load i8*, i8** %7
  %9 = getelementptr inbounds %List, %List* %self, i32 0, i32 3
  %10 = load i8*, i8** %9
  %11 = getelementptr inbounds %List, %List* %self, i32 0, i32 2
  %12 = load i64, i64* %11
  %13 = getelementptr inbounds %List, %List* %self, i32 0, i32 1
  %14 = load i64, i64* %13
  %15 = call i8* @blawn_realloc(i8* %10, i64 %12, i64 %14)
  store i8* %15, i8** %7
  %16 = load i8*, i8** %7
  ret void
}

define void @append.6(%List* %self, %V* %new_element) {
entry:
  %0 = getelementptr inbounds %List, %List* %self, i32 0, i32 0
  %1 = load i64, i64* %0
  %2 = add i64 %1, 1
  %3 = getelementptr inbounds %List, %List* %self, i32 0, i32 1
  %4 = load i64, i64* %3
  %5 = icmp sge i64 %2, %4
  br i1 %5, label %"then of if expr", label %"else of if_expr"

"then of if expr":                                ; preds = %entry
  call void @resize.5(%List* %self)
  br label %"merge of if_expr"

"else of if_expr":                                ; preds = %entry
  br label %"merge of if_expr"

"merge of if_expr":                               ; preds = %"else of if_expr", %"then of if expr"
  %6 = getelementptr inbounds %List, %List* %self, i32 0, i32 3
  %7 = load i8*, i8** %6
  %8 = getelementptr inbounds %List, %List* %self, i32 0, i32 0
  %9 = load i64, i64* %8
  %10 = getelementptr inbounds %List, %List* %self, i32 0, i32 2
  %11 = load i64, i64* %10
  %12 = bitcast %V* %new_element to i8*
  call void @blawn_memcpy(i8* %7, i64 %9, i64 %11, i8* %12)
  %13 = getelementptr inbounds %List, %List* %self, i32 0, i32 0
  %14 = load i64, i64* %13
  %15 = getelementptr inbounds %List, %List* %self, i32 0, i32 0
  %16 = load i64, i64* %15
  %17 = add i64 %16, 1
  store i64 %17, i64* %13
  %18 = load i64, i64* %13
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define %List* @list_constructor(i64) #0 {
  %2 = alloca i64, align 8
  %3 = alloca %List*, align 8
  store i64 %0, i64* %2, align 8
  %4 = call noalias i8* bitcast (i64* (i64)* @malloc to i8* (i64)*)(i64 32) #5
  %5 = bitcast i8* %4 to %List*
  store %List* %5, %List** %3, align 8
  %6 = load %List*, %List** %3, align 8
  %7 = getelementptr inbounds %List, %List* %6, i32 0, i32 3
  store i8* null, i8** %7, align 8
  %8 = load i64, i64* %2, align 8
  %9 = load %List*, %List** %3, align 8
  %10 = getelementptr inbounds %List, %List* %9, i32 0, i32 2
  store i64 %8, i64* %10, align 8
  %11 = load %List*, %List** %3, align 8
  %12 = getelementptr inbounds %List, %List* %11, i32 0, i32 0
  store i64 0, i64* %12, align 8
  %13 = load %List*, %List** %3, align 8
  %14 = getelementptr inbounds %List, %List* %13, i32 0, i32 1
  store i64 1, i64* %14, align 8
  %15 = load %List*, %List** %3, align 8
  ret %List* %15
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
define i8* @get_element(%List*, i64) #0 {
  %3 = alloca %List*, align 8
  %4 = alloca i64, align 8
  store %List* %0, %List** %3, align 8
  store i64 %1, i64* %4, align 8
  %5 = load i64, i64* %4, align 8
  %6 = icmp sle i64 0, %5
  br i1 %6, label %7, label %23

; <label>:7:                                      ; preds = %2
  %8 = load i64, i64* %4, align 8
  %9 = load %List*, %List** %3, align 8
  %10 = getelementptr inbounds %List, %List* %9, i32 0, i32 0
  %11 = load i64, i64* %10, align 8
  %12 = icmp slt i64 %8, %11
  br i1 %12, label %13, label %23

; <label>:13:                                     ; preds = %7
  %14 = load %List*, %List** %3, align 8
  %15 = getelementptr inbounds %List, %List* %14, i32 0, i32 3
  %16 = load i8*, i8** %15, align 8
  %17 = load %List*, %List** %3, align 8
  %18 = getelementptr inbounds %List, %List* %17, i32 0, i32 2
  %19 = load i64, i64* %18, align 8
  %20 = load i64, i64* %4, align 8
  %21 = mul nsw i64 %19, %20
  %22 = getelementptr inbounds i8, i8* %16, i64 %21
  ret i8* %22

; <label>:23:                                     ; preds = %7, %2
  %24 = call i32 @puts(i8* getelementptr inbounds ([31 x i8], [31 x i8]* @.str.1, i32 0, i32 0))
  call void @exit(i32 1) #6
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define void @set_element(%List*, i8*, i64) #0 {
  %4 = alloca %List*, align 8
  %5 = alloca i8*, align 8
  %6 = alloca i64, align 8
  store %List* %0, %List** %4, align 8
  store i8* %1, i8** %5, align 8
  store i64 %2, i64* %6, align 8
  %7 = load i64, i64* %6, align 8
  %8 = icmp sle i64 0, %7
  br i1 %8, label %9, label %27

; <label>:9:                                      ; preds = %3
  %10 = load i64, i64* %6, align 8
  %11 = load %List*, %List** %4, align 8
  %12 = getelementptr inbounds %List, %List* %11, i32 0, i32 0
  %13 = load i64, i64* %12, align 8
  %14 = icmp slt i64 %10, %13
  br i1 %14, label %15, label %27

; <label>:15:                                     ; preds = %9
  %16 = load i8*, i8** %5, align 8
  %17 = ptrtoint i8* %16 to i8
  %18 = load %List*, %List** %4, align 8
  %19 = getelementptr inbounds %List, %List* %18, i32 0, i32 3
  %20 = load i8*, i8** %19, align 8
  %21 = load %List*, %List** %4, align 8
  %22 = getelementptr inbounds %List, %List* %21, i32 0, i32 2
  %23 = load i64, i64* %22, align 8
  %24 = load i64, i64* %6, align 8
  %25 = mul nsw i64 %23, %24
  %26 = getelementptr inbounds i8, i8* %20, i64 %25
  store i8 %17, i8* %26, align 1
  br label %29

; <label>:27:                                     ; preds = %9, %3
  %28 = call i32 @puts(i8* getelementptr inbounds ([31 x i8], [31 x i8]* @.str.1, i32 0, i32 0))
  call void @exit(i32 1) #6
  unreachable

; <label>:29:                                     ; preds = %15
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
define i32 @main_() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i8*, align 8
  store i8* null, i8** %2, align 8
  %3 = load i32, i32* %1, align 4
  ret i32 %3
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
