; ModuleID = 'Blawn'
source_filename = "Blawn"

%struct.String = type { i8*, i64 }
%__mbstate_t = type { i32, i32 }
%div_t = type { i32, i32 }
%ldiv_t = type { i64, i64 }
%lldiv_t = type { i64, i64 }
%imaxdiv_t = type { i64, i64 }
%SDL_Color = type { i8, i8, i8, i8 }
%SDL_Palette = type { i32, %SDL_Color*, i32, i32 }
%SDL_PixelFormat = type { i32, %SDL_Palette*, i8, i8, i16, i32, i32, i32, i32, i8, i8, i8, i8, i8, i8, i8, i8, i32, i64 }
%SDL_Rect = type { i32, i32, i32, i32 }
%SDL_JoystickGUID = type { i128 }
%SDL_GameControllerButtonBind = type { i32, i64 }
%SDL_MessageBoxButtonData = type { i32, i32, i8* }
%SDL_MessageBoxColorScheme = type { i120 }
%SDL_WindowShapeParams = type { i8, %SDL_Color }
%Struct = type { i32, i32 }
%fd_set = type { i1024 }
%timeval = type { i64, i64 }
%timespec = type { i64, i64 }
%__sigset_t = type { i1024 }
%_IO_FILE = type { i8 }
%_G_fpos_t = type { i64, %__mbstate_t }
%random_data = type { i32*, i32*, i32*, i32, i32, i32, i32* }
%drand48_data = type { i48, i48, i16, i16, i64 }
%__locale_struct = type { i832, i16*, i32*, i32*, i832 }
%SDL_AssertData = type { i32, i32, i8*, i8*, i32, i8*, i64 }
%SDL_atomic_t = type { i32 }
%SDL_RWops = type { i8 }
%SDL_AudioSpec = type { i32, i16, i8, i8, i16, i16, i32, i8*, i64* }
%SDL_AudioCVT = type { i32, i16, i16, double, i8*, i32, i32, i32, double, i640, i32 }
%SDL_Point = type { i32, i32 }
%SDL_Surface = type { i32, %SDL_PixelFormat*, i32, i32, i32, i64*, i64*, i32, i64*, %SDL_Rect, i8**, i32 }
%SDL_DisplayMode = type { i32, i32, i32, i32, i64* }
%SDL_Finger = type { i64, double, double, double }
%SDL_MessageBoxData = type { i32, i8**, i8*, i8*, i32, %SDL_MessageBoxButtonData*, %SDL_MessageBoxColorScheme* }
%SDL_RendererInfo = type { i8*, i32, i32, i512, i32, i32 }
%SDL_WindowShapeMode = type { i32, %SDL_WindowShapeParams }
%SDL_version = type { i8, i8, i8 }
%NestStruct = type { i32, i32, %Struct**** }

@TESTES = private unnamed_addr constant [7 x i8] c"TESTES\00"
@winddow = private unnamed_addr constant [8 x i8] c"winddow\00"
@"is succeeded:" = private unnamed_addr constant [14 x i8] c"is succeeded:\00"
@aa = private unnamed_addr constant [3 x i8] c"aa\00"

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
  %"@__NOT_SUPPORTED__3" = alloca i1024
  store i1024 0, i1024* %"@__NOT_SUPPORTED__3"
  %0 = load i1024, i1024* %"@__NOT_SUPPORTED__3"
  %"@tv_sec" = alloca i64
  store i64 0, i64* %"@tv_sec"
  %1 = load i64, i64* %"@tv_sec"
  %"@tv_usec" = alloca i64
  store i64 0, i64* %"@tv_usec"
  %2 = load i64, i64* %"@tv_usec"
  %"@tv_sec1" = alloca i64
  store i64 0, i64* %"@tv_sec1"
  %3 = load i64, i64* %"@tv_sec1"
  %"@tv_nsec" = alloca i64
  store i64 0, i64* %"@tv_nsec"
  %4 = load i64, i64* %"@tv_nsec"
  %"@__NOT_SUPPORTED__2" = alloca i1024
  store i1024 0, i1024* %"@__NOT_SUPPORTED__2"
  %5 = load i1024, i1024* %"@__NOT_SUPPORTED__2"
  %"@__NOT_SUPPORTED__20" = alloca i8
  store i8 0, i8* %"@__NOT_SUPPORTED__20"
  %6 = load i8, i8* %"@__NOT_SUPPORTED__20"
  %"@__pos" = alloca i64
  store i64 0, i64* %"@__pos"
  %7 = load i64, i64* %"@__pos"
  %"@__count" = alloca i32
  store i32 0, i32* %"@__count"
  %8 = load i32, i32* %"@__count"
  %"@__NOT_SUPPORTED__21" = alloca i32
  store i32 0, i32* %"@__NOT_SUPPORTED__21"
  %9 = load i32, i32* %"@__NOT_SUPPORTED__21"
  %10 = alloca %__mbstate_t
  %11 = load %__mbstate_t, %__mbstate_t* %10
  %"@__state" = alloca %__mbstate_t
  store %__mbstate_t %11, %__mbstate_t* %"@__state"
  %12 = load %__mbstate_t, %__mbstate_t* %"@__state"
  %"@fptr" = alloca i32*
  store i32* null, i32** %"@fptr"
  %13 = load i32*, i32** %"@fptr"
  %"@rptr" = alloca i32*
  store i32* null, i32** %"@rptr"
  %14 = load i32*, i32** %"@rptr"
  %"@state" = alloca i32*
  store i32* null, i32** %"@state"
  %15 = load i32*, i32** %"@state"
  %"@rand_type" = alloca i32
  store i32 0, i32* %"@rand_type"
  %16 = load i32, i32* %"@rand_type"
  %"@rand_deg" = alloca i32
  store i32 0, i32* %"@rand_deg"
  %17 = load i32, i32* %"@rand_deg"
  %"@rand_sep" = alloca i32
  store i32 0, i32* %"@rand_sep"
  %18 = load i32, i32* %"@rand_sep"
  %"@end_ptr" = alloca i32*
  store i32* null, i32** %"@end_ptr"
  %19 = load i32*, i32** %"@end_ptr"
  %"@__NOT_SUPPORTED__23" = alloca i48
  store i48 0, i48* %"@__NOT_SUPPORTED__23"
  %20 = load i48, i48* %"@__NOT_SUPPORTED__23"
  %"@__NOT_SUPPORTED__24" = alloca i48
  store i48 0, i48* %"@__NOT_SUPPORTED__24"
  %21 = load i48, i48* %"@__NOT_SUPPORTED__24"
  %"@__c" = alloca i16
  store i16 0, i16* %"@__c"
  %22 = load i16, i16* %"@__c"
  %"@__init" = alloca i16
  store i16 0, i16* %"@__init"
  %23 = load i16, i16* %"@__init"
  %"@__a" = alloca i64
  store i64 0, i64* %"@__a"
  %24 = load i64, i64* %"@__a"
  %"@quot" = alloca i32
  store i32 0, i32* %"@quot"
  %25 = load i32, i32* %"@quot"
  %"@rem" = alloca i32
  store i32 0, i32* %"@rem"
  %26 = load i32, i32* %"@rem"
  %27 = alloca %div_t
  %28 = load %div_t, %div_t* %27
  %"@quot2" = alloca i64
  store i64 0, i64* %"@quot2"
  %29 = load i64, i64* %"@quot2"
  %"@rem3" = alloca i64
  store i64 0, i64* %"@rem3"
  %30 = load i64, i64* %"@rem3"
  %31 = alloca %ldiv_t
  %32 = load %ldiv_t, %ldiv_t* %31
  %"@quot4" = alloca i64
  store i64 0, i64* %"@quot4"
  %33 = load i64, i64* %"@quot4"
  %"@rem5" = alloca i64
  store i64 0, i64* %"@rem5"
  %34 = load i64, i64* %"@rem5"
  %35 = alloca %lldiv_t
  %36 = load %lldiv_t, %lldiv_t* %35
  %"@__NOT_SUPPORTED__25" = alloca i832
  store i832 0, i832* %"@__NOT_SUPPORTED__25"
  %37 = load i832, i832* %"@__NOT_SUPPORTED__25"
  %"@__ctype_b" = alloca i16*
  store i16* null, i16** %"@__ctype_b"
  %38 = load i16*, i16** %"@__ctype_b"
  %"@__ctype_tolower" = alloca i32*
  store i32* null, i32** %"@__ctype_tolower"
  %39 = load i32*, i32** %"@__ctype_tolower"
  %"@__ctype_toupper" = alloca i32*
  store i32* null, i32** %"@__ctype_toupper"
  %40 = load i32*, i32** %"@__ctype_toupper"
  %"@__NOT_SUPPORTED__26" = alloca i832
  store i832 0, i832* %"@__NOT_SUPPORTED__26"
  %41 = load i832, i832* %"@__NOT_SUPPORTED__26"
  %"@quot6" = alloca i64
  store i64 0, i64* %"@quot6"
  %42 = load i64, i64* %"@quot6"
  %"@rem7" = alloca i64
  store i64 0, i64* %"@rem7"
  %43 = load i64, i64* %"@rem7"
  %44 = alloca %imaxdiv_t
  %45 = load %imaxdiv_t, %imaxdiv_t* %44
  %"@always_ignore" = alloca i32
  store i32 0, i32* %"@always_ignore"
  %46 = load i32, i32* %"@always_ignore"
  %"@trigger_count" = alloca i32
  store i32 0, i32* %"@trigger_count"
  %47 = load i32, i32* %"@trigger_count"
  %"@condition" = alloca i8*
  store i8* null, i8** %"@condition"
  %48 = load i8*, i8** %"@condition"
  %"@filename" = alloca i8*
  store i8* null, i8** %"@filename"
  %49 = load i8*, i8** %"@filename"
  %"@linenum" = alloca i32
  store i32 0, i32* %"@linenum"
  %50 = load i32, i32* %"@linenum"
  %"@function" = alloca i8*
  store i8* null, i8** %"@function"
  %51 = load i8*, i8** %"@function"
  %"@__NOT_SUPPORTED__27" = alloca i64
  store i64 0, i64* %"@__NOT_SUPPORTED__27"
  %52 = load i64, i64* %"@__NOT_SUPPORTED__27"
  %"@value" = alloca i32
  store i32 0, i32* %"@value"
  %53 = load i32, i32* %"@value"
  %"@__NOT_SUPPORTED__28" = alloca i8
  store i8 0, i8* %"@__NOT_SUPPORTED__28"
  %54 = load i8, i8* %"@__NOT_SUPPORTED__28"
  %"@freq" = alloca i32
  store i32 0, i32* %"@freq"
  %55 = load i32, i32* %"@freq"
  %"@format" = alloca i16
  store i16 0, i16* %"@format"
  %56 = load i16, i16* %"@format"
  %"@channels" = alloca i8
  store i8 0, i8* %"@channels"
  %57 = load i8, i8* %"@channels"
  %"@silence" = alloca i8
  store i8 0, i8* %"@silence"
  %58 = load i8, i8* %"@silence"
  %"@samples" = alloca i16
  store i16 0, i16* %"@samples"
  %59 = load i16, i16* %"@samples"
  %"@padding" = alloca i16
  store i16 0, i16* %"@padding"
  %60 = load i16, i16* %"@padding"
  %"@size" = alloca i32
  store i32 0, i32* %"@size"
  %61 = load i32, i32* %"@size"
  %"@callback" = alloca i8*
  store i8* null, i8** %"@callback"
  %62 = load i8*, i8** %"@callback"
  %"@userdata" = alloca i64*
  store i64* null, i64** %"@userdata"
  %63 = load i64*, i64** %"@userdata"
  %"@needed" = alloca i32
  store i32 0, i32* %"@needed"
  %64 = load i32, i32* %"@needed"
  %"@src_format" = alloca i16
  store i16 0, i16* %"@src_format"
  %65 = load i16, i16* %"@src_format"
  %"@dst_format" = alloca i16
  store i16 0, i16* %"@dst_format"
  %66 = load i16, i16* %"@dst_format"
  %"@rate_incr" = alloca double
  store double 0.000000e+00, double* %"@rate_incr"
  %67 = load double, double* %"@rate_incr"
  %"@buf" = alloca i8*
  store i8* null, i8** %"@buf"
  %68 = load i8*, i8** %"@buf"
  %"@len" = alloca i32
  store i32 0, i32* %"@len"
  %69 = load i32, i32* %"@len"
  %"@len_cvt" = alloca i32
  store i32 0, i32* %"@len_cvt"
  %70 = load i32, i32* %"@len_cvt"
  %"@len_mult" = alloca i32
  store i32 0, i32* %"@len_mult"
  %71 = load i32, i32* %"@len_mult"
  %"@len_ratio" = alloca double
  store double 0.000000e+00, double* %"@len_ratio"
  %72 = load double, double* %"@len_ratio"
  %"@__NOT_SUPPORTED__29" = alloca i640
  store i640 0, i640* %"@__NOT_SUPPORTED__29"
  %73 = load i640, i640* %"@__NOT_SUPPORTED__29"
  %"@filter_index" = alloca i32
  store i32 0, i32* %"@filter_index"
  %74 = load i32, i32* %"@filter_index"
  %"@format8" = alloca i32
  store i32 0, i32* %"@format8"
  %75 = load i32, i32* %"@format8"
  %"@ncolors" = alloca i32
  store i32 0, i32* %"@ncolors"
  %76 = load i32, i32* %"@ncolors"
  %"@r" = alloca i8
  store i8 0, i8* %"@r"
  %77 = load i8, i8* %"@r"
  %"@g" = alloca i8
  store i8 0, i8* %"@g"
  %78 = load i8, i8* %"@g"
  %"@b" = alloca i8
  store i8 0, i8* %"@b"
  %79 = load i8, i8* %"@b"
  %"@a" = alloca i8
  store i8 0, i8* %"@a"
  %80 = load i8, i8* %"@a"
  %"@colors" = alloca %SDL_Color*
  store %SDL_Color* null, %SDL_Color** %"@colors"
  %81 = load %SDL_Color*, %SDL_Color** %"@colors"
  %"@version" = alloca i32
  store i32 0, i32* %"@version"
  %82 = load i32, i32* %"@version"
  %"@refcount" = alloca i32
  store i32 0, i32* %"@refcount"
  %83 = load i32, i32* %"@refcount"
  %"@palette" = alloca %SDL_Palette*
  store %SDL_Palette* null, %SDL_Palette** %"@palette"
  %84 = load %SDL_Palette*, %SDL_Palette** %"@palette"
  %"@BitsPerPixel" = alloca i8
  store i8 0, i8* %"@BitsPerPixel"
  %85 = load i8, i8* %"@BitsPerPixel"
  %"@BytesPerPixel" = alloca i8
  store i8 0, i8* %"@BytesPerPixel"
  %86 = load i8, i8* %"@BytesPerPixel"
  %"@__NOT_SUPPORTED__30" = alloca i16
  store i16 0, i16* %"@__NOT_SUPPORTED__30"
  %87 = load i16, i16* %"@__NOT_SUPPORTED__30"
  %"@Rmask" = alloca i32
  store i32 0, i32* %"@Rmask"
  %88 = load i32, i32* %"@Rmask"
  %"@Gmask" = alloca i32
  store i32 0, i32* %"@Gmask"
  %89 = load i32, i32* %"@Gmask"
  %"@Bmask" = alloca i32
  store i32 0, i32* %"@Bmask"
  %90 = load i32, i32* %"@Bmask"
  %"@Amask" = alloca i32
  store i32 0, i32* %"@Amask"
  %91 = load i32, i32* %"@Amask"
  %"@Rloss" = alloca i8
  store i8 0, i8* %"@Rloss"
  %92 = load i8, i8* %"@Rloss"
  %"@Gloss" = alloca i8
  store i8 0, i8* %"@Gloss"
  %93 = load i8, i8* %"@Gloss"
  %"@Bloss" = alloca i8
  store i8 0, i8* %"@Bloss"
  %94 = load i8, i8* %"@Bloss"
  %"@Aloss" = alloca i8
  store i8 0, i8* %"@Aloss"
  %95 = load i8, i8* %"@Aloss"
  %"@Rshift" = alloca i8
  store i8 0, i8* %"@Rshift"
  %96 = load i8, i8* %"@Rshift"
  %"@Gshift" = alloca i8
  store i8 0, i8* %"@Gshift"
  %97 = load i8, i8* %"@Gshift"
  %"@Bshift" = alloca i8
  store i8 0, i8* %"@Bshift"
  %98 = load i8, i8* %"@Bshift"
  %"@Ashift" = alloca i8
  store i8 0, i8* %"@Ashift"
  %99 = load i8, i8* %"@Ashift"
  %"@refcount9" = alloca i32
  store i32 0, i32* %"@refcount9"
  %100 = load i32, i32* %"@refcount9"
  %"@__NOT_SUPPORTED__31" = alloca i64
  store i64 0, i64* %"@__NOT_SUPPORTED__31"
  %101 = load i64, i64* %"@__NOT_SUPPORTED__31"
  %"@x" = alloca i32
  store i32 0, i32* %"@x"
  %102 = load i32, i32* %"@x"
  %"@y" = alloca i32
  store i32 0, i32* %"@y"
  %103 = load i32, i32* %"@y"
  %"@x10" = alloca i32
  store i32 0, i32* %"@x10"
  %104 = load i32, i32* %"@x10"
  %"@y11" = alloca i32
  store i32 0, i32* %"@y11"
  %105 = load i32, i32* %"@y11"
  %"@w" = alloca i32
  store i32 0, i32* %"@w"
  %106 = load i32, i32* %"@w"
  %"@h" = alloca i32
  store i32 0, i32* %"@h"
  %107 = load i32, i32* %"@h"
  %"@flags" = alloca i32
  store i32 0, i32* %"@flags"
  %108 = load i32, i32* %"@flags"
  %"@format12" = alloca %SDL_PixelFormat*
  store %SDL_PixelFormat* null, %SDL_PixelFormat** %"@format12"
  %109 = load %SDL_PixelFormat*, %SDL_PixelFormat** %"@format12"
  %"@w13" = alloca i32
  store i32 0, i32* %"@w13"
  %110 = load i32, i32* %"@w13"
  %"@h14" = alloca i32
  store i32 0, i32* %"@h14"
  %111 = load i32, i32* %"@h14"
  %"@pitch" = alloca i32
  store i32 0, i32* %"@pitch"
  %112 = load i32, i32* %"@pitch"
  %"@pixels" = alloca i64*
  store i64* null, i64** %"@pixels"
  %113 = load i64*, i64** %"@pixels"
  %"@userdata15" = alloca i64*
  store i64* null, i64** %"@userdata15"
  %114 = load i64*, i64** %"@userdata15"
  %"@locked" = alloca i32
  store i32 0, i32* %"@locked"
  %115 = load i32, i32* %"@locked"
  %"@lock_data" = alloca i64*
  store i64* null, i64** %"@lock_data"
  %116 = load i64*, i64** %"@lock_data"
  %117 = alloca %SDL_Rect
  %118 = load %SDL_Rect, %SDL_Rect* %117
  %"@clip_rect" = alloca %SDL_Rect
  store %SDL_Rect %118, %SDL_Rect* %"@clip_rect"
  %119 = load %SDL_Rect, %SDL_Rect* %"@clip_rect"
  %"@map" = alloca i8**
  store i8** null, i8*** %"@map"
  %120 = load i8**, i8*** %"@map"
  %"@refcount16" = alloca i32
  store i32 0, i32* %"@refcount16"
  %121 = load i32, i32* %"@refcount16"
  %"@format17" = alloca i32
  store i32 0, i32* %"@format17"
  %122 = load i32, i32* %"@format17"
  %"@w18" = alloca i32
  store i32 0, i32* %"@w18"
  %123 = load i32, i32* %"@w18"
  %"@h19" = alloca i32
  store i32 0, i32* %"@h19"
  %124 = load i32, i32* %"@h19"
  %"@refresh_rate" = alloca i32
  store i32 0, i32* %"@refresh_rate"
  %125 = load i32, i32* %"@refresh_rate"
  %"@driverdata" = alloca i64*
  store i64* null, i64** %"@driverdata"
  %126 = load i64*, i64** %"@driverdata"
  %"@__NOT_SUPPORTED__32" = alloca i128
  store i128 0, i128* %"@__NOT_SUPPORTED__32"
  %127 = load i128, i128* %"@__NOT_SUPPORTED__32"
  %128 = alloca %SDL_JoystickGUID
  %129 = load %SDL_JoystickGUID, %SDL_JoystickGUID* %128
  %130 = alloca %SDL_JoystickGUID
  %131 = load %SDL_JoystickGUID, %SDL_JoystickGUID* %130
  %132 = alloca %SDL_JoystickGUID
  %133 = load %SDL_JoystickGUID, %SDL_JoystickGUID* %132
  %134 = alloca %SDL_JoystickGUID
  %135 = load %SDL_JoystickGUID, %SDL_JoystickGUID* %134
  %136 = alloca %SDL_JoystickGUID
  %137 = load %SDL_JoystickGUID, %SDL_JoystickGUID* %136
  %"@bindType" = alloca i32
  store i32 0, i32* %"@bindType"
  %138 = load i32, i32* %"@bindType"
  %"@__NOT_SUPPORTED__33" = alloca i64
  store i64 0, i64* %"@__NOT_SUPPORTED__33"
  %139 = load i64, i64* %"@__NOT_SUPPORTED__33"
  %140 = alloca %SDL_GameControllerButtonBind
  %141 = load %SDL_GameControllerButtonBind, %SDL_GameControllerButtonBind* %140
  %142 = alloca %SDL_GameControllerButtonBind
  %143 = load %SDL_GameControllerButtonBind, %SDL_GameControllerButtonBind* %142
  %"@id" = alloca i64
  store i64 0, i64* %"@id"
  %144 = load i64, i64* %"@id"
  %"@x20" = alloca double
  store double 0.000000e+00, double* %"@x20"
  %145 = load double, double* %"@x20"
  %"@y21" = alloca double
  store double 0.000000e+00, double* %"@y21"
  %146 = load double, double* %"@y21"
  %"@pressure" = alloca double
  store double 0.000000e+00, double* %"@pressure"
  %147 = load double, double* %"@pressure"
  %"@flags22" = alloca i32
  store i32 0, i32* %"@flags22"
  %148 = load i32, i32* %"@flags22"
  %"@window" = alloca i8**
  store i8** null, i8*** %"@window"
  %149 = load i8**, i8*** %"@window"
  %"@title" = alloca i8*
  store i8* null, i8** %"@title"
  %150 = load i8*, i8** %"@title"
  %"@message" = alloca i8*
  store i8* null, i8** %"@message"
  %151 = load i8*, i8** %"@message"
  %"@numbuttons" = alloca i32
  store i32 0, i32* %"@numbuttons"
  %152 = load i32, i32* %"@numbuttons"
  %"@flags23" = alloca i32
  store i32 0, i32* %"@flags23"
  %153 = load i32, i32* %"@flags23"
  %"@buttonid" = alloca i32
  store i32 0, i32* %"@buttonid"
  %154 = load i32, i32* %"@buttonid"
  %"@text" = alloca i8*
  store i8* null, i8** %"@text"
  %155 = load i8*, i8** %"@text"
  %"@buttons" = alloca %SDL_MessageBoxButtonData*
  store %SDL_MessageBoxButtonData* null, %SDL_MessageBoxButtonData** %"@buttons"
  %156 = load %SDL_MessageBoxButtonData*, %SDL_MessageBoxButtonData** %"@buttons"
  %"@__NOT_SUPPORTED__43" = alloca i120
  store i120 0, i120* %"@__NOT_SUPPORTED__43"
  %157 = load i120, i120* %"@__NOT_SUPPORTED__43"
  %"@colorScheme" = alloca %SDL_MessageBoxColorScheme*
  store %SDL_MessageBoxColorScheme* null, %SDL_MessageBoxColorScheme** %"@colorScheme"
  %158 = load %SDL_MessageBoxColorScheme*, %SDL_MessageBoxColorScheme** %"@colorScheme"
  %"@name" = alloca i8*
  store i8* null, i8** %"@name"
  %159 = load i8*, i8** %"@name"
  %"@flags24" = alloca i32
  store i32 0, i32* %"@flags24"
  %160 = load i32, i32* %"@flags24"
  %"@num_texture_formats" = alloca i32
  store i32 0, i32* %"@num_texture_formats"
  %161 = load i32, i32* %"@num_texture_formats"
  %"@__NOT_SUPPORTED__44" = alloca i512
  store i512 0, i512* %"@__NOT_SUPPORTED__44"
  %162 = load i512, i512* %"@__NOT_SUPPORTED__44"
  %"@max_texture_width" = alloca i32
  store i32 0, i32* %"@max_texture_width"
  %163 = load i32, i32* %"@max_texture_width"
  %"@max_texture_height" = alloca i32
  store i32 0, i32* %"@max_texture_height"
  %164 = load i32, i32* %"@max_texture_height"
  %"@mode" = alloca i32
  store i32 0, i32* %"@mode"
  %165 = load i32, i32* %"@mode"
  %"@binarizationCutoff" = alloca i8
  store i8 0, i8* %"@binarizationCutoff"
  %166 = load i8, i8* %"@binarizationCutoff"
  %167 = alloca %SDL_Color
  %168 = load %SDL_Color, %SDL_Color* %167
  %"@colorKey" = alloca %SDL_Color
  store %SDL_Color %168, %SDL_Color* %"@colorKey"
  %169 = load %SDL_Color, %SDL_Color* %"@colorKey"
  %170 = alloca %SDL_WindowShapeParams
  %171 = load %SDL_WindowShapeParams, %SDL_WindowShapeParams* %170
  %"@parameters" = alloca %SDL_WindowShapeParams
  store %SDL_WindowShapeParams %171, %SDL_WindowShapeParams* %"@parameters"
  %172 = load %SDL_WindowShapeParams, %SDL_WindowShapeParams* %"@parameters"
  %"@major" = alloca i8
  store i8 0, i8* %"@major"
  %173 = load i8, i8* %"@major"
  %"@minor" = alloca i8
  store i8 0, i8* %"@minor"
  %174 = load i8, i8* %"@minor"
  %"@patch" = alloca i8
  store i8 0, i8* %"@patch"
  %175 = load i8, i8* %"@patch"
  %"@member" = alloca i32
  store i32 0, i32* %"@member"
  %176 = load i32, i32* %"@member"
  %"@member2" = alloca i32
  store i32 0, i32* %"@member2"
  %177 = load i32, i32* %"@member2"
  %"@member25" = alloca i32
  store i32 0, i32* %"@member25"
  %178 = load i32, i32* %"@member25"
  %"@member226" = alloca i32
  store i32 0, i32* %"@member226"
  %179 = load i32, i32* %"@member226"
  %"@s" = alloca %Struct****
  store %Struct**** null, %Struct***** %"@s"
  %180 = load %Struct****, %Struct***** %"@s"
  %a = alloca i64
  store i64 0, i64* %a
  %181 = load i64, i64* %a
  %182 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @TESTES, i32 0, i32 0), i64 6)
  call void @print(%struct.String* %182)
  %183 = call i32 @show()
  %184 = call i64 @i32_to_i64(i32 %183)
  %res = alloca i64
  store i64 %184, i64* %res
  %185 = load i64, i64* %res
  %186 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([8 x i8], [8 x i8]* @winddow, i32 0, i32 0), i64 7)
  %187 = call i8* @to_char_ptr(%struct.String* %186)
  %188 = call i32 @i64_to_i32(i64 500)
  %189 = call i32 @i64_to_i32(i64 500)
  %190 = call i32 @i64_to_i32(i64 640)
  %191 = call i32 @i64_to_i32(i64 480)
  %192 = call i32 @i64_to_i32(i64 2)
  %193 = call i8** @SDL_CreateWindow(i8* %187, i32 %188, i32 %189, i32 %190, i32 %191, i32 %192)
  %window = alloca i8**
  store i8** %193, i8*** %window
  %194 = load i8**, i8*** %window
  %195 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @"is succeeded:", i32 0, i32 0), i64 13)
  call void @print(%struct.String* %195)
  %196 = load i64, i64* %res
  %197 = call %struct.String* @int_to_str(i64 %196)
  call void @print(%struct.String* %197)
  %198 = call i8 @i64_to_i8(i64 7)
  %199 = call i64 @i8_to_i64(i8 %198)
  %200 = call %struct.String* @int_to_str(i64 %199)
  call void @print(%struct.String* %200)
  %201 = call %struct.String* @string_constructor(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @aa, i32 0, i32 0), i64 2)
  call void @print(%struct.String* %201)
  ret i8 0
}

