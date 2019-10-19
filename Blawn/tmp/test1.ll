; ModuleID = 'Blawn'
source_filename = "Blawn"

%struct.String = type { i8*, i64 }
%__mbstate_t = type { i32, i32 }
%_IO_FILE = type { i8 }
%_G_fpos_t = type { i64, %__mbstate_t }

@0 = private unnamed_addr constant [34 x i8] c"function 'puts' called from blawn\00"

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
  %"@__NOT_SUPPORTED__2" = alloca i8
  store i8 0, i8* %"@__NOT_SUPPORTED__2"
  %0 = load i8, i8* %"@__NOT_SUPPORTED__2"
  %"@__pos" = alloca i64
  store i64 0, i64* %"@__pos"
  %1 = load i64, i64* %"@__pos"
  %"@__count" = alloca i32
  store i32 0, i32* %"@__count"
  %2 = load i32, i32* %"@__count"
  %"@__NOT_SUPPORTED__3" = alloca i32
  store i32 0, i32* %"@__NOT_SUPPORTED__3"
  %3 = load i32, i32* %"@__NOT_SUPPORTED__3"
  %4 = alloca %__mbstate_t
  %5 = load %__mbstate_t, %__mbstate_t* %4
  %"@__state" = alloca %__mbstate_t
  store %__mbstate_t %5, %__mbstate_t* %"@__state"
  %6 = load %__mbstate_t, %__mbstate_t* %"@__state"
  %7 = call i32 @c_function()
  %8 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([34 x i8], [34 x i8]* @0, i32 0, i32 0), i64 33)
  %9 = getelementptr inbounds %struct.String, %struct.String* %8, i32 0, i32 0
  %10 = load i8*, i8** %9
  %11 = call i32 @puts(i8* %10)
  ret i8 0
}

declare void @__fsid_t()

declare void @_IO_FILE()

declare void @__mbstate_t()

declare void @_G_fpos_t()

declare void @_G_fpos64_t()

declare void @_IO_marker()

