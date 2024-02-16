#include <stdio.h>
#include <stdlib.h>

#define M 3
#define N 4

int *malloc_vector(int);
int **malloc_matrix(int, int);
void print_vector(int *, int);
void print_matrix(int **, int, int);

int main(void)
{
    int *p;
    int **q;

    p = malloc_vector(N);
    q = malloc_matrix(M, N);

    print_vector(p, N);
    print_matrix(q, M, N);

    printf("sizeof(int*) = %ld\n", sizeof(int *));
    printf("sizeof(int) = %ld\n", sizeof(int));
    printf("2次元配列を動的メモリ確保した場合のアドレス\n");
    printf("q = %p\n", q);
    for (int m = 0; m < M; m++)
    {
        printf("&q[%d] = %p\t", m, &q[m]);
        printf("q[%d] = %p\t", m, q[m]);
        for (int n = 0; n < N; n++)
        {
            printf("&q[%d][%d] = %p\t", m, n, &q[m][n]);
        }
        printf("\n");
    }

    int A[M][N];
    printf("2次元配列のアドレス\n");
    printf("A = %p\n", A);
    for (int m = 0; m < M; m++)
    {
        printf("&A[%d] = %p\t", m, &A[m]);
        printf("A[%d] = %p\t", m, A[m]);
        for (int n = 0; n < N; n++)
        {
            printf("&A[%d][%d] = %p\t", m, n, &A[m][n]);
        }
        printf("\n");
    }


    
}
