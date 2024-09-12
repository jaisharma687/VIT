#include <stdio.h>

void swap(float*a, float*b){
    float temp = *a;
    *a = *b;
    *b = temp;
}

void sort(float cost[], float profit[], float weight[],int n){
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            if(cost[j] < cost[j+1]){
                swap(&cost[j],&cost[j+1]);
                swap(&profit[j],&profit[j+1]);
                swap(&weight[j],&weight[j+1]);
            }
        }
    }
}

float knapsack(int n, float profit[],float weight[], float W){
    float cost[n];
    for(int i=0;i<n;i++){
        cost[i] = profit[i] / weight[i];
    }
    sort(cost,profit,weight,n);
    int i=0;
    float maxProfit = 0;
    int cont =1;
    while(cont){
        if(W-weight[i] >= 0){
            W -= weight[i];
            maxProfit += profit[i];
            i++;
        }else{
            cont = 0;
        }
    }
    if(W>0){
        maxProfit += cost[i]*W;
    }
    return maxProfit;
}

int main(){
    int n;
    scanf("%d",&n);
    float profit[n];
    float weight[n];
    for(int i=0;i<n;i++){
        scanf("%f",&profit[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%f",&weight[i]);
    }
    float W;
    scanf("%f",&W);
    printf("%.1f",knapsack(n,profit,weight,W));
    return 0;
}