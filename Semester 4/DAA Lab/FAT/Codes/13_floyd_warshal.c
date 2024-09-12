#include <stdio.h>

void copyTwoDArray(int nodes, int temp[][nodes], int floyd_matrix[][nodes]){
    for (int i = 0; i < nodes; i ++) {
        for(int j = 0; j < nodes; j ++) {
            temp[i][j] = floyd_matrix[i][j];
        }
    }
}

void printArray(int nodes, int floyd_matrix[][nodes]) {
    for (int i = 0; i < nodes; i++){
        for (int j = 0; j < nodes; j++){
            printf("%d ", floyd_matrix[i][j]);
        }
        printf("\n");
    }
}

int min (int a, int b) {
    return a < b ? a: b;
}

void floyd_warshall(int nodes, int floyd_matrix[][nodes]){
    int temp[nodes][nodes];
    printf("A0 =\n");
    printArray(nodes,floyd_matrix);
    printf("\n");
    for (int k = 1; k <= nodes; k ++) {
        copyTwoDArray(nodes, temp, floyd_matrix);
        for (int i = 0; i < nodes; i ++) {
            for (int j = 0; j < nodes; j ++) {
                if ((i == k - 1) || (j == k - 1))
                    floyd_matrix[i][j] = temp[i][j];
                else {
                    floyd_matrix[i][j] = min(temp[i][j], temp[i][k - 1] + temp[k - 1][j]);
                }
            }
            copyTwoDArray(nodes, temp, floyd_matrix);
        }
        printf("A%d=\n", k);
        printArray(nodes, temp);
    }    
}

int main() {
    int floyd_matrix[4][4] = {  {0,3,100,5},
                                {2,0,100,4},
                                {100,1,0,100},
                                {100,100,2,0}  };
    floyd_warshall(4,floyd_matrix);
    return 0;
}