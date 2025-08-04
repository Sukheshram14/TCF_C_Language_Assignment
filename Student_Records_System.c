#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int marks[5];
    float average;
};

void inputStudents(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);

        printf("Name: ");
        scanf(" %[^\n]", students[i].name);

        printf("Enter 5 marks: ");
        for (int j = 0; j < 5; j++) {
            scanf("%d", &students[i].marks[j]);
        }

        calculateAverage(&students[i]);
    }
}

void calculateAverage(struct Student *s) {
    int total = 0;
    for (int j = 0; j < 5; j++) {
        total += s->marks[j];
    }
    s->average = total / 5.0;
}

void displayTopper(struct Student students[], int n) {
    int topper = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].average > students[topper].average) {
            topper = i;
        }
    }

    printf("\nTopper Student:\n");
    printf("ID: %d\n", students[topper].id);
    printf("Name: %s\n", students[topper].name);
    printf("Marks: ");
    for (int j = 0; j < 5; j++) {
        printf("%d ", students[topper].marks[j]);
    }
    printf("\nAverage: %.2f\n", students[topper].average);
}

int main() {
    int n = 5;
    struct Student students[5];

    inputStudents(students, n);
    displayTopper(students, n);

    return 0;
}
