#include "../includes/pipex.h"
#include <errno.h>
extern int errno;


void ft_cmd_handle(char **cmd, char *output_file) 
{
    FILE *output = freopen(output_file, "w", stdout);

    if (!output) {
        perror("Fehler beim Umlenken der Ausgabe auf Datei");
        exit(EXIT_FAILURE);
    }
    if (execvp(cmd[0], cmd) == -1) {
        perror("Fehler bei execvp");
        exit(EXIT_FAILURE);
    }
}

void ft_parent(t_arg **list) 
{
    int pipefd[2];
    pid_t main_pid;
    pid_t child_pid;

    if (pipe(pipefd) == -1) {
        perror("Fehler bei pipe");
        exit(EXIT_FAILURE);
    }

    main_pid = fork();

    if (main_pid == -1) {
        perror("Fehler bei fork");
        exit(EXIT_FAILURE);
    }

    if (main_pid == 0)
    {
        // Kindprozess
        close(pipefd[0]);  
        dup2(pipefd[1], STDOUT_FILENO);  
        close(pipefd[1]);  
        ft_cmd_handle((*list)->cmd_1, "/dev/stdout");
    } 
    else 
    {
        // Elternprozess
        int status;
        close(pipefd[1]);  // Schließe das Schreib-Ende der Pipe im Elternprozess
        dup2(pipefd[0], STDIN_FILENO);  // Umlenken der Standardeingabe auf die Pipe
        close(pipefd[0]);  // Schließe das Lese-Ende der Pipe

        child_pid = fork();

        if (child_pid == -1) {
            perror("Fehler bei fork");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0)
        {
            ft_cmd_handle((*list)->cmd_2, (*list)->outfile);
        }
        else
        {
            // Elternprozess wartet auf den Abschluss des Kindprozesses mit waitpid
            if (waitpid(child_pid, &status, 0) == -1) {
                perror("Fehler bei waitpid");
                exit(EXIT_FAILURE);
            }
            // Überprüfen, ob der Kindprozess mit einem Fehler beendet wurde
            if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE) {
                // Hier können Sie entsprechend auf den Fehler reagieren
                printf("Fehler Kindprozzess \n");
            } else {
                // Hier wird der Code ausgeführt, wenn der Kindprozess erfolgreich war
                //printf("Fehler Im Elternprozess\n");
            }

           // printf("done\n");
        }
    }
}





//-----------------------------------------------------

// void ft_cmd_handle(char **cmd, char *output_file) 
// {
//     FILE *output = freopen(output_file, "w", stdout);

//     if (!output) {
//         perror("Fehler beim Umlenken der Ausgabe auf Datei");
//         //exit(EXIT_FAILURE);
//     }
//     if (execve(cmd[0], cmd, NULL) == -1) 
//     {
//         perror("Fehler bei execve");
//     }
// }

// void ft_parent(t_arg **list) 
// {
//     int pipefd[2];
//     pid_t child_pid;

//     if (pipe(pipefd) == -1) {
//         perror("Fehler bei pipe");
//         //exit(EXIT_FAILURE);
//     }

//     child_pid = fork();

//     if (child_pid == -1) {
//         perror("Fehler bei fork");
//        // exit(EXIT_FAILURE);
//     }

//     if (child_pid == 0)
//     {
//     // Kindprozess
//         close(pipefd[0]);  
//         dup2(pipefd[1], STDOUT_FILENO);  
//         close(pipefd[1]);  
//         ft_cmd_handle((*list)->cmd_1, "/dev/stdout");
//     } 
//     else 
//     {
//         // Elternprozess    
//         int status;
//         close(pipefd[1]);  // Schließe das Schreib-Ende der Pipe im Elternprozess
//         dup2(pipefd[0], STDIN_FILENO);  // Umlenken der Standardeingabe auf die Pipe
//         close(pipefd[0]);  // Schließe das Lese-Ende der Pipe
//         ft_cmd_handle((*list)->cmd_2, (*list)->outfile);

//         // Warten auf den Abschluss des Kindprozesses mit waitpid
//         if (waitpid(child_pid, &status, 0) == -1) {
//             perror("Fehler bei waitpid");
//             exit(EXIT_FAILURE);
//         }
//         // Überprüfen, ob der Kindprozess mit einem Fehler beendet wurde
//         if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE) {
//             // Hier können Sie entsprechend auf den Fehler reagieren
//             printf("Fehler im Kindprozess\n");
//         } else {
//             // Hier wird der Code ausgeführt, wenn der Kindprozess erfolgreich war
//             printf("Im Elternprozess\n");
//         }

        
//         printf("Im Elternprozess\n");
//     }
// }