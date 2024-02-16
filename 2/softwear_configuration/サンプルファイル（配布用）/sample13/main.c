#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

int main(void)
{
    EXAMPLE *A;
    // struct example_struct B;

    A = (EXAMPLE *)malloc(sizeof(EXAMPLE));
    A->a = 1;
    snprintf(A->b, sizeof(A->b), "ABC");
    A->c = M_PI;
    A->d = 2;

    print_example(A);
}
