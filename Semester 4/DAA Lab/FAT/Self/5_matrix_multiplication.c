#include <stdio.h>
# include<limits.h>

int matrixChain(int p[],int n){
    int m[n][n];
    for(int i=0;i<n;i++){
        m[i][i] = 0;
    }
    for(int l=2;l<n;l++){
        for(int i=1;i<n-l+1;i++){
            int j = i+l-1;
            m[i][j] = INT_MAX;
            for(int k=i;k<j;k++){
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q<m[i][j]){
                    m[i][j] = q;
                }
            }
        }
    }
    return m[1][n-1];
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n+1];
    int j = 0;
    for(int i=0;i<n;i++){
        if(i==0){
            int a,b;
            scanf("%d %d",&a,&b);
            arr[j++] = a;
            arr[j++] = b;
        }
        else{
            int ele;
            scanf("%d %d",&ele,&arr[j++]);
        }
    }
    printf("%d",matrixChain(arr,n+1));
}