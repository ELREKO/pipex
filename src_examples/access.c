#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main() {
    // Dateipfad, den du überprüfen möchtest
    const char *file_path = "access.c";

    // Überprüfen, ob die Datei lesbar ist
    if (access(file_path, R_OK) == 0) {
        printf("Die Datei ist lesbar.\n");
    } else {
        perror("Fehler beim Zugriff auf die Datei");
        exit(EXIT_FAILURE);
    }

    // Überprüfen, ob die Datei ausführbar ist
    if (access(file_path, X_OK) == 0) {
        printf("Die Datei ist ausführbar.\n");
    } else {
        perror("Fehler beim Zugriff auf die Datei");
        printf("Fehlermeldung: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Überprüfen, ob die Datei existiert
    if (access(file_path, F_OK) == 0) {
        printf("Die Datei existiert.\n");
    } else {
        perror("Datei existiert nicht oder Zugriff verweigert");
        exit(EXIT_FAILURE);
    }

    return 0;
}
