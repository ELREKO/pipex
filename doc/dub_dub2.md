# dup und dup2
- beide erzeugen eine Kopie des Filediscriptors !
- beide sind unter `<unistd.h>` vorhanden! 

## dup
`int dup(int oldfd);`
Der unterschied ist das `dup` einfach die niedrigste 'ungenutzte' nummer fuer den File discriptor nimmt!

### Example 
```C
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("file.txt", O_RDONLY);
    int new_fd = dup(fd);

    // Jetzt gibt es zwei separate Dateideskriptoren für die gleiche Datei

    close(fd);
    close(new_fd);
    return 0;
}
```


## dup2
`int dup2(int oldfd, int newfd);`
Bei `dup2` kann die nummer vorgegeben werden wenn diese schon genutzt wird dann wird dies erst geschlossen und dann der gewunschten nummer zugewissen! 
--> Sommit hat dup2 etwas mehr kontrolle! 

### Example 
```C
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("file.txt", O_RDONLY);
    int new_fd = open("new_file.txt", O_WRONLY | O_CREAT, 0644);
    dup2(fd, new_fd);

    // Jetzt zeigt new_file.txt auf dasselbe wie file.txt

    close(fd);
    close(new_fd);
    return 0;
}
```







