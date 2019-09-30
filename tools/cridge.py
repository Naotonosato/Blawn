import pycparser
def generate_wrapper():
    generated_types = {}
    txt = """[Cfunction {}]
    arguments: {}
    return: {}
    """
    txt.format(func_name,arguments_type,return_type)
    return 
class FunctionFinder(pycparser.c_ast.NodeVisitor):
    def visit_FuncDef(self,node):
        print(node.decl.name)

txt = """[Cfunction {}]
    arguments: {}
    return: {}
    """.format("func","arg","returns")

ast = pycparser.parse_file("../blawn/t.c",use_cpp=True,cpp_args=r"-Iutils/fake_libc_include")
FunctionFinder().visit(ast)