# include <stdio.h>
# include <string.h>

void lcs(char *X, char *Y,int m,int n){
    int dp[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0||j==0)
                dp[i][j] = 0;
            else if(X[i-1] == Y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else{
                if(dp[i-1][j] > dp[i][j-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
    }
    int index = dp[m-1][n-1];
    char lcs[index+1];
    lcs[index] = '\0';
    int i=m-1,j=n-1;
    while(i>0 && j>0){
        if(X[i-1]==Y[j-1]){
            lcs[index-1] = X[i-1];
            i--;
            j--;
            index--;
        }else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    printf("%s",lcs);
}

int main(){
    char X[100],Y[100];
    fgets(X,sizeof(X),stdin);
    fgets(Y,sizeof(Y),stdin);
    X[strcspn(X,"\n")] = '\0';
    Y[strcspn(Y,"\n")] = '\0';
    int m = strlen(X);
    int n = strlen(Y);
    lcs(X,Y,m+1,n+1);
    return 0;
}