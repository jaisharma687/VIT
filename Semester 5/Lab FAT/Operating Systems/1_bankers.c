#include<stdio.h>

void bankers(int n, int m, int max[n][m], int alloc[n][m], int avail[m]){
    int visited[n], ans[n];
    int idx = 0;
    for(int i=0;i<n;i++) visited[i] = 0;
    int need[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                int flag = 1;
                for(int j=0;j<m;j++){
                    if(need[i][j]>avail[j]){
                        flag = 0;
                        break;
                    }
                }
                if(flag==1){
                    ans[idx++] = i;
                    for(int j=0;j<m;j++){
                        avail[j] += alloc[i][j];
                    }
                    visited[i] = 1;
                }
            }
        }
    }
    if(idx != n){
        printf("No Safe State.");
    }
    else{
        printf("Safe State:");
        for(int i=0;i<n-1;i++){
            printf(" P%d ->",ans[i]);
        }
        printf(" P%d",ans[n-1]);
    }
}

int main(){
    int n;
    int m;
    printf("Enter number of Processes: ");
    scanf("%d",&n);
    printf("Enter number of Resources: ");
    scanf("%d",&m);
    int max[n][m], alloc[n][m], avail[m];
    printf("Enter Allocation Matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter Maximum Matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter Available Resources:\n");
    for(int i=0;i<m;i++){
        scanf("%d",&avail[i]);
        
    }
    bankers(n,m,max,alloc,avail);
    return 0;
}