#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    char message[] = "Hello, pipe!";

    if (pipe(fd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid > 0) {  // Parent process
        write(fd[1], message, sizeof(message));
        close(fd[1]);  // Schließt das Schreiben im Elternprozess
    } else {  // Child process
        close(fd[1]);  // Schließt das Schreiben im Kindprozess
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd[0]);  // Schließt das Lesen im Kindprozess
    }

    return 0;
}
