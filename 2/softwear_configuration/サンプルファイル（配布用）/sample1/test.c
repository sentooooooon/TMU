#include <stdio.h>


int main()
{
  int x[5];
  int a = 5;
  int b[2];
  char c[] = "Takahiro Matsuda";


  // 変数のサイズ
    printf("sizeof(char) = %d\t", sizeof(char));
    printf("sizeof(int) = %d\t", sizeof(int));
    printf("sizeof(float) = %d\t", sizeof(float));
    printf("sizeof(double) = %d\n", sizeof(double));

    // 配列xのアドレス
    for (int i = 0; i < 5; i++)
    {
      printf("&x[%d] = %p\n", i, &x[i]);
    }
      // 文字列cのサイズ
      printf("sizeof(c) = %d\n", sizeof(c));
    int M = sizeof(c) / sizeof(char);

    // 文字列(char型は1バイト)
    printf("%s\n", c);

    for (int i = 0; i < M; i++)
    {
        printf("%d\t %c\t %d\n", i, c[i], c[i]);
    }
    printf("\n");

    printf("a = %d\n", a);
    printf("&a = %p\n", &a);
    
    // 初期化していない状態
    printf("b[0] = %d\n", b[0]);
    printf("b[1] = %d\n", b[1]);
    
    b[0] = 1;
    b[1] = 3;
    // 初期化後
    printf("b[0] = %d\n", b[0]);
    printf("b[1] = %d\n", b[1]);

    // ポインタbに格納されている値
    printf("*b = %d\n", *b);
    
    // ポインタb + 1に格納されている値
    printf("*(b + 1) = %d\n", *(b + 1));
    
    //ポインタbの値＝b[0]のアドレス
    printf("b = %p\t &b[0] = %p\n", b, &b[0]);
    //ポインタb+1の値＝b[1]のアドレス
    printf("b + 1= %p\t &b[1] = %p\n", b + 1, &b[1]);
    
  

   

    
}