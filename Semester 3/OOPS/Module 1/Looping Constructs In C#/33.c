# include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 2;i<=n;i++){
        int val =0;
        for(int j=2;j<i/2+1;j++){
            if(i%j==0){
                val += j;
            }
        }
        if(val +1 == i){
            printf("%d ",i);
        }
    }
}