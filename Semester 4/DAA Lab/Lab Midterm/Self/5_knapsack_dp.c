# include <stdio.h>
# define MAX 20

int max(int a, int b){
    if(a>b) 
        return a; 
    else return b;
}

void printSubset(int array[],int n){
    printf("Subset: ");
    for(int i=1;i<n+1;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

void findSubsets(int profits[],int weights[], int n, int M, int dp[n+1][M+1],int i,int rem_capacity,int chosen[]){
    if(i==0 || rem_capacity == 0){
        printSubset(chosen,n);
        return;
    }
    if(weights[i-1] <= rem_capacity && dp[i][rem_capacity] == profits[i-1]+dp[i-1][rem_capacity - weights[i-1]]){
        chosen[i] = 1;
        findSubsets(profits,weights,n,M,dp,i-1,rem_capacity - weights[i-1],chosen);
        chosen[i] = 0;
    }
    if(dp[i][rem_capacity] == dp[i-1][rem_capacity]){
        findSubsets(profits,weights,n,M,dp,i-1,rem_capacity,chosen);
    }
}

void knapsack(int profits[], int weights[],int n, int M){
    int dp[n+1][M+1];
    for(int i = 0;i <= n;i++){
        for(int j=0;j<=M;j++){
            if(i==0||j==0)
                dp[i][j] = 0;
            else if(weights[i-1] <= j)
                dp[i][j] = max(dp[i-1][j], profits[i-1]+dp[i-1][j-weights[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    int chosen[MAX] = {0};
    findSubsets(profits,weights,n,M,dp,n,M,chosen);
}

int main(){
    int n, M;
    scanf("%d", &n);
    scanf("%d", &M);
    int profits[MAX];
    int weights[MAX];
    for(int i = 0; i < n; i++) {
        scanf("%d", &profits[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    knapsack(profits, weights, n,M);
    return 0;
}