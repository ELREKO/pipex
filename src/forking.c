#include "../includes/pipex.h"

static void ft_cmd_handle(char **cmd, char *input_file, char *output_file, t_arg **list);
static void ft_pipe_setting(int *pipfd, int open_close, t_arg **list);
static void ft_second_pipe(int *pipefd, t_arg **list, pid_t *pid_child);

void ft_forking(t_arg **list) 
{
    int pipefd[2];
    pid_t pid_child[2];

    if (pipe(pipefd) == -1)
        ft_throw_error("ERROR: Error using pipe", list);

    pid_child[0] = fork();
    if (pid_child[0] == -1)
        ft_throw_error("ERROR: Error using fork part one", list);

    if (pid_child[0] == 0)
    {
        // Kindprozess 1
        ft_pipe_setting(pipefd, 1, list);
        ft_cmd_handle((*list)->cmd_1, (*list)->inflile, "/dev/stdout", list);
    }
    else
    {
        // Elternprozess
        ft_pipe_setting(pipefd, 0, list);
        ft_second_pipe(pipefd, list, pid_child);
    }
}

static void ft_second_pipe(int *pipefd, t_arg **list, pid_t *pid_child)
{
    int status;

    if (waitpid(pid_child[0], &status, 0) == -1)
        ft_throw_error("ERROR: Error waitpaid (Childprocess 1)", list);

    pid_child[1] = fork();

    if (pid_child[1] == -1)
        ft_throw_error("ERROR: Error using fork part two", list);

    if (pid_child[1] == 0)
    {
        // Kindprozess 2
        ft_pipe_setting(pipefd, 0, list);  // Hier wurde die Eingabeumleitung aktiviert
        ft_cmd_handle((*list)->cmd_2, "/dev/stdin", (*list)->outfile, list);
    }
    else
    {
        // Elternprozess wartet auf den Abschluss des Kindprozesses 2 mit waitpid
        if (waitpid(pid_child[1], &status, 0) == -1)
            ft_throw_error("ERROR: Error using waitpid (Childprocess 2)", list);
    }
}

static void ft_cmd_handle(char **cmd, char *input_file, char *output_file, t_arg **list)
{    
    int input_fd;
    int output_fd;

    input_fd = open(input_file, O_RDONLY);
    if (input_fd == -1)
        ft_throw_error("ERROR: File open for input", list);

    output_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (output_fd == -1)
        ft_throw_error("ERROR: File open for output", list);

    if (dup2(input_fd, STDIN_FILENO) == -1 || dup2(output_fd, STDOUT_FILENO) == -1)
    {
        close(input_fd);
        close(output_fd);
        ft_throw_error("ERROR: Could not redirect input/output", list);
    }

    close(input_fd);
    close(output_fd);

    if (execvp(cmd[0], cmd) == -1)
    {
        ft_throw_error("ERROR: Could not use execvp", list);
    }
}

/*
 * @brief It open an close the pip
 * 
 * @param pipfd it ist a integer array for the pipe positon.
 * @param open_close it is a int value '1' is put in one end / '0' get it from the other end od the pipe
 */
static void ft_pipe_setting(int *pipfd, int open_close, t_arg **list)
{
    if (open_close == 1)
    {
        close(pipfd[0]);
        dup2(pipfd[1], STDOUT_FILENO);
        close(pipfd[1]);
    }
    else if (open_close == 0)
    {
        close(pipfd[1]);
        dup2(pipfd[0], STDIN_FILENO);
        close(pipfd[0]);
    }
    else
        ft_throw_error("ERROR: Error wrong pipesetting", list);
}
