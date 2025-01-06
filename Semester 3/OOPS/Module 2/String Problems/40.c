# include <stdio.h>
# include <string.h>
# include <ctype.h>

int main()
{
    char str1[100];
    fgets(str1, sizeof(str1), stdin);
    int j=0;
    for(int i=0;i<strlen(str1);i++)
    {
        if(islower(str1[i]))
        {
            str1[i] = toupper(str1[i]); 
        }
    }
    printf("%s",str1);
    return 0;
}