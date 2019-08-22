; ModuleID = 'Blawn'
source_filename = "Blawn"

%C = type { double, double, %T* }
%T = type { %In* }
%In = type { i64 }

declare i64* @malloc(i64)

declare void @free(i64*)

define i8 @main() {
entry:
  %0 = call i64 @f.4(i64 1)
  %1 = call %C* @C.12(i64 2)
  %instance = alloca %C*
  store %C* %1, %C** %instance
  %2 = load %C*, %C** %instance
  br i1 false, label %"then of if expr", label %"else of if_expr"

"then of if expr":                                ; preds = %entry
  %3 = call i64 @add.3(i64 0, i64 0)
  br label %"merge of if_expr"

"else of if_expr":                                ; preds = %entry
  %4 = call double @f.16(double 1.000000e-02)
  br label %"merge of if_expr"

"merge of if_expr":                               ; preds = %"else of if_expr", %"then of if expr"
  %5 = call i64 @f.4(i64 7)
  %6 = call %C* @C.12(i64 0)
  %i = alloca %C*
  store %C* %6, %C** %i
  %7 = load %C*, %C** %i
  %8 = load %C*, %C** %i
  %9 = getelementptr inbounds %C, %C* %8, i32 0, i32 2
  %10 = load %T*, %T** %9
  %11 = getelementptr inbounds %T, %T* %10, i32 0, i32 0
  %12 = load %In*, %In** %11
  %13 = getelementptr inbounds %In, %In* %12, i32 0, i32 0
  %14 = load i64, i64* %13
  %e = alloca i64
  store i64 %14, i64* %e
  %15 = load i64, i64* %e
  ret i8 0
}

declare void @add()

declare void @f()


define i64 @add.3(i64 %l, i64 %r) {
entry:
  %0 = add i64 %l, %r
  %sum = alloca i64
  store i64 %0, i64* %sum
  %1 = load i64, i64* %sum
  %2 = load i64, i64* %sum
  ret i64 %2
}

define i64 @f.4(i64 %arg) {
entry:
  %0 = mul i64 %arg, 2
  %1 = call i64 @add.3(i64 %0, i64 %arg)
  %res = alloca i64
  store i64 %1, i64* %res
  %2 = load i64, i64* %res
  %3 = load i64, i64* %res
  ret i64 %3
}

declare void @In()

declare void @T()

declare void @C()


define double @add.7(double %l, i64 %r) {
entry:
  %0 = sitofp i64 %r to double
  %1 = fadd double %l, %0
  %sum = alloca double
  store double %1, double* %sum
  %2 = load double, double* %sum
  %3 = load double, double* %sum
  ret double %3
}



define %In* @In.10(i64 %ar) {
entry:
  %"@inmem" = alloca i64
  store i64 %ar, i64* %"@inmem"
  %0 = load i64, i64* %"@inmem"
  %1 = call i64* @malloc(i64 8)
  %2 = bitcast i64* %1 to %In*
  %3 = getelementptr inbounds %In, %In* %2, i32 0, i32 0
  store i64 %0, i64* %3
  ret %In* %2
}

define void @"#destructor_of_In"(%In*) {
entry:
  %1 = bitcast %In* %0 to i64*
  call void @free(i64* %1)
  ret void
}

define %T* @T.11(i64 %a) {
entry:
  %0 = call %In* @In.10(i64 0)
  %"@mt" = alloca %In*
  store %In* %0, %In** %"@mt"
  %1 = load %In*, %In** %"@mt"
  %2 = call i64* @malloc(i64 8)
  %3 = bitcast i64* %2 to %T*
  %4 = getelementptr inbounds %T, %T* %3, i32 0, i32 0
  store %In* %1, %In** %4
  ret %T* %3
}

define void @"#destructor_of_T"(%T*) {
entry:
  %1 = bitcast %T* %0 to i64*
  call void @free(i64* %1)
  ret void
}

define %C* @C.12(i64 %arg) {
entry:
  %0 = call double @add.7(double 1.000000e-01, i64 0)
  %"@mem" = alloca double
  store double %0, double* %"@mem"
  %1 = load double, double* %"@mem"
  %2 = sitofp i64 %arg to double
  %3 = fdiv double %2, 2.000000e+00
  %"@mem2" = alloca double
  store double %3, double* %"@mem2"
  %4 = load double, double* %"@mem2"
  %5 = call %T* @T.11(i64 0)
  %"@i" = alloca %T*
  store %T* %5, %T** %"@i"
  %6 = load %T*, %T** %"@i"
  %7 = call i64* @malloc(i64 24)
  %8 = bitcast i64* %7 to %C*
  %9 = getelementptr inbounds %C, %C* %8, i32 0, i32 0
  store double %1, double* %9
  %10 = getelementptr inbounds %C, %C* %8, i32 0, i32 1
  store double %4, double* %10
  %11 = getelementptr inbounds %C, %C* %8, i32 0, i32 2
  store %T* %6, %T** %11
  ret %C* %8
}

define void @"#destructor_of_C"(%C*) {
entry:
  %1 = bitcast %C* %0 to i64*
  call void @free(i64* %1)
  ret void
}


define double @add.15(double %l, double %r) {
entry:
  %0 = fadd double %l, %r
  %sum = alloca double
  store double %0, double* %sum
  %1 = load double, double* %sum
  %2 = load double, double* %sum
  ret double %2
}

define double @f.16(double %arg) {
entry:
  %0 = fmul double %arg, 2.000000e+00
  %1 = call double @add.15(double %0, double %arg)
  %res = alloca double
  store double %1, double* %res
  %2 = load double, double* %res
  %3 = load double, double* %res
  ret double %3
}
