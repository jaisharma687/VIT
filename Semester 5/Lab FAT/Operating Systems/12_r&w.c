#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t wrt, mutex;
int readcnt = 0;
int shared_data = 0;

void reader() {
    sem_wait(&mutex);
    readcnt++;
    if (readcnt == 1) sem_wait(&wrt);
    sem_post(&mutex);
    printf("Reader: Read shared data = %d\n", shared_data);
    sem_wait(&mutex);
    readcnt--;
    if (readcnt == 0) sem_post(&wrt);
    sem_post(&mutex);
}

void writer() {
    sem_wait(&wrt);
    shared_data++;
    printf("Writer: Wrote shared data = %d\n", shared_data);
    sem_post(&wrt);
}

int main() {
    sem_init(&wrt, 0, 1);
    sem_init(&mutex, 0, 1);
    writer(); 
    reader(); 
    reader(); 
    writer(); 
    reader(); 
    sem_destroy(&wrt);
    sem_destroy(&mutex);
    return 0;
}