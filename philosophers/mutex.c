#include <pthread.h>
#include <stdio.h>



void* threadFunction(int* arg) {
    // Acquire the lock on the mutex
    // pthread_mutex_lock(&mutex);

    // Access the shared variable
    (int)(*arg)++;
    printf("Thread incremented the shared variable: %d\n", arg);

    // Release the lock on the mutex
    // pthread_mutex_unlock(&mutex);

    return NULL;
}
void* threadFunction1(int* arg) {
    // Acquire the lock on the mutex
    // pthread_mutex_lock(&mutex);

    // Access the shared variable
    (int)(*arg)++;
    printf("Thread incremented the shared variable: %d\n", arg);

    // Release the lock on the mutex
    // pthread_mutex_unlock(&mutex);
// 
    return NULL;
}

int main() {
    pthread_mutex_t mutex;
int sharedVariable = 0;
    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, threadFunction1, &sharedVariable);
    pthread_create(&thread2, NULL, threadFunction, &sharedVariable);
    pthread_create(&thread1, NULL, threadFunction1, &sharedVariable);
    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy the mutex when no longer needed
    pthread_mutex_destroy(&mutex);

    return 0;
}