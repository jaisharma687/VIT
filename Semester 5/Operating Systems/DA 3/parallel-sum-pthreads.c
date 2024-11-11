#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define ARRAY_SIZE 1000000

typedef struct {
    int* array;
    int start;
    int end;
    long long partial_sum;
} ThreadData;

void* calculate_partial_sum(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    long long sum = 0;

    for (int i = data->start; i < data->end; i++) {
        sum += data->array[i];
    }

    data->partial_sum = sum;
    pthread_exit(NULL);
}

int main() {
    int* array = (int*)malloc(ARRAY_SIZE * sizeof(int));
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    long long total_sum = 0;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    int chunk_size = ARRAY_SIZE / NUM_THREADS;
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].array = array;
        thread_data[i].start = i * chunk_size;
        thread_data[i].end = (i == NUM_THREADS - 1) ? ARRAY_SIZE : (i + 1) * chunk_size;
        thread_data[i].partial_sum = 0;

        pthread_create(&threads[i], NULL, calculate_partial_sum, (void*)&thread_data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        total_sum += thread_data[i].partial_sum;
    }

    printf("Total sum: %lld\n", total_sum);

    free(array);
    return 0;
}


/*
Commands to run the code in WSL:

1: gcc -pthread -o parallel-sum-pthreads parallel-sum-pthreads.c
2: ./parallel-sum-pthreads

*/