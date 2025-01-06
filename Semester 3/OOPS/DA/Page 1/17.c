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
    struct studentdetails *ptr;
    ptr = (struct studentdetails *)malloc(sizeof(struct studentdetails));
    printf("Enter the name:\n");
    scanf("%[^\n]s",ptr->name);
    printf("Enter the roll number:\n");
    scanf("%d",&ptr->roll);
    printf("Enter the grade:\n");
    scanf("%s",&ptr->grades);
    printf("Name: %s\nRoll Number: %d\nGrade: %c",ptr->name,ptr->roll,ptr->grades);
    return 0;
}