#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("not_existing_file.txt", "r");

    if (file == NULL) {
        perror("Fehlermeldung");
        printf("Fehlermeldung: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    } else {
        // Datei erfolgreich geöffnet, hier könntest du etwas mit der Datei machen
        fclose(file);
    }

    return 0;
}