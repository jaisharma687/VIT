# include <stdio.h>

struct st1
{
    struct st2
    {
        int a;
        char b;
    }s;
    int c;
    char d;
};

int main()
{
    struct st1 p1;
    p1.d = 'H';
    p1.c = 45;
    p1.s.a = 49;
    p1.s.b = 's';
    printf("a: %d\nb: %c\nc: %d\nd: %c",p1.s.a,p1.s.b,p1.c,p1.d);
    return 0;
}