#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"
#include "string.h"
int main(void)
{
    EXAMPLE A;
    // struct example_struct B;

    A.a = 1;
    
     // sizeof(A.b)の大きさの分だけ文字列を配列に出力
    snprintf(A.b, sizeof(A.b), "ABC");
    // strcpy(A.b, "ABC");
    A.c = M_PI;
    A.d = 2;

    print_example(A);
}
