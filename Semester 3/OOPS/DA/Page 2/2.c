# include <stdio.h>

struct employee 
{
    char name[30];
    int id;
    int salary;
};

int main()
{
    struct employee emp;
    struct employee *ptr;
    ptr = &emp;
    printf("Enter the name: ");
    scanf("%s",ptr->name);
    printf("Enter the ID number: ");
    scanf("%d",&ptr->id);
    printf("Enter the Salary: ");
    scanf("%d",&ptr->salary);
    printf("Name: %s\nID: %d\nSalary: %d",ptr->name,ptr->id,ptr->salary);
    return 0;
}