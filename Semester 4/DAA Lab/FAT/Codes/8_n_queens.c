#include <stdio.h>
#include <stdlib.h>

#define MAX_N 20

int isSafe(int board[], int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(i - row) == abs(board[i] - col)) {
            return 0;
        }
    }
    return 1;
}

void printSolution(int board[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d,%d\n", i + 1, board[i] + 1);
    }
}

// int solveNQueensUtil(int board[], int row, int n) {
//     if (row == n) {
//         printSolution(board, n);
//         exit(0);  
//     }

//     int count = 0;
//     for (int col = 0; col < n; col++) {
//         if (isSafe(board, row, col, n)) {
//             board[row] = col;
//             count += solveNQueensUtil(board, row + 1, n);
//             board[row] = -1;
//         }
//     }
//     return count;
// }

int solveNQueensUtil(int board[], int row, int n) {
    if (row == n) {
        printSolution(board, n);
        printf("\n");
        return 1;
    }

    int count = 0;
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row] = col;
            count += solveNQueensUtil(board, row + 1, n);
            board[row] = -1;
        }
    }
    return count;
}

void solveNQueens(int n) {
    int board[MAX_N];
    for (int i = 0; i < n; i++) {
        board[i] = -1;
    }
    solveNQueensUtil(board, 0, n);
}


int main() {
    int n;
    scanf("%d", &n);
    printf("The queen positions are\n");
    solveNQueens(n);
    return 0;
}