declare void @__fsid_t()

declare void @__sigset_t()

declare void @timeval()

declare void @timespec()

declare void @fd_set()

declare void @__pthread_rwlock_arch_t()

declare void @__pthread_internal_list()

declare void @__pthread_mutex_s()

declare void @__pthread_cond_s()

declare void @pthread_mutexattr_t()

declare void @pthread_condattr_t()

declare void @pthread_mutex_t()

declare void @pthread_cond_t()

declare void @pthread_rwlock_t()

declare void @pthread_rwlockattr_t()

declare void @pthread_barrier_t()

declare void @pthread_barrierattr_t()

declare void @_IO_FILE()

declare void @__mbstate_t()

declare void @_G_fpos_t()

declare void @_G_fpos64_t()

declare void @_IO_marker()

declare void @div_t()

declare void @ldiv_t()

declare void @lldiv_t()

declare void @random_data()

declare void @drand48_data()

declare void @__locale_struct()

declare void @imaxdiv_t()

declare void @SDL_AssertData()

declare void @SDL_atomic_t()

declare void @SDL_RWops()

declare void @SDL_AudioSpec()

declare void @SDL_AudioCVT()

declare void @SDL_Color()

declare void @SDL_Palette()

declare void @SDL_PixelFormat()

declare void @SDL_Point()

declare void @SDL_Rect()

declare void @SDL_Surface()

declare void @SDL_DisplayMode()

declare void @SDL_Keysym()

declare void @SDL_JoystickGUID()

declare void @SDL_GameControllerButtonBind()

declare void @SDL_Finger()

declare void @SDL_CommonEvent()

declare void @SDL_WindowEvent()

declare void @SDL_KeyboardEvent()

declare void @SDL_TextEditingEvent()

declare void @SDL_TextInputEvent()

declare void @SDL_MouseMotionEvent()

declare void @SDL_MouseButtonEvent()

declare void @SDL_MouseWheelEvent()

declare void @SDL_JoyAxisEvent()

declare void @SDL_JoyBallEvent()

declare void @SDL_JoyHatEvent()

declare void @SDL_JoyButtonEvent()

declare void @SDL_JoyDeviceEvent()

declare void @SDL_ControllerAxisEvent()

declare void @SDL_ControllerButtonEvent()

declare void @SDL_ControllerDeviceEvent()

declare void @SDL_AudioDeviceEvent()

declare void @SDL_TouchFingerEvent()

declare void @SDL_MultiGestureEvent()

declare void @SDL_DollarGestureEvent()

declare void @SDL_DropEvent()

declare void @SDL_QuitEvent()

declare void @SDL_OSEvent()

declare void @SDL_UserEvent()

declare void @SDL_SysWMEvent()

declare void @SDL_HapticDirection()

declare void @SDL_HapticConstant()

declare void @SDL_HapticPeriodic()

declare void @SDL_HapticCondition()

declare void @SDL_HapticRamp()

declare void @SDL_HapticLeftRight()

declare void @SDL_HapticCustom()

declare void @SDL_MessageBoxButtonData()

declare void @SDL_MessageBoxColor()

declare void @SDL_MessageBoxColorScheme()

declare void @SDL_MessageBoxData()

declare void @SDL_RendererInfo()

declare void @SDL_WindowShapeParams()

declare void @SDL_WindowShapeMode()

declare void @SDL_version()

declare void @Struct()

declare void @NestStruct()

declare i8* @SDL_GetPlatform()

declare i16 @__uint16_identity(i16)

declare i32 @__uint32_identity(i32)

declare i64 @__uint64_identity(i64)

define %fd_set* @fd_set.1() {
entry:
  %0 = call i64* @malloc(i64 128)
  %1 = bitcast i64* %0 to %fd_set*
  ret %fd_set* %1
}

define %fd_set* @fd_set.2() {
entry:
  %0 = call i64* @malloc(i64 128)
  %1 = bitcast i64* %0 to %fd_set*
  ret %fd_set* %1
}

define %fd_set* @fd_set.3() {
entry:
  %0 = call i64* @malloc(i64 128)
  %1 = bitcast i64* %0 to %fd_set*
  ret %fd_set* %1
}

define %timeval* @timeval.4() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %timeval*
  ret %timeval* %1
}

declare i32 @select(i32, %fd_set*, %fd_set*, %fd_set*, %timeval*)

define %fd_set* @fd_set.5() {
entry:
  %0 = call i64* @malloc(i64 128)
  %1 = bitcast i64* %0 to %fd_set*
  ret %fd_set* %1
}

define %fd_set* @fd_set.6() {
entry:
  %0 = call i64* @malloc(i64 128)
  %1 = bitcast i64* %0 to %fd_set*
  ret %fd_set* %1
}

define %fd_set* @fd_set.7() {
entry:
  %0 = call i64* @malloc(i64 128)
  %1 = bitcast i64* %0 to %fd_set*
  ret %fd_set* %1
}

define %timespec* @timespec.8() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %timespec*
  ret %timespec* %1
}

define %__sigset_t* @__sigset_t.9() {
entry:
  %0 = call i64* @malloc(i64 128)
  %1 = bitcast i64* %0 to %__sigset_t*
  ret %__sigset_t* %1
}

declare i32 @pselect(i32, %fd_set*, %fd_set*, %fd_set*, %timespec*, %__sigset_t*)

declare i32 @gnu_dev_major(i64)

declare i32 @gnu_dev_minor(i64)

declare i64 @gnu_dev_makedev(i32, i32)

