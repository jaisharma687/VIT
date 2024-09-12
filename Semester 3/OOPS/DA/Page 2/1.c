# include <stdio.h>

struct ptr
{
    int a;
    char b;
    float c;
};

int main()
{
    struct ptr *p;
    p->a = 123;
    p->b = 'A';
    p->c = 15.456;
    printf("a: %i\nb: %c\nc: %.4f",p->a,p->b,p->c);
    return 0;
}