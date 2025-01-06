#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>

sem_t semaphore;

void critical_section(int id) {
    sem_wait(&semaphore);
    printf("Process %d entering critical section...\n", id);
    sleep(1);
    printf("Process %d leaving critical section...\n", id);
    sem_post(&semaphore);
}

int main() {
    pid_t pid1, pid2;
    sem_init(&semaphore, 1, 1);
    pid1 = fork();
    if (pid1 == 0) {
        critical_section(1);
        exit(0);
    } else {
        pid2 = fork();
        if (pid2 == 0) {
            critical_section(2);
            exit(0);
        } else {
            wait(NULL);
            wait(NULL);
        }
    }
    sem_destroy(&semaphore);
    return 0;
}