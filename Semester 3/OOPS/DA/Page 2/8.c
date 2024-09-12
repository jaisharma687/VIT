# include <stdio.h>

struct dist
{
    int feets;
    int inches;
};

void getinput(struct dist *d)
{
    printf("Enter the distance : ");
    scanf("%d %d",&d->feets,&d->inches);
}

void addition(struct dist *d1, struct dist *d2,struct dist *d3)
{
    d3->feets = d1->feets + d2->feets;
    d3->inches = d1->inches + d2->inches;
    if (d3->inches >= 12)
    {
        d3->feets += d3->inches / 12;
        d3->inches = d3->inches % 12;
    }
}

int main()
{
    struct dist d1, d2,d3;
    getinput(&d1);
    getinput(&d2);
    addition(&d1,&d2,&d3);
    printf("For Distance 1: %d feets %d inches\n",d1.feets,d1.inches);
    printf("For Distance 2: %d feets %d inches\n",d2.feets,d2.inches);
    printf("For Distance 3: %d feets %d inches\n",d3.feets,d3.inches);
    return 0;
}