# include <stdio.h>
# include <string.h>
int main(){
    char arr[100];
    int sum=0;
    scanf("%[^\n]%*c",arr);
    int len = strlen(arr);
    for(int i = 0; i < len; i++){
        int a = (int)arr[i]; 
        int val = a-'0';//subrating '0' will subtract the ascii values of the to get the number
        printf("%d %d\n",val,a);
        sum += val;
    }
    printf("%d",sum);
    return 0;
}