define %_IO_FILE* @_IO_FILE.1() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @__underflow(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.2() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @__uflow(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.3() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @__overflow(%_IO_FILE*, i32)

define %_IO_FILE* @_IO_FILE.4() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @_IO_getc(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.5() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @_IO_putc(i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.6() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @_IO_feof(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.7() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @_IO_ferror(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.8() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @_IO_peekc_locked(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.9() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare void @_IO_flockfile(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.10() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare void @_IO_funlockfile(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.11() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @_IO_ftrylockfile(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.12() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @_IO_vfscanf(%_IO_FILE*, i8*, i32, i32*)

define %_IO_FILE* @_IO_FILE.13() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @_IO_vfprintf(%_IO_FILE*, i8*, i32)

define %_IO_FILE* @_IO_FILE.14() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i64 @_IO_padn(%_IO_FILE*, i32, i64)

define %_IO_FILE* @_IO_FILE.15() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @_IO_sgetn(%_IO_FILE*, i64*, i32)

define %_IO_FILE* @_IO_FILE.16() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i64 @_IO_seekoff(%_IO_FILE*, i64, i32, i32)

define %_IO_FILE* @_IO_FILE.17() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i64 @_IO_seekpos(%_IO_FILE*, i64, i32)

define %_IO_FILE* @_IO_FILE.18() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare void @_IO_free_backup_area(%_IO_FILE*)

declare i32 @remove(i8*)

declare i32 @rename(i8*, i8*)

declare i32 @renameat(i32, i8*, i32, i8*)

define %_IO_FILE* @_IO_FILE.19() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare %_IO_FILE* @tmpfile()

declare i8* @tmpnam(i8*)

declare i8* @tmpnam_r(i8*)

declare i8* @tempnam(i8*, i8*)

define %_IO_FILE* @_IO_FILE.20() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fclose(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.21() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fflush(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.22() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fflush_unlocked(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.23() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare %_IO_FILE* @fopen(i8*, i8*)

define %_IO_FILE* @_IO_FILE.24() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

define %_IO_FILE* @_IO_FILE.25() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare %_IO_FILE* @freopen(i8*, i8*, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.26() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare %_IO_FILE* @fdopen(i32, i8*)

define %_IO_FILE* @_IO_FILE.27() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare %_IO_FILE* @fmemopen(i64*, i32, i8*)

define %_IO_FILE* @_IO_FILE.28() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare %_IO_FILE* @open_memstream(i8**, i32*)

define %_IO_FILE* @_IO_FILE.29() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare void @setbuf(%_IO_FILE*, i8*)

define %_IO_FILE* @_IO_FILE.30() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @setvbuf(%_IO_FILE*, i8*, i32, i32)

define %_IO_FILE* @_IO_FILE.31() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare void @setbuffer(%_IO_FILE*, i8*, i32)

define %_IO_FILE* @_IO_FILE.32() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare void @setlinebuf(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.33() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fprintf(%_IO_FILE*, i8*)

declare i32 @printf(i8*)

declare i32 @sprintf(i8*, i8*)

define %_IO_FILE* @_IO_FILE.34() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @vfprintf(%_IO_FILE*, i8*, i32)

declare i32 @vprintf(i8*, i32)

declare i32 @vsprintf(i8*, i8*, i32)

declare i32 @snprintf(i8*, i32, i8*)

declare i32 @vsnprintf(i8*, i32, i8*, i32)

declare i32 @vdprintf(i32, i8*, i32)

declare i32 @dprintf(i32, i8*)

define %_IO_FILE* @_IO_FILE.35() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fscanf(%_IO_FILE*, i8*)

declare i32 @scanf(i8*)

declare i32 @sscanf(i8*, i8*)

define %_IO_FILE* @_IO_FILE.36() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @vfscanf(%_IO_FILE*, i8*, i32)

declare i32 @vscanf(i8*, i32)

declare i32 @vsscanf(i8*, i8*, i32)

define %_IO_FILE* @_IO_FILE.37() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fgetc(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.38() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @getc(%_IO_FILE*)

declare i32 @getchar()

define %_IO_FILE* @_IO_FILE.39() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @getc_unlocked(%_IO_FILE*)

declare i32 @getchar_unlocked()

define %_IO_FILE* @_IO_FILE.40() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fgetc_unlocked(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.41() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fputc(i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.42() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @putc(i32, %_IO_FILE*)

declare i32 @putchar(i32)

define %_IO_FILE* @_IO_FILE.43() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fputc_unlocked(i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.44() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @putc_unlocked(i32, %_IO_FILE*)

declare i32 @putchar_unlocked(i32)

define %_IO_FILE* @_IO_FILE.45() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @getw(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.46() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @putw(i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.47() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i8* @fgets(i8*, i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.48() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i64 @__getdelim(i8**, i32*, i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.49() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i64 @getdelim(i8**, i32*, i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.50() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i64 @getline(i8**, i32*, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.51() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fputs(i8*, %_IO_FILE*)

declare i32 @puts(i8*)

define %_IO_FILE* @_IO_FILE.52() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @ungetc(i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.53() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fread(i64*, i32, i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.54() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fwrite(i64*, i32, i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.55() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fread_unlocked(i64*, i32, i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.56() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fwrite_unlocked(i64*, i32, i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.57() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fseek(%_IO_FILE*, i64, i32)

define %_IO_FILE* @_IO_FILE.58() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i64 @ftell(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.59() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare void @rewind(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.60() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fseeko(%_IO_FILE*, i64, i32)

define %_IO_FILE* @_IO_FILE.61() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i64 @ftello(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.62() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

define %__mbstate_t* @__mbstate_t.63() {
entry:
  %0 = call i64* @malloc(i64 8)
  %1 = bitcast i64* %0 to %__mbstate_t*
  ret %__mbstate_t* %1
}

define %_G_fpos_t* @_G_fpos_t.64() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %_G_fpos_t*
  ret %_G_fpos_t* %1
}

declare i32 @fgetpos(%_IO_FILE*, %_G_fpos_t*)

define %_IO_FILE* @_IO_FILE.65() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

define %_G_fpos_t* @_G_fpos_t.66() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %_G_fpos_t*
  ret %_G_fpos_t* %1
}

declare i32 @fsetpos(%_IO_FILE*, %_G_fpos_t*)

define %_IO_FILE* @_IO_FILE.67() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare void @clearerr(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.68() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @feof(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.69() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @ferror(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.70() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare void @clearerr_unlocked(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.71() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @feof_unlocked(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.72() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @ferror_unlocked(%_IO_FILE*)

declare void @perror(i8*)

define %_IO_FILE* @_IO_FILE.73() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fileno(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.74() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fileno_unlocked(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.75() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare %_IO_FILE* @popen(i8*, i8*)

define %_IO_FILE* @_IO_FILE.76() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @pclose(%_IO_FILE*)

declare i8* @ctermid(i8*)

define %_IO_FILE* @_IO_FILE.77() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare void @flockfile(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.78() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @ftrylockfile(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.79() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare void @funlockfile(%_IO_FILE*)

declare i32 @c_function()
