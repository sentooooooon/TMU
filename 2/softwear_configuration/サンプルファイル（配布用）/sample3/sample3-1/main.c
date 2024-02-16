#include <stdio.h>

void swap_a_b1(int, int);
void swap_a_b2(int *, int *);

int main()
{
    int a = 1;
    int b = 2;

    
    printf("a = %d\t b = %d\n", a, b);
    printf("swap_a_b1\n");
    swap_a_b1(a, b);
    printf("a = %d\t b = %d\n", a, b);
    printf("\n");

    printf("a = %d\t b = %d\n", a, b);
    printf("swap_a_b2\n");
    swap_a_b2(&a, &b);
    printf("a = %d\t b = %d\n", a, b);
}