; ModuleID = 'Blawn'
source_filename = "Blawn"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%C = type { %T* }
%T = type { %struct.String*, i64 }
%struct.String = type { i8*, i64 }

@0 = private unnamed_addr constant [14 x i8] c"Hello World!!\00"
@1 = private unnamed_addr constant [9 x i8] c"whover_m\00"
@.str = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1

declare i64* @malloc(i64)

declare void @free(i64*)

define i8 @main() {
entry:
  %0 = call %C* @test.6(double 1.000000e-01)
  %1 = getelementptr inbounds %C, %C* %0, i32 0, i32 0
  %2 = load %T*, %T** %1
  %3 = call %T* @whover.7(%T* %2, i64 7)
  %4 = call %T* @whover.7(%T* %3, i64 9)
  %i = alloca %T*
  store %T* %4, %T** %i
  %5 = load %T*, %T** %i
  ret i8 0
}

declare void @T()

declare void @C()

declare void @test()

define %T* @T.4(i64 %a) {
entry:
  %0 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @0, i32 0, i32 0), i64 13)
  %"@string" = alloca %struct.String*
  store %struct.String* %0, %struct.String** %"@string"
  %1 = load %struct.String*, %struct.String** %"@string"
  %"@num" = alloca i64
  store i64 0, i64* %"@num"
  %2 = load i64, i64* %"@num"
  %3 = call i64* @malloc(i64 16)
  %4 = bitcast i64* %3 to %T*
  %5 = getelementptr inbounds %T, %T* %4, i32 0, i32 0
  store %struct.String* %1, %struct.String** %5
  %6 = getelementptr inbounds %T, %T* %4, i32 0, i32 1
  store i64 %2, i64* %6
  ret %T* %4
}

define void @destructor_of_T(%T*) {
entry:
  %1 = bitcast %T* %0 to i64*
  call void @free(i64* %1)
  ret void
}

define %C* @C.5(i64 %arg) {
entry:
  %0 = call %T* @T.4(i64 %arg)
  %"@member" = alloca %T*
  store %T* %0, %T** %"@member"
  %1 = load %T*, %T** %"@member"
  %2 = call i64* @malloc(i64 8)
  %3 = bitcast i64* %2 to %C*
  %4 = getelementptr inbounds %C, %C* %3, i32 0, i32 0
  store %T* %1, %T** %4
  ret %C* %3
}

define void @destructor_of_C(%C*) {
entry:
  %1 = bitcast %C* %0 to i64*
  call void @free(i64* %1)
  ret void
}

define %C* @test.6(double %a) {
entry:
  %0 = call %C* @C.5(i64 100)
  %r = alloca %C*
  store %C* %0, %C** %r
  %1 = load %C*, %C** %r
  %2 = load %C*, %C** %r
  ret %C* %2
}

define %T* @whover.7(%T* %self, i64 %arg) {
entry:
  %0 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([9 x i8], [9 x i8]* @1, i32 0, i32 0), i64 8)
  call void @print(%struct.String* %0)
  ret %T* %self
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
  store %struct.String* %0, %struct.String** %3, align 8
  store %struct.String* %1, %struct.String** %4, align 8
  %5 = load %struct.String*, %struct.String** %3, align 8
  %6 = getelementptr inbounds %struct.String, %struct.String* %5, i32 0, i32 0
  %7 = load i8*, i8** %6, align 8
  %8 = load %struct.String*, %struct.String** %4, align 8
  %9 = getelementptr inbounds %struct.String, %struct.String* %8, i32 0, i32 0
  %10 = load i8*, i8** %9, align 8
  %11 = call i8* @strcat(i8* %7, i8* %10) #3
  %12 = load %struct.String*, %struct.String** %4, align 8
  %13 = getelementptr inbounds %struct.String, %struct.String* %12, i32 0, i32 1
  %14 = load i64, i64* %13, align 8
  %15 = load %struct.String*, %struct.String** %3, align 8
  %16 = getelementptr inbounds %struct.String, %struct.String* %15, i32 0, i32 1
  %17 = load i64, i64* %16, align 8
  %18 = add nsw i64 %17, %14
  store i64 %18, i64* %16, align 8
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
