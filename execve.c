#include "main.h"

void custom_execve(const char *pathname, char *const argv[], char *const envp[]) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        /* Code executed by the child process */
        if (execve(pathname, argv, envp) == -1) {
            perror("execve failed");
            exit(1);
        }
    } else {
        /* Code executed by the parent process */
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        }
    }
}

