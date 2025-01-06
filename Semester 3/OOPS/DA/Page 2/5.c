# include <stdio.h>

struct details
{
    char name[30];
    int age;
};

int eligibility(struct details voter)
{
    if(voter.age >= 18)
        return 1;
    else
        return 0;
}

void getdetails(struct details *ptr)
{
    printf("Enter the name: ");
    scanf("%s",ptr->name);
    printf("Enter the age: ");
    scanf("%d",&ptr->age);
}

int main()
{
    struct details voter;
    struct details *p;
    p = &voter;
    getdetails(p);
    if(eligibility(*p))
        printf("Eligible to vote");
    else   
        printf("Not eligible to vote");
    return 0;
}