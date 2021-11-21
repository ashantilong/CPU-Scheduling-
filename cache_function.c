#include <stdio.h>
#include <stdlib.h>
#include "cache_function.h"



int cache_block(char* str){

    str = (char*) malloc(sizeof(3));
    strcpy(str, "abc");
    printf("String = %s, Address = %u\n", str, str);
    free(str);
    return &str;

}