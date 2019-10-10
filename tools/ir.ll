; ModuleID = 'test/test1.c'
source_filename = "test/test1.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.Struct = type { i32, i32 }
%struct.NestStruct = type { i32, i32, %struct.Struct**** }

; Function Attrs: noinline nounwind optnone uwtable
define i32 @main() #0 {
  %1 = alloca i32, align 4
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define i32 @TEST_no_arg_func() #0 {
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define i32 @TEST_arg_func(i32) #0 {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  ret i32 %3
}

; Function Attrs: noinline nounwind optnone uwtable
define i32 @TEST_struct_arg_func(%struct.Struct*) #0 {
  %2 = alloca %struct.Struct*, align 8
  store %struct.Struct* %0, %struct.Struct** %2, align 8
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define %struct.Struct* @TEST_return_struct_func() #0 {
  %1 = alloca %struct.Struct*, align 8
  %2 = load %struct.Struct*, %struct.Struct** %1, align 8
  ret %struct.Struct* %2
}

; Function Attrs: noinline nounwind optnone uwtable
define i32 @TEST_arg_nest_struct(%struct.NestStruct*) #0 {
  %2 = alloca %struct.NestStruct*, align 8
  store %struct.NestStruct* %0, %struct.NestStruct** %2, align 8
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define %struct.NestStruct* @TEST_return_nest_struct() #0 {
  %1 = alloca %struct.NestStruct*, align 8
  %2 = load %struct.NestStruct*, %struct.NestStruct** %1, align 8
  ret %struct.NestStruct* %2
}

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final)"}
