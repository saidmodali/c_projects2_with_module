

#ifndef NUTILITY_H
#define NUTILITY_H

//other std libraries...


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stddef.h>



//macro

#define isleap(y)         ((y) % 4 == 0 &&(( y) % 100 != 0 || (y) % 400 == 0))
#define randomize()        srand((unsigned)time(NULL))
#define asize(a)         (sizeof (a) / sizeof (a)[0])








//funcction declerations ...

int isprime(int);

void set_array_random(int* p, size_t size);
void print_array(const int* p, size_t size);
void pline(void);
void sgets(char* p);
void swap(int*, int*);
int* get_array_min(const int* ptr, size_t size);
int* get_array_max(const int* ptr, size_t size);
const char* get_random_surname(void);
const char* get_random_name(void);





#endif
