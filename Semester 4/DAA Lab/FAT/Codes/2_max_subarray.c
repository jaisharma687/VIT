#include <stdio.h>
#include <limits.h>
#define MAX 20

void find_max_cross_subarray(int A[], int low, int mid, int high, int cross[]){
    int left_sum = -INT_MAX, right_sum = -INT_MAX;
    int sum = 0;
    int max_left = mid,max_right=mid+1;
    for(int i=mid;i>=low;i--){
        sum += A[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    for(int i=mid+1;i<=high;i++){
        sum += A[i];
        if(sum > right_sum){
            right_sum = sum;
            max_right = i;
        }
    }
    cross[0] = max_left;
    cross[1] = max_right;
    cross[2] = left_sum + right_sum;
}

void find_max_subarray(int A[],int low, int high, int output[]){
    if(high == low){
        output[0] = low;
        output[1] = high;
        output[2] = A[low];
    }else{
        int mid = (low+high)/2;
        int left_sub[3],right_sub[3],cross_sub[3];
        find_max_subarray(A,low,mid,left_sub);
        find_max_subarray(A,mid+1,high,right_sub);
        find_max_cross_subarray(A,low,mid,high,cross_sub);
        int left_sum = left_sub[2];
        int right_sum = right_sub[2];
        int cross_sum = cross_sub[2];
        if(left_sum >= cross_sum && left_sum >= right_sum){
            output[0] = left_sub[0];
            output[1] = left_sub[1];
            output[2] = left_sub[2];
        }else if(right_sum >= cross_sum && right_sum >= left_sum){
            output[0] = right_sub[0];
            output[1] = right_sub[1];
            output[2] = right_sub[2];
        }else{
            output[0] = cross_sub[0];
            output[1] = cross_sub[1];
            output[2] = cross_sub[2];
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int array[MAX];
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    int output[3];
    int low = 0;
    int high = n-1;
    find_max_subarray(array,low,high,output);
    printf("Max subarray sum is %d\n",output[2]);
    int l = output[0];
    int h = output[1];
    printf("Max subarray is ");
    for(int i=l;i<=h;i++){
        printf("%d ",array[i]);
    }
    return 0;
}