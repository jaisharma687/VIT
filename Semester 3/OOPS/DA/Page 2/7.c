# include <stdio.h>

struct details
{
    char name[30];
    int marks[5];
    int total;
    float percentage;
};

int main()
{
    struct details std;
    struct details *ptr;
    ptr = &std;
    printf("Enter the name: ");
    scanf("%s",ptr->name);
    ptr->total =0;
    for(int i=0;i<5;i++)
    {
        printf("Enter marks of sunject %d: ",i+1);
        scanf("%d",&ptr->marks[i]);
        ptr->total += ptr->marks[i];
    }
    ptr->percentage = (float)(ptr->total/5);
    printf("Name: %s\n",ptr->name);
    for (int i = 0; i < 5; i++)
        printf("Marks for subject %d are %d\n",i+1,ptr->marks[i]);
    printf("Total: %d\nPercentage: %.2f",ptr->total,ptr->percentage);
    return 0;
}