#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxstudent 60
struct student
{
    int rollNo;
    char name[50];
    float marks;
};

// making function for display students
void display(struct student students[], int count)
{
    printf("\nList of Students:\n");
    for (int i = 0; i < count; i++)
    {
        printf("Roll no: %d,  Name: %s,  Marks:%.2f\n", students[i].rollNo, students[i].name, students[i].marks);
    }
}
// agar marks update karna hoto
void updatemarks(struct student students[], int count, int rollNo, float newmarks)
{
    for (int i = 0; i < count; i++)
    {
        if (students[i].rollNo == rollNo)
        {
            students[i].marks = newmarks;
            printf("Marks updated succesfully for Roll number: %d\n", rollNo);
            return;
        }
    }
    printf("student with roll number %d not found.\n", rollNo);
}
void deletedata(struct student students[], int *count, int rollNo)
{
    int i;
    for (i = 0; i < *count; i++)
    {
        if (students[i].rollNo == rollNo)
        {
            for (int j = i; j < (*count) - 1; j++)
            {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("student with Roll No: %d deleted successfully", rollNo);
            return;
        }
    }
    printf("student with roll n0: %d not found", rollNo);
}

// for add students
void addstudent(struct student students[], int *count)
{
    if (*count < maxstudent)
    {
        printf("Enter roll no:");
        scanf("%d", &students[*count].rollNo);
        getchar();
        printf("Enter name: ");
        fgets(students[*count].name, 50, stdin);
        students[*count].name[strcspn(students[*count].name, "\n")] = '\0';
        printf("Enter marks:");
        scanf("%f", &students[*count].marks);
        (*count)++;
        printf("Student added succesfully.\n");
    }
    else
    {
        printf("Cannot add more students.Maximum limits reached.\n");
    }
}

int main()
{
    struct student students[maxstudent];
    int studentcount = 0;
    int choice, rollNo;
    float newmarks;

    while (1)
    {
        printf("\nStudent Marks Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Update Marks\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addstudent(students, &studentcount);
            break;
        case 2:
            display(students, studentcount);
            break;
        case 3:
            printf("Enter Roll no. to update marks:");
            scanf("%d", &rollNo);
            printf("enter new marks:");
            scanf("%f", &newmarks);
            updatemarks(students, studentcount, rollNo, newmarks);
            break;
        case 4:
            printf("enter roll no to delete student:");
            scanf("%d", rollNo);
            deletedata(students, &studentcount, rollNo);
            break;
        case 5:
            printf("exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice .please try again.\n");
        }
    }
    return 0;
}