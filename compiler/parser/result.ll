; ModuleID = 'Blawn'
source_filename = "Blawn"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.String = type { i8*, i64 }

@0 = private unnamed_addr constant [2 x i8] c"a\00"
@1 = private unnamed_addr constant [2 x i8] c"a\00"
@2 = private unnamed_addr constant [1 x i8] zeroinitializer
@3 = private unnamed_addr constant [2 x i8] c"0\00"
@4 = private unnamed_addr constant [2 x i8] c"1\00"
@5 = private unnamed_addr constant [2 x i8] c"2\00"
@6 = private unnamed_addr constant [2 x i8] c"3\00"
@7 = private unnamed_addr constant [2 x i8] c"4\00"
@8 = private unnamed_addr constant [2 x i8] c"5\00"
@9 = private unnamed_addr constant [2 x i8] c"6\00"
@10 = private unnamed_addr constant [2 x i8] c"7\00"
@11 = private unnamed_addr constant [2 x i8] c"8\00"
@12 = private unnamed_addr constant [2 x i8] c"9\00"
@.str = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1

declare i64* @malloc(i64)

declare void @free(i64*)

define i8 @main() {
entry:
  %0 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @0, i32 0, i32 0), i64 1)
  %s = alloca %struct.String*
  store %struct.String* %0, %struct.String** %s
  %1 = load %struct.String*, %struct.String** %s
  %2 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @1, i32 0, i32 0), i64 1)
  %s2 = alloca %struct.String*
  store %struct.String* %2, %struct.String** %s2
  %3 = load %struct.String*, %struct.String** %s2
  %4 = load %struct.String*, %struct.String** %s
  %5 = load %struct.String*, %struct.String** %s2
  call void @add_string(%struct.String* %4, %struct.String* %5)
  %6 = load %struct.String*, %struct.String** %s
  %7 = getelementptr inbounds %struct.String, %struct.String* %6, i32 0, i32 1
  %8 = load i64, i64* %7
  %9 = call %struct.String* @digit_to_string.2(i64 %8)
  call void @print(%struct.String* %9)
  %10 = load %struct.String*, %struct.String** %s
  call void @print(%struct.String* %10)
  ret i8 0
}

declare void @digit_to_string()

declare void @to_string()

declare void @Person()

define %struct.String* @digit_to_string.2(i64 %num) {
entry:
  %0 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([1 x i8], [1 x i8]* @2, i32 0, i32 0), i64 0)
  %res = alloca %struct.String*
  store %struct.String* %0, %struct.String** %res
  %1 = load %struct.String*, %struct.String** %res
  %2 = icmp eq i64 %num, 0
  br i1 %2, label %"then of if expr", label %"else of if_expr"

"then of if expr":                                ; preds = %entry
  %3 = load %struct.String*, %struct.String** %res
  %4 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @3, i32 0, i32 0), i64 1)
  store %struct.String* %4, %struct.String** %res
  %5 = load %struct.String*, %struct.String** %res
  br label %"merge of if_expr"

"else of if_expr":                                ; preds = %entry
  br label %"merge of if_expr"

"merge of if_expr":                               ; preds = %"else of if_expr", %"then of if expr"
  %6 = icmp eq i64 %num, 1
  br i1 %6, label %"then of if expr1", label %"else of if_expr2"

"then of if expr1":                               ; preds = %"merge of if_expr"
  %7 = load %struct.String*, %struct.String** %res
  %8 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @4, i32 0, i32 0), i64 1)
  store %struct.String* %8, %struct.String** %res
  %9 = load %struct.String*, %struct.String** %res
  br label %"merge of if_expr3"

"else of if_expr2":                               ; preds = %"merge of if_expr"
  br label %"merge of if_expr3"

"merge of if_expr3":                              ; preds = %"else of if_expr2", %"then of if expr1"
  %10 = icmp eq i64 %num, 2
  br i1 %10, label %"then of if expr4", label %"else of if_expr5"

"then of if expr4":                               ; preds = %"merge of if_expr3"
  %11 = load %struct.String*, %struct.String** %res
  %12 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @5, i32 0, i32 0), i64 1)
  store %struct.String* %12, %struct.String** %res
  %13 = load %struct.String*, %struct.String** %res
  br label %"merge of if_expr6"

"else of if_expr5":                               ; preds = %"merge of if_expr3"
  br label %"merge of if_expr6"

"merge of if_expr6":                              ; preds = %"else of if_expr5", %"then of if expr4"
  %14 = icmp eq i64 %num, 3
  br i1 %14, label %"then of if expr7", label %"else of if_expr8"

"then of if expr7":                               ; preds = %"merge of if_expr6"
  %15 = load %struct.String*, %struct.String** %res
  %16 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @6, i32 0, i32 0), i64 1)
  store %struct.String* %16, %struct.String** %res
  %17 = load %struct.String*, %struct.String** %res
  br label %"merge of if_expr9"

"else of if_expr8":                               ; preds = %"merge of if_expr6"
  br label %"merge of if_expr9"

"merge of if_expr9":                              ; preds = %"else of if_expr8", %"then of if expr7"
  %18 = icmp eq i64 %num, 4
  br i1 %18, label %"then of if expr10", label %"else of if_expr11"

"then of if expr10":                              ; preds = %"merge of if_expr9"
  %19 = load %struct.String*, %struct.String** %res
  %20 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @7, i32 0, i32 0), i64 1)
  store %struct.String* %20, %struct.String** %res
  %21 = load %struct.String*, %struct.String** %res
  br label %"merge of if_expr12"

