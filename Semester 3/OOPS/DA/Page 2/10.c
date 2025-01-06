# include <stdio.h>
# include <stdlib.h>

struct fun
{
    int n1;
    int n2;
};

struct fun * takeinput()
{
    struct fun *temp = (struct fun *)malloc(sizeof(struct fun));
    printf("Enter N1: ");
    scanf("%d",&temp->n1);
    printf("Enter N2: ");
    scanf("%d",&temp->n2);
    return temp;
}

void display(struct fun *p)
{
    printf("N1: %d\nN2: %d",p->n1,p->n2);
}

int main()
{
    
    struct fun *input;
    input = takeinput();
    display(input);
    return 0;
}