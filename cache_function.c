#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cache_function.h"
#include "access_time.h"

const int KB = 1024;
const int MB = 1024 * KB;
// int SIZES[] = {1*KB,4*KB,8*KB,16*KB,24*KB,32*KB,64*KB,128*KB,128*KB*2,128*KB*3,512*KB,1*MB,2*MB,3*MB,4*MB};
int SIZES[] = {4*MB,3*MB,2*MB,MB,512*KB,128*KB*3,128*KB*2,128*KB,64*KB,32*KB,24*KB,16*KB,8*KB,4*KB,KB};

void cache_size(/*int* A, clock_t t*/){

    printf("\n");
    printf("==========================================\n");
    printf("CACHE\n");
    printf("==========================================\n");

    for (int i = 0; i < sizeof(SIZES) / sizeof(int); i++){
        int size = SIZES[i];
        int* arr = (int*) calloc(size,sizeof(int));
        for (int j = 0; j < size; j++){
            arr[j] = 1;
        }
        cache_access_time(arr,size);
        free(arr);
    }
}

void cache_block_size(){
    struct timespec start,stop;
    double timediff;
    double totaltime;
    double avgtime;
    int size = 64*KB/sizeof(int);
    int* arr = (int*) calloc(size,sizeof(int)); // making an array of integers of size 128KB (should be less than cache size)
    //int maxstep = 256; // biggest experimental step or "skip" size
    int step = 1; // smallest experimental step size
    int maxp = 256; // max times innermost loop gets run (in this case should be 64)
    int temp = 0; // temp variable to ensure accesses are made


    for (int i = 0; i < size; i++){
            arr[i] = 1;
    }

    printf("\n");
    printf("==========================================\n");
    printf("CACHE BLOCK\n");
    printf("==========================================\n");

    for (int p = 1; p <= maxp; p *= 2){ // controls how many times the innermost loop gets run
      totaltime = 0.0;
      int counter = 0; // ensuring each size step gets the same number of accesses and counting each access
      for (int i = 0; i < p; i++){
        for (int j = 0; j < size; j += step){
            if( clock_gettime( CLOCK_REALTIME, &start) == -1 ) { // storing the start time
                perror( "clock gettime" );
                exit( EXIT_FAILURE );
            }
            temp += arr[j];
            if( clock_gettime( CLOCK_REALTIME, &stop) == -1 ) { // storing the end time
                perror( "clock gettime" );
                exit( EXIT_FAILURE );
            } 
            timediff = (stop.tv_sec - start.tv_sec)
                      + (stop.tv_nsec - start.tv_nsec) // storing the time elapsed in seconds
                      / BILLION;
            totaltime += timediff;
            counter++;
        }
      }
      avgtime = totaltime / counter;
      printf("========================%d========================\n",(temp/1024)*(int)sizeof(int));
      printf("Looped %d times\n",counter);
      printf( "Average access time with step size %d: %.15lf\n", step, avgtime);
      step *= 2;
    }
}