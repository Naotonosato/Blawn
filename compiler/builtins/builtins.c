#include <stdlib.h>
#include <string.h>

struct String;

typedef struct String
{
    char* string;
    long long size;
} String;


void print(String* string)
{
    printf("%s\n",string->string);
}


String* string_constructor(char* str,long long size)
{
    String* string = (String*)malloc(sizeof(String));
    string->string = str;
    string->size = size;
    return string;
}

void add_string(String* string,String* to_add)
{
    strcat(string->string,to_add->string);
    string->size += to_add->size;
}