; ModuleID = 'Blawn'
source_filename = "Blawn"

%struct.String = type { i8*, i64 }
%NoArg = type {}
%NoArg.0 = type {}

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
  %i = alloca i64
  store i64 0, i64* %i
  %0 = load i64, i64* %i
  %1 = load i64, i64* %i
  %2 = add i64 %1, 1
  store i64 %2, i64* %i
  %3 = load i64, i64* %i
  br label %for

for:                                              ; preds = %"merge of for3", %entry
  %j = alloca i64
  store i64 0, i64* %j
  %4 = load i64, i64* %j
  %5 = load i64, i64* %j
  %6 = add i64 %5, 1
  store i64 %6, i64* %j
  %7 = load i64, i64* %j
  br label %for1

for1:                                             ; preds = %"merge of for", %for
  %k = alloca i64
  store i64 0, i64* %k
  %8 = load i64, i64* %k
  %9 = load i64, i64* %k
  %10 = add i64 %9, 1
  store i64 %10, i64* %k
  %11 = load i64, i64* %k
  br label %for2

for2:                                             ; preds = %for2, %for1
  %12 = load i64, i64* %k
  %13 = icmp slt i64 %12, 9
  %14 = icmp eq i1 false, %13
  %15 = load i64, i64* %k
  %16 = load i64, i64* %k
  %17 = add i64 %16, 1
  store i64 %17, i64* %k
  %18 = load i64, i64* %k
  br i1 %14, label %"merge of for", label %for2

"merge of for":                                   ; preds = %for2
  %19 = load i64, i64* %j
  %20 = icmp slt i64 %19, 9
  %21 = icmp eq i1 false, %20
  %22 = load i64, i64* %j
  %23 = load i64, i64* %j
  %24 = add i64 %23, 1
  store i64 %24, i64* %j
  %25 = load i64, i64* %j
  br i1 %21, label %"merge of for3", label %for1

"merge of for3":                                  ; preds = %"merge of for"
  %26 = load i64, i64* %i
  %27 = icmp slt i64 %26, 9
  %28 = icmp eq i1 false, %27
  %29 = load i64, i64* %i
  %30 = load i64, i64* %i
  %31 = add i64 %30, 1
  store i64 %31, i64* %i
  %32 = load i64, i64* %i
  br i1 %28, label %"merge of for4", label %for

"merge of for4":                                  ; preds = %"merge of for3"
  %33 = call %NoArg* @NoArg.2()
  %34 = call %NoArg.0* @NoArg.4(%NoArg* %33)
  %35 = call %NoArg* @NoArg.2()
  %36 = call %NoArg* @NoArg.2()
  call void @m.6(%NoArg* %36)
  call void @f.8(void <badref>)
  %37 = bitcast %NoArg* %36 to i64*
  call void @free(i64* %37)
  %38 = bitcast %NoArg* %35 to i64*
  call void @free(i64* %38)
  %39 = bitcast %NoArg.0* %34 to i64*
  call void @free(i64* %39)
  %40 = bitcast %NoArg* %33 to i64*
  call void @free(i64* %40)
  ret i8 0
}

declare void @NoArg()

declare void @f()

define %NoArg* @NoArg.2() {
entry:
  %0 = call i64* @malloc(i64 0)
  %1 = bitcast i64* %0 to %NoArg*
  ret %NoArg* %1
}

define void @"destructor<NoArg>"(%NoArg*) {
entry:
  %1 = bitcast %NoArg* %0 to i64*
  call void @free(i64* %1)
  ret void
}

define %NoArg.0* @NoArg.4(%NoArg*) {
entry:
  %1 = call i64* @malloc(i64 0)
  %2 = bitcast i64* %1 to %NoArg.0*
  ret %NoArg.0* %2
}

define void @"destructor<NoArg>.5"(%NoArg.0*) {
entry:
  %1 = bitcast %NoArg.0* %0 to i64*
  call void @free(i64* %1)
  ret void
}

define void @m.6(%NoArg* %self) {
entry:
  %0 = alloca %NoArg*
  store %NoArg* %self, %NoArg** %0
  ret void
}

define void @f.8(void %arg) {
entry:
  %0 = alloca void
  store void %arg, void* %0
  load void, void* %0
  ret void <badref>
}
