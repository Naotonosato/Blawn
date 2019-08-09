; ModuleID = 'Blawn'
source_filename = "Blawn"

define i8 @main() {
entry:
  %0 = call i64 @twice.1(i64 7)
  %1 = call i64 @add_seven.2(i64 7)
  %2 = call i64 @add_seven.2(i64 1)
  %3 = call double @add_seven.3(double 5.000000e-01)
  %4 = call double @add_seven.3(double 5.000000e-01)
  %5 = call double @twice.4(double %4)
  %6 = call i64 @twice.1(i64 7)
  %7 = call i64 @add_seven.2(i64 7)
  %8 = call i64 @add_seven.2(i64 1)
  %9 = call double @add_seven.3(double 5.000000e-01)
  %10 = call double @add_seven.3(double 5.000000e-01)
  %11 = call double @twice.4(double %10)
}

define void @twice(i8) {
entry:
  ret void
}

define void @add_seven(i8) {
entry:
  ret void
}

define i64 @twice.1(i64 %num) {
entry:
  %0 = fmul i64 %num, 2
  %1 = fmul i64 %num, 2
  ret i64 %1
}

define i64 @add_seven.2(i64 %num) {
entry:
  %0 = fadd i64 %num, 7
  %1 = fadd i64 %num, 7
  ret i64 %1
}

define double @add_seven.3(double %num) {
entry:
  %0 = fadd double %num, i64 7
  %1 = fadd double %num, i64 7
  ret double %1
}

define double @twice.4(double %num) {
entry:
  %0 = fmul double %num, i64 2
  %1 = fmul double %num, i64 2
  ret double %1
}
