#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cache_function.h"



int cache_block(int* A, clock_t t){
    time_t start_time = time(0);
    double time_taken;

    //This need print the current time 
    printf("\nStartime  time:%s",ctime(&start_time));

    A = (int*) malloc(sizeof(int) * 10);
    //strcpy(str, "abc");
    printf("Value = %d, Address = %u\n", A, A);
    time_taken = (double)(t - start_time) / CLOCKS_PER_SEC;
    printf("\nTime_taken%d ", time_taken);
    free(A);
    return A;

}