## perror und strerror
Im Prinzip machen Sie das gleiche --> Geben eine Fehlerbeschreibung aus!
Nur in der Anwendung sind dies unterschiedlich
### Example 
```c
// Die Ausgabe ist gleich nur das strerror noch <string.h> zu der <errno.h> benoetigt! 
    perror("Fehlermeldung");
    printf("Fehlermeldung: %s\n", strerror(errno));
```