# include <stdio.h>

int main()
{
    int a = 50;
    int *p1;
    p1 = &a;
    printf("%d\n",sizeof(p1));
    float b = 2.39;
    float *p2;
    p2 = &b;
    printf("%d\n",sizeof(p2));
    double c = 9.394021;
    double *p3;
    p3 = &c;
    printf("%d\n",sizeof(p3));
    char d = 'h';
    char *p4;
    p4 = &d;
    printf("%d\n",sizeof(p4));
    char e[] = "hello";
    char *p5;
    p5 = e;
    printf("%d\n",sizeof(p5));
    long int f = 54555;
    long int *p6;
    p6 = &f;
    printf("%d\n",sizeof(p6));
    long long int g = 546885164;
    long long int *p7;
    p7 = &g;
    printf("%d\n",sizeof(p7));
    return 0;
}