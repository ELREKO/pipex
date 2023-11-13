#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

int main (void)
{
    int id_1 = fork();
    int id_2 = fork();

    if (id_1 == 0)
    {
        if (id_2 == 0)
            printf("We are in the proces Y\n");
        else 
            printf("We are in the process x\n");  
    }
    else {
        if (id_2 == 0)
            printf("We are in the process z\n");
        else
            printf("We are int the parent Process\n"); 
    }
    while (wait(NULL) != -1 || errno != ECHILD)
    {
        printf("wait to child\n");
        fflush(stdout);
    }
    
    return (0);
}



// int main() {
//     printf("Vor dem Fork\n");

//     pid_t pid_1 = fork();

//     if (pid_1 < 0) {
//         fprintf(stderr, "Fehler beim Forken\n");
//         return 1;
//     } else if (pid_1 == 0) {
//         printf("Kindprozess 1 : Hello World %d\n", pid_1);
        
//         pid_t pid_2 = fork();
//         if (pid_2 < 0) {
//             printf("Fehler beim zweiten Fork\n");
//         } else if (pid_2 == 0) {
//             printf("Kindprozess 2: Hello World %d\n", pid_2);
//         } else {
//             printf("Elternprozess 1: Hello World %d, Kindprozess 2 ID: %d\n", pid_1,  pid_2);
//         }
//     } else {
//         printf("Elternprozess 1: Hello World %d\n", pid_1);
//     }

//     return 0;
// }