define %_IO_FILE* @_IO_FILE.10() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @__underflow(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.11() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @__uflow(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.12() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @__overflow(%_IO_FILE*, i32)

define %_IO_FILE* @_IO_FILE.13() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @_IO_getc(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.14() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @_IO_putc(i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.15() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @_IO_feof(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.16() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @_IO_ferror(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.17() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @_IO_peekc_locked(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.18() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare void @_IO_flockfile(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.19() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare void @_IO_funlockfile(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.20() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @_IO_ftrylockfile(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.21() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @_IO_vfscanf(%_IO_FILE*, i8*, i32, i32*)

define %_IO_FILE* @_IO_FILE.22() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @_IO_vfprintf(%_IO_FILE*, i8*, i32)

define %_IO_FILE* @_IO_FILE.23() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i64 @_IO_padn(%_IO_FILE*, i32, i64)

define %_IO_FILE* @_IO_FILE.24() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @_IO_sgetn(%_IO_FILE*, i64*, i32)

define %_IO_FILE* @_IO_FILE.25() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i64 @_IO_seekoff(%_IO_FILE*, i64, i32, i32)

define %_IO_FILE* @_IO_FILE.26() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i64 @_IO_seekpos(%_IO_FILE*, i64, i32)

define %_IO_FILE* @_IO_FILE.27() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare void @_IO_free_backup_area(%_IO_FILE*)

declare i32 @remove(i8*)

declare i32 @rename(i8*, i8*)

declare i32 @renameat(i32, i8*, i32, i8*)

define %_IO_FILE* @_IO_FILE.28() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare %_IO_FILE* @tmpfile()

declare i8* @tmpnam(i8*)

declare i8* @tmpnam_r(i8*)

declare i8* @tempnam(i8*, i8*)

define %_IO_FILE* @_IO_FILE.29() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fclose(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.30() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fflush(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.31() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fflush_unlocked(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.32() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare %_IO_FILE* @fopen(i8*, i8*)

define %_IO_FILE* @_IO_FILE.33() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

define %_IO_FILE* @_IO_FILE.34() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare %_IO_FILE* @freopen(i8*, i8*, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.35() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare %_IO_FILE* @fdopen(i32, i8*)

define %_IO_FILE* @_IO_FILE.36() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare %_IO_FILE* @fmemopen(i64*, i32, i8*)

define %_IO_FILE* @_IO_FILE.37() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare %_IO_FILE* @open_memstream(i8**, i32*)

define %_IO_FILE* @_IO_FILE.38() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare void @setbuf(%_IO_FILE*, i8*)

define %_IO_FILE* @_IO_FILE.39() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @setvbuf(%_IO_FILE*, i8*, i32, i32)

define %_IO_FILE* @_IO_FILE.40() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare void @setbuffer(%_IO_FILE*, i8*, i32)

define %_IO_FILE* @_IO_FILE.41() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare void @setlinebuf(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.42() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fprintf(%_IO_FILE*, i8*)

declare i32 @printf(i8*)

declare i32 @sprintf(i8*, i8*)

define %_IO_FILE* @_IO_FILE.43() {
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

define %_IO_FILE* @_IO_FILE.44() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fscanf(%_IO_FILE*, i8*)

declare i32 @scanf(i8*)

declare i32 @sscanf(i8*, i8*)

define %_IO_FILE* @_IO_FILE.45() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @vfscanf(%_IO_FILE*, i8*, i32)

declare i32 @vscanf(i8*, i32)

declare i32 @vsscanf(i8*, i8*, i32)

define %_IO_FILE* @_IO_FILE.46() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fgetc(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.47() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @getc(%_IO_FILE*)

declare i32 @getchar()

define %_IO_FILE* @_IO_FILE.48() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @getc_unlocked(%_IO_FILE*)

declare i32 @getchar_unlocked()

define %_IO_FILE* @_IO_FILE.49() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fgetc_unlocked(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.50() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fputc(i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.51() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @putc(i32, %_IO_FILE*)

declare i32 @putchar(i32)

define %_IO_FILE* @_IO_FILE.52() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fputc_unlocked(i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.53() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @putc_unlocked(i32, %_IO_FILE*)

declare i32 @putchar_unlocked(i32)

define %_IO_FILE* @_IO_FILE.54() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @getw(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.55() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @putw(i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.56() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i8* @fgets(i8*, i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.57() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i64 @__getdelim(i8**, i32*, i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.58() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i64 @getdelim(i8**, i32*, i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.59() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i64 @getline(i8**, i32*, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.60() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fputs(i8*, %_IO_FILE*)

declare i32 @puts(i8*)

define %_IO_FILE* @_IO_FILE.61() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @ungetc(i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.62() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fread(i64*, i32, i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.63() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fwrite(i64*, i32, i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.64() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fread_unlocked(i64*, i32, i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.65() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fwrite_unlocked(i64*, i32, i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.66() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fseek(%_IO_FILE*, i64, i32)

define %_IO_FILE* @_IO_FILE.67() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i64 @ftell(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.68() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare void @rewind(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.69() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fseeko(%_IO_FILE*, i64, i32)

define %_IO_FILE* @_IO_FILE.70() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i64 @ftello(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.71() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

define %__mbstate_t* @__mbstate_t.72() {
entry:
  %0 = call i64* @malloc(i64 8)
  %1 = bitcast i64* %0 to %__mbstate_t*
  ret %__mbstate_t* %1
}

define %_G_fpos_t* @_G_fpos_t.73() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %_G_fpos_t*
  ret %_G_fpos_t* %1
}

declare i32 @fgetpos(%_IO_FILE*, %_G_fpos_t*)

define %_IO_FILE* @_IO_FILE.74() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

define %_G_fpos_t* @_G_fpos_t.75() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %_G_fpos_t*
  ret %_G_fpos_t* %1
}

declare i32 @fsetpos(%_IO_FILE*, %_G_fpos_t*)

define %_IO_FILE* @_IO_FILE.76() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare void @clearerr(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.77() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @feof(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.78() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @ferror(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.79() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare void @clearerr_unlocked(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.80() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @feof_unlocked(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.81() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @ferror_unlocked(%_IO_FILE*)

declare void @perror(i8*)

define %_IO_FILE* @_IO_FILE.82() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fileno(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.83() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fileno_unlocked(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.84() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare %_IO_FILE* @popen(i8*, i8*)

define %_IO_FILE* @_IO_FILE.85() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @pclose(%_IO_FILE*)

declare i8* @ctermid(i8*)

define %_IO_FILE* @_IO_FILE.86() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare void @flockfile(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.87() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @ftrylockfile(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.88() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare void @funlockfile(%_IO_FILE*)

declare i32 @__ctype_get_mb_cur_max()

declare double @atof(i8*)

declare i32 @atoi(i8*)

declare i64 @atol(i8*)

declare i64 @atoll(i8*)

declare double @strtod(i8*, i8**)

declare double @strtof(i8*, i8**)

declare double @strtold(i8*, i8**)

declare i64 @strtol(i8*, i8**, i32)

declare i64 @strtoul(i8*, i8**, i32)

declare i64 @strtoq(i8*, i8**, i32)

declare i64 @strtouq(i8*, i8**, i32)

declare i64 @strtoll(i8*, i8**, i32)

declare i64 @strtoull(i8*, i8**, i32)

declare i8* @l64a(i64)

declare i64 @a64l(i8*)

declare i64 @random()

declare void @srandom(i32)

declare i8* @initstate(i32, i8*, i32)

declare i8* @setstate(i8*)

define %random_data* @random_data.89() {
entry:
  %0 = call i64* @malloc(i64 48)
  %1 = bitcast i64* %0 to %random_data*
  ret %random_data* %1
}

declare i32 @random_r(%random_data*, i32*)

define %random_data* @random_data.90() {
entry:
  %0 = call i64* @malloc(i64 48)
  %1 = bitcast i64* %0 to %random_data*
  ret %random_data* %1
}

declare i32 @srandom_r(i32, %random_data*)

define %random_data* @random_data.91() {
entry:
  %0 = call i64* @malloc(i64 48)
  %1 = bitcast i64* %0 to %random_data*
  ret %random_data* %1
}

declare i32 @initstate_r(i32, i8*, i32, %random_data*)

define %random_data* @random_data.92() {
entry:
  %0 = call i64* @malloc(i64 48)
  %1 = bitcast i64* %0 to %random_data*
  ret %random_data* %1
}

declare i32 @setstate_r(i8*, %random_data*)

declare i32 @rand()

declare void @srand(i32)

declare i32 @rand_r(i32*)

declare double @drand48()

declare double @erand48(i48)

declare i64 @lrand48()

declare i64 @nrand48(i48)

declare i64 @mrand48()

declare i64 @jrand48(i48)

declare void @srand48(i64)

declare i16* @seed48(i48)

declare void @lcong48(i112)

define %drand48_data* @drand48_data.93() {
entry:
  %0 = call i64* @malloc(i64 28)
  %1 = bitcast i64* %0 to %drand48_data*
  ret %drand48_data* %1
}

declare i32 @drand48_r(%drand48_data*, float*)

define %drand48_data* @drand48_data.94() {
entry:
  %0 = call i64* @malloc(i64 28)
  %1 = bitcast i64* %0 to %drand48_data*
  ret %drand48_data* %1
}

declare i32 @erand48_r(i48, %drand48_data*, float*)

define %drand48_data* @drand48_data.95() {
entry:
  %0 = call i64* @malloc(i64 28)
  %1 = bitcast i64* %0 to %drand48_data*
  ret %drand48_data* %1
}

declare i32 @lrand48_r(%drand48_data*, i64*)

define %drand48_data* @drand48_data.96() {
entry:
  %0 = call i64* @malloc(i64 28)
  %1 = bitcast i64* %0 to %drand48_data*
  ret %drand48_data* %1
}

declare i32 @nrand48_r(i48, %drand48_data*, i64*)

define %drand48_data* @drand48_data.97() {
entry:
  %0 = call i64* @malloc(i64 28)
  %1 = bitcast i64* %0 to %drand48_data*
  ret %drand48_data* %1
}

declare i32 @mrand48_r(%drand48_data*, i64*)

define %drand48_data* @drand48_data.98() {
entry:
  %0 = call i64* @malloc(i64 28)
  %1 = bitcast i64* %0 to %drand48_data*
  ret %drand48_data* %1
}

declare i32 @jrand48_r(i48, %drand48_data*, i64*)

define %drand48_data* @drand48_data.99() {
entry:
  %0 = call i64* @malloc(i64 28)
  %1 = bitcast i64* %0 to %drand48_data*
  ret %drand48_data* %1
}

declare i32 @srand48_r(i64, %drand48_data*)

define %drand48_data* @drand48_data.100() {
entry:
  %0 = call i64* @malloc(i64 28)
  %1 = bitcast i64* %0 to %drand48_data*
  ret %drand48_data* %1
}

declare i32 @seed48_r(i48, %drand48_data*)

define %drand48_data* @drand48_data.101() {
entry:
  %0 = call i64* @malloc(i64 28)
  %1 = bitcast i64* %0 to %drand48_data*
  ret %drand48_data* %1
}

declare i32 @lcong48_r(i112, %drand48_data*)

declare i64* @malloc.102(i32)

declare i64* @calloc(i32, i32)

declare i64* @realloc(i64*, i32)

declare void @free.103(i64*)

declare i64* @alloca(i32)

declare i64* @valloc(i32)

declare i32 @posix_memalign(i64**, i32, i32)

declare i64* @aligned_alloc(i32, i32)

declare void @abort()

declare i32 @atexit(i8*)

declare i32 @at_quick_exit(i8*)

declare i32 @on_exit(i8*, i64*)

declare void @exit(i32)

declare void @quick_exit(i32)

declare void @_Exit(i32)

declare i8* @getenv(i8*)

declare i32 @putenv(i8*)

declare i32 @setenv(i8*, i8*, i32)

declare i32 @unsetenv(i8*)

declare i32 @clearenv()

declare i8* @mktemp(i8*)

declare i32 @mkstemp(i8*)

declare i32 @mkstemps(i8*, i32)

declare i8* @mkdtemp(i8*)

declare i32 @system(i8*)

declare i8* @realpath(i8*, i8*)

declare i64* @bsearch(i64*, i64*, i32, i32, i8*)

declare void @qsort(i64*, i32, i32, i8*)

declare i32 @abs(i32)

declare i64 @labs(i64)

declare i64 @llabs(i64)

define %div_t* @div_t.104() {
entry:
  %0 = call i64* @malloc(i64 8)
  %1 = bitcast i64* %0 to %div_t*
  ret %div_t* %1
}

declare %div_t @div(i32, i32)

define %ldiv_t* @ldiv_t.105() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %ldiv_t*
  ret %ldiv_t* %1
}

declare %ldiv_t @ldiv(i64, i64)

define %lldiv_t* @lldiv_t.106() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %lldiv_t*
  ret %lldiv_t* %1
}

declare %lldiv_t @lldiv(i64, i64)

declare i8* @ecvt(double, i32, i32*, i32*)

declare i8* @fcvt(double, i32, i32*, i32*)

declare i8* @gcvt(double, i32, i8*)

declare i8* @qecvt(double, i32, i32*, i32*)

declare i8* @qfcvt(double, i32, i32*, i32*)

declare i8* @qgcvt(double, i32, i8*)

declare i32 @ecvt_r(double, i32, i32*, i32*, i8*, i32)

declare i32 @fcvt_r(double, i32, i32*, i32*, i8*, i32)

declare i32 @qecvt_r(double, i32, i32*, i32*, i8*, i32)

declare i32 @qfcvt_r(double, i32, i32*, i32*, i8*, i32)

declare i32 @mblen(i8*, i32)

declare i32 @mbtowc(i32*, i8*, i32)

declare i32 @wctomb(i8*, i32)

declare i32 @mbstowcs(i32*, i8*, i32)

declare i32 @wcstombs(i8*, i32*, i32)

declare i32 @rpmatch(i8*)

declare i32 @getsubopt(i8**, i8**, i8**)

declare i32 @getloadavg(i8*, i32)

declare i64* @memcpy(i64*, i64*, i32)

declare i64* @memmove(i64*, i64*, i32)

declare i64* @memccpy(i64*, i64*, i32, i32)

declare i64* @memset(i64*, i32, i32)

declare i32 @memcmp(i64*, i64*, i32)

declare i64* @memchr(i64*, i32, i32)

declare i8* @strcpy(i8*, i8*)

declare i8* @strncpy(i8*, i8*, i32)

declare i8* @strcat(i8*, i8*)

declare i8* @strncat(i8*, i8*, i32)

declare i32 @strcmp(i8*, i8*)

declare i32 @strncmp(i8*, i8*, i32)

declare i32 @strcoll(i8*, i8*)

declare i32 @strxfrm(i8*, i8*, i32)

define %__locale_struct* @__locale_struct.107() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @strcoll_l(i8*, i8*, %__locale_struct*)

define %__locale_struct* @__locale_struct.108() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @strxfrm_l(i8*, i8*, i32, %__locale_struct*)

declare i8* @strdup(i8*)

declare i8* @strndup(i8*, i32)

declare i8* @strchr(i8*, i32)

declare i8* @strrchr(i8*, i32)

declare i32 @strcspn(i8*, i8*)

declare i32 @strspn(i8*, i8*)

declare i8* @strpbrk(i8*, i8*)

declare i8* @strstr(i8*, i8*)

declare i8* @strtok(i8*, i8*)

declare i8* @__strtok_r(i8*, i8*, i8**)

declare i8* @strtok_r(i8*, i8*, i8**)

declare i32 @strlen(i8*)

declare i32 @strnlen(i8*, i32)

declare i8* @strerror(i32)

declare i32 @strerror_r(i32, i8*, i32)

define %__locale_struct* @__locale_struct.109() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i8* @strerror_l(i32, %__locale_struct*)

declare i32 @bcmp(i64*, i64*, i32)

declare void @bcopy(i64*, i64*, i32)

declare void @bzero(i64*, i32)

declare i8* @index(i8*, i32)

declare i8* @rindex(i8*, i32)

declare i32 @ffs(i32)

declare i32 @ffsl(i64)

declare i32 @ffsll(i64)

declare i32 @strcasecmp(i8*, i8*)

declare i32 @strncasecmp(i8*, i8*, i32)

define %__locale_struct* @__locale_struct.110() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @strcasecmp_l(i8*, i8*, %__locale_struct*)

define %__locale_struct* @__locale_struct.111() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @strncasecmp_l(i8*, i8*, i32, %__locale_struct*)

declare void @explicit_bzero(i64*, i32)

declare i8* @strsep(i8**, i8*)

declare i8* @strsignal(i32)

declare i8* @__stpcpy(i8*, i8*)

declare i8* @stpcpy(i8*, i8*)

declare i8* @__stpncpy(i8*, i8*, i32)

declare i8* @stpncpy(i8*, i8*, i32)

declare i32* @wcscpy(i32*, i32*)

declare i32* @wcsncpy(i32*, i32*, i32)

declare i32* @wcscat(i32*, i32*)

declare i32* @wcsncat(i32*, i32*, i32)

declare i32 @wcscmp(i32*, i32*)

declare i32 @wcsncmp(i32*, i32*, i32)

declare i32 @wcscasecmp(i32*, i32*)

declare i32 @wcsncasecmp(i32*, i32*, i32)

define %__locale_struct* @__locale_struct.112() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @wcscasecmp_l(i32*, i32*, %__locale_struct*)

define %__locale_struct* @__locale_struct.113() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @wcsncasecmp_l(i32*, i32*, i32, %__locale_struct*)

declare i32 @wcscoll(i32*, i32*)

declare i32 @wcsxfrm(i32*, i32*, i32)

define %__locale_struct* @__locale_struct.114() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @wcscoll_l(i32*, i32*, %__locale_struct*)

define %__locale_struct* @__locale_struct.115() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @wcsxfrm_l(i32*, i32*, i32, %__locale_struct*)

declare i32* @wcsdup(i32*)

declare i32* @wcschr(i32*, i32)

declare i32* @wcsrchr(i32*, i32)

declare i32 @wcscspn(i32*, i32*)

declare i32 @wcsspn(i32*, i32*)

declare i32* @wcspbrk(i32*, i32*)

declare i32* @wcsstr(i32*, i32*)

declare i32* @wcstok(i32*, i32*, i32**)

declare i32 @wcslen(i32*)

declare i32 @wcsnlen(i32*, i32)

declare i32* @wmemchr(i32*, i32, i32)

declare i32 @wmemcmp(i32*, i32*, i32)

declare i32* @wmemcpy(i32*, i32*, i32)

declare i32* @wmemmove(i32*, i32*, i32)

declare i32* @wmemset(i32*, i32, i32)

declare i32 @btowc(i32)

declare i32 @wctob(i32)

define %__mbstate_t* @__mbstate_t.116() {
entry:
  %0 = call i64* @malloc(i64 8)
  %1 = bitcast i64* %0 to %__mbstate_t*
  ret %__mbstate_t* %1
}

declare i32 @mbsinit(%__mbstate_t*)

define %__mbstate_t* @__mbstate_t.117() {
entry:
  %0 = call i64* @malloc(i64 8)
  %1 = bitcast i64* %0 to %__mbstate_t*
  ret %__mbstate_t* %1
}

declare i32 @mbrtowc(i32*, i8*, i32, %__mbstate_t*)

define %__mbstate_t* @__mbstate_t.118() {
entry:
  %0 = call i64* @malloc(i64 8)
  %1 = bitcast i64* %0 to %__mbstate_t*
  ret %__mbstate_t* %1
}

declare i32 @wcrtomb(i8*, i32, %__mbstate_t*)

define %__mbstate_t* @__mbstate_t.119() {
entry:
  %0 = call i64* @malloc(i64 8)
  %1 = bitcast i64* %0 to %__mbstate_t*
  ret %__mbstate_t* %1
}

declare i32 @__mbrlen(i8*, i32, %__mbstate_t*)

define %__mbstate_t* @__mbstate_t.120() {
entry:
  %0 = call i64* @malloc(i64 8)
  %1 = bitcast i64* %0 to %__mbstate_t*
  ret %__mbstate_t* %1
}

declare i32 @mbrlen(i8*, i32, %__mbstate_t*)

define %__mbstate_t* @__mbstate_t.121() {
entry:
  %0 = call i64* @malloc(i64 8)
  %1 = bitcast i64* %0 to %__mbstate_t*
  ret %__mbstate_t* %1
}

declare i32 @mbsrtowcs(i32*, i8**, i32, %__mbstate_t*)

define %__mbstate_t* @__mbstate_t.122() {
entry:
  %0 = call i64* @malloc(i64 8)
  %1 = bitcast i64* %0 to %__mbstate_t*
  ret %__mbstate_t* %1
}

declare i32 @wcsrtombs(i8*, i32**, i32, %__mbstate_t*)

define %__mbstate_t* @__mbstate_t.123() {
entry:
  %0 = call i64* @malloc(i64 8)
  %1 = bitcast i64* %0 to %__mbstate_t*
  ret %__mbstate_t* %1
}

declare i32 @mbsnrtowcs(i32*, i8**, i32, i32, %__mbstate_t*)

define %__mbstate_t* @__mbstate_t.124() {
entry:
  %0 = call i64* @malloc(i64 8)
  %1 = bitcast i64* %0 to %__mbstate_t*
  ret %__mbstate_t* %1
}

declare i32 @wcsnrtombs(i8*, i32**, i32, i32, %__mbstate_t*)

declare double @wcstod(i32*, i32**)

declare double @wcstof(i32*, i32**)

declare double @wcstold(i32*, i32**)

declare i64 @wcstol(i32*, i32**, i32)

declare i64 @wcstoul(i32*, i32**, i32)

declare i64 @wcstoll(i32*, i32**, i32)

declare i64 @wcstoull(i32*, i32**, i32)

declare i32* @wcpcpy(i32*, i32*)

declare i32* @wcpncpy(i32*, i32*, i32)

define %_IO_FILE* @_IO_FILE.125() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare %_IO_FILE* @open_wmemstream(i32**, i32*)

define %_IO_FILE* @_IO_FILE.126() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fwide(%_IO_FILE*, i32)

define %_IO_FILE* @_IO_FILE.127() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fwprintf(%_IO_FILE*, i32*)

declare i32 @wprintf(i32*)

declare i32 @swprintf(i32*, i32, i32*)

define %_IO_FILE* @_IO_FILE.128() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @vfwprintf(%_IO_FILE*, i32*, i32)

declare i32 @vwprintf(i32*, i32)

declare i32 @vswprintf(i32*, i32, i32*, i32)

define %_IO_FILE* @_IO_FILE.129() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fwscanf(%_IO_FILE*, i32*)

declare i32 @wscanf(i32*)

declare i32 @swscanf(i32*, i32*)

define %_IO_FILE* @_IO_FILE.130() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @vfwscanf(%_IO_FILE*, i32*, i32)

declare i32 @vwscanf(i32*, i32)

declare i32 @vswscanf(i32*, i32*, i32)

define %_IO_FILE* @_IO_FILE.131() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fgetwc(%_IO_FILE*)

define %_IO_FILE* @_IO_FILE.132() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @getwc(%_IO_FILE*)

declare i32 @getwchar()

define %_IO_FILE* @_IO_FILE.133() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fputwc(i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.134() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @putwc(i32, %_IO_FILE*)

declare i32 @putwchar(i32)

define %_IO_FILE* @_IO_FILE.135() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32* @fgetws(i32*, i32, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.136() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @fputws(i32*, %_IO_FILE*)

define %_IO_FILE* @_IO_FILE.137() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

declare i32 @ungetwc(i32, %_IO_FILE*)

declare i32 @wcsftime(i32*, i32, i32*, i8**)

declare i64 @imaxabs(i64)

define %imaxdiv_t* @imaxdiv_t.138() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %imaxdiv_t*
  ret %imaxdiv_t* %1
}

declare %imaxdiv_t @imaxdiv(i64, i64)

declare i64 @strtoimax(i8*, i8**, i32)

declare i64 @strtoumax(i8*, i8**, i32)

declare i64 @wcstoimax(i32*, i32**, i32)

declare i64 @wcstoumax(i32*, i32**, i32)

declare i16** @__ctype_b_loc()

declare i32** @__ctype_tolower_loc()

declare i32** @__ctype_toupper_loc()

declare i32 @isalnum(i32)

declare i32 @isalpha(i32)

declare i32 @iscntrl(i32)

declare i32 @isdigit(i32)

declare i32 @islower(i32)

declare i32 @isgraph(i32)

declare i32 @isprint(i32)

declare i32 @ispunct(i32)

declare i32 @isspace(i32)

declare i32 @isupper(i32)

declare i32 @isxdigit(i32)

declare i32 @tolower(i32)

declare i32 @toupper(i32)

declare i32 @isblank(i32)

declare i32 @isascii(i32)

declare i32 @toascii(i32)

declare i32 @_toupper(i32)

declare i32 @_tolower(i32)

define %__locale_struct* @__locale_struct.139() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @isalnum_l(i32, %__locale_struct*)

define %__locale_struct* @__locale_struct.140() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @isalpha_l(i32, %__locale_struct*)

define %__locale_struct* @__locale_struct.141() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @iscntrl_l(i32, %__locale_struct*)

define %__locale_struct* @__locale_struct.142() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @isdigit_l(i32, %__locale_struct*)

define %__locale_struct* @__locale_struct.143() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @islower_l(i32, %__locale_struct*)

define %__locale_struct* @__locale_struct.144() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @isgraph_l(i32, %__locale_struct*)

define %__locale_struct* @__locale_struct.145() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @isprint_l(i32, %__locale_struct*)

define %__locale_struct* @__locale_struct.146() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @ispunct_l(i32, %__locale_struct*)

define %__locale_struct* @__locale_struct.147() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @isspace_l(i32, %__locale_struct*)

define %__locale_struct* @__locale_struct.148() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @isupper_l(i32, %__locale_struct*)

define %__locale_struct* @__locale_struct.149() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @isxdigit_l(i32, %__locale_struct*)

define %__locale_struct* @__locale_struct.150() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @isblank_l(i32, %__locale_struct*)

define %__locale_struct* @__locale_struct.151() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @__tolower_l(i32, %__locale_struct*)

define %__locale_struct* @__locale_struct.152() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @tolower_l(i32, %__locale_struct*)

define %__locale_struct* @__locale_struct.153() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @__toupper_l(i32, %__locale_struct*)

define %__locale_struct* @__locale_struct.154() {
entry:
  %0 = call i64* @malloc(i64 232)
  %1 = bitcast i64* %0 to %__locale_struct*
  ret %__locale_struct* %1
}

declare i32 @toupper_l(i32, %__locale_struct*)

declare i32 @__fpclassify(double)

declare i32 @__signbit(double)

declare i32 @__isinf(double)

declare i32 @__finite(double)

declare i32 @__isnan(double)

declare i32 @__iseqsig(double, double)

declare i32 @__issignaling(double)

declare double @acos(double)

declare double @__acos(double)

declare double @asin(double)

declare double @__asin(double)

declare double @atan(double)

declare double @__atan(double)

declare double @atan2(double, double)

declare double @__atan2(double, double)

declare double @cos(double)

declare double @__cos(double)

declare double @sin(double)

declare double @__sin(double)

declare double @tan(double)

declare double @__tan(double)

declare double @cosh(double)

declare double @__cosh(double)

declare double @sinh(double)

declare double @__sinh(double)

declare double @tanh(double)

declare double @__tanh(double)

declare double @acosh(double)

declare double @__acosh(double)

declare double @asinh(double)

declare double @__asinh(double)

declare double @atanh(double)

declare double @__atanh(double)

declare double @exp(double)

declare double @__exp(double)

declare double @frexp(double, i32*)

declare double @__frexp(double, i32*)

declare double @ldexp(double, i32)

declare double @__ldexp(double, i32)

declare double @log(double)

declare double @__log(double)

declare double @log10(double)

declare double @__log10(double)

declare double @modf(double, float*)

declare double @__modf(double, float*)

declare double @expm1(double)

declare double @__expm1(double)

declare double @log1p(double)

declare double @__log1p(double)

declare double @logb(double)

declare double @__logb(double)

declare double @exp2(double)

declare double @__exp2(double)

declare double @log2(double)

declare double @__log2(double)

declare double @pow(double, double)

declare double @__pow(double, double)

declare double @sqrt(double)

declare double @__sqrt(double)

declare double @hypot(double, double)

declare double @__hypot(double, double)

declare double @cbrt(double)

declare double @__cbrt(double)

declare double @ceil(double)

declare double @__ceil(double)

declare double @fabs(double)

declare double @__fabs(double)

declare double @floor(double)

declare double @__floor(double)

declare double @fmod(double, double)

declare double @__fmod(double, double)

declare i32 @isinf(double)

declare i32 @finite(double)

declare double @drem(double, double)

declare double @__drem(double, double)

declare double @significand(double)

declare double @__significand(double)

declare double @copysign(double, double)

declare double @__copysign(double, double)

declare double @nan(i8*)

declare double @__nan(i8*)

declare i32 @isnan(double)

declare double @j0(double)

declare double @__j0(double)

declare double @j1(double)

declare double @__j1(double)

declare double @jn(i32, double)

declare double @__jn(i32, double)

declare double @y0(double)

declare double @__y0(double)

declare double @y1(double)

declare double @__y1(double)

declare double @yn(i32, double)

declare double @__yn(i32, double)

declare double @erf(double)

declare double @__erf(double)

declare double @erfc(double)

declare double @__erfc(double)

declare double @lgamma(double)

declare double @__lgamma(double)

declare double @tgamma(double)

declare double @__tgamma(double)

declare double @gamma(double)

declare double @__gamma(double)

declare double @lgamma_r(double, i32*)

declare double @__lgamma_r(double, i32*)

declare double @rint(double)

declare double @__rint(double)

declare double @nextafter(double, double)

declare double @__nextafter(double, double)

declare double @nexttoward(double, double)

declare double @__nexttoward(double, double)

declare double @remainder(double, double)

declare double @__remainder(double, double)

declare double @scalbn(double, i32)

declare double @__scalbn(double, i32)

declare i32 @ilogb(double)

declare i32 @__ilogb(double)

declare double @scalbln(double, i64)

declare double @__scalbln(double, i64)

declare double @nearbyint(double)

declare double @__nearbyint(double)

declare double @round(double)

declare double @__round(double)

declare double @trunc(double)

declare double @__trunc(double)

declare double @remquo(double, double, i32*)

declare double @__remquo(double, double, i32*)

declare i64 @lrint(double)

declare i64 @__lrint(double)

declare i64 @llrint(double)

declare i64 @__llrint(double)

declare i64 @lround(double)

declare i64 @__lround(double)

declare i64 @llround(double)

declare i64 @__llround(double)

declare double @fdim(double, double)

declare double @__fdim(double, double)

declare double @fmax(double, double)

declare double @__fmax(double, double)

declare double @fmin(double, double)

declare double @__fmin(double, double)

declare double @fma(double, double, double)

declare double @__fma(double, double, double)

declare double @scalb(double, double)

declare double @__scalb(double, double)

declare i32 @__fpclassifyf(double)

declare i32 @__signbitf(double)

declare i32 @__isinff(double)

declare i32 @__finitef(double)

declare i32 @__isnanf(double)

declare i32 @__iseqsigf(double, double)

declare i32 @__issignalingf(double)

declare double @acosf(double)

declare double @__acosf(double)

declare double @asinf(double)

declare double @__asinf(double)

declare double @atanf(double)

declare double @__atanf(double)

declare double @atan2f(double, double)

declare double @__atan2f(double, double)

declare double @cosf(double)

declare double @__cosf(double)

declare double @sinf(double)

declare double @__sinf(double)

declare double @tanf(double)

declare double @__tanf(double)

declare double @coshf(double)

declare double @__coshf(double)

declare double @sinhf(double)

declare double @__sinhf(double)

declare double @tanhf(double)

declare double @__tanhf(double)

declare double @acoshf(double)

declare double @__acoshf(double)

declare double @asinhf(double)

declare double @__asinhf(double)

declare double @atanhf(double)

declare double @__atanhf(double)

declare double @expf(double)

declare double @__expf(double)

declare double @frexpf(double, i32*)

declare double @__frexpf(double, i32*)

declare double @ldexpf(double, i32)

declare double @__ldexpf(double, i32)

declare double @logf(double)

declare double @__logf(double)

declare double @log10f(double)

declare double @__log10f(double)

declare double @modff(double, float*)

declare double @__modff(double, float*)

declare double @expm1f(double)

declare double @__expm1f(double)

declare double @log1pf(double)

declare double @__log1pf(double)

declare double @logbf(double)

declare double @__logbf(double)

declare double @exp2f(double)

declare double @__exp2f(double)

declare double @log2f(double)

declare double @__log2f(double)

declare double @powf(double, double)

declare double @__powf(double, double)

declare double @sqrtf(double)

declare double @__sqrtf(double)

declare double @hypotf(double, double)

declare double @__hypotf(double, double)

declare double @cbrtf(double)

declare double @__cbrtf(double)

declare double @ceilf(double)

declare double @__ceilf(double)

declare double @fabsf(double)

declare double @__fabsf(double)

declare double @floorf(double)

declare double @__floorf(double)

declare double @fmodf(double, double)

declare double @__fmodf(double, double)

declare i32 @isinff(double)

declare i32 @finitef(double)

declare double @dremf(double, double)

declare double @__dremf(double, double)

declare double @significandf(double)

declare double @__significandf(double)

declare double @copysignf(double, double)

declare double @__copysignf(double, double)

declare double @nanf(i8*)

declare double @__nanf(i8*)

declare i32 @isnanf(double)

declare double @j0f(double)

declare double @__j0f(double)

declare double @j1f(double)

declare double @__j1f(double)

declare double @jnf(i32, double)

declare double @__jnf(i32, double)

declare double @y0f(double)

declare double @__y0f(double)

declare double @y1f(double)

declare double @__y1f(double)

declare double @ynf(i32, double)

declare double @__ynf(i32, double)

declare double @erff(double)

declare double @__erff(double)

declare double @erfcf(double)

declare double @__erfcf(double)

declare double @lgammaf(double)

declare double @__lgammaf(double)

declare double @tgammaf(double)

declare double @__tgammaf(double)

declare double @gammaf(double)

declare double @__gammaf(double)

declare double @lgammaf_r(double, i32*)

declare double @__lgammaf_r(double, i32*)

declare double @rintf(double)

declare double @__rintf(double)

declare double @nextafterf(double, double)

declare double @__nextafterf(double, double)

declare double @nexttowardf(double, double)

declare double @__nexttowardf(double, double)

declare double @remainderf(double, double)

declare double @__remainderf(double, double)

declare double @scalbnf(double, i32)

declare double @__scalbnf(double, i32)

declare i32 @ilogbf(double)

declare i32 @__ilogbf(double)

declare double @scalblnf(double, i64)

declare double @__scalblnf(double, i64)

declare double @nearbyintf(double)

declare double @__nearbyintf(double)

declare double @roundf(double)

declare double @__roundf(double)

declare double @truncf(double)

declare double @__truncf(double)

declare double @remquof(double, double, i32*)

declare double @__remquof(double, double, i32*)

declare i64 @lrintf(double)

declare i64 @__lrintf(double)

declare i64 @llrintf(double)

declare i64 @__llrintf(double)

declare i64 @lroundf(double)

declare i64 @__lroundf(double)

declare i64 @llroundf(double)

declare i64 @__llroundf(double)

declare double @fdimf(double, double)

declare double @__fdimf(double, double)

declare double @fmaxf(double, double)

declare double @__fmaxf(double, double)

declare double @fminf(double, double)

declare double @__fminf(double, double)

declare double @fmaf(double, double, double)

declare double @__fmaf(double, double, double)

declare double @scalbf(double, double)

declare double @__scalbf(double, double)

declare i32 @__fpclassifyl(double)

declare i32 @__signbitl(double)

declare i32 @__isinfl(double)

declare i32 @__finitel(double)

declare i32 @__isnanl(double)

declare i32 @__iseqsigl(double, double)

declare i32 @__issignalingl(double)

declare double @acosl(double)

declare double @__acosl(double)

declare double @asinl(double)

declare double @__asinl(double)

declare double @atanl(double)

declare double @__atanl(double)

declare double @atan2l(double, double)

declare double @__atan2l(double, double)

declare double @cosl(double)

declare double @__cosl(double)

declare double @sinl(double)

declare double @__sinl(double)

declare double @tanl(double)

declare double @__tanl(double)

declare double @coshl(double)

declare double @__coshl(double)

declare double @sinhl(double)

declare double @__sinhl(double)

declare double @tanhl(double)

declare double @__tanhl(double)

declare double @acoshl(double)

declare double @__acoshl(double)

declare double @asinhl(double)

declare double @__asinhl(double)

declare double @atanhl(double)

declare double @__atanhl(double)

declare double @expl(double)

declare double @__expl(double)

declare double @frexpl(double, i32*)

declare double @__frexpl(double, i32*)

declare double @ldexpl(double, i32)

declare double @__ldexpl(double, i32)

declare double @logl(double)

declare double @__logl(double)

declare double @log10l(double)

declare double @__log10l(double)

declare double @modfl(double, float*)

declare double @__modfl(double, float*)

declare double @expm1l(double)

declare double @__expm1l(double)

declare double @log1pl(double)

declare double @__log1pl(double)

declare double @logbl(double)

declare double @__logbl(double)

declare double @exp2l(double)

declare double @__exp2l(double)

declare double @log2l(double)

declare double @__log2l(double)

declare double @powl(double, double)

declare double @__powl(double, double)

declare double @sqrtl(double)

declare double @__sqrtl(double)

declare double @hypotl(double, double)

declare double @__hypotl(double, double)

declare double @cbrtl(double)

declare double @__cbrtl(double)

declare double @ceill(double)

declare double @__ceill(double)

declare double @fabsl(double)

declare double @__fabsl(double)

declare double @floorl(double)

declare double @__floorl(double)

declare double @fmodl(double, double)

declare double @__fmodl(double, double)

declare i32 @isinfl(double)

declare i32 @finitel(double)

declare double @dreml(double, double)

declare double @__dreml(double, double)

declare double @significandl(double)

declare double @__significandl(double)

declare double @copysignl(double, double)

declare double @__copysignl(double, double)

declare double @nanl(i8*)

declare double @__nanl(i8*)

declare i32 @isnanl(double)

declare double @j0l(double)

declare double @__j0l(double)

declare double @j1l(double)

declare double @__j1l(double)

declare double @jnl(i32, double)

declare double @__jnl(i32, double)

declare double @y0l(double)

declare double @__y0l(double)

declare double @y1l(double)

declare double @__y1l(double)

declare double @ynl(i32, double)

declare double @__ynl(i32, double)

declare double @erfl(double)

declare double @__erfl(double)

declare double @erfcl(double)

declare double @__erfcl(double)

declare double @lgammal(double)

declare double @__lgammal(double)

declare double @tgammal(double)

declare double @__tgammal(double)

declare double @gammal(double)

declare double @__gammal(double)

declare double @lgammal_r(double, i32*)

declare double @__lgammal_r(double, i32*)

declare double @rintl(double)

declare double @__rintl(double)

declare double @nextafterl(double, double)

declare double @__nextafterl(double, double)

declare double @nexttowardl(double, double)

declare double @__nexttowardl(double, double)

declare double @remainderl(double, double)

declare double @__remainderl(double, double)

declare double @scalbnl(double, i32)

declare double @__scalbnl(double, i32)

declare i32 @ilogbl(double)

declare i32 @__ilogbl(double)

declare double @scalblnl(double, i64)

declare double @__scalblnl(double, i64)

declare double @nearbyintl(double)

declare double @__nearbyintl(double)

declare double @roundl(double)

declare double @__roundl(double)

declare double @truncl(double)

declare double @__truncl(double)

declare double @remquol(double, double, i32*)

declare double @__remquol(double, double, i32*)

declare i64 @lrintl(double)

declare i64 @__lrintl(double)

declare i64 @llrintl(double)

declare i64 @__llrintl(double)

declare i64 @lroundl(double)

declare i64 @__lroundl(double)

declare i64 @llroundl(double)

declare i64 @__llroundl(double)

declare double @fdiml(double, double)

declare double @__fdiml(double, double)

declare double @fmaxl(double, double)

declare double @__fmaxl(double, double)

declare double @fminl(double, double)

declare double @__fminl(double, double)

declare double @fmal(double, double, double)

declare double @__fmal(double, double, double)

declare double @scalbl(double, double)

declare double @__scalbl(double, double)

declare i64* @SDL_malloc(i32)

declare i64* @SDL_calloc(i32, i32)

declare i64* @SDL_realloc(i64*, i32)

declare void @SDL_free(i64*)

declare void @SDL_GetMemoryFunctions(i8**, i8**, i8**, i8**)

declare i32 @SDL_SetMemoryFunctions(i8*, i8*, i8*, i8*)

declare i32 @SDL_GetNumAllocations()

declare i8* @SDL_getenv(i8*)

declare i32 @SDL_setenv(i8*, i8*, i32)

declare void @SDL_qsort(i64*, i32, i32, i8*)

declare i32 @SDL_abs(i32)

declare i32 @SDL_isdigit(i32)

declare i32 @SDL_isspace(i32)

declare i32 @SDL_toupper(i32)

declare i32 @SDL_tolower(i32)

declare i64* @SDL_memset(i64*, i32, i32)

declare void @SDL_memset4(i64*, i32, i32)

declare i64* @SDL_memcpy(i64*, i64*, i32)

declare i64* @SDL_memmove(i64*, i64*, i32)

declare i32 @SDL_memcmp(i64*, i64*, i32)

declare i32 @SDL_wcslen(i32*)

declare i32 @SDL_wcslcpy(i32*, i32*, i32)

declare i32 @SDL_wcslcat(i32*, i32*, i32)

declare i32 @SDL_wcscmp(i32*, i32*)

declare i32 @SDL_strlen(i8*)

declare i32 @SDL_strlcpy(i8*, i8*, i32)

declare i32 @SDL_utf8strlcpy(i8*, i8*, i32)

declare i32 @SDL_strlcat(i8*, i8*, i32)

declare i8* @SDL_strdup(i8*)

declare i8* @SDL_strrev(i8*)

declare i8* @SDL_strupr(i8*)

declare i8* @SDL_strlwr(i8*)

declare i8* @SDL_strchr(i8*, i32)

declare i8* @SDL_strrchr(i8*, i32)

declare i8* @SDL_strstr(i8*, i8*)

declare i32 @SDL_utf8strlen(i8*)

declare i8* @SDL_itoa(i32, i8*, i32)

declare i8* @SDL_uitoa(i32, i8*, i32)

declare i8* @SDL_ltoa(i64, i8*, i32)

declare i8* @SDL_ultoa(i64, i8*, i32)

declare i8* @SDL_lltoa(i64, i8*, i32)

declare i8* @SDL_ulltoa(i64, i8*, i32)

declare i32 @SDL_atoi(i8*)

declare double @SDL_atof(i8*)

declare i64 @SDL_strtol(i8*, i8**, i32)

declare i64 @SDL_strtoul(i8*, i8**, i32)

declare i64 @SDL_strtoll(i8*, i8**, i32)

declare i64 @SDL_strtoull(i8*, i8**, i32)

declare double @SDL_strtod(i8*, i8**)

declare i32 @SDL_strcmp(i8*, i8*)

declare i32 @SDL_strncmp(i8*, i8*, i32)

declare i32 @SDL_strcasecmp(i8*, i8*)

declare i32 @SDL_strncasecmp(i8*, i8*, i32)

declare i32 @SDL_sscanf(i8*, i8*)

declare i32 @SDL_vsscanf(i8*, i8*, i32)

declare i32 @SDL_snprintf(i8*, i32, i8*)

declare i32 @SDL_vsnprintf(i8*, i32, i8*, i32)

declare double @SDL_acos(double)

declare double @SDL_acosf(double)

declare double @SDL_asin(double)

declare double @SDL_asinf(double)

declare double @SDL_atan(double)

declare double @SDL_atanf(double)

declare double @SDL_atan2(double, double)

declare double @SDL_atan2f(double, double)

declare double @SDL_ceil(double)

declare double @SDL_ceilf(double)

declare double @SDL_copysign(double, double)

declare double @SDL_copysignf(double, double)

declare double @SDL_cos(double)

declare double @SDL_cosf(double)

declare double @SDL_fabs(double)

declare double @SDL_fabsf(double)

declare double @SDL_floor(double)

declare double @SDL_floorf(double)

declare double @SDL_fmod(double, double)

declare double @SDL_fmodf(double, double)

declare double @SDL_log(double)

declare double @SDL_logf(double)

declare double @SDL_log10(double)

declare double @SDL_log10f(double)

declare double @SDL_pow(double, double)

declare double @SDL_powf(double, double)

declare double @SDL_scalbn(double, i32)

declare double @SDL_scalbnf(double, i32)

declare double @SDL_sin(double)

declare double @SDL_sinf(double)

declare double @SDL_sqrt(double)

declare double @SDL_sqrtf(double)

declare double @SDL_tan(double)

declare double @SDL_tanf(double)

declare i8** @SDL_iconv_open(i8*, i8*)

declare i32 @SDL_iconv_close(i8**)

declare i32 @SDL_iconv(i8**, i8**, i32*, i8**, i32*)

declare i8* @SDL_iconv_string(i8*, i8*, i8*, i32)

declare i64* @SDL_memcpy4(i64*, i64*, i32)

declare i32 @SDL_main(i32, i8*)

declare void @SDL_SetMainReady()

define %SDL_AssertData* @SDL_AssertData.155() {
entry:
  %0 = call i64* @malloc(i64 48)
  %1 = bitcast i64* %0 to %SDL_AssertData*
  ret %SDL_AssertData* %1
}

declare i32 @SDL_ReportAssertion(%SDL_AssertData*, i8*, i8*, i32)

declare void @SDL_SetAssertionHandler(i8*, i64*)

declare i8* @SDL_GetDefaultAssertionHandler()

declare i8* @SDL_GetAssertionHandler(i64**)

define %SDL_AssertData* @SDL_AssertData.156() {
entry:
  %0 = call i64* @malloc(i64 48)
  %1 = bitcast i64* %0 to %SDL_AssertData*
  ret %SDL_AssertData* %1
}

declare %SDL_AssertData* @SDL_GetAssertionReport()

declare void @SDL_ResetAssertionReport()

declare i32 @SDL_AtomicTryLock(i32*)

declare void @SDL_AtomicLock(i32*)

declare void @SDL_AtomicUnlock(i32*)

declare void @SDL_MemoryBarrierReleaseFunction()

declare void @SDL_MemoryBarrierAcquireFunction()

define %SDL_atomic_t* @SDL_atomic_t.157() {
entry:
  %0 = call i64* @malloc(i64 4)
  %1 = bitcast i64* %0 to %SDL_atomic_t*
  ret %SDL_atomic_t* %1
}

declare i32 @SDL_AtomicCAS(%SDL_atomic_t*, i32, i32)

define %SDL_atomic_t* @SDL_atomic_t.158() {
entry:
  %0 = call i64* @malloc(i64 4)
  %1 = bitcast i64* %0 to %SDL_atomic_t*
  ret %SDL_atomic_t* %1
}

declare i32 @SDL_AtomicSet(%SDL_atomic_t*, i32)

define %SDL_atomic_t* @SDL_atomic_t.159() {
entry:
  %0 = call i64* @malloc(i64 4)
  %1 = bitcast i64* %0 to %SDL_atomic_t*
  ret %SDL_atomic_t* %1
}

declare i32 @SDL_AtomicGet(%SDL_atomic_t*)

define %SDL_atomic_t* @SDL_atomic_t.160() {
entry:
  %0 = call i64* @malloc(i64 4)
  %1 = bitcast i64* %0 to %SDL_atomic_t*
  ret %SDL_atomic_t* %1
}

declare i32 @SDL_AtomicAdd(%SDL_atomic_t*, i32)

declare i32 @SDL_AtomicCASPtr(i64**, i64*, i64*)

declare i64* @SDL_AtomicSetPtr(i64**, i64*)

declare i64* @SDL_AtomicGetPtr(i64**)

declare i32 @SDL_SetError(i8*)

declare i8* @SDL_GetError()

declare void @SDL_ClearError()

declare i32 @SDL_Error(i32)

declare i16 @SDL_Swap16(i16)

declare i32 @SDL_Swap32(i32)

declare i64 @SDL_Swap64(i64)

declare double @SDL_SwapFloat(double)

declare i8** @SDL_CreateMutex()

declare i32 @SDL_LockMutex(i8**)

declare i32 @SDL_TryLockMutex(i8**)

declare i32 @SDL_UnlockMutex(i8**)

declare void @SDL_DestroyMutex(i8**)

declare i8** @SDL_CreateSemaphore(i32)

declare void @SDL_DestroySemaphore(i8**)

declare i32 @SDL_SemWait(i8**)

declare i32 @SDL_SemTryWait(i8**)

declare i32 @SDL_SemWaitTimeout(i8**, i32)

declare i32 @SDL_SemPost(i8**)

declare i32 @SDL_SemValue(i8**)

declare i8** @SDL_CreateCond()

declare void @SDL_DestroyCond(i8**)

declare i32 @SDL_CondSignal(i8**)

declare i32 @SDL_CondBroadcast(i8**)

declare i32 @SDL_CondWait(i8**, i8**)

declare i32 @SDL_CondWaitTimeout(i8**, i8**, i32)

declare i8** @SDL_CreateThread(i8*, i8*, i64*)

declare i8* @SDL_GetThreadName(i8**)

declare i64 @SDL_ThreadID()

declare i64 @SDL_GetThreadID(i8**)

declare i32 @SDL_SetThreadPriority(i32)

declare void @SDL_WaitThread(i8**, i32*)

declare void @SDL_DetachThread(i8**)

declare i32 @SDL_TLSCreate()

declare i64* @SDL_TLSGet(i32)

declare i32 @SDL_TLSSet(i32, i64*, i8*)

define %SDL_RWops* @SDL_RWops.161() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare %SDL_RWops* @SDL_RWFromFile(i8*, i8*)

define %_IO_FILE* @_IO_FILE.162() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %_IO_FILE*
  ret %_IO_FILE* %1
}

define %SDL_RWops* @SDL_RWops.163() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare %SDL_RWops* @SDL_RWFromFP(%_IO_FILE*, i32)

define %SDL_RWops* @SDL_RWops.164() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare %SDL_RWops* @SDL_RWFromMem(i64*, i32)

define %SDL_RWops* @SDL_RWops.165() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare %SDL_RWops* @SDL_RWFromConstMem(i64*, i32)

define %SDL_RWops* @SDL_RWops.166() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare %SDL_RWops* @SDL_AllocRW()

define %SDL_RWops* @SDL_RWops.167() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare void @SDL_FreeRW(%SDL_RWops*)

define %SDL_RWops* @SDL_RWops.168() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare i64* @SDL_LoadFile_RW(%SDL_RWops*, i32*, i32)

define %SDL_RWops* @SDL_RWops.169() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare i8 @SDL_ReadU8(%SDL_RWops*)

define %SDL_RWops* @SDL_RWops.170() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare i16 @SDL_ReadLE16(%SDL_RWops*)

define %SDL_RWops* @SDL_RWops.171() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare i16 @SDL_ReadBE16(%SDL_RWops*)

define %SDL_RWops* @SDL_RWops.172() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare i32 @SDL_ReadLE32(%SDL_RWops*)

define %SDL_RWops* @SDL_RWops.173() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare i32 @SDL_ReadBE32(%SDL_RWops*)

define %SDL_RWops* @SDL_RWops.174() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare i64 @SDL_ReadLE64(%SDL_RWops*)

define %SDL_RWops* @SDL_RWops.175() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare i64 @SDL_ReadBE64(%SDL_RWops*)

define %SDL_RWops* @SDL_RWops.176() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare i32 @SDL_WriteU8(%SDL_RWops*, i8)

define %SDL_RWops* @SDL_RWops.177() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare i32 @SDL_WriteLE16(%SDL_RWops*, i16)

define %SDL_RWops* @SDL_RWops.178() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare i32 @SDL_WriteBE16(%SDL_RWops*, i16)

define %SDL_RWops* @SDL_RWops.179() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare i32 @SDL_WriteLE32(%SDL_RWops*, i32)

define %SDL_RWops* @SDL_RWops.180() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare i32 @SDL_WriteBE32(%SDL_RWops*, i32)

define %SDL_RWops* @SDL_RWops.181() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare i32 @SDL_WriteLE64(%SDL_RWops*, i64)

define %SDL_RWops* @SDL_RWops.182() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare i32 @SDL_WriteBE64(%SDL_RWops*, i64)

declare i32 @SDL_GetNumAudioDrivers()

declare i8* @SDL_GetAudioDriver(i32)

declare i32 @SDL_AudioInit(i8*)

declare void @SDL_AudioQuit()

declare i8* @SDL_GetCurrentAudioDriver()

define %SDL_AudioSpec* @SDL_AudioSpec.183() {
entry:
  %0 = call i64* @malloc(i64 32)
  %1 = bitcast i64* %0 to %SDL_AudioSpec*
  ret %SDL_AudioSpec* %1
}

define %SDL_AudioSpec* @SDL_AudioSpec.184() {
entry:
  %0 = call i64* @malloc(i64 32)
  %1 = bitcast i64* %0 to %SDL_AudioSpec*
  ret %SDL_AudioSpec* %1
}

declare i32 @SDL_OpenAudio(%SDL_AudioSpec*, %SDL_AudioSpec*)

declare i32 @SDL_GetNumAudioDevices(i32)

declare i8* @SDL_GetAudioDeviceName(i32, i32)

define %SDL_AudioSpec* @SDL_AudioSpec.185() {
entry:
  %0 = call i64* @malloc(i64 32)
  %1 = bitcast i64* %0 to %SDL_AudioSpec*
  ret %SDL_AudioSpec* %1
}

define %SDL_AudioSpec* @SDL_AudioSpec.186() {
entry:
  %0 = call i64* @malloc(i64 32)
  %1 = bitcast i64* %0 to %SDL_AudioSpec*
  ret %SDL_AudioSpec* %1
}

declare i32 @SDL_OpenAudioDevice(i8*, i32, %SDL_AudioSpec*, %SDL_AudioSpec*, i32)

declare i32 @SDL_GetAudioStatus()

declare i32 @SDL_GetAudioDeviceStatus(i32)

declare void @SDL_PauseAudio(i32)

declare void @SDL_PauseAudioDevice(i32, i32)

define %SDL_RWops* @SDL_RWops.187() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

define %SDL_AudioSpec* @SDL_AudioSpec.188() {
entry:
  %0 = call i64* @malloc(i64 32)
  %1 = bitcast i64* %0 to %SDL_AudioSpec*
  ret %SDL_AudioSpec* %1
}

define %SDL_AudioSpec* @SDL_AudioSpec.189() {
entry:
  %0 = call i64* @malloc(i64 32)
  %1 = bitcast i64* %0 to %SDL_AudioSpec*
  ret %SDL_AudioSpec* %1
}

declare %SDL_AudioSpec* @SDL_LoadWAV_RW(%SDL_RWops*, i32, %SDL_AudioSpec*, i8**, i32*)

declare void @SDL_FreeWAV(i8*)

define %SDL_AudioCVT* @SDL_AudioCVT.190() {
entry:
  %0 = call i64* @malloc(i64 136)
  %1 = bitcast i64* %0 to %SDL_AudioCVT*
  ret %SDL_AudioCVT* %1
}

declare i32 @SDL_BuildAudioCVT(%SDL_AudioCVT*, i16, i8, i32, i16, i8, i32)

define %SDL_AudioCVT* @SDL_AudioCVT.191() {
entry:
  %0 = call i64* @malloc(i64 136)
  %1 = bitcast i64* %0 to %SDL_AudioCVT*
  ret %SDL_AudioCVT* %1
}

declare i32 @SDL_ConvertAudio(%SDL_AudioCVT*)

declare i8** @SDL_NewAudioStream(i16, i8, i32, i16, i8, i32)

declare i32 @SDL_AudioStreamPut(i8**, i64*, i32)

declare i32 @SDL_AudioStreamGet(i8**, i64*, i32)

declare i32 @SDL_AudioStreamAvailable(i8**)

declare i32 @SDL_AudioStreamFlush(i8**)

declare void @SDL_AudioStreamClear(i8**)

declare void @SDL_FreeAudioStream(i8**)

declare void @SDL_MixAudio(i8*, i8*, i32, i32)

declare void @SDL_MixAudioFormat(i8*, i8*, i16, i32, i32)

declare i32 @SDL_QueueAudio(i32, i64*, i32)

declare i32 @SDL_DequeueAudio(i32, i64*, i32)

declare i32 @SDL_GetQueuedAudioSize(i32)

declare void @SDL_ClearQueuedAudio(i32)

declare void @SDL_LockAudio()

declare void @SDL_LockAudioDevice(i32)

declare void @SDL_UnlockAudio()

declare void @SDL_UnlockAudioDevice(i32)

declare void @SDL_CloseAudio()

declare void @SDL_CloseAudioDevice(i32)

declare i32 @SDL_SetClipboardText(i8*)

declare i8* @SDL_GetClipboardText()

declare i32 @SDL_HasClipboardText()

declare i32 @SDL_GetCPUCount()

declare i32 @SDL_GetCPUCacheLineSize()

declare i32 @SDL_HasRDTSC()

declare i32 @SDL_HasAltiVec()

declare i32 @SDL_HasMMX()

declare i32 @SDL_Has3DNow()

declare i32 @SDL_HasSSE()

declare i32 @SDL_HasSSE2()

declare i32 @SDL_HasSSE3()

declare i32 @SDL_HasSSE41()

declare i32 @SDL_HasSSE42()

declare i32 @SDL_HasAVX()

declare i32 @SDL_HasAVX2()

declare i32 @SDL_HasNEON()

declare i32 @SDL_GetSystemRAM()

declare i8* @SDL_GetPixelFormatName(i32)

declare i32 @SDL_PixelFormatEnumToMasks(i32, i32*, i32*, i32*, i32*, i32*)

declare i32 @SDL_MasksToPixelFormatEnum(i32, i32, i32, i32, i32)

define %SDL_Color* @SDL_Color.192() {
entry:
  %0 = call i64* @malloc(i64 4)
  %1 = bitcast i64* %0 to %SDL_Color*
  ret %SDL_Color* %1
}

define %SDL_Palette* @SDL_Palette.193() {
entry:
  %0 = call i64* @malloc(i64 24)
  %1 = bitcast i64* %0 to %SDL_Palette*
  ret %SDL_Palette* %1
}

define %SDL_PixelFormat* @SDL_PixelFormat.194() {
entry:
  %0 = call i64* @malloc(i64 56)
  %1 = bitcast i64* %0 to %SDL_PixelFormat*
  ret %SDL_PixelFormat* %1
}

declare %SDL_PixelFormat* @SDL_AllocFormat(i32)

define %SDL_PixelFormat* @SDL_PixelFormat.195() {
entry:
  %0 = call i64* @malloc(i64 56)
  %1 = bitcast i64* %0 to %SDL_PixelFormat*
  ret %SDL_PixelFormat* %1
}

declare void @SDL_FreeFormat(%SDL_PixelFormat*)

define %SDL_Palette* @SDL_Palette.196() {
entry:
  %0 = call i64* @malloc(i64 24)
  %1 = bitcast i64* %0 to %SDL_Palette*
  ret %SDL_Palette* %1
}

declare %SDL_Palette* @SDL_AllocPalette(i32)

define %SDL_PixelFormat* @SDL_PixelFormat.197() {
entry:
  %0 = call i64* @malloc(i64 56)
  %1 = bitcast i64* %0 to %SDL_PixelFormat*
  ret %SDL_PixelFormat* %1
}

define %SDL_Palette* @SDL_Palette.198() {
entry:
  %0 = call i64* @malloc(i64 24)
  %1 = bitcast i64* %0 to %SDL_Palette*
  ret %SDL_Palette* %1
}

declare i32 @SDL_SetPixelFormatPalette(%SDL_PixelFormat*, %SDL_Palette*)

define %SDL_Palette* @SDL_Palette.199() {
entry:
  %0 = call i64* @malloc(i64 24)
  %1 = bitcast i64* %0 to %SDL_Palette*
  ret %SDL_Palette* %1
}

define %SDL_Color* @SDL_Color.200() {
entry:
  %0 = call i64* @malloc(i64 4)
  %1 = bitcast i64* %0 to %SDL_Color*
  ret %SDL_Color* %1
}

declare i32 @SDL_SetPaletteColors(%SDL_Palette*, %SDL_Color*, i32, i32)

define %SDL_Palette* @SDL_Palette.201() {
entry:
  %0 = call i64* @malloc(i64 24)
  %1 = bitcast i64* %0 to %SDL_Palette*
  ret %SDL_Palette* %1
}

declare void @SDL_FreePalette(%SDL_Palette*)

define %SDL_PixelFormat* @SDL_PixelFormat.202() {
entry:
  %0 = call i64* @malloc(i64 56)
  %1 = bitcast i64* %0 to %SDL_PixelFormat*
  ret %SDL_PixelFormat* %1
}

declare i32 @SDL_MapRGB(%SDL_PixelFormat*, i8, i8, i8)

define %SDL_PixelFormat* @SDL_PixelFormat.203() {
entry:
  %0 = call i64* @malloc(i64 56)
  %1 = bitcast i64* %0 to %SDL_PixelFormat*
  ret %SDL_PixelFormat* %1
}

declare i32 @SDL_MapRGBA(%SDL_PixelFormat*, i8, i8, i8, i8)

define %SDL_PixelFormat* @SDL_PixelFormat.204() {
entry:
  %0 = call i64* @malloc(i64 56)
  %1 = bitcast i64* %0 to %SDL_PixelFormat*
  ret %SDL_PixelFormat* %1
}

declare void @SDL_GetRGB(i32, %SDL_PixelFormat*, i8*, i8*, i8*)

define %SDL_PixelFormat* @SDL_PixelFormat.205() {
entry:
  %0 = call i64* @malloc(i64 56)
  %1 = bitcast i64* %0 to %SDL_PixelFormat*
  ret %SDL_PixelFormat* %1
}

declare void @SDL_GetRGBA(i32, %SDL_PixelFormat*, i8*, i8*, i8*, i8*)

declare void @SDL_CalculateGammaRamp(double, i16*)

define %SDL_Point* @SDL_Point.206() {
entry:
  %0 = call i64* @malloc(i64 8)
  %1 = bitcast i64* %0 to %SDL_Point*
  ret %SDL_Point* %1
}

define %SDL_Rect* @SDL_Rect.207() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_PointInRect(%SDL_Point*, %SDL_Rect*)

define %SDL_Rect* @SDL_Rect.208() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_RectEmpty(%SDL_Rect*)

define %SDL_Rect* @SDL_Rect.209() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

define %SDL_Rect* @SDL_Rect.210() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_RectEquals(%SDL_Rect*, %SDL_Rect*)

define %SDL_Rect* @SDL_Rect.211() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

define %SDL_Rect* @SDL_Rect.212() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_HasIntersection(%SDL_Rect*, %SDL_Rect*)

define %SDL_Rect* @SDL_Rect.213() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

define %SDL_Rect* @SDL_Rect.214() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

define %SDL_Rect* @SDL_Rect.215() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_IntersectRect(%SDL_Rect*, %SDL_Rect*, %SDL_Rect*)

define %SDL_Rect* @SDL_Rect.216() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

define %SDL_Rect* @SDL_Rect.217() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

define %SDL_Rect* @SDL_Rect.218() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare void @SDL_UnionRect(%SDL_Rect*, %SDL_Rect*, %SDL_Rect*)

define %SDL_Point* @SDL_Point.219() {
entry:
  %0 = call i64* @malloc(i64 8)
  %1 = bitcast i64* %0 to %SDL_Point*
  ret %SDL_Point* %1
}

define %SDL_Rect* @SDL_Rect.220() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

define %SDL_Rect* @SDL_Rect.221() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_EnclosePoints(%SDL_Point*, i32, %SDL_Rect*, %SDL_Rect*)

define %SDL_Rect* @SDL_Rect.222() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_IntersectRectAndLine(%SDL_Rect*, i32*, i32*, i32*, i32*)

declare i32 @SDL_ComposeCustomBlendMode(i32, i32, i32, i32, i32, i32)

define %SDL_PixelFormat* @SDL_PixelFormat.223() {
entry:
  %0 = call i64* @malloc(i64 56)
  %1 = bitcast i64* %0 to %SDL_PixelFormat*
  ret %SDL_PixelFormat* %1
}

define %SDL_Rect* @SDL_Rect.224() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

define %SDL_Surface* @SDL_Surface.225() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare %SDL_Surface* @SDL_CreateRGBSurface(i32, i32, i32, i32, i32, i32, i32, i32)

define %SDL_Surface* @SDL_Surface.226() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare %SDL_Surface* @SDL_CreateRGBSurfaceWithFormat(i32, i32, i32, i32, i32)

define %SDL_Surface* @SDL_Surface.227() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare %SDL_Surface* @SDL_CreateRGBSurfaceFrom(i64*, i32, i32, i32, i32, i32, i32, i32, i32)

define %SDL_Surface* @SDL_Surface.228() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare %SDL_Surface* @SDL_CreateRGBSurfaceWithFormatFrom(i64*, i32, i32, i32, i32, i32)

define %SDL_Surface* @SDL_Surface.229() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare void @SDL_FreeSurface(%SDL_Surface*)

define %SDL_Surface* @SDL_Surface.230() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

define %SDL_Palette* @SDL_Palette.231() {
entry:
  %0 = call i64* @malloc(i64 24)
  %1 = bitcast i64* %0 to %SDL_Palette*
  ret %SDL_Palette* %1
}

declare i32 @SDL_SetSurfacePalette(%SDL_Surface*, %SDL_Palette*)

define %SDL_Surface* @SDL_Surface.232() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare i32 @SDL_LockSurface(%SDL_Surface*)

define %SDL_Surface* @SDL_Surface.233() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare void @SDL_UnlockSurface(%SDL_Surface*)

define %SDL_RWops* @SDL_RWops.234() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

define %SDL_Surface* @SDL_Surface.235() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare %SDL_Surface* @SDL_LoadBMP_RW(%SDL_RWops*, i32)

define %SDL_Surface* @SDL_Surface.236() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

define %SDL_RWops* @SDL_RWops.237() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare i32 @SDL_SaveBMP_RW(%SDL_Surface*, %SDL_RWops*, i32)

define %SDL_Surface* @SDL_Surface.238() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare i32 @SDL_SetSurfaceRLE(%SDL_Surface*, i32)

define %SDL_Surface* @SDL_Surface.239() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare i32 @SDL_SetColorKey(%SDL_Surface*, i32, i32)

define %SDL_Surface* @SDL_Surface.240() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare i32 @SDL_GetColorKey(%SDL_Surface*, i32*)

define %SDL_Surface* @SDL_Surface.241() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare i32 @SDL_SetSurfaceColorMod(%SDL_Surface*, i8, i8, i8)

define %SDL_Surface* @SDL_Surface.242() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare i32 @SDL_GetSurfaceColorMod(%SDL_Surface*, i8*, i8*, i8*)

define %SDL_Surface* @SDL_Surface.243() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare i32 @SDL_SetSurfaceAlphaMod(%SDL_Surface*, i8)

define %SDL_Surface* @SDL_Surface.244() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare i32 @SDL_GetSurfaceAlphaMod(%SDL_Surface*, i8*)

define %SDL_Surface* @SDL_Surface.245() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare i32 @SDL_SetSurfaceBlendMode(%SDL_Surface*, i32)

define %SDL_Surface* @SDL_Surface.246() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare i32 @SDL_GetSurfaceBlendMode(%SDL_Surface*, i32*)

define %SDL_Surface* @SDL_Surface.247() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

define %SDL_Rect* @SDL_Rect.248() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_SetClipRect(%SDL_Surface*, %SDL_Rect*)

define %SDL_Surface* @SDL_Surface.249() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

define %SDL_Rect* @SDL_Rect.250() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare void @SDL_GetClipRect(%SDL_Surface*, %SDL_Rect*)

define %SDL_Surface* @SDL_Surface.251() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

define %SDL_Surface* @SDL_Surface.252() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare %SDL_Surface* @SDL_DuplicateSurface(%SDL_Surface*)

define %SDL_Surface* @SDL_Surface.253() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

define %SDL_PixelFormat* @SDL_PixelFormat.254() {
entry:
  %0 = call i64* @malloc(i64 56)
  %1 = bitcast i64* %0 to %SDL_PixelFormat*
  ret %SDL_PixelFormat* %1
}

define %SDL_Surface* @SDL_Surface.255() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare %SDL_Surface* @SDL_ConvertSurface(%SDL_Surface*, %SDL_PixelFormat*, i32)

define %SDL_Surface* @SDL_Surface.256() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

define %SDL_Surface* @SDL_Surface.257() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare %SDL_Surface* @SDL_ConvertSurfaceFormat(%SDL_Surface*, i32, i32)

declare i32 @SDL_ConvertPixels(i32, i32, i32, i64*, i32, i32, i64*, i32)

define %SDL_Surface* @SDL_Surface.258() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

define %SDL_Rect* @SDL_Rect.259() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_FillRect(%SDL_Surface*, %SDL_Rect*, i32)

define %SDL_Surface* @SDL_Surface.260() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

define %SDL_Rect* @SDL_Rect.261() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_FillRects(%SDL_Surface*, %SDL_Rect*, i32, i32)

define %SDL_Surface* @SDL_Surface.262() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

define %SDL_Rect* @SDL_Rect.263() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

define %SDL_Surface* @SDL_Surface.264() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

define %SDL_Rect* @SDL_Rect.265() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_UpperBlit(%SDL_Surface*, %SDL_Rect*, %SDL_Surface*, %SDL_Rect*)

define %SDL_Surface* @SDL_Surface.266() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

define %SDL_Rect* @SDL_Rect.267() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

define %SDL_Surface* @SDL_Surface.268() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

define %SDL_Rect* @SDL_Rect.269() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_LowerBlit(%SDL_Surface*, %SDL_Rect*, %SDL_Surface*, %SDL_Rect*)

define %SDL_Surface* @SDL_Surface.270() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

define %SDL_Rect* @SDL_Rect.271() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

define %SDL_Surface* @SDL_Surface.272() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

define %SDL_Rect* @SDL_Rect.273() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_SoftStretch(%SDL_Surface*, %SDL_Rect*, %SDL_Surface*, %SDL_Rect*)

define %SDL_Surface* @SDL_Surface.274() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

define %SDL_Rect* @SDL_Rect.275() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

define %SDL_Surface* @SDL_Surface.276() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

define %SDL_Rect* @SDL_Rect.277() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_UpperBlitScaled(%SDL_Surface*, %SDL_Rect*, %SDL_Surface*, %SDL_Rect*)

define %SDL_Surface* @SDL_Surface.278() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

define %SDL_Rect* @SDL_Rect.279() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

define %SDL_Surface* @SDL_Surface.280() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

define %SDL_Rect* @SDL_Rect.281() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_LowerBlitScaled(%SDL_Surface*, %SDL_Rect*, %SDL_Surface*, %SDL_Rect*)

declare void @SDL_SetYUVConversionMode(i32)

declare i32 @SDL_GetYUVConversionMode()

declare i32 @SDL_GetYUVConversionModeForResolution(i32, i32)

declare i32 @SDL_GetNumVideoDrivers()

declare i8* @SDL_GetVideoDriver(i32)

declare i32 @SDL_VideoInit(i8*)

declare void @SDL_VideoQuit()

declare i8* @SDL_GetCurrentVideoDriver()

declare i32 @SDL_GetNumVideoDisplays()

declare i8* @SDL_GetDisplayName(i32)

define %SDL_Rect* @SDL_Rect.282() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_GetDisplayBounds(i32, %SDL_Rect*)

declare i32 @SDL_GetDisplayDPI(i32, float*, float*, float*)

define %SDL_Rect* @SDL_Rect.283() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_GetDisplayUsableBounds(i32, %SDL_Rect*)

declare i32 @SDL_GetNumDisplayModes(i32)

define %SDL_DisplayMode* @SDL_DisplayMode.284() {
entry:
  %0 = call i64* @malloc(i64 24)
  %1 = bitcast i64* %0 to %SDL_DisplayMode*
  ret %SDL_DisplayMode* %1
}

declare i32 @SDL_GetDisplayMode(i32, i32, %SDL_DisplayMode*)

define %SDL_DisplayMode* @SDL_DisplayMode.285() {
entry:
  %0 = call i64* @malloc(i64 24)
  %1 = bitcast i64* %0 to %SDL_DisplayMode*
  ret %SDL_DisplayMode* %1
}

declare i32 @SDL_GetDesktopDisplayMode(i32, %SDL_DisplayMode*)

define %SDL_DisplayMode* @SDL_DisplayMode.286() {
entry:
  %0 = call i64* @malloc(i64 24)
  %1 = bitcast i64* %0 to %SDL_DisplayMode*
  ret %SDL_DisplayMode* %1
}

declare i32 @SDL_GetCurrentDisplayMode(i32, %SDL_DisplayMode*)

define %SDL_DisplayMode* @SDL_DisplayMode.287() {
entry:
  %0 = call i64* @malloc(i64 24)
  %1 = bitcast i64* %0 to %SDL_DisplayMode*
  ret %SDL_DisplayMode* %1
}

define %SDL_DisplayMode* @SDL_DisplayMode.288() {
entry:
  %0 = call i64* @malloc(i64 24)
  %1 = bitcast i64* %0 to %SDL_DisplayMode*
  ret %SDL_DisplayMode* %1
}

define %SDL_DisplayMode* @SDL_DisplayMode.289() {
entry:
  %0 = call i64* @malloc(i64 24)
  %1 = bitcast i64* %0 to %SDL_DisplayMode*
  ret %SDL_DisplayMode* %1
}

declare %SDL_DisplayMode* @SDL_GetClosestDisplayMode(i32, %SDL_DisplayMode*, %SDL_DisplayMode*)

declare i32 @SDL_GetWindowDisplayIndex(i8**)

define %SDL_DisplayMode* @SDL_DisplayMode.290() {
entry:
  %0 = call i64* @malloc(i64 24)
  %1 = bitcast i64* %0 to %SDL_DisplayMode*
  ret %SDL_DisplayMode* %1
}

declare i32 @SDL_SetWindowDisplayMode(i8**, %SDL_DisplayMode*)

define %SDL_DisplayMode* @SDL_DisplayMode.291() {
entry:
  %0 = call i64* @malloc(i64 24)
  %1 = bitcast i64* %0 to %SDL_DisplayMode*
  ret %SDL_DisplayMode* %1
}

declare i32 @SDL_GetWindowDisplayMode(i8**, %SDL_DisplayMode*)

declare i32 @SDL_GetWindowPixelFormat(i8**)

declare i8** @SDL_CreateWindow(i8*, i32, i32, i32, i32, i32)

declare i8** @SDL_CreateWindowFrom(i64*)

declare i32 @SDL_GetWindowID(i8**)

declare i8** @SDL_GetWindowFromID(i32)

declare i32 @SDL_GetWindowFlags(i8**)

declare void @SDL_SetWindowTitle(i8**, i8*)

declare i8* @SDL_GetWindowTitle(i8**)

define %SDL_Surface* @SDL_Surface.292() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare void @SDL_SetWindowIcon(i8**, %SDL_Surface*)

declare i64* @SDL_SetWindowData(i8**, i8*, i64*)

declare i64* @SDL_GetWindowData(i8**, i8*)

declare void @SDL_SetWindowPosition(i8**, i32, i32)

declare void @SDL_GetWindowPosition(i8**, i32*, i32*)

declare void @SDL_SetWindowSize(i8**, i32, i32)

declare void @SDL_GetWindowSize(i8**, i32*, i32*)

declare i32 @SDL_GetWindowBordersSize(i8**, i32*, i32*, i32*, i32*)

declare void @SDL_SetWindowMinimumSize(i8**, i32, i32)

declare void @SDL_GetWindowMinimumSize(i8**, i32*, i32*)

declare void @SDL_SetWindowMaximumSize(i8**, i32, i32)

declare void @SDL_GetWindowMaximumSize(i8**, i32*, i32*)

declare void @SDL_SetWindowBordered(i8**, i32)

declare void @SDL_SetWindowResizable(i8**, i32)

declare void @SDL_ShowWindow(i8**)

declare void @SDL_HideWindow(i8**)

declare void @SDL_RaiseWindow(i8**)

declare void @SDL_MaximizeWindow(i8**)

declare void @SDL_MinimizeWindow(i8**)

declare void @SDL_RestoreWindow(i8**)

declare i32 @SDL_SetWindowFullscreen(i8**, i32)

define %SDL_Surface* @SDL_Surface.293() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare %SDL_Surface* @SDL_GetWindowSurface(i8**)

declare i32 @SDL_UpdateWindowSurface(i8**)

define %SDL_Rect* @SDL_Rect.294() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_UpdateWindowSurfaceRects(i8**, %SDL_Rect*, i32)

declare void @SDL_SetWindowGrab(i8**, i32)

declare i32 @SDL_GetWindowGrab(i8**)

declare i8** @SDL_GetGrabbedWindow()

declare i32 @SDL_SetWindowBrightness(i8**, double)

declare double @SDL_GetWindowBrightness(i8**)

declare i32 @SDL_SetWindowOpacity(i8**, double)

declare i32 @SDL_GetWindowOpacity(i8**, float*)

declare i32 @SDL_SetWindowModalFor(i8**, i8**)

declare i32 @SDL_SetWindowInputFocus(i8**)

declare i32 @SDL_SetWindowGammaRamp(i8**, i16*, i16*, i16*)

declare i32 @SDL_GetWindowGammaRamp(i8**, i16*, i16*, i16*)

declare i32 @SDL_SetWindowHitTest(i8**, i8*, i64*)

declare void @SDL_DestroyWindow(i8**)

declare i32 @SDL_IsScreenSaverEnabled()

declare void @SDL_EnableScreenSaver()

declare void @SDL_DisableScreenSaver()

declare i32 @SDL_GL_LoadLibrary(i8*)

declare i64* @SDL_GL_GetProcAddress(i8*)

declare void @SDL_GL_UnloadLibrary()

declare i32 @SDL_GL_ExtensionSupported(i8*)

declare void @SDL_GL_ResetAttributes()

declare i32 @SDL_GL_SetAttribute(i32, i32)

declare i32 @SDL_GL_GetAttribute(i32, i32*)

declare i64* @SDL_GL_CreateContext(i8**)

declare i32 @SDL_GL_MakeCurrent(i8**, i64*)

declare i8** @SDL_GL_GetCurrentWindow()

declare i64* @SDL_GL_GetCurrentContext()

declare void @SDL_GL_GetDrawableSize(i8**, i32*, i32*)

declare i32 @SDL_GL_SetSwapInterval(i32)

declare i32 @SDL_GL_GetSwapInterval()

declare void @SDL_GL_SwapWindow(i8**)

declare void @SDL_GL_DeleteContext(i64*)

declare i8** @SDL_GetKeyboardFocus()

declare i8* @SDL_GetKeyboardState(i32*)

declare i32 @SDL_GetModState()

declare void @SDL_SetModState(i32)

declare i32 @SDL_GetKeyFromScancode(i32)

declare i32 @SDL_GetScancodeFromKey(i32)

declare i8* @SDL_GetScancodeName(i32)

declare i32 @SDL_GetScancodeFromName(i8*)

declare i8* @SDL_GetKeyName(i32)

declare i32 @SDL_GetKeyFromName(i8*)

declare void @SDL_StartTextInput()

declare i32 @SDL_IsTextInputActive()

declare void @SDL_StopTextInput()

define %SDL_Rect* @SDL_Rect.295() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare void @SDL_SetTextInputRect(%SDL_Rect*)

declare i32 @SDL_HasScreenKeyboardSupport()

declare i32 @SDL_IsScreenKeyboardShown(i8**)

declare i8** @SDL_GetMouseFocus()

declare i32 @SDL_GetMouseState(i32*, i32*)

declare i32 @SDL_GetGlobalMouseState(i32*, i32*)

declare i32 @SDL_GetRelativeMouseState(i32*, i32*)

declare void @SDL_WarpMouseInWindow(i8**, i32, i32)

declare i32 @SDL_WarpMouseGlobal(i32, i32)

declare i32 @SDL_SetRelativeMouseMode(i32)

declare i32 @SDL_CaptureMouse(i32)

declare i32 @SDL_GetRelativeMouseMode()

declare i8** @SDL_CreateCursor(i8*, i8*, i32, i32, i32, i32)

define %SDL_Surface* @SDL_Surface.296() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare i8** @SDL_CreateColorCursor(%SDL_Surface*, i32, i32)

declare i8** @SDL_CreateSystemCursor(i32)

declare void @SDL_SetCursor(i8**)

declare i8** @SDL_GetCursor()

declare i8** @SDL_GetDefaultCursor()

declare void @SDL_FreeCursor(i8**)

declare i32 @SDL_ShowCursor(i32)

declare void @SDL_LockJoysticks()

declare void @SDL_UnlockJoysticks()

declare i32 @SDL_NumJoysticks()

declare i8* @SDL_JoystickNameForIndex(i32)

define %SDL_JoystickGUID* @SDL_JoystickGUID.297() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_JoystickGUID*
  ret %SDL_JoystickGUID* %1
}

declare %SDL_JoystickGUID @SDL_JoystickGetDeviceGUID(i32)

declare i16 @SDL_JoystickGetDeviceVendor(i32)

declare i16 @SDL_JoystickGetDeviceProduct(i32)

declare i16 @SDL_JoystickGetDeviceProductVersion(i32)

declare i32 @SDL_JoystickGetDeviceType(i32)

declare i32 @SDL_JoystickGetDeviceInstanceID(i32)

declare i8** @SDL_JoystickOpen(i32)

declare i8** @SDL_JoystickFromInstanceID(i32)

declare i8* @SDL_JoystickName(i8**)

define %SDL_JoystickGUID* @SDL_JoystickGUID.298() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_JoystickGUID*
  ret %SDL_JoystickGUID* %1
}

declare %SDL_JoystickGUID @SDL_JoystickGetGUID(i8**)

declare i16 @SDL_JoystickGetVendor(i8**)

declare i16 @SDL_JoystickGetProduct(i8**)

declare i16 @SDL_JoystickGetProductVersion(i8**)

declare i32 @SDL_JoystickGetType(i8**)

define %SDL_JoystickGUID* @SDL_JoystickGUID.299() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_JoystickGUID*
  ret %SDL_JoystickGUID* %1
}

declare void @SDL_JoystickGetGUIDString(%SDL_JoystickGUID, i8*, i32)

define %SDL_JoystickGUID* @SDL_JoystickGUID.300() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_JoystickGUID*
  ret %SDL_JoystickGUID* %1
}

declare %SDL_JoystickGUID @SDL_JoystickGetGUIDFromString(i8*)

declare i32 @SDL_JoystickGetAttached(i8**)

declare i32 @SDL_JoystickInstanceID(i8**)

declare i32 @SDL_JoystickNumAxes(i8**)

declare i32 @SDL_JoystickNumBalls(i8**)

declare i32 @SDL_JoystickNumHats(i8**)

declare i32 @SDL_JoystickNumButtons(i8**)

declare void @SDL_JoystickUpdate()

declare i32 @SDL_JoystickEventState(i32)

declare i16 @SDL_JoystickGetAxis(i8**, i32)

declare i32 @SDL_JoystickGetAxisInitialState(i8**, i32, i16*)

declare i8 @SDL_JoystickGetHat(i8**, i32)

declare i32 @SDL_JoystickGetBall(i8**, i32, i32*, i32*)

declare i8 @SDL_JoystickGetButton(i8**, i32)

declare void @SDL_JoystickClose(i8**)

declare i32 @SDL_JoystickCurrentPowerLevel(i8**)

define %SDL_RWops* @SDL_RWops.301() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare i32 @SDL_GameControllerAddMappingsFromRW(%SDL_RWops*, i32)

declare i32 @SDL_GameControllerAddMapping(i8*)

declare i32 @SDL_GameControllerNumMappings()

declare i8* @SDL_GameControllerMappingForIndex(i32)

define %SDL_JoystickGUID* @SDL_JoystickGUID.302() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_JoystickGUID*
  ret %SDL_JoystickGUID* %1
}

declare i8* @SDL_GameControllerMappingForGUID(%SDL_JoystickGUID)

declare i8* @SDL_GameControllerMapping(i8**)

declare i32 @SDL_IsGameController(i32)

declare i8* @SDL_GameControllerNameForIndex(i32)

declare i8** @SDL_GameControllerOpen(i32)

declare i8** @SDL_GameControllerFromInstanceID(i32)

declare i8* @SDL_GameControllerName(i8**)

declare i16 @SDL_GameControllerGetVendor(i8**)

declare i16 @SDL_GameControllerGetProduct(i8**)

declare i16 @SDL_GameControllerGetProductVersion(i8**)

declare i32 @SDL_GameControllerGetAttached(i8**)

declare i8** @SDL_GameControllerGetJoystick(i8**)

declare i32 @SDL_GameControllerEventState(i32)

declare void @SDL_GameControllerUpdate()

declare i32 @SDL_GameControllerGetAxisFromString(i8*)

declare i8* @SDL_GameControllerGetStringForAxis(i32)

define %SDL_GameControllerButtonBind* @SDL_GameControllerButtonBind.303() {
entry:
  %0 = call i64* @malloc(i64 12)
  %1 = bitcast i64* %0 to %SDL_GameControllerButtonBind*
  ret %SDL_GameControllerButtonBind* %1
}

declare %SDL_GameControllerButtonBind @SDL_GameControllerGetBindForAxis(i8**, i32)

declare i16 @SDL_GameControllerGetAxis(i8**, i32)

declare i32 @SDL_GameControllerGetButtonFromString(i8*)

declare i8* @SDL_GameControllerGetStringForButton(i32)

define %SDL_GameControllerButtonBind* @SDL_GameControllerButtonBind.304() {
entry:
  %0 = call i64* @malloc(i64 12)
  %1 = bitcast i64* %0 to %SDL_GameControllerButtonBind*
  ret %SDL_GameControllerButtonBind* %1
}

declare %SDL_GameControllerButtonBind @SDL_GameControllerGetBindForButton(i8**, i32)

declare i8 @SDL_GameControllerGetButton(i8**, i32)

declare void @SDL_GameControllerClose(i8**)

declare i32 @SDL_GetNumTouchDevices()

declare i64 @SDL_GetTouchDevice(i32)

declare i32 @SDL_GetNumTouchFingers(i64)

define %SDL_Finger* @SDL_Finger.305() {
entry:
  %0 = call i64* @malloc(i64 32)
  %1 = bitcast i64* %0 to %SDL_Finger*
  ret %SDL_Finger* %1
}

declare %SDL_Finger* @SDL_GetTouchFinger(i64, i32)

declare i32 @SDL_RecordGesture(i64)

define %SDL_RWops* @SDL_RWops.306() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare i32 @SDL_SaveAllDollarTemplates(%SDL_RWops*)

define %SDL_RWops* @SDL_RWops.307() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare i32 @SDL_SaveDollarTemplate(i64, %SDL_RWops*)

define %SDL_RWops* @SDL_RWops.308() {
entry:
  %0 = call i64* @malloc(i64 1)
  %1 = bitcast i64* %0 to %SDL_RWops*
  ret %SDL_RWops* %1
}

declare i32 @SDL_LoadDollarTemplates(i64, %SDL_RWops*)

declare void @SDL_PumpEvents()

declare i32 @SDL_PeepEvents(i448*, i32, i32, i32, i32)

declare i32 @SDL_HasEvent(i32)

declare i32 @SDL_HasEvents(i32, i32)

declare void @SDL_FlushEvent(i32)

declare void @SDL_FlushEvents(i32, i32)

declare i32 @SDL_PollEvent(i448*)

declare i32 @SDL_WaitEvent(i448*)

declare i32 @SDL_WaitEventTimeout(i448*, i32)

declare i32 @SDL_PushEvent(i448*)

declare void @SDL_SetEventFilter(i8*, i64*)

declare i32 @SDL_GetEventFilter(i8**, i64**)

declare void @SDL_AddEventWatch(i8*, i64*)

declare void @SDL_DelEventWatch(i8*, i64*)

declare void @SDL_FilterEvents(i8*, i64*)

declare i8 @SDL_EventState(i32, i32)

declare i32 @SDL_RegisterEvents(i32)

declare i8* @SDL_GetBasePath()

declare i8* @SDL_GetPrefPath(i8*, i8*)

declare i32 @SDL_NumHaptics()

declare i8* @SDL_HapticName(i32)

declare i8** @SDL_HapticOpen(i32)

declare i32 @SDL_HapticOpened(i32)

declare i32 @SDL_HapticIndex(i8**)

declare i32 @SDL_MouseIsHaptic()

declare i8** @SDL_HapticOpenFromMouse()

declare i32 @SDL_JoystickIsHaptic(i8**)

declare i8** @SDL_HapticOpenFromJoystick(i8**)

declare void @SDL_HapticClose(i8**)

declare i32 @SDL_HapticNumEffects(i8**)

declare i32 @SDL_HapticNumEffectsPlaying(i8**)

declare i32 @SDL_HapticQuery(i8**)

declare i32 @SDL_HapticNumAxes(i8**)

declare i32 @SDL_HapticEffectSupported(i8**, i576*)

declare i32 @SDL_HapticNewEffect(i8**, i576*)

declare i32 @SDL_HapticUpdateEffect(i8**, i32, i576*)

declare i32 @SDL_HapticRunEffect(i8**, i32, i32)

declare i32 @SDL_HapticStopEffect(i8**, i32)

declare void @SDL_HapticDestroyEffect(i8**, i32)

declare i32 @SDL_HapticGetEffectStatus(i8**, i32)

declare i32 @SDL_HapticSetGain(i8**, i32)

declare i32 @SDL_HapticSetAutocenter(i8**, i32)

declare i32 @SDL_HapticPause(i8**)

declare i32 @SDL_HapticUnpause(i8**)

declare i32 @SDL_HapticStopAll(i8**)

declare i32 @SDL_HapticRumbleSupported(i8**)

declare i32 @SDL_HapticRumbleInit(i8**)

declare i32 @SDL_HapticRumblePlay(i8**, double, i32)

declare i32 @SDL_HapticRumbleStop(i8**)

declare i32 @SDL_SetHintWithPriority(i8*, i8*, i32)

declare i32 @SDL_SetHint(i8*, i8*)

declare i8* @SDL_GetHint(i8*)

declare i32 @SDL_GetHintBoolean(i8*, i32)

declare void @SDL_AddHintCallback(i8*, i8*, i64*)

declare void @SDL_DelHintCallback(i8*, i8*, i64*)

declare void @SDL_ClearHints()

declare i64* @SDL_LoadObject(i8*)

declare i64* @SDL_LoadFunction(i64*, i8*)

declare void @SDL_UnloadObject(i64*)

declare void @SDL_LogSetAllPriority(i32)

declare void @SDL_LogSetPriority(i32, i32)

declare i32 @SDL_LogGetPriority(i32)

declare void @SDL_LogResetPriorities()

declare void @SDL_Log(i8*)

declare void @SDL_LogVerbose(i32, i8*)

declare void @SDL_LogDebug(i32, i8*)

declare void @SDL_LogInfo(i32, i8*)

declare void @SDL_LogWarn(i32, i8*)

declare void @SDL_LogError(i32, i8*)

declare void @SDL_LogCritical(i32, i8*)

declare void @SDL_LogMessage(i32, i32, i8*)

declare void @SDL_LogMessageV(i32, i32, i8*, i32)

declare void @SDL_LogGetOutputFunction(i8**, i64**)

declare void @SDL_LogSetOutputFunction(i8*, i64*)

define %SDL_MessageBoxButtonData* @SDL_MessageBoxButtonData.309() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_MessageBoxButtonData*
  ret %SDL_MessageBoxButtonData* %1
}

define %SDL_MessageBoxColorScheme* @SDL_MessageBoxColorScheme.310() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_MessageBoxColorScheme*
  ret %SDL_MessageBoxColorScheme* %1
}

define %SDL_MessageBoxData* @SDL_MessageBoxData.311() {
entry:
  %0 = call i64* @malloc(i64 56)
  %1 = bitcast i64* %0 to %SDL_MessageBoxData*
  ret %SDL_MessageBoxData* %1
}

declare i32 @SDL_ShowMessageBox(%SDL_MessageBoxData*, i32*)

declare i32 @SDL_ShowSimpleMessageBox(i32, i8*, i8*, i8**)

declare i32 @SDL_GetPowerInfo(i32*, i32*)

declare i32 @SDL_GetNumRenderDrivers()

define %SDL_RendererInfo* @SDL_RendererInfo.312() {
entry:
  %0 = call i64* @malloc(i64 88)
  %1 = bitcast i64* %0 to %SDL_RendererInfo*
  ret %SDL_RendererInfo* %1
}

declare i32 @SDL_GetRenderDriverInfo(i32, %SDL_RendererInfo*)

declare i32 @SDL_CreateWindowAndRenderer(i32, i32, i32, i8***, i8***)

declare i8** @SDL_CreateRenderer(i8**, i32, i32)

define %SDL_Surface* @SDL_Surface.313() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare i8** @SDL_CreateSoftwareRenderer(%SDL_Surface*)

declare i8** @SDL_GetRenderer(i8**)

define %SDL_RendererInfo* @SDL_RendererInfo.314() {
entry:
  %0 = call i64* @malloc(i64 88)
  %1 = bitcast i64* %0 to %SDL_RendererInfo*
  ret %SDL_RendererInfo* %1
}

declare i32 @SDL_GetRendererInfo(i8**, %SDL_RendererInfo*)

declare i32 @SDL_GetRendererOutputSize(i8**, i32*, i32*)

declare i8** @SDL_CreateTexture(i8**, i32, i32, i32, i32)

define %SDL_Surface* @SDL_Surface.315() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

declare i8** @SDL_CreateTextureFromSurface(i8**, %SDL_Surface*)

declare i32 @SDL_QueryTexture(i8**, i32*, i32*, i32*, i32*)

declare i32 @SDL_SetTextureColorMod(i8**, i8, i8, i8)

declare i32 @SDL_GetTextureColorMod(i8**, i8*, i8*, i8*)

declare i32 @SDL_SetTextureAlphaMod(i8**, i8)

declare i32 @SDL_GetTextureAlphaMod(i8**, i8*)

declare i32 @SDL_SetTextureBlendMode(i8**, i32)

declare i32 @SDL_GetTextureBlendMode(i8**, i32*)

define %SDL_Rect* @SDL_Rect.316() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_UpdateTexture(i8**, %SDL_Rect*, i64*, i32)

define %SDL_Rect* @SDL_Rect.317() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_UpdateYUVTexture(i8**, %SDL_Rect*, i8*, i32, i8*, i32, i8*, i32)

define %SDL_Rect* @SDL_Rect.318() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_LockTexture(i8**, %SDL_Rect*, i64**, i32*)

declare void @SDL_UnlockTexture(i8**)

declare i32 @SDL_RenderTargetSupported(i8**)

declare i32 @SDL_SetRenderTarget(i8**, i8**)

declare i8** @SDL_GetRenderTarget(i8**)

declare i32 @SDL_RenderSetLogicalSize(i8**, i32, i32)

declare void @SDL_RenderGetLogicalSize(i8**, i32*, i32*)

declare i32 @SDL_RenderSetIntegerScale(i8**, i32)

declare i32 @SDL_RenderGetIntegerScale(i8**)

define %SDL_Rect* @SDL_Rect.319() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_RenderSetViewport(i8**, %SDL_Rect*)

define %SDL_Rect* @SDL_Rect.320() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare void @SDL_RenderGetViewport(i8**, %SDL_Rect*)

define %SDL_Rect* @SDL_Rect.321() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_RenderSetClipRect(i8**, %SDL_Rect*)

define %SDL_Rect* @SDL_Rect.322() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare void @SDL_RenderGetClipRect(i8**, %SDL_Rect*)

declare i32 @SDL_RenderIsClipEnabled(i8**)

declare i32 @SDL_RenderSetScale(i8**, double, double)

declare void @SDL_RenderGetScale(i8**, float*, float*)

declare i32 @SDL_SetRenderDrawColor(i8**, i8, i8, i8, i8)

declare i32 @SDL_GetRenderDrawColor(i8**, i8*, i8*, i8*, i8*)

declare i32 @SDL_SetRenderDrawBlendMode(i8**, i32)

declare i32 @SDL_GetRenderDrawBlendMode(i8**, i32*)

declare i32 @SDL_RenderClear(i8**)

declare i32 @SDL_RenderDrawPoint(i8**, i32, i32)

define %SDL_Point* @SDL_Point.323() {
entry:
  %0 = call i64* @malloc(i64 8)
  %1 = bitcast i64* %0 to %SDL_Point*
  ret %SDL_Point* %1
}

declare i32 @SDL_RenderDrawPoints(i8**, %SDL_Point*, i32)

declare i32 @SDL_RenderDrawLine(i8**, i32, i32, i32, i32)

define %SDL_Point* @SDL_Point.324() {
entry:
  %0 = call i64* @malloc(i64 8)
  %1 = bitcast i64* %0 to %SDL_Point*
  ret %SDL_Point* %1
}

declare i32 @SDL_RenderDrawLines(i8**, %SDL_Point*, i32)

define %SDL_Rect* @SDL_Rect.325() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_RenderDrawRect(i8**, %SDL_Rect*)

define %SDL_Rect* @SDL_Rect.326() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_RenderDrawRects(i8**, %SDL_Rect*, i32)

define %SDL_Rect* @SDL_Rect.327() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_RenderFillRect(i8**, %SDL_Rect*)

define %SDL_Rect* @SDL_Rect.328() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_RenderFillRects(i8**, %SDL_Rect*, i32)

define %SDL_Rect* @SDL_Rect.329() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

define %SDL_Rect* @SDL_Rect.330() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_RenderCopy(i8**, i8**, %SDL_Rect*, %SDL_Rect*)

define %SDL_Rect* @SDL_Rect.331() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

define %SDL_Rect* @SDL_Rect.332() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

define %SDL_Point* @SDL_Point.333() {
entry:
  %0 = call i64* @malloc(i64 8)
  %1 = bitcast i64* %0 to %SDL_Point*
  ret %SDL_Point* %1
}

declare i32 @SDL_RenderCopyEx(i8**, i8**, %SDL_Rect*, %SDL_Rect*, double, %SDL_Point*, i32)

define %SDL_Rect* @SDL_Rect.334() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %SDL_Rect*
  ret %SDL_Rect* %1
}

declare i32 @SDL_RenderReadPixels(i8**, %SDL_Rect*, i32, i64*, i32)

declare void @SDL_RenderPresent(i8**)

declare void @SDL_DestroyTexture(i8**)

declare void @SDL_DestroyRenderer(i8**)

declare i32 @SDL_GL_BindTexture(i8**, float*, float*)

declare i32 @SDL_GL_UnbindTexture(i8**)

declare i64* @SDL_RenderGetMetalLayer(i8**)

declare i64* @SDL_RenderGetMetalCommandEncoder(i8**)

declare i8** @SDL_CreateShapedWindow(i8*, i32, i32, i32, i32, i32)

declare i32 @SDL_IsShapedWindow(i8**)

define %SDL_Surface* @SDL_Surface.335() {
entry:
  %0 = call i64* @malloc(i64 96)
  %1 = bitcast i64* %0 to %SDL_Surface*
  ret %SDL_Surface* %1
}

define %SDL_Color* @SDL_Color.336() {
entry:
  %0 = call i64* @malloc(i64 4)
  %1 = bitcast i64* %0 to %SDL_Color*
  ret %SDL_Color* %1
}

define %SDL_WindowShapeParams* @SDL_WindowShapeParams.337() {
entry:
  %0 = call i64* @malloc(i64 5)
  %1 = bitcast i64* %0 to %SDL_WindowShapeParams*
  ret %SDL_WindowShapeParams* %1
}

define %SDL_WindowShapeMode* @SDL_WindowShapeMode.338() {
entry:
  %0 = call i64* @malloc(i64 12)
  %1 = bitcast i64* %0 to %SDL_WindowShapeMode*
  ret %SDL_WindowShapeMode* %1
}

declare i32 @SDL_SetWindowShape(i8**, %SDL_Surface*, %SDL_WindowShapeMode*)

define %SDL_WindowShapeMode* @SDL_WindowShapeMode.339() {
entry:
  %0 = call i64* @malloc(i64 12)
  %1 = bitcast i64* %0 to %SDL_WindowShapeMode*
  ret %SDL_WindowShapeMode* %1
}

declare i32 @SDL_GetShapedWindowMode(i8**, %SDL_WindowShapeMode*)

declare i32 @SDL_GetTicks()

declare i64 @SDL_GetPerformanceCounter()

declare i64 @SDL_GetPerformanceFrequency()

declare void @SDL_Delay(i32)

declare i32 @SDL_AddTimer(i32, i8*, i64*)

declare i32 @SDL_RemoveTimer(i32)

define %SDL_version* @SDL_version.340() {
entry:
  %0 = call i64* @malloc(i64 3)
  %1 = bitcast i64* %0 to %SDL_version*
  ret %SDL_version* %1
}

declare void @SDL_GetVersion(%SDL_version*)

declare i8* @SDL_GetRevision()

declare i32 @SDL_GetRevisionNumber()

declare i32 @SDL_Init(i32)

declare i32 @SDL_InitSubSystem(i32)

declare void @SDL_QuitSubSystem(i32)

declare i32 @SDL_WasInit(i32)

declare void @SDL_Quit()

declare i32 @main.341()

declare i32 @f(i3200)

declare i32 @TEST_no_arg_func()

declare i32 @TEST_arg_func(i32)

define %Struct* @Struct.342() {
entry:
  %0 = call i64* @malloc(i64 8)
  %1 = bitcast i64* %0 to %Struct*
  ret %Struct* %1
}

declare i32 @TEST_struct_arg_func(%Struct*)

define %Struct* @Struct.343() {
entry:
  %0 = call i64* @malloc(i64 8)
  %1 = bitcast i64* %0 to %Struct*
  ret %Struct* %1
}

declare %Struct* @TEST_return_struct_func()

define %Struct* @Struct.344() {
entry:
  %0 = call i64* @malloc(i64 8)
  %1 = bitcast i64* %0 to %Struct*
  ret %Struct* %1
}

define %NestStruct* @NestStruct.345() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %NestStruct*
  ret %NestStruct* %1
}

declare i32 @TEST_arg_nest_struct(%NestStruct*)

define %NestStruct* @NestStruct.346() {
entry:
  %0 = call i64* @malloc(i64 16)
  %1 = bitcast i64* %0 to %NestStruct*
  ret %NestStruct* %1
}

declare %NestStruct* @TEST_return_nest_struct()

declare void @List()

declare void @Person()

declare void @t()

declare i32 @show()
