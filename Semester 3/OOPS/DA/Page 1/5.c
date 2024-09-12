# include <stdio.h>
# include <ctype.h>

int main(){
    char str[100];
    char *ptr;
    ptr = str;
    fgets(str,sizeof(str),stdin);
    int vowels = 0;
    int consonants = 0;
    while(*ptr!='\0'){
        char c = tolower(*ptr);
        if(isalpha(c))
        {
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
                vowels++;
            else
                consonants++;
        }
        ptr++;
    }
    printf("Number of vowels and consonants are: %d & %d",vowels,consonants);
    return 0;
}