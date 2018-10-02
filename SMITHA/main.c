#include<stdio.h>
#include<stdlib.h>
#include"headers.h"

int comp_id_string( const void* key, const void* element);
void const* get_func(char x);
void test_func(char x);

struct function_map {
    char opcode;
    void  *str();
};


int comp_id_string( const void* key, const void* element)
{
    char key_id     = ((struct function_map*) key)->opcode;
    char element_id = ((struct function_map*) element)->opcode;

    if (key_id < element_id) return -1;
    if (key_id > element_id) return  1;
    return 0;
}

static struct function_map func[] = {
     {'A',allocate()} ,
 //   {'D', display_memory},
 //   {'F', free_memory},
 //   {'H', help},
 //   {'I' , invertbits},
 //   {'P' , write_pattern},
 //   {'V' , verify_pattern},
 //   {'W' , write_memory}
 //   
     };

#define ELEMENTS_OF(x) (sizeof(x) / sizeof((x)[0]))

void const* get_func(char x)
{
    struct function_map key = {x};
    struct function_map* fs = bsearch(&key, func , ELEMENTS_OF(func), sizeof(func[0]), comp_id_string);

    if (!fs) return "invalid opcode";

    return fs->str;
}

void test_func(char x)
{
    get_func(x);
//printf("%c",x);
}

int main(void){
test_func('A');
return 0;
}
