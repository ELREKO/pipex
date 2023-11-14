# execve
- `#include <unistd.h>`
- `int execve(const char *filename, char *const argv[], char *const envp[]);`
    - `filename` - Pfad zum auszufuerenden Programm 
    - `argv[]` Zeigern auf nullterminierte Strings, wobei der erste String der Befehl und die folgenden Strings die Argumente sind. Das letzte Element muss `NULL` sein.
    - `envp[]` : Ein Array von Zeigern auf nullterminierte Strings, die die Umgebungsvariablen für das neue Programm darstellen.

## Besonderheiten
- `execve` kehrt bei erfolgreicher Ausfuerung nicht zum Programm zuruek nur bei Fehler gibt es `-1` zuruueck!
- Die Controlle geht an das neue Programm ueber! 


[link](https://openbook.rheinwerk-verlag.de/linux_unix_programmierung/Kap07-009.htm#RxxKap07009040002001F028118)

