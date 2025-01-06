# include <stdio.h>
int fact(int x){
    int val=1;
    for(int i = 1;i<=x;i++){
        val *= i;
    }
    return val;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int j = 1;j<=n;j++){
        int temp = j,rem,sum=0;
        for(int i = 0;j!=0;i++){
            rem = j%10;
            j /= 10;
            sum += fact(rem);
        }
        // printf("%d %d\n",sum,temp);
        if(temp == sum){
            printf("%d ",j);
        }
    }
}