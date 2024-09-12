# include <stdio.h>

int main()
{
    char str[100];
    char *ptr;
    ptr = str;
    fgets(str,sizeof(str),stdin);
    while(*ptr!='\0')
    {
        printf("%c",*ptr);
        *ptr++;
    }
    return 0;
}