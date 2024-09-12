#include <stdio.h>

void copyArray(int nodes, int floyd[][nodes], int nextfloyd[][nodes]){
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            nextfloyd[i][j] = floyd[i][j];
        }
    }
}

void printArray(int nodes,int array[][nodes]){
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int min(int a, int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}

void floydWarshal(int nodes, int floyd[][nodes]){
    int temp[nodes][nodes];
    printf("A0=\n");
    printArray(nodes,floyd);
    for(int k = 1; k<=nodes;k++){
        copyArray(nodes,floyd,temp);
        for(int i=0;i<nodes;i++){
            for(int j=0;j<nodes;j++){
                if((i==k-1) || (j==k-1)){
                    floyd[i][j] = temp[i][j];
                }
                else{
                    floyd[i][j] = min(temp[i][j],temp[i][k-1]+temp[k-1][j]);
                }
            }
            copyArray(nodes,floyd,temp);
        }
        printf("A%d=\n",k);
        printArray(nodes,temp);
    }
}

int main(){
    int floyd[4][4] = {   {0,3,100,5},
                        {2,0,100,4},
                        {100,1,0,100},
                        {100,100,2,0}};
    floydWarshal(4,floyd);
    return 0;
}