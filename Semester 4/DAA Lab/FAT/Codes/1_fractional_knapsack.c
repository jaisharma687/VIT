# include <stdio.h>

void swap(float *a,float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}

void sort(float arr[],float p[],float w[]){
    for(int i=0;i<6;i++){
        for(int j=0;j<7-i-1;j++){
            if(arr[j]<arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                swap(&p[j],&p[j+1]);
                swap(&w[j],&w[j+1]);
            }
        }
    }
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
    float cost[n];
    for(int i = 0;i<n;i++){
        cost[i] = profit[i] / weight[i];
    }
    sort(cost,profit,weight);
    float W;
    scanf("%f",&W);
    int i = 0;
    float max_profit = 0;
    int cont = 1;
    while(cont){
        if(W - weight[i] >= 0){
            W -= weight[i];
            max_profit += profit[i];
            i++;
        }
        else{
            break;
        }
    }
    if(W!=0){
        max_profit += cost[i]*W;
    }
    printf("%.1f",max_profit);
    return 0;
}