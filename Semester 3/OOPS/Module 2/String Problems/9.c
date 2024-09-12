# include <stdio.h>

int main()
{
    char str[100];
    fgets(str, sizeof(str), stdin);
    int vowels=0;
    int consonants=0;
    for (int i = 0; str[i] != '\0'; i++) 
    {
        char ch = str[i];
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) 
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' 
            ||ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') 
            {
                vowels++;
            } 
            else 
            {
                consonants++;
            }
        }
    }
    printf("Number vowels and consonants are: %d %d " , vowels,consonants);
    return 0;
}