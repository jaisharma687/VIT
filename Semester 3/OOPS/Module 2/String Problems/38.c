# include <stdio.h>
# include <ctype.h>
# include <string.h>

int main()
{
    char str1[100];
    char vowels[100];
    int v=0;
    int index[100];
    fgets(str1, sizeof(str1), stdin);
    for(int i=0;i<strlen(str1);i++)
    {
        
        if(isalpha(str1[i]))
        {
            if (str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u' 
            ||str1[i] == 'A' || str1[i] == 'E' || str1[i] == 'I' || str1[i] == 'O' || str1[i] == 'U') 
            {
                vowels[v] = str1[i];
                index[v] = i;
                v++;
            }
        }
    }
    for(int i=0;i<v;i++)
    {
        int t = index[i];
        str1[t] = vowels[v-i-1];
    }
    printf("%s",str1);
    return 0;
}