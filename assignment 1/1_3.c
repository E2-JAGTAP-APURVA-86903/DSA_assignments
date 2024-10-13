#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5
#define SWAP(a, b)        \
    {                     \
        Student temp = a; \
        a = b;            \
        b = temp;         \
    }

typedef struct
{
    int rollno;
    char name[50];
    float marks;
} Student;

void disp_students(Student arr[SIZE]);
void bubble_sort_students_by_marks(Student arr[SIZE]);

int main()
{
    Student students[SIZE] = {

        {1, "apurva", 10},
        {2, "aalisha", 20},
        {1, "aapeksha", 30},
        {1, "purva", 40},
        {1, "divya", 10},

    };

    printf("\n Before sorting by marks:\n");
    disp_students(students);

    // Sorting students using bubble sort according to their marks
    bubble_sort_students_by_marks(students);

    printf("\n After sorting by marks:\n");
    disp_students(students);

    return 0;
}
// Bubble sort function to sort students by marks
void bubble_sort_students_by_marks(Student arr[SIZE])
{
    int i, pos;
    for (i = 0; i < SIZE - 1; i++)
    {
        for (pos = 0; pos < SIZE - 1 - i; pos++)
        {
            if (arr[pos].marks > arr[pos + 1].marks)
            {
                SWAP(arr[pos], arr[pos + 1]);
            }
        }
    }
}
void disp_students(Student arr[SIZE])
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("Roll No: %d \n Name: %s\n Marks:%.2f\n", arr[i].rollno, arr[i].name, arr[i].marks);
    }
    printf("\n");
}