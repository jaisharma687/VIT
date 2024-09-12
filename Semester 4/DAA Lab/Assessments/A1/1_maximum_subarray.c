#include <stdio.h>

void find_max_crossing_subarray(int A[], int low, int mid, int high, int cross[]) {
    int left_sum = -999999, right_sum = -999999;
    int sum = 0, max_left = mid, max_right = mid + 1;

    for (int i = mid; i >= low; i--) {
        sum += A[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    sum = 0;

    for (int i = mid + 1; i < high; i++) {
        sum += A[i];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = i;
        }
    }

    cross[0] = max_left;
    cross[1] = max_right;
    cross[2] = left_sum + right_sum;
}

void find_max_subarray(int A[], int low, int high, int output[]) {
    if (high == low) {
        output[0] = low;
        output[1] = high;
        output[2] = A[low];
    } else {
        int mid = (low + high) / 2;
        int left_sub[3], right_sub[3], cross_sub[3];

        find_max_subarray(A, low, mid, left_sub);
        find_max_subarray(A, mid + 1, high, right_sub);
        find_max_crossing_subarray(A, low, mid, high, cross_sub);

        if (left_sub[2] >= right_sub[2] && left_sub[2] >= cross_sub[2]) {
            output[0] = left_sub[0];
            output[1] = left_sub[1];
            output[2] = left_sub[2];
        } else if (right_sub[2] >= cross_sub[2]) {
            output[0] = right_sub[0];
            output[1] = right_sub[1];
            output[2] = right_sub[2];
        } else {
            output[0] = cross_sub[0];
            output[1] = cross_sub[1];
            output[2] = cross_sub[2];
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[20];
    int out[3];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    find_max_subarray(arr, 0, n, out);

    printf("The maximum sub array is [%d", arr[out[0]]);
    for (int i = out[0] + 1; i <= out[1]; i++) {
        printf(" %d", arr[i]);
    }
    printf("]\nThe maximum sub array sum is :%d", out[2]);

    return 0;
}