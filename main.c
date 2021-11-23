#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "cache_function.h"


int main(){

int a = 1;
clock_t start;

start = clock();
while(a <= 64 * 1024 * 1024){
    cache_block(&a , start);
    a = a + 1;
}

return 0;

}
