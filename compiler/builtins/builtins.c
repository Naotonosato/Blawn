#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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

void resize_list(List* self)
{
    self->allocated_size*=2;
    void* ptr = realloc(self->elements, self->element_size*self->allocated_size);
    if ( ptr == NULL )
    {
        puts("CRITICAL ERROR: failed to realloc at appending element to self");
        exit(1);
    }
    self->elements = ptr;
}

i64 append_to_list(List *self, void *element)
{
    if(self->size + 1>= self->allocated_size)
    {
        resize_list(self);
    }
	
	memcpy(
        self->elements + (self->size * self->element_size), 
        element, 
        self->element_size
        );
    self->size+=1;
	return true;
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

int main()
{
    String* s = string_constructor("aaaa",4);
    List* l = list_constructor(sizeof(s));
    append_to_list(l,s);
    append_to_list(l,s);
    printf("%s\n",((String*)get_element(l,1))->string);
    printf("%s\n",(*((String*)get_element(l,1))).string);
}