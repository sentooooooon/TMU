#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    // a.out int a double b char* c の場合
    if(argc != 4)
    {
        fprintf(stderr, "usage: a.out int a double b char *c\n");
        exit(1);
    }

    // gcc -D STRTO main.c でコンパイルする場合
    #if STRTO
    printf("strtol. strtodを使用\n");
    // ptr1, ptr2には変換できなかった文字が出力される．
    char *ptr1;
    char *ptr2;
    
    // 3つ目の引数は基数　
    // a.out 13 3.0 a -> a は10進数
    // a.out 015 3.0 a -> a は8進数
    // a.out 0xD 3.0 a -> a は8進数
    int a = strtol(argv[1],&ptr1,0);
    double b = strtod(argv[2],&ptr2);
    char *c = argv[3];
    printf("%s\n", ptr1);
    printf("%s\n", ptr2);

    // gcc main.c でコンパイルする場合
    #else
    printf("atoi, atofを使用\n");
    int a = atoi(argv[1]);
    double b = atof(argv[2]);
    char *c = argv[3];

    #endif
    printf("%s\n", argv[0]);
    printf("%d\n", a);
    printf("%f\n", b);
    printf("%s\n", c);

    exit(0);
}
