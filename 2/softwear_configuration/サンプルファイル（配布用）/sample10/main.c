#include <stdio.h>
#include "functions.h"

int main()
{
    int x1, x2;

    x1 = sum_function(function1, 1, 10);
    x2 = sum_function(function2, 1, 100);

    printf("x1 = %d\n", x1);
    printf("x2 = %d\n", x2);

}
