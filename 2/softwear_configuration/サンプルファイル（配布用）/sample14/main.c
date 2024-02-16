#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

int main(void)
{
    EXAMPLE A;
    EXAMPLE *B;

    B = (EXAMPLE *)malloc(sizeof(EXAMPLE));
    printf("sizeof(char) = %d\n", sizeof(char));
    printf("sizeof(int) = %d\n", sizeof(int));
    printf("sizeof(double) = %d\n", sizeof(double));
    printf("&A = %p\n", &A);
    printf("&(A.a) = %p\n", &(A.a));
    printf("&(A.b) = %p\n", &(A.b));
    printf("&(A.c) = %p\n", &(A.c));
    printf("&(A.d) = %p\n", &(A.d));

    printf("\n");
    printf("&B = %p\n", B);
    printf("&(B->a) = %p\n", &(B->a));
    printf("&(B->b) = %p\n", &(B->b));
    printf("&(B->c) = %p\n", &(B->c));
    printf("&(B->d) = %p\n", &(B->d));

}
