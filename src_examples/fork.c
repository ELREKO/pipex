#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() {
    pid_t pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fehler beim Forken\n");
        return 1;
    } else if (pid == 0) {
        printf("Kindprozess: Hello World % d\n", pid);
    } else {
        printf("Elternprozess: Hello World %d\n", pid);
    }
    return 0;
}
