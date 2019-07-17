#include <builder.hpp>
#include <blawn.tab.h>
#include <iostream>


int main(void)
{
    Builder* builder;
    builder->generate();
    yyparse();
    return 0;
}