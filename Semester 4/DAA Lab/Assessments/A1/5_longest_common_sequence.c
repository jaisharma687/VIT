#include <stdio.h>
#include <string.h>

int lcs(char* X, char* Y, int m, int n) {
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }

    return dp[m][n];
}

void printLCS(char* X, char* Y, int m, int n) {
    int dp[m + 1][n + 1];
    int index = lcs(X, Y, m, n);
    char lcs[index + 1];
    lcs[index] = '\0';
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    printf("The longest common sub sequence is : %s\n", lcs);
}

int main() {
    char X[100], Y[100];
    fgets(X, sizeof(X), stdin);
    X[strcspn(X, "\n")] = '\0';
    fgets(Y, sizeof(Y), stdin);
    Y[strcspn(Y, "\n")] = '\0';
    int m = strlen(X);
    int n = strlen(Y);
    printLCS(X, Y, m, n);
    return 0;
}