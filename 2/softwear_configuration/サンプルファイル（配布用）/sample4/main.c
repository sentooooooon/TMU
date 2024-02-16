#include <stdio.h>

int a = 10;
void func1(void);

int main(void)
{

    printf("a = %d\n", a);
    func1();
    printf("a = %d\n", a);

}
