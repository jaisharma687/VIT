# include <stdio.h>

#define MAX 10

void subsets(int arr[],int n, int target, int current, int index, int path[],int path_index){
    if(current == target){
        printf("Subset: ");
        for(int i=0;i<path_index;i++){
            printf("%d ",path[i]);
        }
        printf("\n");
        return;
    }
    if(index == n || current > target)
        return;
    path[path_index] = arr[index];
    subsets(arr,n,target,current+arr[index],index+1,path,path_index+1);
    subsets(arr,n,target,current,index+1,path,path_index);
}

int main(){
    int n;
    printf("Number of elements: ");
    scanf("%d",&n);
    int arr[MAX];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Target: ");
    int target;
    scanf("%d",&target);
    int path[MAX];
    subsets(arr,n,target,0,0,path,0);
    return 0;
}