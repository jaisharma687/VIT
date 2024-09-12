// Each year the Department of Traffic Accidents receives 
// accident count reports from a number of cities and towns 
// across the country. Given details of ‘n’ days, develop 
// an algorithm and write a program to determine the average 
// number of accidents and for each day, print the difference 
// between the number of accidents on that day and average. 
// For example, if the number of accidents is 5 and the values 
// are 10, 12, 15, 13, 5 then average is 11 and the difference 
// of values are 1, 1, 4, 2, 6
#include <stdio.h>
int main(){
    int arr[100];
    int n;
    scanf("%d",&n);
    for(int i =0; i<n;i++){
        scanf("%d ",arr[i]);
    }
    int sum = 0;
    for(int i = 0; i<n;i++){
        sum += arr[i];
    }
    int avg = sum/n;
    for(int i = 0; i<n;i++){
        int dif;
        if(sum>arr[i]){
            dif = sum-arr[i];
        }
        else if(sum<arr[i]){
            dif = -sum+arr[i];
        }
        printf("%d ",arr[i]);
    }
}
