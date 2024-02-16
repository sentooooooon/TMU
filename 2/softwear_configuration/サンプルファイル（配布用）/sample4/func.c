#include <stdio.h>
    
void func1(void)
{
    extern int a;
    a = 20;
    printf("a = %d\n", a);
}

