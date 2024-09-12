# include <stdio.h>
# include <stdlib.h>

struct poly
{
    int coeff;
    int expo;
    struct poly*next;
};

struct poly *head1,*head2,*head3,*temp,*newpoly;

struct poly * insert(int coeff, int expo, struct poly *x)
{
    newpoly = (struct poly *)malloc(sizeof(struct poly));
    newpoly->expo = expo;
    newpoly->coeff = coeff;
    newpoly->next = NULL;
    if(x==0)
        temp = x = newpoly;
    else
    {
        temp->next = newpoly;
        temp = newpoly;
    }
    return x;
}

struct poly *create(struct poly *x)
{
    int n;
    printf("Enter number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int coeff;
        int expo;
        scanf("%d %d",&coeff,&expo);
        x = insert(coeff,expo,x);
    }
    return x;
}

struct poly *polyadd(struct poly *x1, struct poly *x2)
{
    struct poly *result=NULL, *temp1,*temp2;
    temp1 = head1;
    temp2 = head2;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->expo>temp2->expo)
        {
            result = insert(temp1->coeff,temp1->expo,result);
            temp1 = temp1->next;
        }
        else if(temp1->expo<temp2->expo)
        {
            result = insert(temp2->coeff,temp2->expo,result);
            temp2 = temp2->next;
        }
        else
        {
            result = insert(temp1->coeff+temp2->coeff,temp2->expo,result);
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
    }
    return result;
}

void display(struct poly * x)
{
    temp = x;
    while(temp!=NULL)
    {
        printf("%d.x^%d ",temp->coeff,temp->expo);
        temp = temp->next;
        if(temp!=NULL)
            printf("+ ");
        else
            printf("\n");
    }
}

int main()
{
    head1 = NULL;
    head1 = create(head1);
    display(head1);
    head2 = NULL;
    head2 = create(head2);
    display(head2);
    head3 = NULL;
    head3 = polyadd(head1,head2);
    display(head3);
    return 0;
}