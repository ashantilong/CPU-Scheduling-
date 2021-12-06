#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cache_function.h"
#include "access_time.h"

const int KB = 1024;
const int MB = 1024 * KB;
int SIZES[] = {1*KB,4*KB,8*KB,16*KB,24*KB,32*KB,64*KB,128*KB,128*KB*2,128*KB*3,512*KB,1*MB,2*MB,3*MB,4*MB};

void cache_size(/*int* A, clock_t t*/){
    /*
    time_t start_time = time(0);
    double time_taken;

    //This need print the current time 
    printf("\nStartime  time: %s",ctime(&start_time));

    A = (int*) malloc(sizeof(int) * 10);
    //strcpy(str, "abc");
    printf("Value = %d, Address = %p\n", *A, A);
    time_taken = (double)(t - start_time) / CLOCKS_PER_SEC;
    printf("\nTime_taken %f", time_taken);
    free(A);
    return *A;
    */

    //printf("made it into cache block\n");
    for (int i = 0; i < sizeof(SIZES) / sizeof(int); i++){
        //printf("made it inside SIZES loop\n");
        int size = SIZES[i];
        int* arr = (int*) calloc(size,sizeof(int));
        for (int i = 0; i < size; i++){
            arr[i] = 1;
        }
        access_time_data(arr,size);
        free(arr);
    }
}