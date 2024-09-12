# include <stdio.h>

struct ptr
{
    char a;
    int b;
    float c;
};

int main()
{
    struct ptr element;
    struct ptr *p;
    p = &element;
    printf("Enter a: ");
    scanf("%c",&p->a);
    printf("Enter b: ");
    scanf("%d",&p->b);
    printf("Enter c: ");
    scanf("%f",&p->c);
    printf("a: %c\nb: %d\nc: %.3f",p->a,p->b,p->c);
    return 0;
}