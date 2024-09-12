#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int v[], int w[], int n, int W,int V[n + 1][W + 1]) {
    for (int i = 0; i <= n; i++) {
        for (int wt = 0; wt <= W; wt++) {
            if (i == 0 || wt == 0) {
                V[i][wt] = 0;
            } 
            else if (w[i - 1] <= wt) {
                V[i][wt] = max(V[i - 1][wt], v[i - 1] + V[i - 1][wt - w[i - 1]]);
            } 
            else {
                V[i][wt] = V[i - 1][wt];
            }
        }
    }
}

int main() {
    int n,W;
    scanf("%d",&n);
    scanf("%d",&W);
    int values[100];
    int weights[100];
    for(int i=0;i<n;i++){
        scanf("%d",&values[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&weights[i]);
    }
    int V[n + 1][W + 1];
    knapsack(values, weights, n, W,V);
    int out[100] = {0};
    
    int res = V[n][W] - values[n-1];
    int w = W - weights[n-1];
    out[n]=1;
    for (int i = n-1; i >0 && res > 0; i--) {
        if(res == V[i][w] && V[i-1][w] != V[i][w])
        {
            out[i] = 1;
            res = res - values[i - 1];
            w = w - weights[i - 1];
        }
    }
    for(int i=1;i<n+1;i++){
        printf("%d",out[i]);
        out[i] = 0;
    }
    printf("\n");
    res = V[n][W];
    w = W;
    for (int i = n; i >0 && res > 0; i--) {
        if (res == V[i - 1][w]) 
            continue;        
        else {
            out[i] = 1;
            res = res - values[i - 1];
            w = w - weights[i - 1];
        }
    }
    for(int i=1;i<n+1;i++){
        printf("%d",out[i]);
    }
    return 0;
}