#include <stdio.h>
#include <stdlib.h>
#define N 10
int comparison1(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    return x - y;
}

int comparison2(const void *a, const void *b)
{
    char x = *(char *)a;
    char y = *(char *)b;

    return (int)(x - y);
}

int main(void)
{
    int a[] = {15, 3, 1, 10, 2, 81, 9, 4, 62, 8};
    char b[] = {'a', 'x', 'U', '9', 'Z', 'j', 'o', '!', 'B', 'n'};

    for (int n = 0; n < N; n++)
    {
        printf("%d\t", a[n]);
    }
    printf("\n");
    qsort(a, N, sizeof(int), comparison1);

    for (int n = 0; n < N; n++)
    {
        printf("%d\t", a[n]);
    }
    printf("\n");

    for (int n = 0; n < N; n++)
    {
        printf("%c\t", b[n]);
    }
    printf("\n");
    qsort(b, N, sizeof(char), comparison2);

    for (int n = 0; n < N; n++)
    {
        printf("%c\t", b[n]);
    }
    printf("\n");

}
