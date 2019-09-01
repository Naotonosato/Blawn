#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define i64 long long
 
struct String;

typedef struct String
{
    char* string;
    i64 size;
} String;


typedef struct List
{
    i64 size;
    i64 allocated_size;
    i64 element_size;
    void* elements;
} List;


List* list_constructor(i64 element_size)
{
    List* self = (List*)malloc(sizeof(List));
    self->elements = NULL;
    self->element_size = element_size;
    self->size = 0;
    self->allocated_size = 1;
    return self;
}

void* blawn_realloc(void* array,i64 element_size,i64 allocated_size)
{
    void* ptr = realloc(array, element_size * allocated_size);
    if ( ptr == NULL )
    {
        puts("\x1b[31mCRITICAL ERROR:\x1b[39m failed to realloc at appending element to list");
        exit(1);
    }
    return ptr;
}


void blawn_memcpy(void* array,i64 size,i64 element_size,void *element)
{
	memcpy(
        array + (size * element_size), 
        &element, 
        element_size
        );
}

void* get_element(List* self,i64 index)
{
    if (0 <= index && index < self->size)
    {
        return (char*)self->elements + self->element_size*index;
    }
    else
    {
        puts("Error: list index out of range");
        exit(1);
    }
}

void set_element(List* self,void* element,i64 index)
{
    if (0 <= index && index < self->size)
    {
        * ((char*)self->elements + self->element_size*index) = element;
    }
    else
    {
        puts("Error: list index out of range");
        exit(1);
    }
}


void print(String* string)
{
    printf("%s\n",string->string);
}

String* string_constructor(char* str,i64 size)
{
    String* string = (String*)malloc(sizeof(String));
    string->string = str;
    string->size = size;
    return string;
}

void append_string(String* string,String* to_add)
{
    char* new_str;
    new_str = malloc(string->size + to_add->size);
    new_str[0] = '\0';
    strcat(new_str,string->string);
    strcat(new_str,to_add->string);
    string->size += to_add->size;
    string->string = new_str;
}


String* int_to_str(i64 n)
{
    i64 n_copy = n;
    i64 size;
    if (n >= 0)
    {
        size = 0;
        while(n)
        {
            n /= 10;
            size++;
        }
    }
    else
    {
        size = 1;
        n = -n;
        while(n)
        {
            n /= 10;
            size++;
        }
    }
    char* str = (char*)malloc(size);
    snprintf(str,size+1,"%lld",n_copy);
    return string_constructor(str,size);
}

String* float_to_str(double n)
{
    int digit = 16;
    char* str = (char*)malloc(digit);
    snprintf(str,digit+1,"%lf",n);
    return string_constructor(str,digit);
}
/*
int main_()
{   
    void* a = NULL;
    /*String* s = string_constructor("aaaa",4);
    String* ns = string_constructor("bbbb",4);
    List* l = list_constructor(sizeof(s));
    for (int i=0;i < 10000000; i++)
    {
        append_to_list(l,s);
    }
    append_to_list(l,s);
    
    set_element(l,ns,10000000);
    
    printf("%s\n",(*(String**)get_element(l,10000000))->string);
    printf("%s\n",((*(String**)get_element(l,1)))->string);

    char cs = 'A';
    char cns = 'X';
    List* sl = list_constructor(sizeof(cs));
    for (int i=0;i < 10000000; i++)
    {
        append_to_list(sl,cs);
    }
    set_element(sl,cns,11);
    
    putchar( *((char*)get_element(sl,11))  );
    return 0;
    */
//}*/
