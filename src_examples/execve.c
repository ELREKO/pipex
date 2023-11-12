#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *args[] = { "/bin/ls", "-l", NULL }; // Beispielargumente für den Befehl

    // Ausführung des ls-Befehls
    if (execve("/bin/ls", args, NULL) == -1) {
        perror("Fehler bei execve");
        exit(EXIT_FAILURE);
    }

    printf("Das sollte nicht gedruckt werden, wenn execve erfolgreich ist.\n");
    return 0;
}
