#include <stdio.h>
#include <stdbool.h>
#define MAX 100

int main(){
    //char s[MAX] = {'a',' ','+',' ','b',' ','=',' ','c',' ','-',' ','9','\0'};// s = "a + b = c - 9"
    char s[MAX];
    printf("Enter the expression: \n");
    scanf("%[^\n]s",s);
    int i = 0;
    char identifers[MAX];
    char operators[MAX];
    char constants[MAX];
    int id = 0;
    int op = 0;
    int co = 0;
    bool lhs = true;
    while(s[i]!='\0'){
        if(((int)(s[i]-'a') >=0 && (int)(s[i]-'a')<= 25) ||  ((int)(s[i]-'A') >=0 && (int)(s[i]-'A')<= 25)){
            identifers[id] = s[i];
            id++;
        }else if((int)(s[i]-'0') >=0 && (int)(s[i]-'0')<= 9){
            constants[co] = s[i];
            co++;
        }else if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '=' || s[i] == '*' || s[i] == '%'){
            operators[op] = s[i];
            op++;
        }
        i++;
    }
    int j = 0;
    printf("Identifers are : ");
    while(j<id){
        printf("%c, ",identifers[j++]);
    }
    j = 0;
    printf("\nOperators are : ");
    while(j<op){
        printf("%c, ",operators[j++]);
    }
    j = 0;
    printf("\nConstants are : ");
    while(j<co){
        printf("%c, ",constants[j++]);
    }
    return 0;
}