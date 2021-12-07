#include <stdio.h>
#include <stdlib.h>
//---------------------------------------------------
// CSCI 340 - Operating System I
// Fall 2021 (Anthony Leclerc)
// access time implementation file
// CPU Scheduling Project 
//
//---------------------------------------------------

//Constant
#define DEBUG 0
#define BILLION  1000000000.0

//----------------------------------------------------------------
//C-Style data structures

//-----------------------BEGIN (FUNCTION)--------------------------
//description:
int cache_access_time(int* arr, int size);
int cache_block_access_time();