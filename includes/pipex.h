#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "../libft/libft.h"

typedef struct s_arg
{
    char    *inflile;
    char    **cmd_1;
    char    **cmd_2;
    char    *outfile;
    char    *path_1;
    char    *path_2;
}   t_arg;

// errorhandling.c
void ft_throw_error(const char *msg, t_arg **arg);
void ft_free_struct_arg(t_arg **arg);
void ft_free_str(char *str);
void ft_free_map(char **map);

// reading_arg.c
 t_arg *ft_read_arg(char **arg, char **envp);

 // foring.c
void ft_forking(t_arg **list);

#endif
