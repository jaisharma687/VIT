#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 10
#define MAX_PROCESSES 10

struct MemoryBlock {
    int id;
    int size;
    int allocated;
    int process_id;
};

struct Process {
    int id;
    int size;
};

void initializeMemory(struct MemoryBlock memory[], int sizes[], int n);
void firstFit(struct MemoryBlock memory[], int n, struct Process processes[], int m);
void bestFit(struct MemoryBlock memory[], int n, struct Process processes[], int m);
void worstFit(struct MemoryBlock memory[], int n, struct Process processes[], int m);
void displayMemory(struct MemoryBlock memory[], int n, const char* algorithm_name);
void copyMemory(struct MemoryBlock dest[], struct MemoryBlock src[], int n);

int main() {
    struct MemoryBlock memory[MAX_BLOCKS];
    struct MemoryBlock temp_memory[MAX_BLOCKS];
    struct Process processes[MAX_PROCESSES];
    int n, m, i;
    int block_sizes[MAX_BLOCKS];
    printf("Enter the number of memory blocks: ");
    scanf("%d", &n);
    printf("\nEnter the size of each memory block:\n");
    for(i = 0; i < n; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &block_sizes[i]);
    }
    printf("\nEnter the number of processes: ");
    scanf("%d", &m);
    printf("\nEnter the size of each process:\n");
    for(i = 0; i < m; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processes[i].size);
        processes[i].id = i + 1;
    }
    initializeMemory(memory, block_sizes, n);
    printf("\n\n=== Memory Allocation Results ===\n");
    printf("\n1. First Fit Algorithm\n");
    printf("----------------------------\n");
    copyMemory(temp_memory, memory, n);
    firstFit(temp_memory, n, processes, m);
    displayMemory(temp_memory, n, "First Fit");
    printf("\n2. Best Fit Algorithm\n");
    printf("----------------------------\n");
    copyMemory(temp_memory, memory, n);
    bestFit(temp_memory, n, processes, m);
    displayMemory(temp_memory, n, "Best Fit");
    printf("\n3. Worst Fit Algorithm\n");
    printf("----------------------------\n");
    copyMemory(temp_memory, memory, n);
    worstFit(temp_memory, n, processes, m);
    displayMemory(temp_memory, n, "Worst Fit");
    return 0;
}

void initializeMemory(struct MemoryBlock memory[], int sizes[], int n) {
    for(int i = 0; i < n; i++) {
        memory[i].id = i + 1;
        memory[i].size = sizes[i];
        memory[i].allocated = 0;
        memory[i].process_id = 0;
    }
}

void copyMemory(struct MemoryBlock dest[], struct MemoryBlock src[], int n) {
    for(int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

void firstFit(struct MemoryBlock memory[], int n, struct Process processes[], int m) {
    for(int i = 0; i < m; i++) {
        int allocated = 0;
        for(int j = 0; j < n; j++) {
            if(!memory[j].allocated && memory[j].size >= processes[i].size) {
                memory[j].allocated = 1;
                memory[j].process_id = processes[i].id;
                printf("Process %d (%d KB) -> Allocated to Block %d (%d KB)\n", 
                    processes[i].id, processes[i].size, memory[j].id, memory[j].size);
                allocated = 1;
                break;
            }
        }
        if(!allocated) {
            printf("Process %d (%d KB) -> Cannot be allocated\n", 
                processes[i].id, processes[i].size);
        }
    }
}

void bestFit(struct MemoryBlock memory[], int n, struct Process processes[], int m) {
    for(int i = 0; i < m; i++) {
        int best_idx = -1;
        int min_diff = __INT_MAX__;
        for(int j = 0; j < n; j++) {
            if(!memory[j].allocated && memory[j].size >= processes[i].size) {
                if(memory[j].size - processes[i].size < min_diff) {
                    min_diff = memory[j].size - processes[i].size;
                    best_idx = j;
                }
            }
        }
        if(best_idx != -1) {
            memory[best_idx].allocated = 1;
            memory[best_idx].process_id = processes[i].id;
            printf("Process %d (%d KB) -> Allocated to Block %d (%d KB)\n", 
                processes[i].id, processes[i].size, memory[best_idx].id, memory[best_idx].size);
        } else {
            printf("Process %d (%d KB) -> Cannot be allocated\n", 
                processes[i].id, processes[i].size);
        }
    }
}

void worstFit(struct MemoryBlock memory[], int n, struct Process processes[], int m) {
    for(int i = 0; i < m; i++) {
        int worst_idx = -1;
        int max_diff = -1;
        for(int j = 0; j < n; j++) {
            if(!memory[j].allocated && memory[j].size >= processes[i].size) {
                if(memory[j].size - processes[i].size > max_diff) {
                    max_diff = memory[j].size - processes[i].size;
                    worst_idx = j;
                }
            }
        }
        if(worst_idx != -1) {
            memory[worst_idx].allocated = 1;
            memory[worst_idx].process_id = processes[i].id;
            printf("Process %d (%d KB) -> Allocated to Block %d (%d KB)\n", 
                processes[i].id, processes[i].size, memory[worst_idx].id, memory[worst_idx].size);
        } else {
            printf("Process %d (%d KB) -> Cannot be allocated\n", 
                processes[i].id, processes[i].size);
        }
    }
}

void displayMemory(struct MemoryBlock memory[], int n, const char* algorithm_name) {
    printf("\nFinal Memory State (%s):\n", algorithm_name);
    printf("Block\tSize\tStatus\t\tProcess\n");
    printf("----------------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%s\t\t", 
            memory[i].id, 
            memory[i].size, 
            memory[i].allocated ? "Allocated" : "Free");
        if(memory[i].allocated)
            printf("P%d\n", memory[i].process_id);
        else
            printf("None\n");
    }
    printf("\n");
}