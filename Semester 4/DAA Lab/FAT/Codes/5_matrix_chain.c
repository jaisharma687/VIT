# include <stdio.h>
# include <limits.h>

int matrix_chain(int p[],int n){
    int m[n][n];
    for(int i=1;i<n;i++)
        m[i][i] = 0;
    for(int l=2;l<n;l++){
        for(int i=1;i<n-l+1;i++){
            int j = i+l-1;
            m[i][j] = INT_MAX;
            for(int k=i;k<j;k++){
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n-1];
}

int main(){
    int arr_size;
    int array[20];
    int j=0;
    scanf("%d",&arr_size);
    for(int i=0;i<arr_size;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(i==0){
            array[j++] = a;
            array[j++] = b;
        }else{
            array[j++] = b;
        }
    }
    printf("%d",matrix_chain(array,arr_size+1));
    return 0;
}