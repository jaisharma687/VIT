#include <stdio.h>
#include <stdlib.h>

int isSafe(int board[],int n, int row, int col){
    for(int i=0;i<row;i++){
        if(board[i] == col || abs(row - i) == abs(board[i] - col))
            return 0;
    }
    return 1;
}

void printNQueen(int board[],int n){
    printf("[ ");
    for(int i=0;i<n;i++){
        if(i==n-1) {
            printf("%d ",board[i] + 1);
        }else{
            printf("%d, ",board[i] + 1);
        }
    }
    printf("]");
}

int solveNQueen(int board[], int n, int row){
    if(row==n){
        printNQueen(board,n);
        printf("\n");
        // return 1;
        exit(0);
    }
    int count = 0;
    for(int col=0;col<n;col++){
        if(isSafe(board,n,row,col)){
            board[row] = col; 
            count += solveNQueen(board,n,row+1);
            board[row] = -1;
        }
    }
    return count;
}

void NQueen(int n){
    int board[n];
    for(int i=0;i<n;i++){
        board[i] = -1;
    }
    int c = solveNQueen(board,n,0);
    printf("Number of solutions: %d",c);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("The queen positions are\n");
    NQueen(n);
    return 0;
}