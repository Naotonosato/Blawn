import os,sys
dir_name = sys.argv[1]

for path,dirs,files in os.walk(os.path.abspath(dir_name)):
    for file in files:
        if file.endswith(".cpp") or file.endswith(".c") or file.endswith(".hpp") or file.endswith(".h"):
            arg = path + "/" + file
            os.system('clang-format -i -style="{BreakBeforeBraces: Allman,SortIncludes: false,BasedOnStyle: Google,IndentWidth: 4,AccessModifierOffset: 0,Standard: Auto}" ' + arg)
