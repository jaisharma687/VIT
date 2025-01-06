#include <stdio.h>
#include <limits.h>

void crossSum(int arr[],int low, int mid, int high,int output[]){
    int left_sum = INT_MIN;
    int sum =0;
    int max_left=mid;
    for(int i=mid;i>=low;i--){
        sum += arr[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    int right_sum = INT_MIN;
    int max_right=mid+1;
    for(int i=mid+1;i<=high;i++){
        sum += arr[i];
        if(sum > right_sum){
            right_sum = sum;
            max_right = i;
        }
    }
    output[0] = max_left;
    output[1] = max_right;
    output[2] = left_sum + right_sum;
}

void maxSum(int arr[], int low, int high,int output[]){
    if(low==high){
        output[0] = low;
        output[1] = high;
        output[2] = arr[0];
    }else{
        int mid = (low + high)/2;
        int right[3],left[3],cross[3];
        maxSum(arr,low,mid,right);
        maxSum(arr,mid+1,high,left);
        crossSum(arr,low,mid,high,cross);
        int left_sum = left[2];
        int right_sum = right[2];
        int cross_sum = cross[2];
        if(left_sum > right_sum && left_sum > cross_sum){
            output[0] = left[0];
            output[1] = left[1];
            output[2] = left[2];
        }else if(right_sum > left_sum && right_sum > cross_sum){
            output[0] = right[0];
            output[1] = right[1];
            output[2] = right[2];
        }
        else{
            output[0] = cross[0];
            output[1] = cross[1];
            output[2] = cross[2];
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int out[3];
    maxSum(arr,0,n-1,out);
    for(int i=out[0];i<=out[1];i++){
        printf("%d ",arr[i]);
    }
    printf("\n%d",out[2]);
    return 0;
}