#include <stdio.h>


void func3(void)
{
    static int a = 0;
    int b = 0;

    a += 200;
    b += 200;
    printf("a = %d\t b = %d\n", a, b);
}
void func4(void);

int main(void)
{
    func3();
    func3();
    func4();
    func4();
}
