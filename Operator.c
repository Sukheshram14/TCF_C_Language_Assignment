#include <stdio.h>

int main() {
    char op;
    double num1, num2, result;

    // Input from user
    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter operator (+, -, *, /, %%): ");
    scanf(" %c", &op);  // Note the space before %c to consume newline

    printf("Enter second number: ");
    scanf("%lf", &num2);

    // Switch-case for operations
    switch (op) {
        case '+':
            result = num1 + num2;
            break;

        case '-':
            result = num1 - num2;
            break;

        case '*':
            result = num1 * num2;
            break;

        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Error: Division by zero is not allowed.\n");
                return 1;
            }
            break;

        case '%':
            if ((int)num2 != 0) {
                result = (int)num1 % (int)num2;
            } else {
                printf("Error: Modulo by zero is not allowed.\n");
                return 1;
            }
            break;

        default:
            printf("Error: Unsupported operator '%c'\n", op);
            return 1;
    }

    printf("Result: %.2lf\n", result);
    return 0;
}
