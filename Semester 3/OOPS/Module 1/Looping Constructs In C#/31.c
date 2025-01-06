# include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int v = i;
        int value = 0;
        for(int j = 0;v!=0;j++){
            int rem = v%10;
            v /= 10;
            value += rem*rem*rem;
        }
        if(i == value){
            printf("%d ",value);
        }
    }
}