#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5 

sem_t chopstick[N];

void philosopher(int i) {
    printf("Philosopher %d is thinking...\n", i + 1);
    sleep(1);
    sem_wait(&chopstick[i]);
    sem_wait(&chopstick[(i + 1) % N]);
    printf("Philosopher %d is eating...\n", i + 1);
    sleep(2);
    sem_post(&chopstick[i]);
    sem_post(&chopstick[(i + 1) % N]);
    printf("Philosopher %d finished eating and is now thinking...\n", i + 1);
}

int main() {
    for (int i = 0; i < N; i++) {
        sem_init(&chopstick[i], 0, 1);
    }
    for (int i = 0; i < N; i++) {
        philosopher(i);
    }
    for (int i = 0; i < N; i++) {
        sem_destroy(&chopstick[i]);
    }
    return 0;
}