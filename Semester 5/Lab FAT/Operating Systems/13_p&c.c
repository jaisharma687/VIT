#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5 

int buffer[BUFFER_SIZE];
int i = 0, j = 0;

sem_t full;  
sem_t empty;  
sem_t mutex;  

void producer(int item) {
    sem_wait(&empty); 
    sem_wait(&mutex); 
    buffer[i] = item;
    printf("Producer produces: %d\n", item);
    i = (i + 1) % BUFFER_SIZE;
    sem_post(&mutex); 
    sem_post(&full);  
}

void consumer() {
    sem_wait(&full);
    sem_wait(&mutex); 
    int item = buffer[j];
    printf("Consumer consumes: %d\n", item);
    j = (j + 1) % BUFFER_SIZE; 
    sem_post(&mutex); 
    sem_post(&empty); 
}

int main() {
    sem_init(&full, 0, 0);            
    sem_init(&empty, 0, BUFFER_SIZE);    
    sem_init(&mutex, 0, 1);             
    producer(1);  
    producer(2);  
    consumer();   
    producer(3);  
    consumer();   
    consumer();
    producer(4); 
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
    return 0;
}