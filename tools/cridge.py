import sys,os
import ctypes
import clang.cindex
from clang.cindex import Index,Config,CursorKind,TypeKind,TranslationUnit
Config.set_library_path('/usr/lib/llvm-6.0/lib/')
Config.set_library_file('/usr/lib/llvm-6.0/lib/libclang.so.1')
REAL_NUMBER_TYPES = set({
    TypeKind.DOUBLE,TypeKind.FLOAT,TypeKind.FLOAT128
})
INTEGER_TYPES = set({
    TypeKind.INT,TypeKind.INT128,TypeKind.LONG,
    TypeKind.LONGDOUBLE,TypeKind.LONGLONG,
    TypeKind.UCHAR,TypeKind.CHAR32
})
NUMERIC_TYPES = REAL_NUMBER_TYPES | INTEGER_TYPES

BUILTIN_C_TYPES = {
TypeKind.BOOL:ctypes.c_bool,
TypeKind.CHAR_S:ctypes.c_char,
TypeKind.CHAR_U:ctypes.c_char,
TypeKind.DOUBLE:ctypes.c_double,
TypeKind.FLOAT:ctypes.c_float,
TypeKind.INT:ctypes.c_int,
TypeKind.LONG:ctypes.c_long,
TypeKind.LONGDOUBLE:ctypes.c_longdouble,
TypeKind.LONGLONG:ctypes.c_longlong,
TypeKind.SCHAR:ctypes.c_char,
TypeKind.SHORT:ctypes.c_short,
TypeKind.UCHAR:ctypes.c_char,
TypeKind.UINT:ctypes.c_uint,
TypeKind.ULONG:ctypes.c_ulong,
TypeKind.ULONGLONG:ctypes.c_ulonglong,
TypeKind.USHORT:ctypes.c_ushort,
TypeKind.WCHAR:ctypes.c_wchar
}
BUILTIN_C_TYPE_NAMES = {
TypeKind.BOOL:"__C_BOOL__",
TypeKind.CHAR_S:"__C_CHAR__",
TypeKind.CHAR_U:"__C_CHAR__",
TypeKind.DOUBLE:"__C_DOUBLE__",
TypeKind.FLOAT:"__C_FLOAT__",
TypeKind.INT:"__C_INT__",
TypeKind.LONG:"__C_LONG__",
TypeKind.LONGDOUBLE:"__C_LONGDOUBLE__",
TypeKind.LONGLONG:"__C_LONGLONG__",
TypeKind.SCHAR:"__C_SCHAR__",
TypeKind.SHORT:"__C_SHORT__",
TypeKind.UCHAR:"__C_UCHAR__",
TypeKind.UINT:"__C_UINT__",
TypeKind.ULONG:"__C_ULONG__",
TypeKind.ULONGLONG:"__C_ULONGLONG__",
TypeKind.USHORT:"__C_USHORT__",
TypeKind.WCHAR:"__C_WCHAR__",
}

UNIQUE_NUMBER = 0
GENERATED = set()
def get_unique():
    global UNIQUE_NUMBER
    UNIQUE_NUMBER += 1
    return UNIQUE_NUMBER

for t in BUILTIN_C_TYPE_NAMES:
    size = ctypes.sizeof(BUILTIN_C_TYPES[t])
    BUILTIN_C_TYPE_NAMES[t] += "SIZE_" + str(size)

def _rename_type(name):
    to_delete = "struct "
    return name.replace(to_delete,"").replace("const ","")

def get_finally_pointee(node_type,count=0):
    if node_type.kind == TypeKind.POINTER:
        count += 1
        node_type,count = get_finally_pointee(node_type.get_pointee(),count)
    return node_type,count

def to_blawn_type(type_info):
    global GENERATED
    if type_info.kind == TypeKind.VOID:
        return "__C_VOID__"
    if type_info.kind == TypeKind.POINTER:
        ptr_size = str(type_info.get_size())
        type_info,count = get_finally_pointee(type_info)
        if to_blawn_type(type_info) == "__C_VOID__":
            return "__PTR__ " * count + "__C_INT__SIZE_" + ptr_size
        return "__PTR__ " * count + to_blawn_type(type_info)
    if type_info.kind in BUILTIN_C_TYPE_NAMES:
        return BUILTIN_C_TYPE_NAMES[type_info.kind]
    if type_info.kind == TypeKind.ENUM:
        return "__C_INT__SIZE_" + str(type_info.get_size())
    if type_info.kind in (TypeKind.FUNCTIONPROTO,TypeKind.FUNCTIONNOPROTO):
        return "__C_UNKNOWN__SIZE_" + str(type_info.get_size())
    if type_info.kind == TypeKind.CONSTANTARRAY:
        return "__C_UNKNOWN__SIZE_" + str(type_info.get_size())
    if type_info.get_declaration().is_anonymous():
        return "__C_UNKNOWN__SIZE_" + str(type_info.get_size())
    if type_info.get_size() < 0:
        return "__PTR__ __C_UNKNOWN__SIZE_1"
    if "union " in type_info.spelling:
        return "__C_UNKNOWN__SIZE_" + str(type_info.get_size())
    if not (_rename_type(type_info.spelling) in GENERATED):
        pass#print(_rename_type(type_info.spelling))
    return _rename_type(type_info.spelling)

