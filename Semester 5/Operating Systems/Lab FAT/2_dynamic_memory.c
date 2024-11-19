#include<stdio.h>

void firstFit(int p[], int pSize, int b[], int bSize){
    int bcopy[bSize];
    for(int i=0;i<bSize;i++) bcopy[i]=b[i];
    printf("First Fit\n");
    for(int i=0;i<pSize;i++){
        int allocated = -1;
        for(int j=0;j<bSize;j++){
            if(bcopy[j]>=p[i]){
                allocated = j;
                bcopy[j] -= p[j];
                printf("P%d is allocated to B%d\n",i+1,j+1);
                break;
            }
        }
        if(allocated==-1){
            printf("P%d is not allocated\n",i+1);
        }
    }
}

void worstFit(int p[], int pSize, int b[], int bSize){
    int bcopy[bSize];
    for(int i=0;i<bSize;i++) bcopy[i]=b[i];
    printf("Worst Fit\n");
    for(int i=0;i<pSize;i++){
        int worst = -1;
        for(int j=0;j<bSize;j++){
            if(bcopy[j]>=p[i] && (worst == -1 || bcopy[worst] < bcopy[j])){
                worst = j;
            }
        }
        if(worst!=-1){
            printf("P%d is allocated to B%d\n",i+1,worst+1);
            bcopy[worst] -= p[i];
        }
        else{
            printf("P%d is not allocated\n",i+1);
        }
    }
}

void bestFit(int p[], int pSize, int b[], int bSize){
    int bcopy[bSize];
    for(int i=0;i<bSize;i++) bcopy[i]=b[i];
    printf("Best Fit\n");
    for(int i=0;i<pSize;i++){
        int best = -1;
        for(int j=0;j<bSize;j++){
            if(bcopy[j]>=p[i] && (best == -1 || bcopy[best] > bcopy[j])){
                best = j;
            }
        }
        if(best!=-1){
            printf("P%d is allocated to B%d\n",i+1,best+1);
            bcopy[best] -= p[i];
        }
        else{
            printf("P%d is not allocated\n",i+1);
        }
    }
}

int main() {
    int x, y;
    printf("Enter number of processes: ");
    scanf("%d", &x);
    int p[x];
    for (int i = 0; i < x; i++) {
        printf("Enter size of P%d: ", i + 1);
        scanf("%d", &p[i]);
    }
    printf("Enter number of blocks: ");
    scanf("%d", &y);
    int b[y];
    for (int i = 0; i < y; i++) {
        printf("Enter size of B%d: ", i + 1);
        scanf("%d", &b[i]);
    }
    firstFit(p, x, b, y);
    worstFit(p, x, b, y);
    bestFit(p, x, b, y);
    return 0;
}