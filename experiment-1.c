#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd1, fd2;
    char buffer[100];
    int n;

    fd1 = open("source.txt", O_RDONLY);
    fd2 = open("dest.txt", O_CREAT | O_WRONLY | O_TRUNC, 0777);

    if(fd1 < 0 || fd2 < 0) {
        printf("File open error!\n");
        return 0;
    }

    while((n = read(fd1, buffer, sizeof(buffer))) > 0) {
        write(fd2, buffer, n);
    }

    printf("File copied successfully!\n");

    close(fd1);
    close(fd2);

    return 0;
}
