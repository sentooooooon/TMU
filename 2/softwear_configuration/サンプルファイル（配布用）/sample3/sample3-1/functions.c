
#include <stdio.h>

void swap_a_b1(int a, int b)
{
    int c;
    c = a;
    a = b;
    b = c;
}

void swap_a_b2(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;

}