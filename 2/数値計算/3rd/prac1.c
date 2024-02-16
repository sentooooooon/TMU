#include<stdio.h>
#include <stdlib.h>
int main() {
 int a,b;
 int *p;
 int c[3] = {10,11,12};
 a = 2;
 b = 3;
 p = &a;
 printf( "a = %d, b = %d, *p = %d\n", a, b, *p );
 b = *p;
 printf( "a = %d, b = %d, *p = %d\n", a, b, *p );
*p = 4;
 printf( "a = %d, b = %d, *p = %d\n", a, b, *p );
p = malloc( sizeof(int));
 *p = b; b = 5;
 printf( "a = %d, b = %d, *p = %d\n", a, b, *p );
 free(p); p = &c[1];
 printf( "p[1] = %d\n", p[1] );
}
