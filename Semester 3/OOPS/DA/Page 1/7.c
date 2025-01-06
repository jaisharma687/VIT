# include <stdio.h>

struct stud 
{
    char name[30];
    int roll;
    char grade;
};

int main()
{
    struct stud student;
    struct stud *ptr;
    ptr = &student;
    fgets(ptr->name,sizeof(ptr->name),stdin);
    ptr->roll = 145;
    ptr->grade = 'C';
    printf("Name: %sRoll: %d\nGrade: %c",ptr->name,ptr->roll,ptr->grade);
    return 0;
}