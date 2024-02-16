
#include <stdio.h>

int a_plus_b1(int a, int b)
{
    return a + b;
}

void a_plus_b2(int a, int b, int* c)
{
    *c = a + b;
    
}