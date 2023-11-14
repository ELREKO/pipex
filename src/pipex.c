#include "../includes/pipex.h"

char **ft_path_filter(char **envp);
char *ft_get_path (char **envp, char *cmd);

int main(int ac, char **ag, char **envp) 
{

    int i_count;


    if (ac == 0)
        return (0);
    i_count = 0;
    while (ag[i_count] != NULL)
    {
        printf("%s\n", ag[i_count++]);
    }
    printf("\n\n\n-------------------------------------------------------------\n");
    ////-------------------



    //cmd = ft_strjoin(str_split, cmd_1);
    // char *args[] = { "/bin/ls", "-l", NULL }; // Beispielargumente für den Befehl

    // // Ausführung des ls-Befehls
    // if (execve("/bin/ls", args, NULL) == -1) {
    //     perror("Fehler bei execve");
    //     exit(EXIT_FAILURE);
    // }

    printf("%s\n",ft_get_path(envp, "ls"));







} 

char *ft_get_path (char **envp, char *cmd)
{
    int i_count;
    char **str_split;
    char *str_tmp;
    char *path;


    str_split = ft_path_filter(envp);
    i_count = 0;
    while(str_split[i_count] != NULL)
    {
        str_tmp = ft_strjoin(str_split[i_count++], "/");
        path = ft_strjoin(str_tmp, cmd);
        if (access(path, X_OK) == 0)
            break;
        free(str_tmp);
        free(path);
    }
    free(str_tmp);
    i_count = 0;
    while (str_split[i_count] != NULL)
        i_count++;
    while (i_count >= 0)    
        free(str_split[i_count--]);
    free(str_split);
    return (path);
}

char **ft_path_filter(char **envp)
{
    int i_count;
    char *result;
    char **str_split;

    i_count = 0;
    while (envp[i_count] != NULL)
    {

        result = ft_strnstr(envp[i_count], "PATH=/home", 20)  ;
        if (result != NULL) 
        {
            
            result = ft_strdup(ft_strchr(envp[i_count], '/'));
            str_split = ft_split(result, ':');
            free(result);
            return(str_split);
           //printf("Teilstring gefunden: %s\n\n", envp[i_count]);
        }
        i_count++;
    } 
    return(NULL);
}
