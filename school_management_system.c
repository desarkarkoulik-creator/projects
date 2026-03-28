 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of students
#define MAX_STUDENTS 100

// Structure to store student details
struct Student {
    char firstName[50];
    char lastName[50];
    int rollNumber;
    float gpa;
    int courseIds[5];
} students[MAX_STUDENTS];

int studentCount = 0;

// Function to add student details
void addStudent() {
    printf("Add Student Details\n");
    printf("-------------------\n");
    printf("Enter First Name: ");
    scanf("%s", students[studentCount].firstName);
    printf("Enter Last Name: ");
    scanf("%s", students[studentCount].lastName);
    printf("Enter Roll Number: ");
    scanf("%d", &students[studentCount].rollNumber);
    printf("Enter GPA: ");
    scanf("%f", &students[studentCount].gpa);
    printf("Enter 5 Course IDs: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &students[studentCount].courseIds[i]);
    }
    studentCount++;
    printf("Student added successfully!\n");
}

// Function to find student by roll number
void findByRollNumber() {
    int roll;
    printf("Enter Roll Number to find: ");
    scanf("%d", &roll);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            printf("Student Found:\n");
            printf("First Name: %s\n", students[i].firstName);
            printf("Last Name: %s\n", students[i].lastName);
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("GPA: %.2f\n", students[i].gpa);
            printf("Courses: ");
            for (int j = 0; j < 5; j++) {
                printf("%d ", students[i].courseIds[j]);
            }
            printf("\n");
            return;
        }
    }
    printf("Student with roll number %d not found.\n", roll);
}

// Function to find student by first name
void findByFirstName() {
    char name[50];
    printf("Enter First Name to find: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].firstName, name) == 0) {
            printf("Student Found:\n");
            printf("First Name: %s\n", students[i].firstName);
            printf("Last Name: %s\n", students[i].lastName);
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("GPA: %.2f\n", students[i].gpa);
            printf("\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No student found with first name %s.\n", name);
    }
}

// Function to find students registered in a course
void findByCourse() {
    int courseId;
    printf("Enter Course ID: ");
    scanf("%d", &courseId);
    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        for (int j = 0; j < 5; j++) {
            if (students[i].courseIds[j] == courseId) {
                printf("Student Found: %s %s (Roll: %d)\n", students[i].firstName, students[i].lastName, students[i].rollNumber);
                found = 1;
                break;
            }
        }
    }
    if (!found) {
        printf("No students registered for course %d.\n", courseId);
    }
}

// Function to count total students
void countStudents() {
    printf("Total number of students: %d\n", studentCount);
    printf("Maximum capacity: %d\n", MAX_STUDENTS);
}

// Function to delete a student by roll number
void deleteStudent() {
    int roll;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student with roll number %d deleted successfully.\n", roll);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", roll);
}

// Function to update student details
void updateStudent() {
    int roll;
    printf("Enter Roll Number to update: ");
    scanf("%d", &roll);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            printf("Updating student %s %s...\n", students[i].firstName, students[i].lastName);
            printf("1. Update First Name\n2. Update Last Name\n3. Update GPA\n4. Update Courses\n");
            int choice;
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    printf("Enter New First Name: ");
                    scanf("%s", students[i].firstName);
                    break;
                case 2:
                    printf("Enter New Last Name: ");
                    scanf("%s", students[i].lastName);
                    break;
                case 3:
                    printf("Enter New GPA: ");
                    scanf("%f", &students[i].gpa);
                    break;
                case 4:
                    printf("Enter 5 New Course IDs: ");
                    for (int j = 0; j < 5; j++) {
                        scanf("%d", &students[i].courseIds[j]);
                    }
                    break;
                default:
                    printf("Invalid choice.\n");
            }
            printf("Student updated successfully.\n");
            return;
        }
    }
    printf("Student with roll number %d not found.\n", roll);
}

int main() {
    int choice;
    while (1) {
        printf("\n--- School Management System ---\n");
        printf("1. Add Student Details\n");
        printf("2. Find Student by Roll Number\n");
        printf("3. Find Student by First Name\n");
        printf("4. Find Students in Course\n");
        printf("5. Count Total Students\n");
        printf("6. Delete Student\n");
        printf("7. Update Student\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: findByRollNumber(); break;
            case 3: findByFirstName(); break;
            case 4: findByCourse(); break;
            case 5: countStudents(); break;
            case 6: deleteStudent(); break;
            case 7: updateStudent(); break;
            case 8: exit(0);
            default: printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
