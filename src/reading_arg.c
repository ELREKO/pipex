#include "../includes/pipex.h"

static void ft_check_infile(t_arg **list);
static void ft_get_path (char **envp, t_arg **arg);
static char **ft_path_filter(char **envp);

// reading the different given Arguments --> set the path with 'ft_get_path'
t_arg *ft_read_arg(char **arg, char **envp)
{
    t_arg *list;

    list = malloc(sizeof(t_arg));
    if (!list)
        ft_throw_error("ERROR: malloc", &list);
    list->inflile = ft_strdup(arg[1]);
    ft_check_infile(&list);
    list->cmd_1 = ft_split(arg[2], ' ');
    list->cmd_2 = ft_split(arg[3], ' ');
    list->outfile = ft_strdup(arg[4]);
    ft_get_path(envp, &list);
   free(list->cmd_1[0]);
   free(list->cmd_2[0]);
   list->cmd_1[0] = ft_strdup(list->path_1);
   list->cmd_2[0] = ft_strdup(list->path_2);
    return (list);   
}

static void ft_check_infile(t_arg **list)
{
    int fd;

    fd = open((*list)->inflile, O_RDONLY);
    if (fd == -1)
        ft_throw_error("ERROR: File open for input", list);
    close(fd);
}

// checking with acces is the path excahanablie 
static void ft_get_path (char **envp, t_arg **arg)
{
    int i_count;
    char **str_split;
    char *str_tmp;

    str_split = ft_path_filter(envp);
    i_count = 0;
    while(str_split[i_count] != NULL)
    {
        str_tmp = ft_strjoin(str_split[i_count++], "/");
        (*arg)->path_1 = ft_strjoin(str_tmp, (*arg)->cmd_1[0]);
        (*arg)->path_2 = ft_strjoin(str_tmp, (*arg)->cmd_2[0]);\
        free(str_tmp);
        if (access(((*arg)->path_1), X_OK) == 0 && access(((*arg)->path_2), X_OK) == 0)
            break;
        if (str_split[i_count + 1] == NULL)
        {
            ft_free_map(str_split);
            ft_throw_error("ERROR: one or more cmd not executable\n", arg);
        }
        free((*arg)->path_1);
        free((*arg)->path_2);
    }
    ft_free_map(str_split);
}

// search the paht from the enviorment and split it into diffrent path
static char **ft_path_filter(char **envp)
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
            result = ft_strdup(envp[i_count]);
            str_split = ft_split(result, ':');
            free(result);
            return(str_split);
        }
        i_count++;
    } 
    return (NULL);
}