# include <stdio.h>
# include <string.h>

int Ispalindrome(char* str)
{
    int i, len;
    len = strlen(str);
    for(i = 0; i < len / 2; i++)
    {
        if( *(str +i ) != *(str + len - i - 1) ) 
        return 0; 
    }
    return 1;
}

int main()
{
    char string[20];
    printf("Enter the string ::");
    fgets(string, sizeof(string), stdin);
    if (string[strlen(string) - 1] == '\n') 
    {
        string[strlen(string) - 1] = '\0';
    }
    if( Ispalindrome(string))
        printf("%s is a palindrome\n", string);
    else
        printf("\n%s is not a palindrome\n" ,string);
    return 0;
}