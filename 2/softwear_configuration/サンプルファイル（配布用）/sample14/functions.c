#include <stdio.h>
#include <math.h>
#include "header.h"

void print_example(EXAMPLE *X)
{
    printf("%d\n", X->a);
    printf("%s\n", X->b);
    printf("%.30f\n", X->c);
    printf("%d\n", X->d);
}