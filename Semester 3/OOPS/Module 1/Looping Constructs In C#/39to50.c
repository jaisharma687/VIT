# include <stdio.h>
# include <math.h>
# include <string.h>

void binary(int dec)
{   
    int bi=0;
    for(int i=0;dec!=0;i++)
    {
        int rem = dec%2;
        bi += (pow(10,i)*rem);
        dec /= 2;
    }
    printf("%d",bi);
}

void octal(int dec)
{
    int oc=0;
    for(int i=0;dec!=0;i++)
    {
        int rem = dec%8;
        oc += (pow(10,i)*rem);
        dec /= 8;
    }
    printf("%d",oc);
}

void hexadecimal(int dec)
{
    char hx[10],rhx[10];
    char hexvalue[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    for(int i=0;dec!=0;i++)
    {
        int rem = dec%16;
        rhx[i] = hexvalue[rem];
        if(dec<16)
        {
            rhx[i+1] = '\0';
        }
        dec /= 16;
    }
    for(int i=0;i<strlen(rhx);i++)
    {
        hx[i] = rhx[strlen(rhx)-i-1];
    }
    hx[strlen(rhx)] = '\0';
    printf("%s",hx);
}

void bdec(int bi)
{
    int dec = 0;
    for(int i = 0; bi!=0;i++)
    {
        int rem = bi%10;
        dec += rem*pow(2,i);
        bi/=10;
    }
    printf("%d",dec);
}

void odec(int oc)
{
    int dec = 0;
    for(int i = 0; oc!=0;i++)
    {
        int rem = oc%10;
        dec += rem*pow(8,i);
        oc/=10;
    }
    printf("%d",dec);
}

void hdec(char hx[])
{   
    int dec = 0,power=0;
    int len = strlen(hx);
    for(int i=len-1;i>=0;i--)
    {
        int rem;
        if(hx[i]>='0' && hx[i]<='9')
        {
            rem = hx[i] - '0';
        }
        else if(hx[i]>='A' && hx[i]<='F')
        {
            rem = hx[i] - 'A'+10;
        }
        dec += rem*pow(16,power);
        power++;
    }
    printf("%d",dec);
}

int main()
{
    // int n;
    // scanf("%d",&n);
    // binary(n);
    // octal(n);
    // hexadecimal(n);
    // bdec(n);
    // odec(n);
    // char n[] = "2AF\0";
    // hdec(n);
    return 0;
}