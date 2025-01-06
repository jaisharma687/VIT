# include <stdio.h>

# define MAX 10

int max_profit = 0;
int max_weight = 0;
int bestSet[MAX] = {0};

void knapsack(int idx, int profit, int weight,int set[], int parray[], int warray[], int capacity, int n){
    if(weight > capacity)
        return;
    if(idx >= n){
        if(profit > max_profit){
            max_profit = profit;
            max_weight = weight;
            for(int i=0;i<n;i++){
                bestSet[i] = set[i];
            }
        }
        return;
    }
    set[idx] = 1;
    knapsack(idx+1,profit+parray[idx],weight+warray[idx],set,parray,warray,capacity,n);
    set[idx] = 0;
    knapsack(idx+1,profit,weight,set,parray,warray,capacity,n);
}

int main(){
    int n;
    scanf("%d",&n);
    int parray[MAX], warray[MAX];
    for(int i=0;i<n;i++)
        scanf("%d",&parray[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&warray[i]);
    int capacity;
    scanf("%d",&capacity);
    int set[MAX] = {0};
    knapsack(0,0,0,set,parray,warray,capacity,n);
    printf("Array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",bestSet[i]);
    }
    printf("\nMax profit is %d",max_profit);
    printf("\nWeight is %d",max_weight);
    return 0;
}