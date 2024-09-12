#include <stdio.h>

#define infinite 100;

void copyTwoDArray(int nodes, int temp[][nodes], int floyd_matrix[][nodes])
{

    for (int i = 0; i < nodes; i ++) 
    {
        for(int j = 0; j < nodes; j ++) 
        {
            temp[i][j] = floyd_matrix[i][j];
        }
    }
}

void printArray(int nodes, int floyd_matrix[][nodes]) {

    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            printf("%d ", floyd_matrix[i][j]);
        }
        printf("\n");
    }
}

int min_of_two (int a, int b) 
{
    return a < b ? a: b;
}

void floyd_warshall(int nodes, int floyd_matrix[][nodes])
{
    int temp[nodes][nodes];
    printf("A0 =\n");
    for (int i = 0; i < nodes; i ++) {
        for (int j = 0; j < nodes; j ++) {
            printf("%d ",floyd_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int k = 1; k <= nodes; k ++) {

        copyTwoDArray(nodes, temp, floyd_matrix);

        for (int i = 0; i < nodes; i ++) {
            for (int j = 0; j < nodes; j ++) {

                if ((i == k - 1) || (j == k - 1))
                    floyd_matrix[i][j] = temp[i][j];

                else {
                    floyd_matrix[i][j] = min_of_two(temp[i][j], temp[i][k - 1] + temp[k - 1][j]);
                }

            }
            copyTwoDArray(nodes, temp, floyd_matrix);
        }
            printf("A%d=\n", k);
            printArray(nodes, temp);
    }    
}

int main() 
{
    int floyd_matrix[4][4];

    floyd_matrix[0][0] = floyd_matrix[1][1] = floyd_matrix[2][2] = floyd_matrix[3][3] = floyd_matrix[4][4] = 0;

    floyd_matrix[0][2] = floyd_matrix[1][2] = floyd_matrix[2][0] = floyd_matrix[2][3] = floyd_matrix[3][0] = floyd_matrix[3][1] = 100;

    floyd_matrix[0][1] = 3;
    floyd_matrix[0][3] = 5;

    floyd_matrix[1][0] = 2;
    floyd_matrix[1][3] = 4;

    floyd_matrix[2][1] = 1;

    floyd_matrix[3][2] = 2;

    // int floyd_matrix[5][5] = {{0,6,8,100,-4},{100,0,100,1,7},{100,4,0,100,100},{2,100,-5,0,100},{100,100,100,3,0}};

    // floyd_warshall(4,floyd_matrix);
    // floyd_warshall(5,floyd_matrix);

    return 0;
}