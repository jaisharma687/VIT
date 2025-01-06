# include <stdio.h>
# include <stdlib.h>

struct poly
{
    int expo;
    int coeff;
    struct poly *next;
};
struct poly *head,*head1,*head2,*newpoly,*temp,*traverse1,*traverse2;

void inputadd(int exp,int coef)
{   
    newpoly = (struct poly *)malloc(sizeof(struct poly));
    newpoly->expo = exp;
    newpoly->coeff = coef;
    newpoly->next = 0;
    if(head==0)
    {
        head = temp = newpoly;
    }
    else
    {
        temp->next = newpoly;
        temp = newpoly;
    }        
}

int main()
{
    head1 = 0;
    head2 = 0;
    head = 0;
    int n,m;
    // printf("Enter the value of n:\n");
    scanf("%d",&n);
    while(n>0)
    {
        newpoly = (struct poly *)malloc(sizeof(struct poly));
        // printf("Enter the value of expo and coeff:\n");
        scanf("%d %d",&newpoly->expo,&newpoly->coeff);
        newpoly->next = 0;
        if(head1==0)
        {
            head1 = temp = newpoly;
        }
        else
        {
            temp->next = newpoly;
            temp = newpoly;
        }
        n--;
    }
    // printf("Enter the value of m:\n");
    scanf("%d",&m);
    while(m>0)
    {
        newpoly = (struct poly *)malloc(sizeof(struct poly));
        // printf("Enter the value of expo and coeff:\n");
        scanf("%d %d",&newpoly->expo,&newpoly->coeff);
        newpoly->next = 0;
        if(head2==0)
        {
            head2 = temp = newpoly;
        }
        else
        {
            temp->next = newpoly;
            temp = newpoly;
        }
        m--;
    }
    traverse1 = head1;
    traverse2 = head2;
    while(traverse1!=0 && traverse2!=0)
    {
        if(traverse1->expo == traverse2->expo)
        {
            inputadd(traverse1->expo,traverse1->coeff+traverse2->coeff);
            traverse1=traverse1->next;
            traverse2=traverse2->next;
        }
        else if(traverse1->expo > traverse2->expo)
        {
            inputadd(traverse1->expo,traverse1->coeff);
            traverse1=traverse1->next;
        }
        else
        {   
            inputadd(traverse2->expo,traverse2->coeff);
            traverse2=traverse2->next;
        }
    }
    while (traverse1 != 0)
    {
        inputadd(traverse1->expo, traverse1->coeff);
        traverse1 = traverse1->next;
    }
    while (traverse2 != 0)
    {
        inputadd(traverse2->expo, traverse2->coeff);
        traverse2 = traverse2->next;
    }
    // printf("\nPoly add is:\n");
    temp = head;
    while(temp!=0)
    {
        printf("%d %d\n",temp->expo,temp->coeff);
        temp = temp->next;
    }
    return 0;
}