#include <stdio.h>
#include <math.h>
int int_pow(int base, int exp) {
    int result = 1;
    while (exp--)
        result *= base;
    return result;
}

int main() {
    int start = 1, end = 1000;

    for (int num = start; num <= end; num++) {
        int sum = 0, temp = num, digits = 0;

        // Count digits
        while (temp != 0) {
            digits++;
            temp /= 10;
        }

        temp = num;
        while (temp != 0) {
            int digit = temp % 10;
            sum += int_pow(digit, digits);
            temp /= 10;
        }

        if (sum == num)
            printf("%d ", num);
    }

    return 0;
}
