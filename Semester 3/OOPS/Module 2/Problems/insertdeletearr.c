# include <stdio.h>
int main(){
    int arr[100];
    int n;
    scanf("%d",&n);
    printf("Array Elements:\n");
    for(int i = 0; i< n ; i++){
        scanf("%d",&arr[i]);
    }
    for(int i =0; i< n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nInsert Element and Index\n");
    int insert,insertindex,deleteindex;
    scanf("%d %d",&insert,&insertindex);
    for(int i=n-1;i>=insertindex;i--){
        arr[i+1]=arr[i];
    }
    arr[insertindex]=insert;
    for(int i =0; i<n+1;i++){
        printf("%d ",arr[i]);
    }
    printf("\nDelete Index\n");
    scanf("%d",&deleteindex);
    for(int i=deleteindex;i<n;i++){
        arr[i]=arr[i+1];
    }
    for(int i =0; i<n;i++){
        printf("%d ",arr[i]);
    }
}