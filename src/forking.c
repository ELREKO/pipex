#include "../includes/pipex.h"
#include <errno.h>
extern int errno;

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void ft_cmd_handle(char **cmd, char *output_file, t_arg **list) {
    // Öffne die Datei im Schreibmodus (O_CREAT erstellt die Datei, wenn sie nicht existiert)
    int output_fd;

    output_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (output_fd == -1) {
        ft_throw_error("ERROR: File open", list);
        return; // Beende die Funktion, da die Datei nicht erfolgreich geöffnet wurde
    }

    // Leite die Standardausgabe um, damit sie in die Datei geschrieben wird
    if (dup2(output_fd, STDOUT_FILENO) == -1) {
        close(output_fd);
        ft_throw_error("ERROR: Could not redirect output", list);
        
        return; // Beende die Funktion, da die Umleitung nicht erfolgreich war
    }

    // Schließe die nicht benötigten Dateideskriptoren
    close(output_fd);

    // Führe das Programm aus
    if (execvp(cmd[0], cmd) == -1) {
        // Fehlerbehandlung, falls execvp fehlschlägt
        ft_throw_error("ERROR: Could not use execvp", list);
        // Beende die Funktion, da execvp nicht erfolgreich war
    }
}

void ft_check (char **cmd, t_arg **list)
{
        if (execvp(cmd[0], cmd) == -1) {
        // Fehlerbehandlung, falls execvp fehlschlägt
        ft_throw_error("ERROR: Could not use execvp", list);
        // Beende die Funktion, da execvp nicht erfolgreich war
    }
}

// void ft_cmd_handle(char **cmd, char *output_file, t_arg **list) 
// {
//     FILE *output = freopen(output_file, "w", stdout);

//     if (!output)
//         ft_throw_error("ERROR: File open", list);
//     if (execvp(cmd[0], cmd) == -1)
//         ft_throw_error("ERROR: Could not use execvp", list);
//     printf("\n\nTest muss\n\n");
// }

void ft_child_1(int *pipfd, t_arg **list)
{
        close(pipfd[0]);  
        dup2(pipfd[1], STDOUT_FILENO);  
        close(pipfd[1]);  
        ft_cmd_handle((*list)->cmd_1, "/dev/stdout", list);
}

//void ft_child_2_parant(t_arg **list, int pipfd)

void ft_forking(t_arg **list) 
{
    int pipefd[2];
    pid_t pid_child[2];
    int status;
    //int exit_status;

    if (pipe(pipefd) == -1)
        ft_throw_error("ERROR: Error using pipe", list);
    pid_child[0] = fork();
    if (pid_child[0] == -1)
        ft_throw_error("ERROR: Error using fork part one", list);
    if (pid_child[0] == 0)
        ft_child_1(pipefd, list);
    else 
    {// Kind 2
        close(pipefd[1]);  // Schließe das Schreib-Ende der Pipe im Elternprozess
        dup2(pipefd[0], STDIN_FILENO);  // Umlenken der Standardeingabe auf die Pipe
        close(pipefd[0]);  // Schließe das Lese-Ende der Pipe
        if (waitpid(pid_child[0], &status, 0) == -1)
            ft_throw_error("ERROR: Error waitpaid (Childprocess 1)", list);
        pid_child[1] = fork();

        if (pid_child[1] == -1)
            ft_throw_error("ERROR: Error using fork part two", list);

        if (pid_child[1] == 0)
            ft_cmd_handle((*list)->cmd_2, (*list)->outfile, list);
        else
        {
            // Elternprozess wartet auf den Abschluss des Kindprozesses 2 mit waitpid
            if (waitpid(pid_child[1], &status, 0) == -1)
                ft_throw_error("ERROR: Error using waitpid (Childprocess 2)", list);
        }
    }
}

