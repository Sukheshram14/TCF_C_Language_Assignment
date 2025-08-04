#include <stdio.h>
#define PI 3.14159

double areaCircle(float radius) {
    return PI * radius * radius;
}

int areaRectangle(int length, int breadth) {
    return length * breadth;
}

double areaTriangle(float base, float height) {
    return 0.5 * base * height;
}

int main() {
    char shape;
    printf("Choose shape (c = circle, r = rectangle, t = triangle): ");
    scanf(" %c", &shape);  // space before %c to avoid newline issue

    switch(shape) {
        case 'c': {
            float r;
            printf("Enter radius: ");
            scanf("%f", &r);
            printf("Area of circle: %.2lf\n", areaCircle(r));
            break;
        }
        case 'r': {
            int l, b;
            printf("Enter length and breadth: ");
            scanf("%d %d", &l, &b);
            printf("Area of rectangle: %d\n", areaRectangle(l, b));
            break;
        }
        case 't': {
            float base, height;
            printf("Enter base and height: ");
            scanf("%f %f", &base, &height);
            printf("Area of triangle: %.2lf\n", areaTriangle(base, height));
            break;
        }
        default:
            printf("Invalid shape selected.\n");
    }

    return 0;
}
