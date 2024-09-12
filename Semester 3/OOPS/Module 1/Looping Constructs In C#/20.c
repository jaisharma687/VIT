# include <string.h>
# include <stdio.h>
int main(){
    char arr[100];
    scanf("%[^\n]%*c",arr);
    int len = strlen(arr);
    for(int i = 0; i<len;i++){
        printf("The ASCII value of %c is %d\n",arr[i],(int)arr[i]);
    }
    return 0;
}