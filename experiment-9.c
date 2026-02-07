#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = 1234;
    int shmid;
    char *data;

    shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    data = (char*) shmat(shmid, NULL, 0);

    printf("Write data: ");
    gets(data);

    printf("Data written in shared memory: %s\n", data);

    shmdt(data);

    return 0;
}
