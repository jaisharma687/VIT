# include <stdio.h>
# include <string.h>
int main(){
    // char name[11];
    // scanf("%10s",name);
    // printf("%10s",name);

    // char LastName[11];
    // char FirstName[11];
    // printf("Enter your name (last , first): ");
    // scanf("%10s%*[^,],%10s", LastName, FirstName);
    // printf("Nice to meet you %s %s\n", FirstName, LastName);
    // return 0;

    char s1[10];
    char s2[10];
    gets(s1); 
    puts(s1);
    strcpy(s2,s1);
    puts(s2);
    return 0;
}