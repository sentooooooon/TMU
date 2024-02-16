#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"


int main(void)
{

    EXAMPLE_U X;
    EXAMPLE_S Z;
    printf("%d\t%d\t%d\t%d\n", CHAR, INT, FLOAT, DOUBLE);
    printf("sizeof(char) = %d\n", sizeof(char));
    printf("sizeof(int) = %d\n", sizeof(int));
    printf("sizeof(float) = %d\n", sizeof(float));
    printf("sizeof(double) = %d\n", sizeof(double));
    printf("sizeof(EXAMPLE_U) = %d\n", sizeof(EXAMPLE_U));
    printf("sizeof(EXAMPLE_U2) = %d\n", sizeof(EXAMPLE_U2));

    printf("&X = %p\n", &X);
    printf("&(X.c) = %p\n", &(X.c));
    printf("&(X.i) = %p\n", &(X.i));
    printf("&(X.f) = %p\n", &(X.f));
    printf("&(X.d) = %p\n", &(X.d));

    Z.t = INT;
    Z.v.i = 1;
    print_example(Z);
    Z.t = DOUBLE;
    Z.v.d = M_PI/2;
    print_example(Z);


}
