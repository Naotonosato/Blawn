; ModuleID = 'Blawn'
source_filename = "Blawn"

%struct.String = type { i8*, i64 }

@0 = private unnamed_addr constant [14 x i8] c"AAAAAAAAAAAAA\00"

declare i64* @malloc(i64)

declare void @free(i64*)

declare %struct.String* @string_constructor(i8*, i64)

declare void @append_string(%struct.String*, %struct.String*)

declare void @print(%struct.String*)

declare i8* @to_char_ptr(%struct.String*)

declare %struct.String* @int_to_str(i64)

declare %struct.String* @float_to_str(double)

define i8 @i64_to_i8(i64) {
i64_to_i8:
  %1 = trunc i64 %0 to i8
  ret i8 %1
}

define i32 @i64_to_i32(i64) {
i64_to_i32:
  %1 = trunc i64 %0 to i32
  ret i32 %1
}

define i8 @i32_to_i8(i32) {
i32_to_i8:
  %1 = trunc i32 %0 to i8
  ret i8 %1
}

define i32 @i8_to_i32(i8) {
i8_to_i32:
  %1 = zext i8 %0 to i32
  ret i32 %1
}

define i64 @i32_to_i64(i32) {
i32_to_i64:
  %1 = zext i32 %0 to i64
  ret i64 %1
}

define i64 @i8_to_i64(i8) {
i8_to_i64:
  %1 = zext i8 %0 to i64
  ret i64 %1
}

declare void @blawn_memcpy(i8*, i64, i64, i8*)

declare i8* @blawn_realloc(i8*, i64, i64)

declare i8* @blawn_index(i8*, i64, i64, i64)

declare i8* @blawn_set_element(i8*, i64, i64, i8*, i64)

define i8 @main() {
entry:
  %a = alloca i64
  store i64 0, i64* %a
  %0 = load i64, i64* %a
  %1 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @0, i32 0, i32 0), i64 13)
  call void @print(%struct.String* %1)
  ret i8 0
}

declare void @List()

declare void @Person()

declare void @t()
