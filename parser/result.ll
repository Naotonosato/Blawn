; ModuleID = 'Blawn'
source_filename = "Blawn"

%Test = type { i64, double, i64 }
%Test.0 = type { double, double, double }

declare i64* @malloc(i64)

declare void @free(i64*)

define i8 @main() {
entry:
  %0 = call i64 @twice.4(i64 1)
  %var = alloca i64
  store i64 %0, i64* %var
  %1 = load i64, i64* %var
  %2 = call double @twice.8(double 9.000000e-01)
  %aa = alloca double
  store double %2, double* %aa
  %3 = load double, double* %aa
  %4 = call %Test* @Test.10(i64 7)
  %instance_with_int_arg = alloca %Test*
  store %Test* %4, %Test** %instance_with_int_arg
  %5 = load %Test*, %Test** %instance_with_int_arg
  %6 = call %Test.0* @Test.12(double 1.000000e-02)
  %instance_with_float_arg = alloca %Test.0*
  store %Test.0* %6, %Test.0** %instance_with_float_arg
  %7 = load %Test.0*, %Test.0** %instance_with_float_arg
  ret i8 0
}

declare void @add()

declare void @twice()

define void @twice.1(i64 %num) {
entry:
  %0 = call i64 @add.3(i64 %num, i64 %num)
  %num_x_2 = alloca i64
  store i64 %0, i64* %num_x_2
  %1 = load i64, i64* %num_x_2
  %2 = load i64, i64* %num_x_2
  ret i64 %2
}

define void @add.2(i64 %l, i64 %r) {
entry:
  %0 = fadd i64 %l, %r
  %sum = alloca i64
  store i64 %0, i64* %sum
  %1 = load i64, i64* %sum
  %2 = load i64, i64* %sum
  ret i64 %2
}

define i64 @add.3(i64 %l, i64 %r) {
entry:
  %0 = fadd i64 %l, %r
  %sum = alloca i64
  store i64 %0, i64* %sum
  %1 = load i64, i64* %sum
  %2 = load i64, i64* %sum
  ret i64 %2
}

define i64 @twice.4(i64 %num) {
entry:
  %0 = call i64 @add.3(i64 %num, i64 %num)
  %num_x_2 = alloca i64
  store i64 %0, i64* %num_x_2
  %1 = load i64, i64* %num_x_2
  %2 = load i64, i64* %num_x_2
  ret i64 %2
}

define void @twice.5(double %num) {
entry:
  %0 = call double @add.7(double %num, double %num)
  %num_x_2 = alloca double
  store double %0, double* %num_x_2
  %1 = load double, double* %num_x_2
  %2 = load double, double* %num_x_2
  ret double %2
}

define void @add.6(double %l, double %r) {
entry:
  %0 = fadd double %l, %r
  %sum = alloca double
  store double %0, double* %sum
  %1 = load double, double* %sum
  %2 = load double, double* %sum
  ret double %2
}

define double @add.7(double %l, double %r) {
entry:
  %0 = fadd double %l, %r
  %sum = alloca double
  store double %0, double* %sum
  %1 = load double, double* %sum
  %2 = load double, double* %sum
  ret double %2
}

define double @twice.8(double %num) {
entry:
  %0 = call double @add.7(double %num, double %num)
  %num_x_2 = alloca double
  store double %0, double* %num_x_2
  %1 = load double, double* %num_x_2
  %2 = load double, double* %num_x_2
  ret double %2
}

declare void @Test()

define void @Test.9(i64 %arg) {
entry:
  %"@member" = alloca i64
  store i64 %arg, i64* %"@member"
  %0 = load i64, i64* %"@member"
  %"@num" = alloca double
  store double 5.000000e-01, double* %"@num"
  %1 = load double, double* %"@num"
  %2 = call i64 @twice.4(i64 %arg)
  %"@instance_var" = alloca i64
  store i64 %2, i64* %"@instance_var"
  %3 = load i64, i64* %"@instance_var"
  %4 = call i64* @malloc(i64 24)
  %5 = bitcast i64* %4 to %Test*
  %6 = getelementptr inbounds %Test, %Test* %5, i32 0, i32 0
  store i64 %0, i64* %6
  %7 = getelementptr inbounds %Test, %Test* %5, i32 0, i32 1
  store double %1, double* %7
  %8 = getelementptr inbounds %Test, %Test* %5, i32 0, i32 2
  store i64 %3, i64* %8
  ret %Test* %5
}

define %Test* @Test.10(i64 %arg) {
entry:
  %"@member" = alloca i64
  store i64 %arg, i64* %"@member"
  %0 = load i64, i64* %"@member"
  %"@num" = alloca double
  store double 5.000000e-01, double* %"@num"
  %1 = load double, double* %"@num"
  %2 = call i64 @twice.4(i64 %arg)
  %"@instance_var" = alloca i64
  store i64 %2, i64* %"@instance_var"
  %3 = load i64, i64* %"@instance_var"
  %4 = call i64* @malloc(i64 24)
  %5 = bitcast i64* %4 to %Test*
  %6 = getelementptr inbounds %Test, %Test* %5, i32 0, i32 0
  store i64 %0, i64* %6
  %7 = getelementptr inbounds %Test, %Test* %5, i32 0, i32 1
  store double %1, double* %7
  %8 = getelementptr inbounds %Test, %Test* %5, i32 0, i32 2
  store i64 %3, i64* %8
  ret %Test* %5
}

define void @destructor_of_Test(%Test) {
entry:
  call void @free(%Test %0)
  ret void
}

define void @Test.11(double %arg) {
entry:
  %"@member" = alloca double
  store double %arg, double* %"@member"
  %0 = load double, double* %"@member"
  %"@num" = alloca double
  store double 5.000000e-01, double* %"@num"
  %1 = load double, double* %"@num"
  %2 = call double @twice.8(double %arg)
  %"@instance_var" = alloca double
  store double %2, double* %"@instance_var"
  %3 = load double, double* %"@instance_var"
  %4 = call i64* @malloc(i64 24)
  %5 = bitcast i64* %4 to %Test.0*
  %6 = getelementptr inbounds %Test.0, %Test.0* %5, i32 0, i32 0
  store double %0, double* %6
  %7 = getelementptr inbounds %Test.0, %Test.0* %5, i32 0, i32 1
  store double %1, double* %7
  %8 = getelementptr inbounds %Test.0, %Test.0* %5, i32 0, i32 2
  store double %3, double* %8
  ret %Test.0* %5
}

define %Test.0* @Test.12(double %arg) {
entry:
  %"@member" = alloca double
  store double %arg, double* %"@member"
  %0 = load double, double* %"@member"
  %"@num" = alloca double
  store double 5.000000e-01, double* %"@num"
  %1 = load double, double* %"@num"
  %2 = call double @twice.8(double %arg)
  %"@instance_var" = alloca double
  store double %2, double* %"@instance_var"
  %3 = load double, double* %"@instance_var"
  %4 = call i64* @malloc(i64 24)
  %5 = bitcast i64* %4 to %Test.0*
  %6 = getelementptr inbounds %Test.0, %Test.0* %5, i32 0, i32 0
  store double %0, double* %6
  %7 = getelementptr inbounds %Test.0, %Test.0* %5, i32 0, i32 1
  store double %1, double* %7
  %8 = getelementptr inbounds %Test.0, %Test.0* %5, i32 0, i32 2
  store double %3, double* %8
  ret %Test.0* %5
}

define void @destructor_of_Test.13(%Test.0) {
entry:
  call void @free(%Test.0 %0)
  ret void
}
