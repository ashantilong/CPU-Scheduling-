#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "access_time.h"
#include "cache_function.h"

int comp (const void * elem1, const void * elem2){
    int f = *((double*)elem1);
    int s = *((double*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int cache_access_time(int* arr, int size){
    struct timespec start,stop;
    double timediff;
    double totaltime = 0.0;
    double avgtime;
    double mediantime;
    int temp = 0;

    double* times = (double*)calloc(size,sizeof(double));

    for (int i = 0; i < size; i++){

      if( clock_gettime( CLOCK_REALTIME, &start) == -1 ) {
        perror( "clock gettime" );
        exit( EXIT_FAILURE );
      }

      temp += arr[i];

      if( clock_gettime( CLOCK_REALTIME, &stop) == -1 ) {
        perror( "clock gettime" );
        exit( EXIT_FAILURE );
      } 

      timediff = (stop.tv_sec - start.tv_sec)
          + (stop.tv_nsec - start.tv_nsec)
           / BILLION;

      totaltime += timediff;
      times[i] = timediff;
    }

    avgtime = totaltime / size;
    qsort (times, size, sizeof(double), comp);
    mediantime = (times[size/2] + times[(size/2) - 1]) / 2;

    printf("========================%d========================\n",(temp/1024)*(int)sizeof(int));
    printf( "Average time for accessing an array of size %dKB containing %d integers: %.10lf\n", (size/1024)*(int)sizeof(int), size, avgtime);
    printf( "Median time for accessing an array of size %dKB containing %d integers: %.10lf\n", (size/1024)*(int)sizeof(int), size, mediantime);
    return( EXIT_SUCCESS );
}

int cache_block_access_time(){
    struct timespec start,stop;
    double timediff;
    double totaltime;
    double avgtime;
    int size = 64*1024/sizeof(int);
    int* arr = (int*) calloc(size,sizeof(int)); // making an array of integers of size 128KB (should be less than cache size)
    //int maxstep = 256; // biggest experimental step or "skip" size
    int step = 1; // smallest experimental step size
    int maxp = 256; // max times innermost loop gets run (in this case should be 64)
    int temp = 0; // temp variable to ensure accesses are made


    for (int i = 0; i < size; i++){
            arr[i] = 1;
    }

    for (int p = 1; p <= maxp; p *= 2){ // controls how many times the innermost loop gets run
      totaltime = 0.0;
      for (int i = 0; i < p; i++){
        for (int j = 0; j < size; j += step){
            if( clock_gettime( CLOCK_REALTIME, &start) == -1 ) {
                perror( "clock gettime" );
                exit( EXIT_FAILURE );
            }
            temp += arr[j];
            if( clock_gettime( CLOCK_REALTIME, &stop) == -1 ) {
                perror( "clock gettime" );
                exit( EXIT_FAILURE );
            } 
            timediff = (stop.tv_sec - start.tv_sec)
                      + (stop.tv_nsec - start.tv_nsec)
                      / BILLION;
            totaltime += timediff;
        }
      }
      avgtime = totaltime / size;
      printf("========================%d========================\n",(temp/1024)*(int)sizeof(int));
      printf( "Average access time with step size %d: %.10lf\n", step, avgtime);
      step *= 2;
    }

    return 0;
}