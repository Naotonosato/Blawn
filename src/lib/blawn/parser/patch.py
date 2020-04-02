#use http://www.comrite.com/wp/c11-stdshared_ptr-as-semantic-value-in-bison-c-mode/
#as reference. thanks!

with open("./parser.tab.hh") as file:
    source = file.read()
    source = source.replace(
        "return *new (yyas_<T> ()) T (t);",
        "return *new (yyas_<T> ()) T (std::move((T&)t));"
        )
with open("./parser.tab.hh",mode="w") as file:
    file.write(source)