"else of if_expr11":                              ; preds = %"merge of if_expr9"
  br label %"merge of if_expr12"

"merge of if_expr12":                             ; preds = %"else of if_expr11", %"then of if expr10"
  %22 = icmp eq i64 %num, 5
  br i1 %22, label %"then of if expr13", label %"else of if_expr14"

"then of if expr13":                              ; preds = %"merge of if_expr12"
  %23 = load %struct.String*, %struct.String** %res
  %24 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @8, i32 0, i32 0), i64 1)
  store %struct.String* %24, %struct.String** %res
  %25 = load %struct.String*, %struct.String** %res
  br label %"merge of if_expr15"

"else of if_expr14":                              ; preds = %"merge of if_expr12"
  br label %"merge of if_expr15"

"merge of if_expr15":                             ; preds = %"else of if_expr14", %"then of if expr13"
  %26 = icmp eq i64 %num, 6
  br i1 %26, label %"then of if expr16", label %"else of if_expr17"

"then of if expr16":                              ; preds = %"merge of if_expr15"
  %27 = load %struct.String*, %struct.String** %res
  %28 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @9, i32 0, i32 0), i64 1)
  store %struct.String* %28, %struct.String** %res
  %29 = load %struct.String*, %struct.String** %res
  br label %"merge of if_expr18"

"else of if_expr17":                              ; preds = %"merge of if_expr15"
  br label %"merge of if_expr18"

"merge of if_expr18":                             ; preds = %"else of if_expr17", %"then of if expr16"
  %30 = icmp eq i64 %num, 7
  br i1 %30, label %"then of if expr19", label %"else of if_expr20"

"then of if expr19":                              ; preds = %"merge of if_expr18"
  %31 = load %struct.String*, %struct.String** %res
  %32 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @10, i32 0, i32 0), i64 1)
  store %struct.String* %32, %struct.String** %res
  %33 = load %struct.String*, %struct.String** %res
  br label %"merge of if_expr21"

"else of if_expr20":                              ; preds = %"merge of if_expr18"
  br label %"merge of if_expr21"

"merge of if_expr21":                             ; preds = %"else of if_expr20", %"then of if expr19"
  %34 = icmp eq i64 %num, 8
  br i1 %34, label %"then of if expr22", label %"else of if_expr23"

"then of if expr22":                              ; preds = %"merge of if_expr21"
  %35 = load %struct.String*, %struct.String** %res
  %36 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @11, i32 0, i32 0), i64 1)
  store %struct.String* %36, %struct.String** %res
  %37 = load %struct.String*, %struct.String** %res
  br label %"merge of if_expr24"

"else of if_expr23":                              ; preds = %"merge of if_expr21"
  br label %"merge of if_expr24"

"merge of if_expr24":                             ; preds = %"else of if_expr23", %"then of if expr22"
  %38 = icmp eq i64 %num, 9
  br i1 %38, label %"then of if expr25", label %"else of if_expr26"

"then of if expr25":                              ; preds = %"merge of if_expr24"
  %39 = load %struct.String*, %struct.String** %res
  %40 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @12, i32 0, i32 0), i64 1)
  store %struct.String* %40, %struct.String** %res
  %41 = load %struct.String*, %struct.String** %res
  br label %"merge of if_expr27"

"else of if_expr26":                              ; preds = %"merge of if_expr24"
  br label %"merge of if_expr27"

"merge of if_expr27":                             ; preds = %"else of if_expr26", %"then of if expr25"
  %42 = load %struct.String*, %struct.String** %res
  ret %struct.String* %42
}

; Function Attrs: noinline nounwind optnone uwtable
define void @print(%struct.String*) #0 {
  %2 = alloca %struct.String*, align 8
  store %struct.String* %0, %struct.String** %2, align 8
  %3 = load %struct.String*, %struct.String** %2, align 8
  %4 = getelementptr inbounds %struct.String, %struct.String* %3, i32 0, i32 0
  %5 = load i8*, i8** %4, align 8
  %6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i8* %5)
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: noinline nounwind optnone uwtable
define %struct.String* @string_constructor(i8*, i64) #0 {
  %3 = alloca i8*, align 8
  %4 = alloca i64, align 8
  %5 = alloca %struct.String*, align 8
  store i8* %0, i8** %3, align 8
  store i64 %1, i64* %4, align 8
  %6 = call noalias i8* bitcast (i64* (i64)* @malloc to i8* (i64)*)(i64 16) #3
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
define void @add_string(%struct.String*, %struct.String*) #0 {
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
  %13 = call noalias i8* bitcast (i64* (i64)* @malloc to i8* (i64)*)(i64 %12) #3
  store i8* %13, i8** %5, align 8
  %14 = load i8*, i8** %5, align 8
  %15 = getelementptr inbounds i8, i8* %14, i64 0
  store i8 0, i8* %15, align 1
  %16 = load i8*, i8** %5, align 8
  %17 = load %struct.String*, %struct.String** %3, align 8
  %18 = getelementptr inbounds %struct.String, %struct.String* %17, i32 0, i32 0
  %19 = load i8*, i8** %18, align 8
  %20 = call i8* @strcat(i8* %16, i8* %19) #3
  %21 = load i8*, i8** %5, align 8
  %22 = load %struct.String*, %struct.String** %4, align 8
  %23 = getelementptr inbounds %struct.String, %struct.String* %22, i32 0, i32 0
  %24 = load i8*, i8** %23, align 8
  %25 = call i8* @strcat(i8* %21, i8* %24) #3
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
declare i8* @strcat(i8*, i8*) #2

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final)"}
!1 = !{i32 1, !"wchar_size", i32 4}
