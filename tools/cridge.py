import clang.cindex
from clang.cindex import Index
from clang.cindex import Config


def generate_wrapper():
    generated_types = {}
    txt = """[Cfunction {}]
    arguments: {}
    return: {}
    """
    txt.format(func_name,arguments_type,return_type)


def print_method_area(node):
    if node.kind.name == 'FUNCTION_DECL':
        pass
    for child in node.get_children():
        print_method_area(child)

index = Index.create()
parsed = index.parse("../compiler/utils/test.cpp")
print_method_area(parsed.cursor)