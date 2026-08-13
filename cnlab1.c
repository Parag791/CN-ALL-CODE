#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x, y;

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    printf("Before swapping: x = %d, y = %d\n", x, y);

    swap(&x, &y);

    printf("After swapping: x = %d, y = %d\n", x, y);

    return 0;
}
2.#include <stdio.h>

struct dob
{
    int day, month, year;
};

struct student_info
{
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};

void displayValue(struct student_info s)
{
    printf("\nUsing Call by Value:\n");
    printf("Roll No: %d\n", s.roll_no);
    printf("Name: %s\n", s.name);
    printf("CGPA: %.2f\n", s.CGPA);
    printf("DOB: %d/%d/%d\n",
           s.age.day, s.age.month, s.age.year);
}

void displayAddress(struct student_info *s)
{
    printf("\nUsing Call by Address:\n");
    printf("Roll No: %d\n", s->roll_no);
    printf("Name: %s\n", s->name);
    printf("CGPA: %.2f\n", s->CGPA);
    printf("DOB: %d/%d/%d\n",
           s->age.day, s->age.month, s->age.year);
}

int main()
{
    struct student_info s1;

    printf("Enter Roll No: ");
    scanf("%d", &s1.roll_no);

    printf("Enter Name: ");
    scanf("%s", s1.name);

    printf("Enter CGPA: ");
    scanf("%f", &s1.CGPA);

    printf("Enter DOB (dd mm yyyy): ");
    scanf("%d %d %d",
          &s1.age.day,
          &s1.age.month,
          &s1.age.year);

    displayValue(s1);
    displayAddress(&s1);

    return 0;
}
