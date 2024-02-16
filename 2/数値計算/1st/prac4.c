#include <stdio.h>

int main() {
    int sum = 0;

    while (1) {
        float a;
        scanf("%f", &a);

        if ((int)a == a) {
            sum += a;
        }
        if (a == 0) {
            break;
        }
        if((int)a != a){
            printf("%d", sum);
        }
    }

    return 0;
}
