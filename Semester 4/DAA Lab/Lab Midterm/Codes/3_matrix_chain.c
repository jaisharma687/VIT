#include <stdio.h>
#include <limits.h>

int MatrixChainOrder(int p[], int n) {
    int m[n][n];
    int i, j, k, L, q;
    for (i = 1; i < n; i++)
        m[i][i] = 0;
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1];
}

int main() {
    int arr_size;
    scanf("%d",&arr_size);
    int arr[arr_size+1];
    int j=0;
    for(int i=0;i<arr_size;i++){
        if(i==0){
            int a,b;
            scanf("%d %d",&a,&b);
            // printf("%d %d\n",a,b);
            arr[j++]=a;
            arr[j++]=b;
        }
        else
        {
            int ele;
            scanf("%d %d",&ele,&arr[j++]);
        }
        
    }
    // for(int i=0;i<j;i++){
    //     printf("%d ",arr[i]);
    // }
    printf("The minimum number of multiplication needed is %d\n", MatrixChainOrder(arr, arr_size+1));
    return 0;
}