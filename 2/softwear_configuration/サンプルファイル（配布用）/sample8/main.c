#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(void)
{

    int a[N];
    int *b;
    
    // メモリの確保
    b = (int *)malloc(sizeof(int) * N);
    

    // メモリを確保できなければ終了
    if(b == NULL)
    {
        fprintf(stderr, "Memory Allocation Error");
        exit(1);
    }

    for (int n = 0; n < N; n++)
    {
        a[n] = n;
        b[n] = n;
    }
    for (int n = 0; n < N; n++)
    {
        printf("%p\t%d\n", a + n, a[n]);
    }
    printf("\n");
    for (int n = 0; n < N; n++)
    {
        printf("%p\t%d\n", b + n, b[n]);
    }
    // メモリの解放
    free(b);
}
