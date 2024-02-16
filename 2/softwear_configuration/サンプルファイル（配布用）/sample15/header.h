#ifndef HEADER_H
#define HEADER_H
typedef enum vartype { 
    CHAR =100,
    INT,
    FLOAT,
    DOUBLE
} VARTYPE;

typedef union example_union
{
    char c;
    int i;
    float f;
    double d;
    

} EXAMPLE_U;

// 比較用
typedef union example_union2
{
    char c;
    int i;
    float f;

} EXAMPLE_U2;

typedef struct example_struct
{
    VARTYPE t;
    EXAMPLE_U v;

} EXAMPLE_S;

void print_example(EXAMPLE_S);

#endif

