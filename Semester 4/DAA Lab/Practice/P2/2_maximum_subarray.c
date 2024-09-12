# include <stdio.h>

void cross_subarray(int A[], int low, int mid, int high, int cross[]){
    int l_sum = -999999;
    int r_sum = -999999;
    int sum_left = 0;
    int sum_right = 0;
    int max_left;
    int max_right;
    for(int i = mid; i>=low;i--){
        sum_left += A[i];
        if(sum_left > l_sum){
            l_sum = sum_left;
            max_left = i;
        }
    }
    for(int i = mid+1; i<high;i++){
        sum_right += A[i];
        if(sum_right > r_sum){
            r_sum = sum_right;
            max_right = i;
        }
    }
    cross[0] = max_left;
    cross[1] = max_right;
    cross[2] = l_sum + r_sum;
}

void max_subarray(int A[],int low, int high,int output[]){
    if(high == low){
        output[0] = low;
        output[1] = high;
        output[2] = A[low];
    }
    else{
        int mid = (low+high)/2;
        int left_sub[3];
        max_subarray(A,low,mid,left_sub);
        int right_sub[3]; 
        max_subarray(A,mid+1,high,right_sub);
        int cross_sub[3];
        cross_subarray(A,low,mid,high,cross_sub);
        if(left_sub[2] >= right_sub[2] && left_sub[2] >= cross_sub[2]){
            output[0] = left_sub[0];
            output[1] = left_sub[1];
            output[2] = left_sub[2];
        }
        else if (left_sub[2] <= right_sub[2] && right_sub[2] >= cross_sub[2]){
            output[0] = right_sub[0];
            output[1] = right_sub[1];
            output[2] = right_sub[2];
        }
        else{
            output[0] = cross_sub[0];
            output[1] = cross_sub[1];
            output[2] = cross_sub[2];
        }
    }
}


int main(){
    int n;
    scanf("%d",&n);
    int arr[20];
    int out[3];
    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int low = 0;
    int high = n;
    max_subarray(arr,low,high,out);
    printf("The sub array [");
    for(int i = out[0];i<=out[1];i++){
        if(i != out[1])
            printf("%d ",arr[i]);
        else
            printf("%d",arr[i]);
    }
    printf("] has the largest sum %d",out[2]);
    return 0;
}