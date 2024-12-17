#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STUDENTS 25

int main() {
    char *studentNames[MAX_STUDENTS];
    float studentGrades[MAX_STUDENTS];
    bool dataEntered = false;

    while (true) {
        printf("1_Enter student names and grades\n");
        printf("2_Show all students and their grades\n");
        printf("3_Search for a student by name\n");
        printf("4_Compute the average grade\n");
        printf("5_Exit\n");
        printf("Choose an option (1-2-3-4-5):\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (dataEntered) {
                    printf("Data has already been entered\n");
                } else {
                    for (int i = 0; i < MAX_STUDENTS; i++) {
                        printf("Provide the name for student %d:\n", i + 1);
                        scanf("%s", studentNames[i]);
                        do {
                            printf("Provide the grade (0-20) for student %d:\n", i + 1);
                            scanf("%f", &studentGrades[i]);
                        } while (studentGrades[i] < 0 || studentGrades[i] > 20);
                        dataEntered = true;
                    }
                }
                break;

            case 2:
                if (!dataEntered) {
                    printf("No data has been entered yet\n");
                } else {
                    for (int i = 0; i < MAX_STUDENTS; i++) {
                        printf("Student: %s, Grade: %.2f\n", studentNames[i], studentGrades[i]);
                    }
                }
                break;

            case 3:
                if (!dataEntered) {
                    printf("No data has been entered yet\n");
                } else {
                    printf("Enter the name to search for:\n");
                    char searchName[50];
                    scanf("%s", searchName);
                    bool found = false;
                    for (int i = 0; i < MAX_STUDENTS; i++) {
                        if (strcmp(searchName, studentNames[i]) == 0) {
                            printf("Student: %s, Grade: %.2f\n", studentNames[i], studentGrades[i]);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Student not found\n");
                    }
                }
                break;

            case 4:
                if (!dataEntered) {
                    printf("No data has been entered yet\n");
                } else {
                    float sum = 0;
                    for (int i = 0; i < MAX_STUDENTS; i++) {
                        sum += studentGrades[i];
                    }
                    float average = sum / MAX_STUDENTS;
                    printf("The average grade is: %.2f\n", average);
                }
                break;

            case 5:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid selection. Please try again.\n");
                break;
        }
    }
}
