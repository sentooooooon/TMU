#ifndef HEADER_H
#define HEADER_H
typedef struct example_struct {
    int a;
    char b[8];
    double c;
    int d;

} EXAMPLE;

void print_example(EXAMPLE *);

#endif

