#include <stdio.h>
#include <stdlib.h>
#define N 10

int main()
{
    int a[N];
    for (int n = 0; n < N; n++)
    {
        a[n] = (n + 1) * (n + 1);
        printf("a[n] = %d\t *(a + n) = %d\n", a[n], *(a + n));
    }
    
    int* p = a;
    for (int n = 0; n < N; n++)
    {
        printf("%p \t %d\n", p, *p);
        p += 1;
    }
    
}