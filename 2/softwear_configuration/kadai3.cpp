/*問題 3：stdlib.h の qsort 関数など，標準ライブラリに含まれているソート関数では，
2 つの変数を比較するための関数を定義することにより，並べ替えの基準を自由に設定
することができる．独自の比較関数を定義し，並べ替えを実行した例を示しなさい．並
べ替える変数は構造体など何でもよい．*/

#include <stdlib.h>
#include<iostream>

using namespace std;

int comp( const void* lhs, const void* rhs ) {
    return *(char*)lhs - *(char*)rhs;
}

typedef struct {
    char s;
} test;

int main() {
    // 構造体を要素とする配列を作成
    test array[] = {
        {'e'},
        {'a'},
        {'k'},
        {'y'},
        {'u'}
    };

    size_t array_size = sizeof(array) / sizeof(array[0]);

    qsort(array, array_size, sizeof(test), comp);

    for (size_t i = 0; i < array_size; ++i) {
        printf("%c ", array[i].s);
    }
    return 0;
}