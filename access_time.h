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
int access_time_data(int* arr, int size);