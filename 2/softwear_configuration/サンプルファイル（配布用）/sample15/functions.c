#include <stdio.h>
#include <math.h>
#include "header.h"

void print_example(EXAMPLE_S z)
{
    switch (z.t)
    {
    case CHAR:
        printf("%c\n", z.v.c);
        break;
    case INT:
        printf("%d\n", z.v.i);
        break;
    case FLOAT:
        printf("%f\n", z.v.f);
        break;
    case DOUBLE:
        printf("%f\n", z.v.d);
        break;
    default:
        printf("error\n");
    }
}