#include "../includes/pipex.h"
#include <errno.h>
extern int errno;


void ft_cmd_handle(char **cmd, char *output_file, t_arg **list) 
{
    FILE *output = freopen(output_file, "w", stdout);

    if (!output) {
        perror("Fehler beim Umlenken der Ausgabe auf Datei");
       // exit(EXIT_FAILURE);
    }
    if (execvp(cmd[0], cmd) == -1) {
        perror("Fehler bei execvp");
       // exit(EXIT_FAILURE);
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
        // Kindprozess 1 
        close(pipefd[0]);  
        dup2(pipefd[1], STDOUT_FILENO);  
        close(pipefd[1]);  
        ft_cmd_handle((*list)->cmd_1, "/dev/stdout", list);
    } 
    else 
    {
        int status;
        // Elternprozess
        
        close(pipefd[1]);  // Schließe das Schreib-Ende der Pipe im Elternprozess
        dup2(pipefd[0], STDIN_FILENO);  // Umlenken der Standardeingabe auf die Pipe
        close(pipefd[0]);  // Schließe das Lese-Ende der Pipe

        // Elternprozess wartet auf den Abschluss des Kindprozesses mit waitpid
        if (waitpid(main_pid, &status, 0) == -1) {
            perror("Fehler bei waitpid (Kindprozess 1)");
            exit(EXIT_FAILURE);
        }

        // Überprüfen, ob der Kindprozess 1 mit einem Fehler beendet wurde
        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            if (exit_status != 0) {
                printf("Fehler Kindprozess 1 mit Exit-Status %d\n", exit_status);
            }
        }

        // Weiter mit der Erstellung des Kindprozesses 2
        child_pid = fork();

        if (child_pid == -1) {
            perror("Fehler bei fork (Kindprozess 2)");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0)
        {
            // Kindprozess 2
            ft_cmd_handle((*list)->cmd_2, (*list)->outfile, list);
        }
        else
        {
            // Elternprozess wartet auf den Abschluss des Kindprozesses 2 mit waitpid
            if (waitpid(child_pid, &status, 0) == -1) {
                perror("Fehler bei waitpid (Kindprozess 2)");
                exit(EXIT_FAILURE);
            }

            // Überprüfen, ob der Kindprozess 2 mit einem Fehler beendet wurde
            if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE) {
                printf("Fehler Kindprozess 2 \n");
            }
        }
    }
}
