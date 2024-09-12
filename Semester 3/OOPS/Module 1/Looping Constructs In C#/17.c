# include <stdio.h>
# include <string.h>
int main(){
    char arr[100],rev[100];
    scanf("%[^\n]%*c",arr);
    int len = strlen(arr);
    for(int i = 0; i<len;i++){
        rev[len-i-1]=arr[i];
    }
    int count = 0;
    for(int i=0;i<len;i++){
        if(rev[i]!=arr[i]){
            count += 1;
        }
    }
    if(count!=0){
        printf("Not Palindrome");
    }
    else{
        printf("Palindrome");
    }
    return 0;
}