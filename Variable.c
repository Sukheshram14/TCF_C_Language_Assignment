#include <stdio.h>

int main() {
    int a = 10, b = 20, temp;

    printf("Before swap:\n");
    printf("a = %d, b = %d\n", a, b);

    // Swap logic
    temp = a;
    a = b;
    b = temp;

    printf("After swap:\n");
    printf("a = %d, b = %d\n", a, b);

    return 0;
}