def get_unsupported(element):
    return f"__NOT_SUPPORTED__{get_unique()}","__C_UNKNOWN__SIZE_" + str(element["type"].get_size())

def rename_element(element):
    if element["type"].kind == TypeKind.CONSTANTARRAY:
        return f"__NOT_SUPPORTED__{get_unique()}"
    if element["type"].get_size() < 0:
        return f"__NOT_SUPPORTED__{get_unique()}"
    if "union " in element["type"].spelling:
        return f"__NOT_SUPPORTED__{get_unique()}"
    if element["type"].get_declaration().is_anonymous():
        return f"__NOT_SUPPORTED__{get_unique()}"
    else:
        return element["name"]

def generate_Ctype(structures):
    global GENERATED
    Ctype_template = "Ctype {}\n"
    member_template = "    @{} = {}\n"
    classes = ""
    for name,struct in structures.items():
        field = [{"name":element.spelling,"type":element.type.get_canonical()} for element in struct.get_fields()]
        C_type_wrapper = Ctype_template.format(name.replace("struct ",""))
        if struct.get_size() > 0 and len(field) == 0:
            C_type_wrapper += member_template.format(
                f"__NOT_SUPPORTED__{get_unique()}",
                "__C_UNKNOWN__SIZE_" + str(struct.get_size())
                )
        if struct.get_size() < 0:
            continue
        if "::(anonymous at" in name:
            continue
        if "union " in name:
            continue
        for element in field:
            element_type_name = to_blawn_type(element["type"])
            element_name = rename_element(element)
            #if not is_supported_type(element["type"]):
            #   element_name = "__cannot_access__<type {} is not supported>".format(element_type_name)
            
            if name.replace("struct ","") == element_type_name.split(" ")[-1].replace(" ",""):
                element_name,element_type_name = get_unsupported(element)
            C_type_wrapper += member_template.format(
                element_name,
                element_type_name
                )
            GENERATED.add(element_type_name)
        classes += C_type_wrapper
    return classes

def generate_wrapper(functions):
    template = """[Cfunction {}]
    arguments: {}
    return: {}
"""
    wrapper = ""
    for func_name,info in functions.items():
        types = info["ARGUMENTS_TYPE"]
        return_type = info["RESULT_TYPE"]
        args_text = ",".join([to_blawn_type(t) for t in types])
        return_text = to_blawn_type(return_type)
        wrapper += template.format(func_name,args_text,return_text)
    return wrapper


def get_functions(filename,node,functions_dict={},structures_dict={}):
    global GENERATED
    if node.kind in (CursorKind.STRUCT_DECL,CursorKind.UNION_DECL):
        spelling = node.type.get_canonical().spelling
        #print(node.canonical.is_anonymous())
        if not node.is_anonymous():
            GENERATED.add(spelling)
            structures_dict[spelling] = node.type.get_canonical()
    if node.kind == CursorKind.FUNCTION_DECL:
        functions_dict[node.spelling] = {"RESULT_TYPE":node.result_type.get_canonical(),"ARGUMENTS_TYPE":[]}
        for arg in node.get_arguments():
            functions_dict[node.spelling]["ARGUMENTS_TYPE"].append(arg.type.get_canonical())
    for child in node.get_children():
        get_functions(filename,child,functions_dict,structures_dict)
    return functions_dict,structures_dict

if __name__ == "__main__":
    source_filename = sys.argv[1]#"test/test1.h"#"../compiler/builtins/builtins.c"#"test/test1.h"#"../compiler/builtins/builtins.c"
    print(source_filename)
    output_filename = os.path.splitext(os.path.basename(source_filename))[0] + ".bridge"
    cursor = Index.create().parse(source_filename, options = TranslationUnit.PARSE_SKIP_FUNCTION_BODIES).cursor
    functions,structures = get_functions(source_filename,cursor)
    Ctypes = generate_Ctype(structures)
    wrapper = generate_wrapper(functions)
    with open(output_filename,"wt") as file:
        file.write(Ctypes)
        file.write(wrapper)
        file.flush()