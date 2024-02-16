#include <stdio.h>

int a_plus_b1(int, int);
int a_plus_b2(int, int, int*);

int main()
{
    int a = 1;
    int b = 2;
    int c;
    
    printf("%d + %d = %d\n", a, b, a_plus_b1(a, b));

    a_plus_b2(a, b, &c);
    printf("%d + %d = %d\n", a, b, c);
}