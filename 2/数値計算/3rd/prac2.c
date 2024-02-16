#include <stdio.h>
#include <ctype.h>

void func(char *p) {
    while (*p) {
        *p = toupper(*p);
        putchar(*p);
        p++;
    }
}

int main() {
    char s[] = "abcd";
    func(s);
    return 0;
}
