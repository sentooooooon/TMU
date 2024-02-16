#include <stdio.h>
    
static void func3(void)
{
    static int c = 0;
    int d = 0;

    c += 100;
    d += 100;
    printf("c = %d\t d = %d\n", c, d);
}
void func4(void)
{
    func3();
}