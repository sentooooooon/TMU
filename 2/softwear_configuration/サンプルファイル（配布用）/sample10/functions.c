#include <stdio.h>

int sum_function(int (* func)(int), int n1, int n2)
{
    int sum_out = 0;
    for (int n = n1; n <= n2; n++)
    {   
        sum_out += func(n);
    }
    return sum_out;
}

// 整数の2乗を返す
int function1(int n)
{
    return n * n;
}

// そのままを返す
int function2(int n)
{
    return n;
}