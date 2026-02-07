#include <stdio.h>
#include <pthread.h>

void *printMsg(void *arg) {
    printf("Thread Running: %s\n", (char*)arg);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, printMsg, "Hello from Thread 1");
    pthread_create(&t2, NULL, printMsg, "Hello from Thread 2");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main Thread Finished\n");

    return 0;
}
