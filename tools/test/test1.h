#include <SDL2/SDL.h>
int main()
{
    unsigned int a;
}
int f(int[100]){}
int TEST_no_arg_func()
{
    return 0;
}
int TEST_arg_func(int arg)
{
    return arg;
}
typedef struct Struct
{
    int member;
    int member2;
} Struct;

int TEST_struct_arg_func(Struct* arg)
{
    return 0;
}

Struct* TEST_return_struct_func()
{
    Struct* s;
    return s;
}

typedef struct NestStruct
{
    int member;
    int member2;
    Struct**** s;
} NestStruct;

int TEST_arg_nest_struct(NestStruct* n)
{
    return 0;
}

NestStruct* TEST_return_nest_struct()
{
    NestStruct* n;
    return n;
}