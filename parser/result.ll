; ModuleID = 'Blawn'
source_filename = "Blawn"

%C = type { %T*, i64 }
%T = type { i64 }

declare i64* @malloc(i64)

declare void @free(i64*)

declare void @putchar(i64)

define i8 @main() {
entry:
  %0 = call %C* @C.8(i64 0)
  %o = alloca %C*
  store %C* %0, %C** %o
  %1 = load %C*, %C** %o
  %2 = load %C*, %C** %o
  %3 = getelementptr inbounds %C, %C* %2, i32 0, i32 0
  %4 = load %T*, %T** %3
  %5 = getelementptr inbounds %T, %T* %4, i32 0, i32 0
  %6 = load i64, i64* %5
  store i64 120, i64* %5
  %7 = load i64, i64* %5
  %8 = load %C*, %C** %o
  %9 = getelementptr inbounds %C, %C* %8, i32 0, i32 0
  %10 = load %T*, %T** %9
  %11 = getelementptr inbounds %T, %T* %10, i32 0, i32 0
  %12 = load i64, i64* %11
  %t = alloca i64
  store i64 %12, i64* %t
  %13 = load i64, i64* %t
  call void @putchar(i64 %13)
  ret i8 0
}



define i64 @add.5(i64 %l, i64 %r) {
entry:
  %0 = add i64 %l, %r
  %sum = alloca i64
  store i64 %0, i64* %sum
  %1 = load i64, i64* %sum
  %2 = load i64, i64* %sum
  ret i64 %2
}

define i64 @twice.6(i64 %arg) {
entry:
  %0 = call i64 @add.5(i64 %arg, i64 %arg)
  %arg_x_2 = alloca i64
  store i64 %0, i64* %arg_x_2
  %1 = load i64, i64* %arg_x_2
  %2 = load i64, i64* %arg_x_2
  ret i64 %2
}

define %T* @T.7(i64 %a) {
entry:
  %0 = call i64 @twice.6(i64 %a)
  %"@member" = alloca i64
  store i64 %0, i64* %"@member"
  %1 = load i64, i64* %"@member"
  %2 = call i64* @malloc(i64 8)
  %3 = bitcast i64* %2 to %T*
  %4 = getelementptr inbounds %T, %T* %3, i32 0, i32 0
  store i64 %1, i64* %4
  ret %T* %3
}

define void @"#destructor_of_T"(%T*) {
entry:
  %1 = bitcast %T* %0 to i64*
  call void @free(i64* %1)
  ret void
}

define %C* @C.8(i64 %arg) {
entry:
  %0 = call %T* @T.7(i64 %arg)
  %"@member" = alloca %T*
  store %T* %0, %T** %"@member"
  %1 = load %T*, %T** %"@member"
  %"@m2" = alloca i64
  store i64 0, i64* %"@m2"
  %2 = load i64, i64* %"@m2"
  %3 = call i64* @malloc(i64 16)
  %4 = bitcast i64* %3 to %C*
  %5 = getelementptr inbounds %C, %C* %4, i32 0, i32 0
  store %T* %1, %T** %5
  %6 = getelementptr inbounds %C, %C* %4, i32 0, i32 1
  store i64 %2, i64* %6
  ret %C* %4
}

define void @"#destructor_of_C"(%C*) {
entry:
  %1 = bitcast %C* %0 to i64*
  call void @free(i64* %1)
  ret void
}
