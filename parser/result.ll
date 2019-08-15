; ModuleID = 'Blawn'
source_filename = "Blawn"

define i8 @main() {
entry:
  %0 = call i64 @twice.4(i64 9)
  %var = alloca i64
  store i64 %0, i64* %var
  %1 = load i64, i64* %var
  %2 = call i64 @twice.4(i64 9)
  %3 = load i64, i64* %var
  %4 = add i64 %3, 9
  store i64 %4, i64* %var
  %5 = call i64 @twice.4(i64 9)
  %6 = mul i64 0, %3
  %a = alloca i64
  store i64 %6, i64* %a
  %7 = load i64, i64* %a
  ret i8 0
}

define void @add() {
empty_entry:
  ret void
}

define void @twice() {
empty_entry:
  ret void
}

define i64 @add.3(i64 %l, i64 %r) {
entry:
  %0 = add i64 %l, %r
  %sum = alloca i64
  store i64 %0, i64* %sum
  %1 = load i64, i64* %sum
  ret i64 %1
}

define i64 @twice.4(i64 %num) {
entry:
  %0 = call i64 @add.3(i64 %num, i64 %num)
  %num_x_2 = alloca i64
  store i64 %0, i64* %num_x_2
  %1 = load i64, i64* %num_x_2
  ret i64 %1
}
