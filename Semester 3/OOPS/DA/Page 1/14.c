# include <stdio.h>
# include <stdlib.h>

int main()
{
    int *a;
    char *b;
    float *c;
    a = (int *)malloc(sizeof(int));
    b = (char *)malloc(sizeof(char));
    c = (float *)malloc(sizeof(float));
    *a = 14;
    *b = 'c';
    *c = 14.556;
    printf("Int: %i\nChar: %c\nFloat: %f",*a,*b,*c);
    free(a);
    free(b);
    free(c);
    return 0;
}