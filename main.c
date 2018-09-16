#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include<sys/wait.h> 

char* concat(const char *s1, const char *s2);

int main (int argc, char *argv[]) {
    pid_t childpid = 0;
    int i, n, j, m, k;
    const char helpOption[] = "-h";
    const char testErrorOption[] = "-p";
    const char getPidsOption[] = "-n";

    if (!(argc >= 2)) {
        fprintf(stderr, "Incorrect options. For help: %s -h  \n", argv[0]);
        return 1;
    }

    if ((!strcmp(argv[1], helpOption)) && (argc == 2)) {
        fprintf(stderr, "Command Options\n Help: %s -h  \n Test Error: %s -p  \n Create forking processes: %s -n PID loops delay \n", argv[0], argv[0], argv[0]);
        return 0;
    } else if ((!strcmp(argv[1], testErrorOption)) && (argc == 2)) {
        perror(concat(argv[0], ": Error: Detailed error message"));
        return 1;
    } else if ((!strcmp(argv[1], getPidsOption)) && (argc == 5)) {
        n = atoi(argv[2]);
        k = atoi(argv[3]);
        m = atoi(argv[4]);

        for (i = 1; i < n; i++) {
            if (childpid = fork()){
                break;
            }
        }

        for (j = 0; j <= k; j++) {
            wait(NULL);
            fprintf(stderr, "i:%d ", i);
            fprintf(stderr, "process ID:%ld ", (long)getpid());
            fprintf(stderr, "parent ID:%ld ", (long)getppid());
            fprintf(stderr, "child ID:%ld\n", (long)childpid);
            sleep(m);
        }

        return 0;  
    } else {
        fprintf(stderr, "Incorrect options. For help: %s -h  \n", argv[0]);
        return 1;
    }
}

char* concat(const char *s1, const char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}