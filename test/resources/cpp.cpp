class C
{
    short a;
    short b;
    bool c;
};

union U
{
    int a;
    float b;
    C c;
    bool d;
};

int main()
{
    C c;
    union U u;
    u.a = 10;
    u.c = c;
    return 0;
}