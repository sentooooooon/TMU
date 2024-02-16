#include <stdio.h>
#include <stdlib.h>


int *malloc_vector(int len)
{
    int *p;
    p = (int *)malloc(sizeof(int) * len);
    if (p == NULL)
    {
        fprintf(stderr, "error\n");
        exit(1);
    }

    for (int i = 0; i < len; i++)
    {
        p[i] = 0;
    }

        return p;
}
int **malloc_matrix(int row, int col)
{
    int **p;
    p = (int **)malloc(sizeof(int *) * row);
    if (p == NULL)
    {
        fprintf(stderr, "error\n");
        exit(1);
    }
    for (int i = 0; i < row; i++)
    {
        if ((p[i] = (int *)malloc(sizeof(int) * col)) == NULL)
        {
            fprintf(stderr, "error\n");
            exit(1);
        }
        for (int j = 0; j < col; j++)
        {
            p[i][j] = 0;
        }
    }
    return p;
}

void print_vector(int* p, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\t", p[i]);
    }
    printf("\n");
    printf("\n");
}

void print_matrix(int** p, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
}