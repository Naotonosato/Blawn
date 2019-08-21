; ModuleID = 'Blawn'
source_filename = "Blawn"

declare i64* @malloc(i64)

declare void @free(i64*)

define i8 @main() {
entry:
  %0 = call i64 @f.2(i64 1)
  ret i8 0
}

declare void @f()

define void @f.1(i64 %arg) {
entry:
  %0 = mul i64 %arg, 2
  %res = alloca i64
  store i64 %0, i64* %res
  %1 = load i64, i64* %res
  %2 = load i64, i64* %res
  ret i64 %2
}

define i64 @f.2(i64 %arg) {
entry:
  %0 = mul i64 %arg, 2
  %res = alloca i64
  store i64 %0, i64* %res
  %1 = load i64, i64* %res
  %2 = load i64, i64* %res
  ret i64 %2
}
