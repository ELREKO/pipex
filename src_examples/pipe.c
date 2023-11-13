#include <stdio.h>
#include <unistd.h>

int main() {
    int fd_read, fd_write; // Separate Dateideskriptoren für das Lesen und Schreiben des Pipes
    char message[] = "Hello, pipe!";

    if (pipe(&fd_read) == -1 || pipe(&fd_write) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid > 0) {  // Parent process
        close(fd_read);  // Schließt das Lesen im Elternprozess
        write(fd_write, message, sizeof(message));
        close(fd_write);  // Schließt das Schreiben im Elternprozess
    } else {  // Child process
        close(fd_write);  // Schließt das Schreiben im Kindprozess
        char buffer[100];
        read(fd_read, buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd_read);  // Schließt das Lesen im Kindprozess
    }

    return 0;
}
