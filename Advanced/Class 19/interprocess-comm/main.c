#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void handler(int signum) {
    printf("Cannot divide by zero.\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {

    /* Process PID */
    /*
    int mypid, myppid;
    printf("Program to know PID and PPID's information.\n");
    mypid = getpid();
    myppid = getppid();
    printf("My process ID is %d\n", mypid);
    printf("My parent process ID is %d\n", myppid);
    printf("Cross verification of PID's by executing process commandso n shell\n");
    system("ps -ef");
    */

    /* SIGNALS */
    //printf("Testint SIGSTOP\n");
    //raise(SIGSTOP);
    //printf("I am back!\n");
    
    /*
    alarm(5);

    for (int i = 1; i < 10; i++) {
        printf("%d\n", i);
        sleep(1);
    }
    */

    /* void (*signal)( int sig, void (*handler) (int) )) (int); */
    void (*sigHandler)(int) = signal(SIGFPE, handler);

    if (sigHandler == SIG_ERR) {
        perror("Signal error: ");
        return 1;
    }

    return 0;
}
