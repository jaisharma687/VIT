#include <stdio.h>

int subset_count = 0;

void print_subset(int subset[], int size) 
{
    printf("{");
    for (int i = 0; i < size; i++) 
    {
        printf("%d", subset[i]);
        if (i < size - 1) 
        {
            printf(", ");
        }
    }
    printf("}\n");
}

void subset_sum(int list[], int sum, int starting_index, int target_sum, int subset[], int subset_size, int list_size) 
{ 
    if (target_sum == sum) 
    { 
        subset_count++; 
        print_subset(subset, subset_size);
        if (starting_index < list_size)
            subset_sum(list, sum - list[starting_index], starting_index + 1, target_sum, subset, subset_size - 1, list_size); 
    } 
    else
    { 
        for (int i = starting_index; i < list_size; i++) 
        { 
            subset[subset_size] = list[i];
            subset_sum(list, sum + list[i], i + 1, target_sum, subset, subset_size + 1, list_size); 
        } 
    } 
}

int main() 
{
    int list[100]; 
    int target_sum;
    scanf("%d", &target_sum);
    int num, index = 0;
    while (scanf("%d", &num) == 1) {
        list[index++] = num;
    }
    int subset[100];

    subset_sum(list, 0, 0, target_sum, subset, 0, index);

    // printf("Number of subsets with sum %d: %d\n", target_sum, subset_count);

    return 0;
}
