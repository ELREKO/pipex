
# access
Prueft berechtigungen auf Datien! 
`int access(const char *pfad, int modus);`

## Modus
`00 oder F_OK` -- Die Datei existiert! 
`01 oder X_OK` -- Die Datei ist ausfuerbar (nur Linux/UNIX).! 
`02 oder W_OK` -- Die Datei ist beschreibar
`04 oder R_OK` -- Die Datie ist lesbar.
`06 oder W_OK|R_OK` -- die datie ist lesbar und beschreibar! 

## Example
```c
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

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

    return 0;
}
```