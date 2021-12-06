#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cache_function.h"
#include "access_time.h"



int main(int argc, char** argv){
    /*
    int a = 1;
    clock_t start;
    
    start = clock();
    while(a <= 64 * 1024 * 1024){
        cache_block(&a , start);
        a = a + 1;
    }
    */

    /*
    int* arr = (int*) calloc(SIZE,sizeof(int));
    for (int i = 0; i < SIZE; i++){
        arr[i] = 1;
    }
    access_time_data(arr);
    */

    cache_size();

    return 0;
}
