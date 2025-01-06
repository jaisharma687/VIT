# include <stdio.h>
int main()
{
    char n[9],c[9];
    scanf("%[^\n]%*c",n);
    for(int i=0;i<8;i++)
    {
        printf("%c",(int)n[i]);
    }
    for(int i = 0; i<8 ; i++)
    {
        if(n[i]=='0')
        {
            c[i]='1';
        }
        else if(n[i]=='1')
        {
            c[i]='0';
        }
        else
        {
            printf("Not a binary number");
        }
    }
    printf("\n");
    for(int i=0;i<8;i++)
    {
        printf("%c",(int)c[i]);
    }
}