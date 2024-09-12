# include <stdio.h>
# include <stdlib.h>

struct studentdetails
{
    char name[30];
    int roll;
    char grades;
};

int main()
{
    int n;
    printf("Enter the number of students(N):\n");
    scanf("%d",&n);
    struct studentdetails *ptr;
    ptr = (struct studentdetails *)malloc(n*sizeof(struct studentdetails));
    for(int i=0;i<n;i++)
    {
        printf("Enter the name of student %d: ",i+1);
        scanf("%s",(ptr+i)->name);
        printf("Enter the roll number of student %d: ",i+1);
        scanf("%d",&(ptr+i)->roll);
        printf("Enter the grade of student %d: ",i+1);
        scanf("%s",&(ptr+i)->grades);
    }
    for(int i=0;i<n;i++)
        printf("Name: %s\nRoll Number: %d\nGrade: %c\n",(ptr+i)->name,(ptr+i)->roll,(ptr+i)->grades);
    return 0;
}