# include <stdio.h>

int main()
{
    char n[9],c[9],b[10];
    int carry = 1;
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
    for(int i=7;i>=0;i--)
    {   
        if(carry == 0)
        {
            b[i] = c[i];
        }
        else if(c[i]=='0' && carry == 1)
        {
            b[i] = '1';
            carry = 0;
        }
        else if(c[i]=='1' && carry == 1)
        {
            b[i] = '0';
        }
    }
    if(carry == 1)
    {   
        for(int i=7;i>=0;i--)
        {
            b[i+1] = b[i];
        }
        b[0] = '1';
    }
    printf("\n");
    for(int i=0;i<9;i++)
    {
        printf("%c",(int)b[i]);
    }
    return 0;
}