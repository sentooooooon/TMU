#include <stdio.h>

#define M 3
#define N 4

int main(void)
{

    int A[M][N];

    for (int m = 0; m < M; m++)
    {
        for (int n = 0; n < N; n++)
        {
            A[m][n] = m * N + n + 1;
        }
    }

    
    for (int m = 0; m < M; m++)
    {
        for (int n = 0; n < N; n++)
        {
            printf("%2d ", A[m][n]);
        }
        printf("\n");
    }

    printf("%p\n", A);
    for (int m = 0; m < M; m++)
    {
        for (int n = 0; n < N; n++)
        {
            printf("%p\t", &(A[m][n]));
        }
        printf("\n");
    }
    printf("\n");

    for (int m = 0; m < M; m++)
    {
        for (int n = 0; n < N; n++)
        {
            printf("%2d ", *(A[m] + n));
        }
        printf("\n");
    }
    
}
