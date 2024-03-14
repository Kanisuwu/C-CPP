#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_COUNT 10
#define BUF_SIZE  100

void childProcess(void);
void parentProcess(void);

int main(void) {
    pid_t pid;
    char buf[BUF_SIZE];

    pid = fork();
    if (pid == 0)
        childProcess();
    else if (pid > 0)
        parentProcess();
    else {
        printf("fork() failed!\n");
        return 1;
    }
    return 0;
}

void childProcess(void) {
    int i = 0;
    for (i = 1; i <= MAX_COUNT; i++)
        printf("This line is from child, value = %d\n", i);
    printf("*** Child process is done. ***\n");
}

void parentProcess(void) {
    int i = 0;

    for (i = 1; i <= MAX_COUNT; i++)
        printf("This line is from parent, value = %d\n", i);
    printf("*** Parent process is done. ***\n");
}
